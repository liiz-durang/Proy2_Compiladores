/**
 * Analisis Semántico
 * 
 * Tabla de Tipos
 * Guarda información de los tipos de datos
 **/ 



#ifndef __TiposTabla_HPP__
#define __TiposTabla_HPP__

#include <map>
#include <string>
using namespace std;

#include "Tipo.h"

class TiposTabla
{
private:
    //Tabla de tipos
    map<int,Tipo> tiposT;
public:
    TiposTabla(/* args */);
    ~TiposTabla();
    //Agregar Tipos nativos
    void addTipo(int id, string name, int tamanio);

    //Agregar Tipos arreglo
    void addTipo(int id, string name, int items,  int base);

    //Agregar Tipo struct
    void addTipo(int id, string name, SimbolosTabla *tab);

    //Obtener tamanio del tipo
    int getTamanio(int id);

    //Obtener items del tipo
    int getItems(int id);

    //Obtener referencia de algun tabla de simbolos de struct 
    SimbolosTabla *getTab(int id);

    //Obtener Base
    int getBase(int id);

    //Obtener nombre del tipo
    string getName(int id);
};

#endif // !__TiposTabla_HPP__