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

//tamaño en bytes de la tabla de símbolos a la que se apuntará en la tabla de tipos
#define TAMSTRUCT 100;

class TiposTabla
{
private:
    //Tabla de tipos
   map<int,Tipo> tiposT;

public:
    TiposTabla(/* args */);
    ~TiposTabla();

    /*
    * Agrega un tipo a partir de su nombre y tamaño
    * sirve para los tipos nativos. 
    * Creando un nuevo tipo.
    * @param id del tipo
    * @param name nombre del tipo
    * @param tamanio tamaño en bytes  del tipo nativo
    */
    void addTipo(int id, string name, int tamanio);

    /*
    * Agrega un tipo para las estructuras
    * creando el nuevo tipo
    * @param id del tipo
    * @param name nombre del tipo (struct)
    * @param tab tabla de símbolos para la estructura
    */
    void addTipo(int id, string name, SimbolosTabla *tabla);
    
    /*
    * Agrega un tipo para los arreglos
    * creando el nuevo tipo
    * @param id del tipo
    * @param name nombre del tipo (array)
    * @param items número de elementos del arreglo
    * @param base NO SE MUY BIEN QUE ES GG
    */
    void addTipo(int id, string name, int items,  int base);

    

    //Obtener tamanio del tipo
    int getTamanio(int id);

    //Obtener items del tipo
    int getItems(int id);

    //Obtener referencia de algun tabla de simbolos de struct 
    SimbolosTabla *getTabla(int id);

    //Obtener Base
    int getBase(int id);

    //Obtener nombre del tipo
    string getName(int id);
};

#endif // !__TiposTabla_HPP__