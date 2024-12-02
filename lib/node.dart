import 'package:balbismo/SymbolTable.dart';
import 'package:balbismo/vars.dart';

abstract class Node<T, E> {
  final T nodeValue;
  final List<Node> children;
  int id = 0;

  Node(this.nodeValue, this.children) {
    id = newId();
  }
  static String ir = "";
  static int i = 0;

  static int newId() {
    return i++;
  }

  static int irIndent = 0;

  static addIrLine(String line) {
    ir += "${"  " * irIndent}${line.trim()}\n";
  }

  static addIrlLabel(String label) {
    ir += "${"  " * irIndent}${label.trim()}:\n";
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
    final newTable = table.createChild();
    for (var child in children) {
      child.evaluate(newTable);
    }
  }
}

class TypeNode extends Node<LangType, void> {
  TypeNode(LangType value) : super(value, []);
}

class ArrayTypeNode extends Node<LangType, void> {
  ArrayTypeNode(TypeNode primitiveTypeNode, ArraySpecification size)
      : super(ArrayType(primitiveTypeNode.nodeValue.primitiveType), [size]);

  ArraySpecification get size => children[0] as ArraySpecification;
}

class ArraySpecification extends Node<void, LangVal?> {
  ArraySpecification(Node<dynamic, LangVal>? expr)
      : super(null, [if (expr != null) expr]);

  Node<dynamic, LangVal>? get childExpr =>
      children.firstOrNull as Node<dynamic, LangVal>?;
  @override
  LangVal? evaluate(SymbolTable table) {
    return childExpr?.evaluate(table);
  }
}

class IdentifierNode extends Node<String, LangVal> {
  IdentifierNode(String value) : super(value, []);

  @override
  LangVal evaluate(SymbolTable table) {
    var varData = table.get(nodeValue);
    if (varData == null) {
      throw Exception("Variable $nodeValue not found");
    }
    if (varData.type is ArrayType) {
      return LangVal(varData.ptrName, varData.type);
    }
    Node.addIrLine(
        "%var$id = load ${varData.type.primitiveType.irType}, ptr ${varData.ptrName}");
    return LangVal("%var$id", varData.type);
  }
}

class IndexedIdentifierNode extends IdentifierNode {
  IndexedIdentifierNode(super.value, Node<dynamic, LangVal> index) {
    children.add(index);
  }

  Node<dynamic, LangVal> get index => children[0] as Node<dynamic, LangVal>;

  @override
  LangVal evaluate(SymbolTable table) {
    final varData = table.get(nodeValue);
    if (varData == null) {
      throw Exception("Variable $nodeValue not found");
    }
    if (varData.type is! ArrayType) {
      throw Exception("Variable $nodeValue is not an array");
    }
    final indexResult = index.evaluate(table);
    if (indexResult.type.primitiveType != PrimitiveTypes.int) {
      throw Exception("Index must be int");
    }
    Node.addIrLine(
        "%arrayPtr.$id = getelementptr ${varData.type.primitiveType.irType}, ${varData.type.irType} ${varData.ptrName}, i64 ${indexResult.regName}");
    Node.addIrLine(
        "%var$id = load ${varData.type.primitiveType.irType}, ptr %arrayPtr.$id");
    return LangVal("%var$id", PrimitiveType(varData.type.primitiveType));
  }
}

class IntVal extends Node<int, LangVal> {
  IntVal(String value) : super(int.parse(value), []);

  @override
  LangVal evaluate(SymbolTable table) {
    Node.addIrLine("%val$id = add i64 0, $nodeValue");
    return LangVal("%val$id", const PrimitiveType(PrimitiveTypes.int));
  }
}

class ParameterList extends Node<void, void> {
  ParameterList(List<DeclareNode> children) : super(null, children);
  List<DeclareNode> get params => children.cast<DeclareNode>();
}

class FunctionList extends Node<void, void> {
  FunctionList(List<FuncDec> children) : super(null, children);

  List<FuncDec> get funcs => children.cast<FuncDec>();

