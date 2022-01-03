
#include "Driver.h"
#include <fstream>
#include <iostream>


Driver::Driver()
{
    numType = 0;
    numLabel = 0;
    numTemp = 0;
    dir= 0;
    cteF = 0;
    pilaSimbolos = Pila();
}

Driver::~Driver()
{
}

void Driver::parse(const string& filename)
{
    std::ifstream in_file(filename);
    if (!in_file.good())
    {
        exit(EXIT_FAILURE);
    }
    parse_helper(in_file);
    return;
}


void Driver::parse_helper(istream &stream)
{
    
    delete (lexer);
    try
    {
        lexer = new Lexer(&stream);
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "Error al crear lexer:  exiting!!\n";
        exit(EXIT_FAILURE);
    }

    delete (parser);
    try
    {
        parser = new yy::Parser((*lexer) /* lexer */,
                                   (*this) /* driver */);
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "Error al crear parser: (" << ba.what() << "), exiting!!\n";
        exit(EXIT_FAILURE);
    }
    const int accept(0);
    if (parser->parse() != accept)
    {
        std::cerr << "¡Error de sintaxis!\n";
    }
    return;
}

void Driver:: setType(int type){
    gType = type;
}

int Driver::getGtype(){
    return gType;
}

void Driver:: setId(string id){
    gId = id;
}

string Driver:: getId(){
    return gId;
}

Pila Driver:: getPilaTSimbolos(){
    return pilaSimbolos;
}

int Driver::getDir(){
    return dir;
}

void Driver::addSym(string id, int type, string cat){
    cout << "Función addSym de driver" << endl;
    getPilaTSimbolos().lookTop()->printTable();
    cout << "Función addSym de driver2" << endl;
    cout << getPilaTSimbolos().lookTop()->is_in(getId()) << endl;
    if (getPilaTSimbolos().lookTop()->is_in(getId()) == false) {
        cout << "Se agregará el simbolo a la tabla de simbolos" << endl;
        getPilaTSimbolos().lookTop()->addSimbolo(getId(),Simbolo(getDir(),getGtype(),"variable"));
    }
}

void Driver::printTable(){
    getPilaTSimbolos().printPilaSimbolos();
}

void Driver::pushTablaSimbolos(){
    cout << "Función pushTablaSimbolos de Driver" << endl;
    getPilaTSimbolos().push(new SimbolosTabla());
}