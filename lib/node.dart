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
  static int irIndent = 0;

  static addIrLine(String line) {
    ir +=  "${"  "* irIndent}${line.trim()}\n";
  }
  static addIrlLabel(String label) {
    ir +=  "${"  "* irIndent}${label.trim()}:\n";
    irIndent++;
  }

  static endIrLabel() {
    irIndent--;
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
    Node.addIrLine(
        "%var$id = load ${varData.type.irType}, ptr ${varData.ptrName}");
    return LangVal("%var$id", varData.type);
  }
}

class IntVal extends Node<int, LangVal> {
  IntVal(String value) : super(int.parse(value), []);

  @override
  LangVal evaluate(SymbolTable table) {
    Node.addIrLine("%val$id = add i64 0, $valueNode");
    return LangVal("%val$id", LangType.int);
  }
}

class FloatVal extends Node<double, LangVal> {
  FloatVal(String value) : super(double.parse(value), []);

  @override
  LangVal evaluate(SymbolTable table) {
    Node.addIrLine("%val$id = fadd double 0.0, ${valueNode}");
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
    Node.addIrLine("$ptrName = alloca ${type.valueNode.irType}");
    if (children.length > 2) {
      var value = children[2].evaluate(table);
      Node.addIrLine(
          "store ${type.valueNode.irType} ${value.regName}, ptr $ptrName");
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
    Node.addIrLine(
        "store ${varData.type.irType} ${value.regName}, ptr ${varData.ptrName}");
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
        Node.addIrLine(
            "%unOp.$id = sub ${childResult.type.irType} 0, ${childResult.regName}");
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
        Node.addIrLine("%conv.$id = sitofp i64 ${rightResult.regName} to double");
        rightResult = LangVal("%conv.$id", LangType.float);
      } else {
        Node.addIrLine("%conv.$id = sitofp i64 ${leftResult.regName} to double");
        leftResult = LangVal("%conv.$id", LangType.float);
      }
    }
    if (leftResult.type == LangType.float) {
      switch (valueNode) {
        case MathOp.add:
          Node.addIrLine(
              "%binOp.$id = fadd double ${leftResult.regName}, ${rightResult.regName}");
          return LangVal("%binOp.$id", leftResult.type);
        case MathOp.sub:
          Node.addIrLine(
              "%binOp.$id = fsub double ${leftResult.regName}, ${rightResult.regName}");
          return LangVal("%binOp.$id", leftResult.type);
        case MathOp.mul:
          Node.addIrLine(
              "%binOp.$id = fmul double ${leftResult.regName}, ${rightResult.regName}");
          return LangVal("%binOp.$id", leftResult.type);
        case MathOp.div:
          Node.addIrLine(
              "%binOp.$id = fdiv double ${leftResult.regName}, ${rightResult.regName}");
          return LangVal("%binOp.$id", leftResult.type);
        default:
          throw Exception("Unknown operator: $valueNode");
      }
    }