  @override
  void evaluate(SymbolTable table) {
    for (var func in funcs) {
      func.evaluate(table);
    }
  }
}

class ReturnStatement extends Node<void, void> {
  ReturnStatement(Node<dynamic, LangVal> value) : super(null, [value]);

  Node<dynamic, LangVal> get value => children[0] as Node<dynamic, LangVal>;

  @override
  void evaluate(SymbolTable table) {
    final valueResult = value.evaluate(table);
    
    Node.addIrLine("ret ${valueResult.type.irType} ${valueResult.regName}");
  }
}

class FuncDec extends Node<void,void> {
  FuncDec(TypeNode returnType, IdentifierNode identifier,ParameterList params, BlockNode block)
      : super(null, [returnType, identifier, params, block]);

  IdentifierNode get identifier => children[1] as IdentifierNode;
  BlockNode get block => children.last as BlockNode;
  List<DeclareNode> get params => (children[2] as ParameterList).params;
  TypeNode get returnType => children[0] as TypeNode;

  @override
  void evaluate(SymbolTable table) {
    print(identifier.nodeValue);
    final funcName = identifier.nodeValue;
    final returnType = this.returnType.nodeValue;
    final func = LangFunc(funcName, this);
    SymbolTable.createFunction(funcName, func);
    final String paramsStr = params.map((e) => "${e.type.nodeValue.irType} %${e.identifier.nodeValue} ").join(", ");
    Node.addIrLine("define ${returnType.irType} @$funcName($paramsStr) {");
    Node.addIrlLabel("entry");
    final newTable = SymbolTable();
    for (var param in params) {
      if (param.type.nodeValue is ArrayType) {
        newTable.create(param.identifier.nodeValue, LangVar("%${param.identifier.nodeValue}", param.type.nodeValue));
        continue;
      }
     
    final ptrName = "%ptr.${param.identifier.nodeValue}.$id";
      Node.addIrLine("$ptrName = alloca ${param.type.nodeValue.irType}");
      Node.addIrLine("store ${param.type.nodeValue.irType} %${param.identifier.nodeValue}, ptr $ptrName");
      newTable.create(param.identifier.nodeValue, LangVar(ptrName, param.type.nodeValue));
    }
    block.evaluate(newTable);
    Node.addIrLine("ret ${returnType.irType} ${returnType.primitiveType == PrimitiveTypes.int ? "0" : "0.0"}");
    Node.endIrLabel();
    Node.addIrLine("}");
  }
}

class ArgumentList extends Node<void, List<LangVal>> {
  ArgumentList(List<Node<dynamic,LangVal>> children) : super(null, children);

  List<Node<dynamic, LangVal>> get args => children.cast<Node<dynamic, LangVal>>();

  @override
  List<LangVal> evaluate(SymbolTable table) {
    return args.map((e) => e.evaluate(table)).toList();
  }
}

class FuncCall extends Node<void, LangVal> {
  FuncCall(IdentifierNode identifier, ArgumentList args)
      : super(null, [identifier, args]);

  IdentifierNode get identifier => children[0] as IdentifierNode;
  ArgumentList get args => children[1] as ArgumentList;

  @override
  LangVal evaluate(SymbolTable table) {
    final func = SymbolTable.getFunction(identifier.nodeValue);
    if (func == null) {
      throw Exception("Function ${identifier.nodeValue} not found");
    }
    final argValues = args.evaluate(table);
    final argTypes = func.funcDec.params.map((e) => e.type.nodeValue).toList();
    if (argValues.length != argTypes.length) {
      throw Exception("Argument count mismatch");
    }
    for (var i = 0; i < argValues.length; i++) {
      if (argValues[i].type != argTypes[i]) {
        throw Exception("Argument type mismatch");
      }
    }
    final argStr = argValues.map((e) => "${e.type.irType} ${e.regName}").join(", ");
    Node.addIrLine("%call.$id = call ${func.funcDec.returnType.nodeValue.irType} @${func.name}($argStr)");
    return LangVal("%call.$id", func.funcDec.returnType.nodeValue);
  }
}
class FloatVal extends Node<double, LangVal> {
  FloatVal(String value) : super(double.parse(value), []);

