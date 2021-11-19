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
    const int OR        = 23;
    const int MENQ      = 24;
    const int MAYQ      = 25;
    const int IGUAL     = 26;
    const int DIF       = 27;
    const int MENI      = 28;
    const int MAYI      = 29;
    const int ASIG      = 30;

    const int PYC       = 31;
    const int COMA      = 32;
    const int PUNTO     = 33;

    const int ESP       = 34;

    const int NUMERO    = 35; //Entero o flotante o double
    const int ID        = 36; 

    const int CADENA    = 37; //cadena o caracter

}
#endif