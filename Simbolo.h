/**
 * Analisis Semántico
 * 
 * Simbolos
 * Elementos de la tabla de símbolos 
 * Se conforma por:
 * identificador | dirección de memoria | tipo | categoria | argumentos
 **/ 

#ifndef __Simbolo_HPP__
#define __Simbolo_HPP__

#include <string>
#include <vector>
using namespace std;

class Simbolo
{
private:
    int direccion;
    int type;
    string categoria;
    vector<int> args;

public:
    Simbolo();
    //Para las variables y struct
    Simbolo(int dir, int type, string cat);
    //Para las funciones
    Simbolo(int dir, int type, string cat, vector<int> args);
    ~Simbolo();

    int getDirerccion();
    int getType();
    string getCategoria();
    vector<int> getArgs();
    
};




#endif // !__SYM_HPP__
