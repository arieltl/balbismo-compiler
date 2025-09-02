// ignore_for_file: constant_identifier_names

import 'dart:convert';
import 'dart:io';

import 'package:balbismo/SymbolTable.dart';
import 'package:balbismo/node.dart';
import 'package:balbismo/yamlParser.dart';
enum CompileModes {
  IR,
  OPT_IR,
  ASM,
  BIN,
  RUN;
  
}

CompileModes invalidMode(){
  print("Invalid mode");
  printUsage();
  return CompileModes.ASM;
}

 Future<void> main(List<String> arguments) async{
  var mode = CompileModes.IR;
  var fileInName = "";
  var extraArgs = <String>[];
  if (arguments.length == 1) {
      printUsage();
  } else if (arguments.length > 1) {
    mode  = switch (arguments[0]){
      "gen-ir" => CompileModes.IR,
      "gen-asm" => CompileModes.ASM,
      "compile" => CompileModes.BIN,
      "run" => CompileModes.RUN,
      "opt-ir" => CompileModes.OPT_IR,
      _ => invalidMode(),
    };
    fileInName = arguments[1];
    extraArgs = arguments.sublist(2);
  } else {
    print("No file specified");
    printUsage();
  }
  String outputPath = switch (mode) {
    CompileModes.IR => "build/main.ll",
    CompileModes.OPT_IR => "build/main.ll",
    CompileModes.ASM => "build/main.s",
    CompileModes.BIN => "build/main",
    CompileModes.RUN => ""

  };
  // check if -o is in extraArgs
  if (extraArgs.contains("-o")) {
    var index = extraArgs.indexOf("-o");
    outputPath = extraArgs[index + 1];
    extraArgs.removeAt(index);
    extraArgs.removeAt(index);
  }
  
  Node.ir += "declare i32 @printf(i8*, ...)\n";
  Node.ir += "declare i32 @scanf(i8*, ...)\n";
    //check if build directory exists
  if (!Directory("build").existsSync()) {
    Directory("build").createSync();
    //check if tmp directory exists
    if (!Directory("build/tmp").existsSync()) {
      Directory("build/tmp").createSync();
    }
  }
  //run bison parser binary named balbismo_parser using process pass file to stdin
  var parser = await Process.start("lex-parse/balbismo_parser", ["-o", "build/tmp/ast.out"]);
  var codeFile = File(fileInName);


  codeFile.openRead().pipe(parser.stdin);
  print("Parsing with flex-bison");

  String parserError = await parser.stderr.transform(utf8.decoder).join("\n");
  int _ = await parser.exitCode;
  if (parserError.isNotEmpty) {
    print("-------------Parser failed---------------");
    print(parserError);

    exit(1);
  } else {
    print("---------------Parser finished successfully----------------");
  }
  print("Reading AST file: build/tmp/ast.out");
  var ast = parseAstFile("build/tmp/ast.out");
  print("-----------------AST Loaded Successfully-----------------");
  print("Generating IR code on build/tmp/main.ll");
  ast.evaluate(SymbolTable());
  File("build/tmp/main.ll").writeAsStringSync(Node.ir);
  print("-----------------IR Generated Successfully-----------------");


  switch (mode) {
    case CompileModes.IR:
      print("Outputting IR code to $outputPath");
      File(outputPath).writeAsStringSync(Node.ir);
    case CompileModes.OPT_IR:
      //run opt on build/main.ll
      var opt = await Process.start("opt", ["-S", "build/tmp/main.ll", "-o", outputPath, ...extraArgs]);
      print("Optimizing IR code with opt and outputting to $outputPath");
      opt.stdout.forEach((e)=>print(e));
      String optError = await opt.stderr.transform(utf8.decoder).join("\n");
      int optExitcode = await opt.exitCode;
      if (optError.isNotEmpty || optExitcode != 0) {
        print("-------------Opt failed---------------");
        print(optError);
        exit(1);
      } 
      print("---------------Opt finished successfully----------------");
    case CompileModes.ASM:
      //run llc on build/main.ll
      print("Generating assembly with llc and outputting to $outputPath");
      var llc = await Process.start("llc", ["-o", outputPath, "build/tmp/main.ll", ...extraArgs]);
      llc.stdout.forEach((e)=>print(e));
      String llcError = await llc.stderr.transform(utf8.decoder).join("\n");
      int llcExitcode = await llc.exitCode;
      if (llcError.isNotEmpty || llcExitcode != 0) {
        print("-------------llc failed---------------");
        print(llcError);
        exit(1);
      }
      print("---------------llc finished successfully----------------");

    case CompileModes.BIN:
      // run clang on build/main.s
      print("Compiling with clang and outputting to $outputPath");
      var clang = await Process.start("clang", ["-o", outputPath, "build/tmp/main.ll", ...extraArgs]);
      clang.stdout.forEach((e)=>print(e));
      String clangError = await clang.stderr.transform(utf8.decoder).join("\n");
      int clangExitcode = await clang.exitCode;
      if (clangExitcode != 0) {
        print("-------------clang failed---------------");
        print(clangError);
        exit(1);
      }
      print("---------------clang finished successfully----------------");
    case CompileModes.RUN:
      //run lli on build/main.ll
      print("Running with lli");
      print("----program output:\n");
      var lli = await Process.start("stdbuf", ["-oL","lli", "build/tmp/main.ll", ...extraArgs]);
      lli.stdout.transform(utf8.decoder).forEach((element) => print(element));
      stdin.pipe(lli.stdin);
     
      
      String lliError = await lli.stderr.transform(utf8.decoder).join("\n");
      int lliExitcode = await lli.exitCode;
      if (lliExitcode != 0) {

        print("-------------lli failed---------------");
        print(lliError);
        exit(1);
      }
      print("---------------lli finished successfully----------------");
    //close stdin
    default:
      break;
  }

  print("-----------------Finished Compiling Successfully-----------------");
  exit(0);

}

void printUsage(){
  print("Usage: balbismo <mode> <file> [args]");
  print("<mode> is one of the following:");
  print("Modes:");
  print("  gen-ir: Generate IR code");
  print("  opt-ir: Generate optimized IR code");
  print("  gen-asm: Generate assembly code");
  print("  compile: Compile to binary");
  print("  run: Gen IR and interpret with lli");
  print("  help: Print this message");
  print("<file> is the input file to be compiled");
  print("[args] are arguments");
  print("Arguments:");
  print("  -o <file>: Output file path default is build/main.ext where ext is ll, s or nothing");
  print("  Extra arguments will be passed to the compilers/interpreters as listed below:");
  print("     compile uses clang, run uses lli, gen-asm uses llc and opt-ir uses opt.");
  print("  Extra arguments cant be used with gen-ir");
  exit(1);
}