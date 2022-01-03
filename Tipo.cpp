/**
 * Analisis Semántico
 * 
 * Tipo
 * Guarda información de los tipos de datos
 * id   |   Nombre  | Tamanio | items | Tipo_Base
 * 
 **/ 

#include "Tipo.h"

Tipo::Tipo(){

}


Tipo::~Tipo(){

}

/*
 * Crea un tipo a partir de su nombre y tamaño
 * sirve para los tipos nativos
 * @param name nombre del tipo
 * @param tamanio tamaño del tipo nativo
 */
Tipo::Tipo(string name, int tamanio){
    this->name = name;
    this->isTable = false;
    this->base.base = -1;
    this->items= -1;
    this->tamanio = tamanio;
}

/*
 * Crea un tipo para las estructuras
 * @param name nombre del tipo (struct)
 * @param tabla apuntador tabla de símbolos para la estructura
 * @param tamanio tamaño en bytes de la tabla de símbolos
 */
Tipo::Tipo(string name, SimbolosTabla *tabla, int tamanio){
    this->name = name;
    this->isTable = true;
    this->base.tabla = tabla;
    this->items = -1;
    this->tamanio = tamanio;
}

/*
 * Crea un tipo para los arreglos
 * @param name nombre del tipo (array)
 * @param items número de elementos del arreglo
 * @param tamanio tamaño en bytes
 */
Tipo::Tipo(string name, int items, int base, int tamanio){
    this->name = name;
    this->isTable = false;
    this->base.base = base;
    this->items = items;
    this->tamanio = tamanio;
}
    
/*
* Getters
*/
int Tipo::getTamanio(){
    return tamanio;
}
    
SimbolosTabla *Tipo::getTabla(){
    if(isTable){
        return base.tabla;
    }else{
        return nullptr;
    }   
}

int Tipo::getItems(){
    return items;
}

//Para arreglos
int Tipo::getBase(){
    if(!isTable) {
        return base.base;
    }
    else{
        return -1;
    }   
}

string Tipo::getName(){
    return name;
}