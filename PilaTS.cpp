#include "PilaTS.h"


PilaTS::PilaTS(/* args */){

}

PilaTS::~PilaTS(){

}

void PilaTS::Push(SimbolosTabla* tabla){
    datos.push_back(tabla);
}

SimbolosTabla* PilaTS::Pop(){
    unsigned int tam = datos.size();
    SimbolosTabla* temp = datos[tam - 1];
    datos.pop_back();
    
    return temp;
}
    
SimbolosTabla* PilaTS::Top(){
    unsigned int tam = datos.size();
    SimbolosTabla* temp = datos[tam - 1];
    
    return temp;
    
}

SimbolosTabla* PilaTS::Bottom(){
    return  datos[0];
}

