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

    //void print();
    //Funcion para representar un op de tipo string en un op de tipo enum
    //QuadType resolveQuad(string op);
    //QuadType resolveQuad();
    
    string getResultado();
    string getArg1();
    string getArg2();
    string getOperador();
};



#endif // !__CUADRUPLA_H__
