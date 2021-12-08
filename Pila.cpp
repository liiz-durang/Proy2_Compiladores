#include "Pila.h"


Pila::Pila(/* args */){
    
}

Pila::~Pila(){

}

/*
* Ingresar una tabla de simbolos a la pila
* @params tabla Referencia a tabla de simbolos
*/
void Pila::push(SimbolosTabla* tabla){
    datos.push_back(tabla);
}

/*
* Quitar una tabla de simbolos 
* Se quitará la última tabla que se ingresó
*/
SimbolosTabla* Pila::pop(){
    unsigned int tam = datos.size();
    SimbolosTabla* temp = datos[tam - 1];
    datos.pop_back();
    
    return temp;
}

/*
*  Ver el Top de la pila
*/
SimbolosTabla* Pila::lookTop(){
    unsigned int tam = datos.size();
    SimbolosTabla* temp = datos[tam - 1];
    
    return temp;
}

/*
*  Ver el Fondo de la pila
*/
SimbolosTabla* Pila::lookBottom(){
    return  datos[0];
}

