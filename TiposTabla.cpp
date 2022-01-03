/**
 * Analisis Semántico
 * 
 * Tabla de Tipos
 * Guarda información de los tipos de datos
 **/ 

#include "TiposTabla.h"

TiposTabla::TiposTabla(/* args */){

}

TiposTabla::~TiposTabla(){

}

/*
* Agrega un tipo a partir de su nombre y tamaño
* sirve para los tipos nativos. 
* Creando un nuevo tipo.
* @param id del tipo
* @param name nombre del tipo
* @param tamanio tamaño del tipo nativo
*/
void TiposTabla::addTipo(int id, string name, int tamanio){
    tiposT[id] = Tipo(name, tamanio);
}

/*
* Agrega un tipo para las estructuras
* @param id del tipo
* @param name nombre del tipo (struct)
* @param tab tabla de símbolos para la estructura
*/
void TiposTabla::addTipo(int id, string name, SimbolosTabla *tabla){
    int tam = TAMSTRUCT;
    tiposT[id] = Tipo(name, tabla, tam);
}

/*
* Agrega un tipo para los arreglos
* creando el nuevo tipo
* @param id del tipo
* @param name nombre del tipo (array)
* @param items número de elementos del arreglo
* @param base NO SE MUY BIEN QUE ES GG
*/
void TiposTabla::addTipo(int id, string name, int items,  int base){
    int tam = tiposT[base].getTamanio()*items;
    tiposT[id] = Tipo(name, items, base, tam);
}

//Getters
int TiposTabla::getTamanio(int id){
    return tiposT[id].getTamanio();
}

int TiposTabla::getItems(int id){
    return tiposT[id].getItems();
}

SimbolosTabla *TiposTabla::getTabla(int id){
    return tiposT[id].getTabla();
}
    
int TiposTabla::getBase(int id){
    return tiposT[id].getBase();  
}

string TiposTabla::getName(int id){
    return tiposT[id].getName();        
}

int TiposTabla::getId(string name){

    map<int,Tipo>::iterator it;
    it = tiposT.begin();
    while(it != tiposT.end()){
        if( (it->second).getName() == name ){
            return it->first;
        }
    }
    return -1;

}
