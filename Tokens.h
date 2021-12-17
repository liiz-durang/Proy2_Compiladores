/*
* Analizador Léxico
* Compiladores 2022-1
* Grupo: 1
* Integrantes: Durán González Lizeth        |   García Meneses jeremy   
            Mendoza de la Vega Elizabeth    |   Parada Pérez Jesús Bryan
*
* Descripción: Clase con valores que nos retorna el Lexer al encontrar el token
*/

#ifndef TOKENS_H
#define TOKENS_H

    //Declaración de constantes para nuestros tokens.
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

    const int LKEY      = 15; //Llave izquierdo {
    const int RKEY      = 16; //Llave derecho }
    const int LPAR      = 17; //Parentesis izquierdo (
    const int RPAR      = 18; //Parentesis derecho )
    const int MAS       = 19; // +
    const int MENOS     = 20; //-
    const int MUL       = 21; // *
    const int DIV       = 22; // '/'
    const int AND       = 23; //&&
    const int OR        = 24; // ||
    const int NOT       = 25; // !
    const int MENOR     = 26; // <
    const int MAYOR     = 27; // >
    const int IGUAL     = 28; // ==
    const int DIF       = 29; // !=
    const int MENORI    = 30; // <=
    const int MAYORI    = 31; //>=
    const int ASIG      = 32; // =

    const int PYC       = 33; // ;
    const int COMA      = 34; // ,
    const int PUNTO     = 35; // .

    const int ESP       = 36; // espacio

    const int NUMERO   = 37; //Entero o flotante o double
    //const int NFLOAT     = 37;
    //const int NDOUBLE    = 41;
    //const int NENTERO    = 42;

    const int ID        = 38; // identificadores

    const int CADENA    = 39; // "<Cadenas>""
    const int CARACTER  = 40; // '<caracter>'
    
#endif