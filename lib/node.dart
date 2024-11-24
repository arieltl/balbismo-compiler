
import 'package:balbismo/SymbolTable.dart';
import 'package:balbismo/vars.dart';



abstract class Node<T, E> {
  final T valueNode;
  final List<Node> children;
  int id = 0;

  Node(this.valueNode, this.children) {
    id = newId();
  }
  static String ir = "";
  static int i = 0;

  static int newId() {
    return i++;
  }

  E evaluate(SymbolTable table) {
    throw Exception("Not implemented");
  }
}

class BlockNode extends Node<void, void> {
  BlockNode(List<Node> children) : super(null, children);

  @override
  void evaluate(SymbolTable table) {
    for (var child in children) {
      child.evaluate(table);
    }
  }
}

class TypeNode extends Node<LangType, void> {
  TypeNode(String value) : super(LangType.fromString(value), []);
}

class IdentifierNode extends Node<String, LangVal> {
  IdentifierNode(String value) : super(value, []);

  @override
  LangVal evaluate(SymbolTable table) {
    var varData = table.get(valueNode);
    if (varData == null) {
      throw Exception("Variable $valueNode not found");
    }
    Node.ir +=
        "%var$id = load ${varData.type.irType}, ptr ${varData.ptrName}\n";
    return LangVal("%var$id", varData.type);
  }
}

class IntVal extends Node<int, LangVal> {
  IntVal(String value) : super(int.parse(value), []);

  @override
  LangVal evaluate(SymbolTable table) {
    Node.ir += "%val$id = add i64 0, $valueNode\n";
    return LangVal("%val$id", LangType.int);
  }
}

class FloatVal extends Node<double, LangVal> {
  FloatVal(String value) : super(double.parse(value), []);

  @override
  LangVal evaluate(SymbolTable table) {
    Node.ir += "%val$id = fadd double 0.0, ${valueNode}\n";
    return LangVal("%val$id", LangType.float);
  }
}

class DeclareNode extends Node<void, void> {
  DeclareNode(TypeNode type, IdentifierNode identifier, [Node? value])
      : super(null, [type, identifier, if (value != null) value]);

  IdentifierNode get identifier => children[1] as IdentifierNode;
  TypeNode get type => children[0] as TypeNode;

  @override
  void evaluate(SymbolTable table) {
    var ptrName = '%ptr.${identifier.valueNode}';
    table.create(identifier.valueNode, LangVar(ptrName, type.valueNode));
    Node.ir += "$ptrName = alloca ${type.valueNode.irType}\n";
    if (children.length > 2) {
      var value = children[2].evaluate(table);
      Node.ir += "store ${type.valueNode.irType} ${value.regName}, ptr $ptrName\n";
    }
  }
}

class AssignmentNode extends Node<void, void> {
  AssignmentNode(IdentifierNode identifier, Node value)
      : super(null, [identifier, value]);

  IdentifierNode get identifier => children[0] as IdentifierNode;
  Node get valueNode => children[1];

  @override
  void evaluate(SymbolTable table) {
    var varData = table.get(identifier.valueNode);
    if (varData == null) {
      throw Exception("Variable ${identifier.valueNode} not found");
    }
    var value = valueNode.evaluate(table);
    if (varData.type != value.type) {
      throw Exception("Type mismatch");
    }
    Node.ir +=
        "store ${varData.type.irType} ${value.regName}, ptr ${varData.ptrName}\n";
  }
}

enum MathOp {
  add,
  sub,
  mul,
  div,
  mod;

  //math op from string
  static MathOp fromString(String op) {
    switch (op) {
      case "+":
        return MathOp.add;
      case "-":
        return MathOp.sub;
      case "*":
        return MathOp.mul;
      case "/":
        return MathOp.div;
      case "%":
        return MathOp.mod;
      default:
        throw Exception("Unknown operator: $op");
    }
  }
}

