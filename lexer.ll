%{
	#include <iostream>
	#include <string>

	using namespace std;

	#include "Tokens.h"
	#include "Lexer.h"
	#include "parser.tab.hh"

	#undef YY_DECL
	#define YY_DECL int Lexer::yylex(yy::Parser::semantic_type* const lval, yy::Parser::location_type *location)
	using token = yy::Parser::token;

	#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
	
	//variable para reportar el tipo de un número
	int numType;
	//variable para contar líneas
	int line = 1;
%}

%option c++
%option outfile = "Lexer.cpp"
%option yyclass = "Lexer"


ENTERO [0-9]+
FLOTANTE ([0-9])*("."([0-9])+)?([Ee]([+-])?([0-9])+)?[fF]
DOUBLE ([0-9])*("."([0-9])+)?([Ee]([+-])?([0-9])+)?[dD]?
ID [a-zA-Z][A-Za-z0-9_]*
ESP [ \t\r]+
CADENA  \"([\x20-\x21\x23-\xFE])*\"
CARACTER \'([\x20-\x21\x23-\xFE \t\n\r])\'

%%


%{ 
	//Codigo ejecutado al inicio de yylex
	yylval = lval;

%}

"char"		{return CHAR;}
"int"		{return INT; }

"float"		{return FLOAT; }
"double" 	{return DOUBLE; }

"struct"	{return STRUCT;}
"void"		{return VOID;}

"if"		{return IF;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"do"		{return DO;}
"print"		{return PRINT;}
"scan"		{return SCAN;}
"break"		{return BREAK;}
"return"	{return RETURN;}

"{"			{return LKEY;}
"}" 		{return RKEY;}
"(" 		{return LPAR;}
")" 		{return RPAR;}
"+"			{return MAS;}
"-"			{return MENOS;}
"*"			{return MUL;}
"/"			{return DIV;}
"||" 		{return OR;}
"&&"        {return AND;}
"!" 		{return NOT;}
"<" 		{return MENOR;}
">" 		{return MAYOR;}
"=="		{return IGUAL;}
"!="		{return DIF;}
"<=" 		{return MENORI;}
">=" 		{return MAYORI;}
"="			{return ASIG;}

";"			{return PYC;}
","			{return COMA;}
"." 		{return PUNTO;}

{ENTERO}	{ 	numType = 1;
				return NUMERO;}
{FLOTANTE}	{	numType = 2;
				return NUMERO;}
{DOUBLE}	{	numType = 3;
				return NUMERO;}

{ID}		{return ID;}

{CADENA} 	{	numType = 5;
				return CADENA;}
{CARACTER}	{	numType = 4;
				return CARACTER;}

{ESP}   	{}
"\n"    	{line++;}
.			{cout<<"ERROR LEXICO " << yytext << endl;}

%%

int yyFlexLexer::yywrap(){
    return 1;
}

int Lexer::getType()
{
    return numType;
}

int Lexer::getLine()
{
    return line;
}

string Lexer::getVal()
{
    return yytext;
}
