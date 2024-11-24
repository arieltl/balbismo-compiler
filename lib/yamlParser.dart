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
    case "Type":
      return TypeNode(value);
    case "IntLiteral":
      return IntVal(value);
    case "FloatLiteral":
      return FloatVal(value);
    case "Declaration":
      return DeclareNode(children[0] as TypeNode, children[1] as IdentifierNode, children.length > 2 ? children[2] : null); 
    case "Assignment":
      return AssignmentNode(children[0] as IdentifierNode, children[1]);
    case "UnOp":
      return UnOp(value, children[0] as Node<dynamic, LangVal>);
    case "BinOp":
      return BinOp(value, children[0], children[1]);
    case "Print":
      return PrintNode(children[0] as Node<dynamic, LangVal>);
    default:
      throw Exception("Unknown node type: $type");
  }
}