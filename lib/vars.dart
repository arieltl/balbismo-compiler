import 'package:equatable/equatable.dart';

enum PrimitiveTypes { 
  int("i64"), 
  float("double");
  //lang type from string

  final String _irType;
  String get irType => _irType;


  const PrimitiveTypes(this._irType);
  static PrimitiveTypes fromString(String type) {
    switch (type) {
      case "int":
        return PrimitiveTypes.int;
      case "float":
        return PrimitiveTypes.float;
      default:
        throw Exception("Unknown type: $type");
    }
  }

  





  @override
  toString() => irType;
 }

 abstract class LangType extends Equatable {
    final PrimitiveTypes primitiveType;
    const LangType(this.primitiveType);

    @override
    List<Object> get props => [primitiveType];

    String get irType => primitiveType.irType;

  @override
  String toString() {
    return irType;
  }

    
  }

  class PrimitiveType extends LangType {
    const PrimitiveType(super.primitiveType);
  }

  class ArrayType extends LangType {
    const ArrayType(super.primitiveType);

    @override
    String get irType => "${primitiveType.irType}*";
  }

 class LangVal<T extends LangType> {
  final String regName;
  final T type;

  const LangVal(this.regName, this.type);
 }

 class LangVar<T extends LangType> {
  final String ptrName;
  final T type;

  const LangVar(this.ptrName, this.type);
 }