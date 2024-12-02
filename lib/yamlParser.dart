import 'dart:io';

import 'package:balbismo/node.dart';
import 'package:balbismo/vars.dart';
import 'package:yaml/yaml.dart';

Node parseAstFile(String path) {
  var yamlString = File(path).readAsStringSync();
  YamlMap astDict = loadYaml(yamlString)[0];
  return parseNode(astDict);
}

Node parseNode(YamlMap node) {
  var type = node["type"];
  var childrenDict = node["children"];
  final children = <Node>[];
  if (childrenDict != null) {
    for (var child in childrenDict) {
      children.add(parseNode(child));
    }
  }
  final value = node["value"];
  switch (type) {
    case "Block":
      return BlockNode(children);
    case "Identifier":
      return IdentifierNode(value);
    case "IndexedIdentifier":
      return IndexedIdentifierNode(value, children[0] as Node<dynamic, LangVal>);
    case "Type":
      return TypeNode(PrimitiveType(PrimitiveTypes.fromString(value)));
    case "ArrayType":
      return ArrayTypeNode(children[0] as TypeNode, children[1] as ArraySpecification);
    case "ArraySpecifier":
      return ArraySpecification(children.firstOrNull as Node<dynamic, LangVal>?);
    case "IntLiteral":
      return IntVal(value);
    case "FloatLiteral":
      return FloatVal(value);
    case "Declaration":
      return DeclareNode(children[0] as Node<LangType,dynamic>, children[1] as IdentifierNode, children.length > 2 ? children[2] : null); 
    case "Assignment":
      return AssignmentNode(children[0] as IdentifierNode, children[1]);
    case "UnOp":
      return UnOp(value, children[0] as Node<dynamic, LangVal>);
    case "BinOp":
      return BinOp(value, children[0] as Node<dynamic, LangVal>, children[1] as Node<dynamic, LangVal>);
    case "Print":
      return PrintNode(children[0] as StringLiteral, children.sublist(1).cast());
    case "RelOp":
      return RelOp(value, children[0] as Node<dynamic, LangVal>, children[1] as Node<dynamic, LangVal>);
    case "BoolUnOp":
      return BoolUnOp(value, children[0] as Node<dynamic, LangVal>);
    case "BoolBinOp":
      return BoolBinOp(value, children[0] as Node<dynamic, LangVal>, children[1] as Node<dynamic, LangVal>);
    case "IfStatement":
      return IfNode(children[0] as Node<dynamic, LangVal>, children[1] as BlockNode, children.length > 2 ? children[2] : null);
    case "WhileStatement":
      return WhileNode(children[0] as Node<dynamic, LangVal>, children[1] as BlockNode);
    case "ParameterList":
      return ParameterList(children.cast());
    case "ArgumentList":
      return ArgumentList(children.cast());
    case "FunctionDeclaration":
      return FuncDec(children[0] as TypeNode , children[1] as IdentifierNode, children[2] as ParameterList, children[3] as BlockNode);
    case "FunctionCall":
      return FuncCall(children[0] as IdentifierNode, children[1] as ArgumentList);
    case "ReturnStatement":
      return ReturnStatement(children[0] as Node<dynamic, LangVal>);
    case "FunctionList":
      return FunctionList(children.cast());
    case "TypeCast":
      return TypeCast(PrimitiveType(PrimitiveTypes.fromString(value)), children[0] as Node<dynamic, LangVal>);
    case "StringLiteral":
      return StringLiteral(value);
    default:
      throw Exception("Unknown node type: $type");
  }
}