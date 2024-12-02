#!/bin/bash
# Check if a test file name is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <testfile>"
    exit 1
fi

TESTFILE=$1

cd lex-parse
./balbismo -o ast2.out < "$TESTFILE"
cd ..

./bin/balbismo.exe 
opt -S -O2 main.ll > opt.ll
clang -o main opt.ll
./main