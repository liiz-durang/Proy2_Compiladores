%{
	#include <iostream>
	#include <string>
	using namespace std;
	#include "Tokens.h"

	#include "Scanner.h"

%}

%option c++
%option outfile = "Scanner.cpp"
%option yyclass = "COMP::Scanner"
%option case-insensitive
%option noyywrap


ENTERO [0-9]+
FLOTANTE ([0-9])*.([0-9])+([Ee]([+-])?([0-9])+)?[fF]
DOUBLE ([0-9])*.([0-9])+([Ee]([+-])?([0-9])+)?[dD]?
ID [a-zA-Z][A-Za-z0-9_]*
ESP [ \t\n\r]
CADENA  \"([\x20-\x21\x23-\xFE])*\”
CARACTER \’[\x20-\x21\x23-\xFE \t\n\r]\’

%%
"char"		{return CHAR;}
"int"		{return INT;}
"float"		{return FLOAT;}
"double" 	{return DOUBLE;}
"struct"	{return STRUCT;}
"void"		{return VOID;}

"if"		{return IF;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"do"		{return DO;}
"print"		{return PRINT;}
"scan"		{RETURN SCAN;}
"break"		{return BREAK;}
"return"	{return RETURN;}

"{"			{return LKEY;}
"}" 		{return RKEY;}
"(" 		{return lpar;}
")" 		{return rpar;}
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
{ESP}		{}

{ENTERO}	{return NUMERO;}
{FLOTANTE}	{return NUMERO;}
{DOUBLE}	{return NUMERO;}

{ID}		{return ID;}

{CADENA} 	{return CADENA;}
{CARACTER}	{return CARACTER;}


.		{cout<<"ERROR LEXICO " << yytext << endl;}

%%

int yyFlexLexer::yywrap(){
	return 1;
}