  @override
  LangVal evaluate(SymbolTable table) {
    Node.addIrLine("%val$id = fadd double 0.0, $nodeValue");
    return LangVal("%val$id", const PrimitiveType(PrimitiveTypes.float));
  }
}

class DeclareNode extends Node<void, void> {
  DeclareNode(Node<LangType, dynamic> type, IdentifierNode identifier,
      [Node? value])
      : super(null, [type, identifier, if (value != null) value]);

  IdentifierNode get identifier => children[1] as IdentifierNode;
  Node<LangType, dynamic> get type => children[0] as Node<LangType, dynamic>;

  @override
  void evaluate(SymbolTable table) {
    var ptrName = '%ptr.${identifier.nodeValue}.$id';
    final varType = type.nodeValue;
    final langVar = LangVar(ptrName, varType);
    table.create(identifier.nodeValue, langVar);
    if (varType is PrimitiveType) {
      Node.addIrLine("$ptrName = alloca ${varType.primitiveType.irType}");
      if (children.length > 2) {
        var value = children[2].evaluate(table);
        if (varType.primitiveType != value.type.primitiveType) {
          throw Exception("Type mismatch");
        }

        Node.addIrLine(
            "store ${varType.primitiveType.irType} ${value.regName}, ptr $ptrName");
      }
    } else if (varType is ArrayType) {
      var arrayTypeNode = type as ArrayTypeNode;
      var size = arrayTypeNode.size.evaluate(table);
      if (size != null) {
        Node.addIrLine(
            "%arrayptr.$id = alloca ${varType.primitiveType.irType}, i64 ${size.regName}");
            

        Node.addIrLine(
            "$ptrName = getelementptr ${varType.primitiveType.irType}, ${varType.irType} %arrayptr.$id, i64 0");
      } else {
        //need size
        throw Exception("Array size not found"); 
      }


      if (children.length > 2) {
        //cant assign to array
        throw Exception("Cannot assign to array");
      }
    }
  }
}

class AssignmentNode extends Node<void, void> {
  AssignmentNode(IdentifierNode identifier, Node value)
      : super(null, [identifier, value]);

  IdentifierNode get identifier => children[0] as IdentifierNode;

  @override
  Node get nodeValue => children[1];

  @override
  void evaluate(SymbolTable table) {
    final identifierNode = identifier;

    var varData = table.get(identifier.nodeValue);
    
    
    
    if (varData == null) {
      throw Exception("Variable ${identifier.nodeValue} not found");
    }
    var varType = varData.type;

    if (varData.type is ArrayType && identifierNode is !IndexedIdentifierNode) {
      throw Exception("Cannot assign to array");
      
    }
    if (varData.type is! ArrayType && identifierNode is IndexedIdentifierNode) {
      throw Exception("Cannot index non-array");
    }
    var value = nodeValue.evaluate(table);

    var ptrName = varData.ptrName;
    if (varData.type is ArrayType) {
      if (varData.type.primitiveType != value.type.primitiveType) {
        throw Exception("Type mismatch");
      }
      final IndexedIdentifierNode indexedIdentifierNode = identifierNode as IndexedIdentifierNode;
      final indexResult = indexedIdentifierNode.index.evaluate(table);
      if (indexResult.type.primitiveType != PrimitiveTypes.int) {
        throw Exception("Index must be int");
      }
      Node.addIrLine(
          "%arrayPtr.$id = getelementptr ${varData.type.primitiveType.irType}, ${varData.type.irType} ${varData.ptrName}, i64 ${indexResult.regName}");
      ptrName = "%arrayPtr.$id";
    } else if (varData.type != value.type) {
      throw Exception("Type mismatch");
    }
    Node.addIrLine(
        "store ${varData.type.primitiveType.irType} ${value.regName}, ptr ${ptrName}");
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
    //cant be array
    if (childResult.type is ArrayType) {
      throw Exception("Cannot apply unary operator to array");
    }

    switch (nodeValue) {
      case MathOp.add:
        return childResult;
      case MathOp.sub:
        Node.addIrLine(
            "%unOp.$id = sub ${childResult.type.irType} 0, ${childResult.regName}");
        return LangVal("%unOp.$id", childResult.type);
      default:
        throw Exception("Unknown operator: $nodeValue");
    }
  }
}

