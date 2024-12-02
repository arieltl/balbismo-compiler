import 'dart:io';

import 'package:balbismo/SymbolTable.dart';
import 'package:balbismo/node.dart';
import 'package:balbismo/yamlParser.dart';


void main(){


  Node.ir += "declare i32 @printf(i8*, ...)\n";
  Node.ir += "declare i32 @scanf(i8*, ...)\n";
  
  var ast = parseAstFile("lex-parse/ast2.out");
  ast.evaluate(SymbolTable());
  
  //output main.ll
  File("main.ll").writeAsStringSync(Node.ir);
}