    switch (valueNode) {
      case MathOp.add:
        Node.addIrLine(
            "%binOp.$id = add ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
        return LangVal("%binOp.$id", leftResult.type);
      case MathOp.sub:
        Node.addIrLine(
            "%binOp.$id = sub ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
        return LangVal("%binOp.$id", leftResult.type);
      case MathOp.mul:
        Node.addIrLine(
            "%binOp.$id = mul ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
        return LangVal("%binOp.$id", leftResult.type);
      case MathOp.div:
        Node.addIrLine(
            "%binOp.$id = sdiv ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
        return LangVal("%binOp.$id", leftResult.type);
      case MathOp.mod:
        Node.addIrLine(
            "%binOp.$id = srem ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
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
    Node.addIrLine(
        "%format_ptr$id = getelementptr [4 x i8], [4 x i8]* @format${childResult.type}, i32 0, i32 0");
    Node.addIrLine(
        "call i32 (i8*, ...) @printf(i8* %format_ptr$id, ${childResult.type} ${childResult.regName})");
  }
}

enum RelOperator {
  eq,
  ne,
  lt,
  gt,
  le,
  ge;

  static RelOperator fromString(String op) {
    switch (op) {
      case "==":
        return RelOperator.eq;
      case "!=":
        return RelOperator.ne;
      case "<":
        return RelOperator.lt;
      case ">":
        return RelOperator.gt;
      case "<=":
        return RelOperator.le;
      case ">=":
        return RelOperator.ge;
      default:
        throw Exception("Unknown operator: $op");
    }
  }
}

class RelOp extends Node<RelOperator, LangVal> {
  RelOp(String value, Node<dynamic,LangVal> left, Node<dynamic,LangVal> right)
      : super(RelOperator.fromString(value), [left, right]);

  @override
  LangVal evaluate(SymbolTable table) {
    var leftResult = children[0].evaluate(table);
    var rightResult = children[1].evaluate(table);

    if (leftResult.type != rightResult.type) {
      if (leftResult.type == LangType.float) {
        Node.addIrLine("%conv.$id = sitofp i64 ${rightResult.regName} to double");
        rightResult = LangVal("%conv.$id", LangType.float);
      } else {
        Node.addIrLine("%conv.$id = sitofp i64 ${leftResult.regName} to double");
        leftResult = LangVal("%conv.$id", LangType.float);
      }
    }
    if (leftResult.type == LangType.float) {
      switch (valueNode) {
        case RelOperator.eq:
          Node.addIrLine(
              "%temp.$id = fcmp oeq double ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.ne:
          Node.addIrLine(
              "%temp.$id = fcmp one double ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.lt:
          Node.addIrLine(
              "%temp.$id = fcmp olt double ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.gt:
          Node.addIrLine(
              "%temp.$id = fcmp ogt double ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.le:
          Node.addIrLine(
              "%temp.$id = fcmp ole double ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.ge:
          Node.addIrLine(
              "%temp.$id = fcmp oge double ${leftResult.regName}, ${rightResult.regName}");
          break;
        default:
          throw Exception("Unknown operator: $valueNode");
      }
    } else {
      switch (valueNode) {
        case RelOperator.eq:
          Node.addIrLine(
              "%temp.$id = icmp eq ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.ne:
          Node.addIrLine(
              "%temp.$id = icmp ne ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.lt:
          Node.addIrLine(
              "%temp.$id = icmp slt ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.gt:
          Node.addIrLine(
              "%temp.$id = icmp sgt ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.le:
          Node.addIrLine(
              "%temp.$id = icmp sle ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
          break;
        case RelOperator.ge:
          Node.addIrLine(
              "%temp.$id = icmp sge ${leftResult.type.irType} ${leftResult.regName}, ${rightResult.regName}");
          break;
        default:
          throw Exception("Unknown operator: $valueNode");
      }
    }
    Node.addIrLine("%relOp.$id = zext i1 %temp.$id to i64");
    return LangVal("%relOp.$id", LangType.int);
  }
}

enum BoolOperator {
  not,
  and,
  or;

  static BoolOperator fromString(String op) {
    switch (op) {
      case "&&":
        return BoolOperator.and;
      case "||":
        return BoolOperator.or;
      case "!":
        return BoolOperator.not;  
      default:
        throw Exception("Unknown operator: $op");
    }
  }
}
class BoolUnOp extends Node<BoolOperator, LangVal> {
  BoolUnOp(String value, Node<dynamic, LangVal> child)
      : super(BoolOperator.fromString(value), [child]);

  Node<dynamic, LangVal> get child => children[0] as Node<dynamic, LangVal>;

  

  @override
  LangVal evaluate(SymbolTable table) {
    if (valueNode != BoolOperator.not) {
      throw Exception("Invalid operator for BoolUnOp");
    }
    final childResult = child.evaluate(table);
    if (childResult.type != LangType.int) {
      throw Exception("Not operantion can only be applied to int");
    }


    //if child is not 0 convert to 0 else convert to 1
    Node.addIrLine(
        "%boolIsZero.$id = icmp eq i64 ${childResult.regName}, 0");
    Node.addIrLine("%boolUnOp.$id = zext i1 %boolIsZero.$id to i64");
    return LangVal("%boolUnOp.$id", LangType.int);
  }

}

class BoolBinOp extends Node<BoolOperator, LangVal> {
  BoolBinOp(String value, Node<dynamic, LangVal> left, Node<dynamic, LangVal> right)
      : super(BoolOperator.fromString(value), [left, right]);

  @override
  LangVal evaluate(SymbolTable table) {
    final leftResult = children[0].evaluate(table);
    final rightResult = children[1].evaluate(table);

    if (leftResult.type != LangType.int || rightResult.type != LangType.int) {
      throw Exception("BoolBinOp can only be applied to int");
    }
    //should always return 0 or 1 in i64
    switch (valueNode) {
      case BoolOperator.and:
        Node.addIrLine(
            "%and.$id = and i64 ${leftResult.regName}, ${rightResult.regName}");
        Node.addIrLine("%logic.$id = icmp ne i64 %and.$id, 0");
        Node.addIrLine("%boolBinOp.$id = zext i1 %logic.$id to i64");
            
        break;
      case BoolOperator.or:
        Node.addIrLine(
            "%and.$id = or i64 ${leftResult.regName}, ${rightResult.regName}");
        Node.addIrLine("%logic.$id = icmp ne i64 %and.$id, 0");
        Node.addIrLine("%boolBinOp.$id = zext i1 %logic.$id to i64");
        break;
      default:
        throw Exception("Unknown operator: $valueNode");
    }
    return LangVal("%boolBinOp.$id", LangType.int);
  }
}

class IfNode extends Node<void, void> {
  IfNode(Node<dynamic, LangVal> condition, BlockNode thenBlock, [Node? elseBlock])
      : super(null, [condition, thenBlock, if (elseBlock != null) elseBlock]);

  Node<dynamic, LangVal> get condition => children[0] as Node<dynamic, LangVal>;
  BlockNode get thenBlock => children[1] as BlockNode;
  Node? get elseBlock => children.length > 2 ? children[2] : null;

  @override
  void evaluate(SymbolTable table) {

    var conditionResult = condition.evaluate(table);
    if (conditionResult.type != LangType.int) {
      throw Exception("Condition must be int");
    }
    Node.addIrLine("%conditionCast.$id = icmp ne i64 ${conditionResult.regName}, 0");
    Node.addIrLine("br i1 %conditionCast.$id, label %then.$id, label %else.$id");
    Node.addIrlLabel("then.$id");
    thenBlock.evaluate(table);
    final elseNode = elseBlock;
    Node.addIrLine("br label %end.$id");
    Node.endIrLabel();
    if (elseNode != null) {
      Node.addIrlLabel("else.$id");
      elseNode.evaluate(table);
      Node.addIrLine("br label %end.$id");
      Node.endIrLabel();
    }
    Node.addIrLine("end.$id:");
  }
}