class UnOp extends Node<MathOp, LangVal> {
  UnOp(String value, Node<dynamic, LangVal> child)
      : super(MathOp.fromString(value), [child]);

  Node<dynamic, LangVal> get child => children[0] as Node<dynamic, LangVal>;
  @override
  LangVal evaluate(SymbolTable table) {
    final childResult = child.evaluate(table);

    switch (valueNode) {
      case MathOp.add:
        return childResult;
      case MathOp.sub:
        Node.ir +=
            "%unOp.$id = sub ${childResult.type.irType} 0, ${childResult.regName}\n";
        return LangVal("%unOp.$id", childResult.type);
      default:
        throw Exception("Unknown operator: $valueNode");
    }
  }
}

class BinOp extends Node<MathOp, LangVal> {
  BinOp(String value, Node left, Node right)
      : super(MathOp.fromString(value), [left, right]);

  @override
  LangVal evaluate(SymbolTable table) {
    var leftResult = children[0].evaluate(table);
    var rightResult = children[1].evaluate(table);

    if (leftResult.type != rightResult.type) {
      if (leftResult.type == LangType.float) {
        Node.ir += "%conv.$id = sitofp i64 ${rightResult.regName} to double\n";
        rightResult = LangVal("%conv.$id", LangType.float);
      } else {
        Node.ir += "%conv.$id = sitofp i64 ${leftResult.regName} to double\n";
        leftResult = LangVal("%conv.$id", LangType.float);
      }
    }
    if (leftResult.type == LangType.float) {
      switch (valueNode){
        case MathOp.add:
          Node.ir +=
              "%binOp.$id = fadd double ${leftResult.regName}, ${rightResult.regName}\n";
          return LangVal("%binOp.$id", leftResult.type);
        case MathOp.sub:
          Node.ir +=
              "%binOp.$id = fsub double ${leftResult.regName}, ${rightResult.regName}\n";
          return LangVal("%binOp.$id", leftResult.type);
        case MathOp.mul:
          Node.ir +=
              "%binOp.$id = fmul double ${leftResult.regName}, ${rightResult.regName}\n";
          return LangVal("%binOp.$id", leftResult.type);
        case MathOp.div:
          Node.ir +=
              "%binOp.$id = fdiv double ${leftResult.regName}, ${rightResult.regName}\n";
          return LangVal("%binOp.$id", leftResult.type);
        default:
          throw Exception("Unknown operator: $valueNode");
      }
    }

    switch (valueNode) {
      case MathOp.add:
        Node.ir +=
            "%binOp.$id = add ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}\n";
        return LangVal("%binOp.$id", leftResult.type);
      case MathOp.sub:
        Node.ir +=
            "%binOp.$id = sub ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}\n";
        return LangVal("%binOp.$id", leftResult.type);
      case MathOp.mul:
        Node.ir +=
            "%binOp.$id = mul ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}\n";
        return LangVal("%binOp.$id", leftResult.type);
      case MathOp.div:
        Node.ir +=
            "%binOp.$id = sdiv ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}\n";
        return LangVal("%binOp.$id", leftResult.type);
      case MathOp.mod:
        Node.ir +=
            "%binOp.$id = srem ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}\n";
        return LangVal("%binOp.$id", leftResult.type);
      default:
        throw Exception("Unknown operator: $valueNode");
    }
  }
}

class PrintNode extends Node<void, void> {
  PrintNode(Node<dynamic, LangVal> child) : super(null, [child]);

  Node<dynamic, LangVal> get child => children[0] as Node<dynamic, LangVal>;

  @override
  void evaluate(SymbolTable table) {
    var childResult = child.evaluate(table);
    //print using printf
    Node.ir +=
        "%format_ptr$id = getelementptr [4 x i8], [4 x i8]* @format${childResult.type}, i32 0, i32 0\n";
    Node.ir +=
        "call i32 (i8*, ...) @printf(i8* %format_ptr$id, ${childResult.type} ${childResult.regName})\n";
  }
}
