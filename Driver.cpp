
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