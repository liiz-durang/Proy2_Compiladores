/**
 * Analisis Semántico
 * 
 * Tabla de Simbolos
 * Guarda información de los identificadores
 **/ 

#ifndef __SimbolosTabla_HPP__
#define __SimbolosTabla_HPP__

#include <string>
#include <vector>
#include <map>
#include "Simbolo.h"
using namespace std;


class SimbolosTabla
{
private:
    map<string, Simbolo> Tsimbolos;
public:
    SimbolosTabla();
    ~SimbolosTabla();
    map<string,Simbolo> getSimbolos();
    void addSimbolo(string id, Simbolo s);
    int getDireccion(string id);
    int getType(string id);
    string getCategoria(string id);
    vector<int> getArgs(string id);
    bool is_in(string id);
    int getTam();
};

#endif // !__SimbolosTabla_HPP__