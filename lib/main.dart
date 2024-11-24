import 'dart:io';

import 'package:balbismo/SymbolTable.dart';
import 'package:balbismo/node.dart';
import 'package:balbismo/yamlParser.dart';


void main(){
  Node.ir += "@formati64 = private constant [4 x i8] c\"%d\\0A\\00\"\n";
  Node.ir += "@formatdouble = private constant [4 x i8] c\"%f\\0A\\00\"\n";

  Node.ir += "declare i32 @printf(i8*, ...)\n";

  Node.ir += "define i32 @main() {\n";
  Node.ir += "entry:\n";
  Node.irIndent++;
  var ast = parseAstFile("lex-parse/ast2.out");
  ast.evaluate(SymbolTable());
  Node.addIrLine("ret i32 0\n");
  Node.irIndent--;
  Node.ir += "}\n";
  
  //output main.ll
  File("main.ll").writeAsStringSync(Node.ir);
}