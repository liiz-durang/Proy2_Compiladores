/**
 * Analisis Semántico
 * 
 * Tabla de Simbolos
 * Guarda información de los simbolos
 **/ 

#ifndef __SimbolosTabla_H__
#define __SimbolosTabla_H__

#include <string>
#include <vector>
#include <map>
#include "Simbolo.h"
using namespace std;


class SimbolosTabla
{
private:
    //Tabla de Simbolos
    map<string, Simbolo> Tsimbolos;
public:
    SimbolosTabla();
    ~SimbolosTabla();
    /*
    * Agrega un simbolo a la tabla de simbolos
    * @params id dentro de la tabal de simbolos
    * @s simbolo a agregar
    */
    void addSimbolo(string id, Simbolo s);

    /*
    * True si el elemento está en la tabla de simbolos 
    * @param id identificador dentro de la t simbolos
    */
    bool is_in(string id);

    /*
    * Getters
    */
    map<string,Simbolo> getSimbolos();
    int getDireccion(string id);
    int getTipo(string id);
    string getCategoria(string id);
    //vector<int> getArgs(string id);

    void printTable();
    
};

#endif // !__SimbolosTabla_H__