%skeleton "lalr1.cc"
%require  "3.8"
%debug 
%defines 
%define api.parser.class {Parser}

%code requires{
#include "Expresion.h"
#include "Numero.h"
#include "SimbolosTabla.h"
#include "TiposTabla.h"
#include "Simbolo.h"

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

%token <std::string>        ID
%token <std::string>        NUMERO
%token                      CADENA
%token                      CARACTER
%token                      IF WHILE DO
%token                      PRINT SCAN BREAK RETURN 
%token                      CHAR INT FLOAT DOUBLE STRUCT VOID
%token                      LKEY RKEY PYC COMA PUNTO
%left                       ASIG
%left                       AND
%left                       OR 
%left                       IGUAL DIF
%left                       MENOR MAYOR MENORI MAYORI
%left                       MAS MENOS
%left                       MUL DIV
%left                       NOT
%nonassoc                   LPAR RPAR 
%nonassoc                   ELSE

%type <int>  tipo
%type <Expresion>       o a i r mm md n f

%locations

%start p

%%


p : dd;

dd:
    d dd
    | 
    %empty  
;

d:
    tipo{
        driver.setType($1);
        
    } ID {
        //cout << $3 << endl;
        driver.setId($3);
        cout << "Id Global:" << driver.getId() << endl;
        cout << "Tipo Global:" << driver.getGtype() << endl;

        driver.addSym(driver.getId(),driver.getGtype(),"variable");      
    } 
    dcl1
    |
    STRUCT {
            driver.setType(5);
            cout<<driver.getGtype()<<endl;
            } dcl3
    |
    VOID{
            driver.setType(0);
            cout<<driver.getGtype()<<endl;
        }   dcl2
;

dcl1:
    lv_ PYC 
    |
    LPAR la RPAR LKEY dls bqs RKEY
;

dcl2:
    ID LPAR la RPAR LKEY dls bqs RKEY
;

dcl3:
    ds 
    |
    ID dcl2
;

dv:
    lv PYC
;

lv:
    ID lv_ 
;

lv_:
    COMA ID lv_ {
        driver.addSym(driver.getId(),driver.getGtype(),"variable");
    }
    |
    %empty
;

tipo:
    INT { 
            $$ = 1;
            //cout << "Tipo: " << $$ << endl; 
        }
    |
    FLOAT { 
            $$ = 2;
            //cout << "Tipo: " << $$ << endl;
        }
    |
    DOUBLE {
                $$ = 3; 
                //cout << "Tipo: " << $$ << endl;
            }
    |
    CHAR { 
            $$ = 4;
            //cout << "Tipo: " << $$ << endl;
        }
;

ds:
    bs lv PYC;

bs:
    LKEY dls RKEY;

la:
    as
    |
    %empty
;

as:
    as COMA ar 
    | 
    ar
;

ar:
    tipo ID;

dls:
    dls dl
    |
    %empty
;

dl:
    tipo dv;

bqs:
    ss
    | 
    %empty;

ss:
    ss s
    |
    s;

s:
    si | sw | sps | spw | sa | sb | sd | sr | ssc;

si: 
    IF LPAR o RPAR bos ELSE bos 
    |
    IF LPAR o RPAR bos;

sw: 
    WHILE LPAR o RPAR bos;

sd: 
    DO bos WHILE LPAR o RPAR PYC;

sa: 
    pi ASIG o PYC;

pi:
    ID
    |
    ID PUNTO ID;

spw:
    PRINT LPAR o RPAR PYC;

sps:
    PRINT LPAR CADENA RPAR PYC;

ssc:
    SCAN LPAR ID RPAR PYC;

sb:
    BREAK PYC;

sr:
    RETURN PYC;

o:
    o OR a 
    |
    a;

a: 
    a AND i 
    |
    i;

i:
    i IGUAL r
    |
    i DIF r
    |
    r;

r:
    r MENOR mm
    |
    r MENORI mm
    |
    r MAYOR mm
    |
    r MAYORI mm
    |
    mm;

mm:
    mm MAS md
    |
    mm MENOS md
    |
    md;

md:
    md DIV n
    |
    md MUL n
    |
    n;

n:
    NOT n
    |
    f;

f:
    LPAR o RPAR
    |
    ID 
    |
    NUMERO
    |
    ID LPAR lps RPAR
    |
    ID PUNTO ID
    |
    CARACTER;

lps:
    pas
    |
    %empty;

pas:
    pas COMA pa
    |
    pa;

pa:
    o;

bos:
    LKEY ss RKEY
    |
    s;


%%



void yy::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}