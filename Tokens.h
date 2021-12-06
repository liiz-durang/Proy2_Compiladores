#ifndef TOKENS_H
#define TOKENS_H

/*Valores que nos retorna el Lexer al encontrar el token*/
namespace COMP{

    const int CHAR      = 1; 
    const int INT       = 2;
    const int FLOAT     = 3;
    const int DOUBLE    = 4;
    const int STRUCT    = 5;
    const int VOID      = 6;
    const int IF        = 7;
    const int ELSE      = 8;
    const int WHILE     = 9;
    const int DO        = 10;
    const int PRINT     = 11;
    const int SCAN      = 12;
    const int BREAK     = 13;
    const int RETURN    = 14;

    const int LKEY      = 15;
    const int RKEY      = 16;
    const int LPAR      = 17;
    const int RPAR      = 18;
    const int MAS       = 19;
    const int MENOS     = 20;
    const int MUL       = 21;
    const int DIV       = 22;
    const int AND       = 23;
    const int OR        = 24;
    const int NOT       = 25;
    const int MENOR     = 26;
    const int MAYOR     = 27;
    const int IGUAL     = 28;
    const int DIF       = 29;
    const int MENORI    = 30;
    const int MAYORI    = 31;
    const int ASIG      = 32;

    const int PYC       = 33;
    const int COMA      = 34;
    const int PUNTO     = 35;

    const int ESP       = 36;

    const int NUMERO    = 37; //Entero o flotante o double

    const int ID        = 38; 

    const int CADENA    = 39; //cadena o caracter
}
#endif