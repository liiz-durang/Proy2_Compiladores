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
union TipeBase{
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
    TipeBase base;
public:
    Tipo();
    ~Tipo();
    //Tipo nativo, con nombre y tamaño
    Tipo(string name, int tamanio);

    //Tipo para struct
    //*tab - Apuntador a la tabla de simbolos de la struct
    Tipo(string name, SimbolosTabla *tab, int tam);

    //Tipo para arreglos 
    //int items - Número de elementos del arreglo
    // int tamanio - Tamanio en bytes
    Tipo(string name, int items, int base, int tamanio);
    
    int getTamanio();
    SimbolosTabla *getTabla();
    int getItems();
    int getBase();
    string getName();
};

#endif // !__TIPO_HPP__