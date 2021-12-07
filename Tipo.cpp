/**
 * Analisis Semántico
 * 
 * Tipo
 * Guarda información de los tipos de datos
 * id   |   Nombre  | Tamanio | items | Tipo_Base
 * 
 **/ 

#include <Tipo.h>

Tipo::Tipo(){

}


Tipo::~Tipo(){

}

//Tipo nativo, con nombre y tamaño
Tipo::Tipo(string name, int tamanio){

}

//Tipo para struct
//*tab - Apuntador a la tabla de simbolos de la struct
Tipo::Tipo(string name, SimbolosTabla *tab, int tam){

}

    //Tipo para arreglos 
    //int items - Número de elementos del arreglo
    // int tamanio - Tamanio en bytes
Tipo::Tipo(string name, int items, int base, int tamanio){

}
    
int Tipo::getTamanio(){
    return tamanio;
}
    
SimbolosTabla *Tipo::getTabla(){

}

int Tipo::getItems(){
    return items;
}

int Tipo::getBase(){

}

string Tipo::getName(){
    return name;
}

