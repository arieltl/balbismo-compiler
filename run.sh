#!/bin/bash

# Check if a test file name is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <testfile>"
    exit 1
fi

TESTFILE=$1

# Execute the parser
cd lex-parse
./balbismo -o ast2.out < "$TESTFILE"
cd ..

# Run the Dart program
dart run

# Execute the LLVM IR file
lli main.ll