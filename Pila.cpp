#include "Pila.h"
#include <iostream>
using namespace std;


Pila::Pila(/* args */){
    
}

Pila::~Pila(){

}

/*
* Ingresar una tabla de simbolos a la pila
* @params tabla Referencia a tabla de simbolos
*/
void Pila::push(SimbolosTabla* tabla){
    cout << "función push de la pila" << endl;
    datos.push_back(tabla);
    cout << "Tamaño de la pila" << datos.size() << endl;
    cout << "Tamaño de la pila" << datos.size() << endl;
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
    int tam = datos.size();
    cout << "Tamaño de la pila " << datos.size() << endl;
    //cout << "función looktop" << endl;
    SimbolosTabla* temp = datos[tam-1];
    //cout << "función looktop2" << endl;
    return temp;
}

/*
*  Ver el Fondo de la pila
*/
SimbolosTabla* Pila::lookBottom(){
    //cout << "Funciión lookBotton" << endl;
    return  datos[0];
}

void Pila::printPilaSimbolos(){
    for(int i=0; i<datos.size();i++){
        datos[i]->printTable();
    }
}