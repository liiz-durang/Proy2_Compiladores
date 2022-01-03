#ifndef __Simbolo_HPP__
#define __Simbolo_HPP__

/**
 * Analisis Semántico
 * 
 * Simbolos
 * Elementos de la tabla de símbolos 
 * Se conforma por:
 * identificador | dirección de memoria | tipo | categoria | argumentos
 **/ 

#include <string>
#include <vector>
using namespace std;

class Simbolo
{
private:
    int dir;
    int tipo;
    string cat;
    vector<int> args;

public:
    Simbolo();
    ~Simbolo();
    /*
    * Crea un símbolo para una variable o estructura
    * @param dirección de la variable
    * @tipo de dato del simbolo, según la tabla de tipos
    * @categoria categoria del simbolo
    */
    Simbolo(int dir, int tipo, string cat);

    /*
    *Para las funciones
    */
    Simbolo(int dir, int tipo, string cat, vector<int> args);
    
    /*
    * Getters
    */
    int getDireccion();
    int getTipo();
    string getCategoria();
    vector<int> getArgs();

    void printSimbolo();
    
};




#endif // !__SYM_HPP__