

import 'package:balbismo/vars.dart';

class SymbolTable {
  final Map<String, LangVar> _table = {};

  

  LangVar create(String key, LangVar value) {
    if (_table.containsKey(key)) {
      throw Exception("Key already exists");
    }
    _table[key] = value;
    return value;
  }
  void canSet(String key, LangVal value) {

    final langVar = _table[key];
    if (langVar == null) {
      throw Exception("Key does not exist");
    }
    if (langVar.type != value.type) {
      throw Exception("Type mismatch");
    }
  }

  LangVar? get(String key) {
    return _table[key];
  }

  void remove(String key) {
    _table.remove(key);
  }

  void clear() {
    _table.clear();
  }
}