class BinOp extends Node<MathOp, LangVal> {
  BinOp(String value, Node left, Node right)
      : super(MathOp.fromString(value), [left, right]);

  Node<dynamic, LangVal> get left => children[0] as Node<dynamic, LangVal>;
  Node<dynamic, LangVal> get right => children[1] as Node<dynamic, LangVal>;

  @override
  LangVal evaluate(SymbolTable table) {
    var leftResult = left.evaluate(table);
    var rightResult = right.evaluate(table);
    // cant be array
    if (leftResult.type is ArrayType || rightResult.type is ArrayType) {
      throw Exception("Cannot apply binary operator to array");
    }

    if (leftResult.type != rightResult.type) {
      if (leftResult.type.primitiveType == PrimitiveTypes.float) {
        Node.addIrLine(
            "%conv.$id = sitofp i64 ${rightResult.regName} to double");
        rightResult =
            LangVal("%conv.$id", const PrimitiveType(PrimitiveTypes.float));
      } else {
        Node.addIrLine(
            "%conv.$id = sitofp i64 ${leftResult.regName} to double");
        leftResult =
            LangVal("%conv.$id", const PrimitiveType(PrimitiveTypes.float));
      }
    }
    if (leftResult.type.primitiveType == PrimitiveTypes.float) {
      switch (nodeValue) {
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
          throw Exception("Unknown operator: $nodeValue");
      }
    }

    switch (nodeValue) {
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
        throw Exception("Unknown operator: $nodeValue");
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
  RelOp(String value, Node<dynamic, LangVal> left, Node<dynamic, LangVal> right)
      : super(RelOperator.fromString(value), [left, right]);

  Node<dynamic, LangVal> get left => children[0] as Node<dynamic, LangVal>;
  Node<dynamic, LangVal> get right => children[1] as Node<dynamic, LangVal>;
  @override
  LangVal evaluate(SymbolTable table) {
    var leftResult = left.evaluate(table);
    var rightResult = right.evaluate(table);

    //cant be array
    if (leftResult.type is ArrayType || rightResult.type is ArrayType) {
      throw Exception("Cannot apply binary operator to array");
    }
    if (leftResult.type != rightResult.type) {
      if (leftResult.type.primitiveType == PrimitiveTypes.float) {
        Node.addIrLine(
            "%conv.$id = sitofp i64 ${rightResult.regName} to double");
        rightResult =
            LangVal("%conv.$id", const PrimitiveType(PrimitiveTypes.float));
      } else {
        Node.addIrLine(
            "%conv.$id = sitofp i64 ${leftResult.regName} to double");
        leftResult =
            LangVal("%conv.$id", const PrimitiveType(PrimitiveTypes.float));
      }
    }
    if (leftResult.type.primitiveType == PrimitiveTypes.float) {
      switch (nodeValue) {
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
          throw Exception("Unknown operator: $nodeValue");
      }
    } else {
      switch (nodeValue) {
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
          throw Exception("Unknown operator: $nodeValue");
      }
    }
    Node.addIrLine("%relOp.$id = zext i1 %temp.$id to i64");
    return LangVal("%relOp.$id", const PrimitiveType(PrimitiveTypes.int));
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
    if (nodeValue != BoolOperator.not) {
      throw Exception("Invalid operator for BoolUnOp");
    }
    final childResult = child.evaluate(table);
    //cant be array
    //has to be int
    if (childResult.type is! PrimitiveType ||
        childResult.type.primitiveType != PrimitiveTypes.int) {
      throw Exception("Not operantion can only be applied to int");
    }

    //if child is not 0 convert to 0 else convert to 1
    Node.addIrLine("%boolIsZero.$id = icmp eq i64 ${childResult.regName}, 0");
    Node.addIrLine("%boolUnOp.$id = zext i1 %boolIsZero.$id to i64");
    return LangVal("%boolUnOp.$id", const PrimitiveType(PrimitiveTypes.int));
  }
}

class BoolBinOp extends Node<BoolOperator, LangVal> {
  BoolBinOp(
      String value, Node<dynamic, LangVal> left, Node<dynamic, LangVal> right)
      : super(BoolOperator.fromString(value), [left, right]);

  Node<dynamic, LangVal> get left => children[0] as Node<dynamic, LangVal>;
  Node<dynamic, LangVal> get right => children[1] as Node<dynamic, LangVal>;

  @override
  LangVal evaluate(SymbolTable table) {
    final leftResult = left.evaluate(table);
    final rightResult = right.evaluate(table);

    //cant be array
    if (leftResult.type is ArrayType || rightResult.type is ArrayType) {
      throw Exception("Cannot apply binary operator to array");
    }

    if (leftResult.type.primitiveType != PrimitiveTypes.int ||
        rightResult.type.primitiveType != PrimitiveTypes.int) {
      throw Exception("BoolBinOp can only be applied to int");
    }
    //should always return 0 or 1 in i64
    switch (nodeValue) {
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
        throw Exception("Unknown operator: $nodeValue");
    }
    return LangVal("%boolBinOp.$id", const PrimitiveType(PrimitiveTypes.int));
  }
}

class IfNode extends Node<void, void> {
  IfNode(Node<dynamic, LangVal> condition, BlockNode thenBlock,
      [Node? elseBlock])
      : super(null, [condition, thenBlock, if (elseBlock != null) elseBlock]);

  Node<dynamic, LangVal> get condition => children[0] as Node<dynamic, LangVal>;
  BlockNode get thenBlock => children[1] as BlockNode;
  Node? get elseBlock => children.length > 2 ? children[2] : null;

  @override
  void evaluate(SymbolTable table) {
    var conditionResult = condition.evaluate(table);
    //cant be array
    //has to be int
    if (conditionResult.type is! PrimitiveType ||
        conditionResult.type.primitiveType != PrimitiveTypes.int) {
      throw Exception("Condition must be int");
    }

    Node.addIrLine(
        "%conditionCast.$id = icmp ne i64 ${conditionResult.regName}, 0");
    Node.addIrLine(
        "br i1 %conditionCast.$id, label %then.$id, label %else.$id");
    Node.addIrlLabel("then.$id");
    thenBlock.evaluate(table);
    final elseNode = elseBlock;
    Node.addIrLine("br label %end.$id");
    Node.endIrLabel();
    Node.addIrlLabel("else.$id");
    if (elseNode != null) {
      elseNode.evaluate(table);
    }

    Node.addIrLine("br label %end.$id");
    Node.endIrLabel();
    Node.addIrLine("end.$id:");
  }
}

class WhileNode extends Node<void, void> {
  WhileNode(Node<dynamic, LangVal> condition, BlockNode block)
      : super(null, [condition, block]);

  Node<dynamic, LangVal> get condition => children[0] as Node<dynamic, LangVal>;
  BlockNode get block => children[1] as BlockNode;

  @override
  void evaluate(SymbolTable table) {
    Node.addIrLine("br label %while.$id");
    Node.addIrlLabel("while.$id");
    var conditionResult = condition.evaluate(table);
    if (conditionResult.type is! PrimitiveType ||
        conditionResult.type.primitiveType != PrimitiveTypes.int) {
      throw Exception("Condition must be int");
    }

    Node.addIrLine(
        "%conditionCast.$id = icmp ne i64 ${conditionResult.regName}, 0");
    Node.addIrLine(
        "br i1 %conditionCast.$id, label %block.$id, label %end.$id");
    Node.endIrLabel();
    Node.addIrlLabel("block.$id");
    block.evaluate(table);
    Node.addIrLine("br label %while.$id");
    Node.endIrLabel();
    Node.addIrLine("end.$id:");
  }
}
