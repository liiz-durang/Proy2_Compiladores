# Proyecto 2 Compiladores 

Compilador para lenguaje C-- Versión 0.

* Durán González Lizeth 
* García Meneses jeremy 
* Mendoza de la Vega Elizabeth 
* Parada Pérez Jesús Bryan 

## Ejecución:
Analizador Léxico
```shell
$ flex lexer.ll
$ g++ main.cpp Scanner.cpp -o lexer
$ ./lexer <archivoPrueba>
```

Analizador Sintáctico
```shell
$ bison -d -v parser.yy
```
