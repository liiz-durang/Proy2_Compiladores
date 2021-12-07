/**
 * Cuadrupla
 **/

#include "Cuadrupla.h"
#include <iostream>

Cuadrupla::Cuadrupla(/* args */)
{
}

Cuadrupla::Cuadrupla(string op, string arg1, string arg2, string resultado)
{
    this->operador = operador;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->resultado = resultado;
}

Cuadrupla::~Cuadrupla()
{
}

string Cuadrupla::getResultado()
{
    return resultado;
}

string Cuadrupla::getArg1()
{
    return arg1;
}

string Cuadrupla::getArg2()
{
    return arg2;
}

string Cuadrupla::getOperador()
{
    return operador;
}

