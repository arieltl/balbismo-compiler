

import 'package:balbismo/vars.dart';

// class SymbolTable {
//   final Map<String, LangVar> _table = {};
//   static final Map<String, LangFunc> _functions = {};
  

//   static LangFunc createFunction(String key, LangFunc value) {
//     if (_functions.containsKey(key)) {
//       throw Exception("Key already exists");
//     }
//     _functions[key] = value;
//     return value;
//   }

//   static LangFunc? getFunction(String key) {
//     return _functions[key];
//   }


//   LangVar create(String key, LangVar value) {
//     if (_table.containsKey(key)) {
//       throw Exception("Key already exists");
//     }
//     _table[key] = value;
//     return value;
//   }
//   void canSet(String key, LangVal value) {

//     final langVar = _table[key];
//     if (langVar == null) {
//       throw Exception("Key does not exist");
//     }
//     if (langVar.type != value.type) {
//       throw Exception("Type mismatch");
//     }
//   }

//   LangVar? get(String key) {
//     return _table[key];
//   }

//   void remove(String key) {
//     _table.remove(key);
//   }

//   void clear() {
//     _table.clear();
//   }
// }


class SymbolTable {
  final Map<String, LangVar> _table = {};
  static final Map<String, LangFunc> _functions = {};
  
  SymbolTable? _parent;

  SymbolTable createChild() {
    final child = SymbolTable();
    child._parent = this;
    return child;
  }

  static LangFunc createFunction(String key, LangFunc value) {
    if (_functions.containsKey(key)) {
      throw Exception("Key already exists");
    }
    _functions[key] = value;
    return value;
  }

  static LangFunc? getFunction(String key) {
    return _functions[key];
  }


  LangVar create(String key, LangVar value) {
    if (_table.containsKey(key)) {
      throw Exception("Key already exists");
    }
    _table[key] = value;
    return value;
  }
  
  void canSet(String key, LangVal value) {

    final langVar = get(key);
    if (langVar == null) {
      throw Exception("Key does not exist");
    }
    if (langVar.type != value.type) {
      throw Exception("Type mismatch");
    }
  }

  LangVar? get(String key) {
    // return _table[key];
    if (_table.containsKey(key)) {
      return _table[key];
    } else if (_parent != null) {
      return _parent?.get(key);
    } else {
      return null;
    }
  }

  void remove(String key) {
    _table.remove(key);
  }

  void clear() {
    _table.clear();
  }
}


