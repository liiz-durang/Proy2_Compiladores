/**
 * Analisis Semántico
 * 
 * Tipo
 * Guarda información de los tipos de datos
 * id   |   Nombre  | Tamanio | items | Tipo_Base
 * 
 **/ 

#ifndef __TIPO_HPP__
#define __TIPO_HPP__

#include "SimbolosTabla.h"
#include <string>
using namespace std;


//fing.edu.uy/tecnoinf/maldonado/cursos/eda/material/teo/EDA-teorico13.pdf
union TipoBase{
    SimbolosTabla *tabla;
    int base;
};

class Tipo
{
private:
    string name;
    int tamanio;
    int items;
    bool  isTable;
    TipoBase base;

public:
    Tipo();
    ~Tipo();
    /*
    * Crea un tipo a partir de su nombre y tamaño
    * sirve para los tipos nativos
    * @param name nombre del tipo
    * @param tamanio tamaño del tipo nativo
    */
    Tipo(string name, int tamanio);

    /*
    * Crea un tipo para las estructuras
    * @param name nombre del tipo (struct)
    * @param tabla apuntador a tabla de símbolos para la estructura
    * @param tamanio tamaño en bytes de la tabla de símbolos
    */
    Tipo(string name, SimbolosTabla *tabla, int tamanio);

    /*
    * Crea un tipo para los arreglos
    * @param name nombre del tipo (array)
    * @param items número de elementos del arreglo
    * @param tamanio tamaño en bytes
    */
    Tipo(string name, int items, int base, int tamanio);
    
    /*
    * Getters
    */
    int getTamanio();
    SimbolosTabla *getTabla();
    int getItems();
    int getBase();
    string getName();
};

#endif // !__TIPO_HPP__