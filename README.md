# Proyecto 2 Compiladores 

Compilador para lenguaje C-- Versión 0.
> Analizador léxico

* Durán González Lizeth 
* García Meneses jeremy 
* Mendoza de la Vega Elizabeth 
* Parada Pérez Jesús Bryan 

## Ejecución:

```shell
$ flex lexer.ll
$ bison -d -v parser.yy
$ g++ *.cpp *.cc -o exe
$ ./lexer <archivoPrueba>
```
