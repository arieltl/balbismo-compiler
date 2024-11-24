enum LangType { 
  int("i64"), 
  float("double");
  //lang type from string

  final String irType;

  const LangType(this.irType);
  static LangType fromString(String type) {
    switch (type) {
      case "int":
        return LangType.int;
      case "float":
        return LangType.float;
      default:
        throw Exception("Unknown type: $type");
    }
  }

  @override
  toString() => irType;
 }

 class LangVal {
  final String regName;
  final LangType type;

  LangVal(this.regName, this.type);
 }

 class LangVar {
  final String ptrName;
  final LangType type;

  LangVar(this.ptrName, this.type);
 }