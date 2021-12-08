#include "SimbolosTabla.h"

SimbolosTabla::SimbolosTabla(){

}

SimbolosTabla::~SimbolosTabla(){
    
}
/*
* Agrega un simbolo a la tabla de simbolos
* @params id dentro de la tabal de simbolos
* @s simbolo a agregar
*/
void SimbolosTabla::addSimbolo(string id, Simbolo s){
    Tsimbolos[id] = s;
}

/*
* True si el elemento está en la tabla de simbolos 
* @param id identificador dentro de la t simbolos
*/
bool SimbolosTabla::is_in(string id){
    map<string,Simbolo>::iterator it;
    it = Tsimbolos.find(id);
    return it!= Tsimbolos.end();
}

/*
* Getters
*/
map<string,Simbolo> SimbolosTabla::getSimbolos(){
    return Tsimbolos;
}

int SimbolosTabla::getDireccion(string id){
    return Tsimbolos[id].getDireccion();
}

int SimbolosTabla::getTipo(string id){
    return Tsimbolos[id].getTipo();
}

string SimbolosTabla::getCategoria(string id){
    return Tsimbolos[id].getCategoria();
}
vector<int> SimbolosTabla::getArgs(string id){
    return Tsimbolos[id].getArgs();
}
