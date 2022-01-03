%{
	#include <iostream>
	#include <string>

	using namespace std;

	#include "Lexer.h"

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

"char"		{return token::CHAR;}
"int"		{return token::INT; }

"float"		{return token::FLOAT; }
"double" 	{return token::DOUBLE; }

"struct"	{return token::STRUCT;}
"void"		{return token::VOID;}

"if"		{return token::IF;}
"else"		{return token::ELSE;}
"while"		{return token::WHILE;}
"do"		{return token::DO;}
"print"		{return token::PRINT;}
"scan"		{return token::SCAN;}
"break"		{return token::BREAK;}
"return"	{return token::RETURN;}

"{"			{return token::LKEY;}
"}" 		{return token::RKEY;}
"(" 		{return token::LPAR;}
")" 		{return token::RPAR;}
"+"			{return token::MAS;}
"-"			{return token::MENOS;}
"*"			{return token::MUL;}
"/"			{return token::DIV;}
"||" 		{return token::OR;}
"&&"        {return token::AND;}
"!" 		{return token::NOT;}
"<" 		{return token::MENOR;}
">" 		{return token::MAYOR;}
"=="		{return token::IGUAL;}
"!="		{return token::DIF;}
"<=" 		{return token::MENORI;}
">=" 		{return token::MAYORI;}
"="			{return token::ASIG;}

";"			{return token::PYC;}
","			{return token::COMA;}
"." 		{return token::PUNTO;}

{ENTERO}	{ 	numType = 1;
				yylval->build<std::string>(yytext);
				return token::NUMERO;
			}

{FLOTANTE}	{	numType = 2;
				yylval->build<std::string>(yytext);
				return token::NUMERO;
			}

{DOUBLE}	{	numType = 3;
				yylval->build<std::string>(yytext);
				return token::NUMERO;
			}

{ID}		{
				yylval->build<std::string>(yytext);
				return token::ID;
			}

{CADENA} 	{	numType = 5;
				yylval->build<std::string>(yytext);
				return token::CADENA;
			}

{CARACTER}	{	numType = 4;
				yylval->build<std::string>(yytext);
				return token::CARACTER;
			}

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
