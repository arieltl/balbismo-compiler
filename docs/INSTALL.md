# Instalação

##  Opcao 1: Binário
Nos releases do projeto, você pode encontrar um binário para Linux. Baixe o binário e execute o comando `chmod +x balbismo` para torná-lo executável e `chmod +x lex-parse/balbismo_parser` para tornar o parser executável.


Alguns comando podem precisar de outras dependências, como o `llvm` e o `clang`, mais detalhes no final do arquivo.

## Opcao 2: Build manual
#### Dependências:
    - Dart: ^3.5.0
    - Flex
    - Bison
    - GCC

1. Clone o repositório
2. Compile o parser:
    ```bash
    cd lex-parse
    bison -d balbismo.y -v 
    flex balbismo.l
    gcc balbismo.tab.c lex.yy.c ast.c -o balbismo_parser -lfl
    cd ..
    ```
3. Compile o compilador:
    ```bash
    dart pub get
    dart compile exe bin/balbismo.dart -o balbismo
    ```

Alguns comando podem precisar de outras dependências, como o `llvm` e o `clang`, mais detalhes no final do arquivo.

### Outras dependências
Alguns comandos do compilador dependem das seguintes ferramentas do LLVM:
- llc
- clang
- lli
- opt

O comando `balbismo run` depende do stdbuf, alem do lli.
