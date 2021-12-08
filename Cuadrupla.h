/**
 * Funciones de la Cuadrupla.
 * Representa una instrucción de 3 direcciones:
 * x = y op z
 * op, operador
 * y, argumento 1
 * z, argumento 2
 * x, dirección de resultado
 **/

#ifndef __CUADRUPLA_H__
#define __CUADRUPLA_H__
#include <string>
using namespace std;

//Tipos de operaciones de tres direcciones en cuadruplas
enum CuadruplaTipo {QIF, QGOTO, QMAS, QMENOS, QMUL, QDIV, QCOPY, QLABEL,QCASTINT, QCASTFLOAT};

class Cuadrupla
{
private:
    string operador;
    string arg1;
    string arg2;
    string resultado;
public:
    Cuadrupla();
    Cuadrupla(string operador, string arg1, string arg2, string resultado);    
    ~Cuadrupla();

    void print();
    //Funcion para representar un op de tipo string en un op de tipo enum
    CuadruplaTipo resolverCuadrupla(string op);
    CuadruplaTipo resolverCuadrupla();
    
    string getResultado();
    string getArg1();
    string getArg2();
    string getOperador();
};



#endif // !__CUADRUPLA_H__
