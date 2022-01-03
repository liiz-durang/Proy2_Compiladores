/*
* Analizador Léxico
* Compiladores 2022-1
* Grupo: 1
* Integrantes: Durán González Lizeth        |   García Meneses jeremy   
            Mendoza de la Vega Elizabeth    |   Parada Pérez Jesús Bryan
*
* Descripción: Clase Scanner hereda de clase yyFlexLexer
*/

#ifndef __LEXER_H__
#define __LEXER_H__ 1
#include "location.hh"
#include "parser.tab.hh"

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif


#include <string>
using namespace std;


    class Lexer : public yyFlexLexer
    {
    public:
        Lexer(std::istream *in) : yyFlexLexer(in){
        loc = new yy::Parser::location_type();
    };

        using FlexLexer::yylex;
        virtual int yylex(yy::Parser::semantic_type* const lval, yy::Parser::location_type *location);
         //Función para retornar el contador de líneas
        virtual int getLine();
        //Función para retornar el tipo de un número
        virtual int getType();
        //Función para retornar el valor en yytext
        virtual string getVal();

    private:
        const int ERROR = -1;
        yy::Parser::semantic_type *yylval = nullptr;
        yy::Parser::location_type *loc = nullptr;
    };


#endif /* END __LEXER_H__ */