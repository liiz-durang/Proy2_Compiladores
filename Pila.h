#ifndef __PILA_H__
#define __PILA_H_

#include <vector>
#include "SimbolosTabla.h"
using namespace std;

class Pila
{
private:
    /* data */
    vector<SimbolosTabla*> datos;
public:

    Pila(/* args */);
    ~Pila();

    /*
    * Ingresar una tabla de simbolos a la pila
    * @params tabla Referencia a tabla de simbolos
    */
    void push(SimbolosTabla* tabla);

    /*
    * Quitar una tabla de simbolos 
    * Se quitará la última tabla que se ingresó
    */
    SimbolosTabla* pop();
    
    /*
    *  Ver el Top de la pila
    */
    SimbolosTabla* lookTop(); //tope pila
    
    /*
    *  Ver el Fondo de la pila
    */
    SimbolosTabla* lookBottom(); //fondo pila

    void printPilaSimbolos();
};


#endif