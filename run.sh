#!/bin/bash

# Execute the parser
cd lex-parse
./balbismo -o ast2.out < test2.balbismo
cd ..

# Run the Dart program
dart run

# Execute the LLVM IR file
lli main.ll