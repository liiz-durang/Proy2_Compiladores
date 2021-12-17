%skeleton "lalr1.cc"
%require  "3.8"
%debug 
%defines 
%define api.parser.class {Parser}

%code requires{
#include "Expresion.h"
#include "Numero.h"
#include "Tokens.h"

    class Driver;
    class Lexer;

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { Lexer  &lexer  }
%parse-param { Driver  &driver  }

%code{

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Driver.h"
#include "Lexer.h"

#undef yylex
#define yylex lexer.yylex
}

%define api.value.type variant
%define parse.assert

%token         ID
%token          NUMERO
%token        CADENA
%token          CARACTER
%token                  IF WHILE DO
%token                  PRINT SCAN BREAK RETURN 
%token                  CHAR INT FLOAT DOUBLE STRUCT VOID ESP
%token                  LKEY RKEY PYC COMA PUNTO
%left                   ASIG
%left                   AND
%left                   OR 
%left                   IGUAL DIF
%left                   MENOR MAYOR MENORI MAYORI
%left                   MAS MENOS
%left                   MUL DIV
%left                   NOT
%nonassoc               LPAR RPAR 
%nonassoc               ELSE

%type<int>  tipo
%type <Expresion>       expresion a i r mm md n f

%locations

%start programa

%%


programa : 
    declaraciones 
    ;

declaraciones:
    declaracion declaraciones 
    | 
    declaracion 
    ;

declaracion:
    tipo ID dcl1 
    | 
    STRUCT dcl3
    | 
    VOID ID LPAR lista-args RPAR LKEY decl-locales bloque-sentencias RKEY
    ;

dcl1:
    lista-var PYC 
    |
    LPAR lista-args RPAR LKEY decl-locales bloque-sentencias RKEY
    ;

dcl2:
    ID LPAR lista-args RPAR LKEY decl-locales bloque-sentencias RKEY
    |
    decl-struct
    ;

dcl3:
    decl-struct
    |
    ID dcl2;

decl-var:
    lista-var PYC

lista-var:
    ID lista-var 
    |
    COMA ID lista-var
    |
    ID
    ;

tipo:
    INT { $$ = 1; }
    |
    FLOAT { $$= 2; }
    |
    DOUBLE { $$= 3; }
    |
    CHAR { $$= 4; }
    ;

decl-struct:
    body-struct lista-var PYC
    ;

body-struct: 
    LKEY decl-locales RKEY
    ;

lista-args: 
    args 
    ;

args: 
    args COMA arg 
    |
    arg
    ;

arg: 
    tipo ID
    ;

decl-locales:
    decl-locales decl-local 
    |
    decl-local 
    ;

decl-local:
    tipo decl-var
    ;

bloque-sentencias: 
    sentencias 
    ;

sentencias: 
    sentencias sentencia 
    |
    sentencia
    ;

sentencia: 
    sentIf 
    |
    sentWhile
    |
    sentPuts
    |
    sentPutw
    |
    sentAsig 
    | 
    sentBreak 
    |
    sentDo 
    |
    sentReturn 
    |
    sentScan 
    ;

sentIf:
    IF LPAR expresion RPAR bloque-o-sentencia ELSE bloque-o-sentencia
    |
    IF LPAR expresion RPAR bloque-o-sentencia
    ;

sentWhile:
    WHILE LPAR expresion RPAR bloque-o-sentencia
    ;

sentDo:
    DO bloque-o-sentencia WHILE LPAR expresion RPAR 
    ;

sentAsig:
    parte-izq ASIG expresion PYC
    ;

parte-izq:
    ID 
    | 
    ID PUNTO ID
    ;

sentPutw:
    PRINT LPAR expresion RPAR PYC
    ;

sentPuts: 
    PRINT LPAR CADENA RPAR PYC
    ;

sentScan:
    SCAN LPAR ID RPAR PYC
    ;

sentBreak:
    BREAK
    ;

sentReturn: 
    RETURN PYC
    | 
    RETURN expresion PYC
    ;

expresion: 
    expresion OR a  
    |
    a
    ;

a: 
    a AND i 
    |
    i
    ;

i:
    i IGUAL r
    |
    i DIF r
    |
    r
    ;

r:
    r MENOR mm
    |
    r MENORI mm 
    |
    r MAYOR mm 
    |
    r MAYORI mm 
    |
    mm
    ;

mm:
    mm MAS md 
    |
    mm MENOS md
    |
    md
    ;

md: 
    md DIV n 
    |
    md MUL n
    |
    n 
    ;

n: 
    NOT n
    |
    f 
    ;

f: 
    LPAR expresion RPAR 
    |
    ID 
    |
    NUMERO 
    |
    ID LPAR lista_params RPAR 
    |
    ID PUNTO ID 
    |
    CARACTER 
    ;

lista_params:
    params 
    ;

params:
    params COMA param 
    |
    param 
    ;

param:
    expresion
    ;

bloque-o-sentencia:
    LKEY sentencias RKEY 
    |
    sentencia
    ;

%%



void yy::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}