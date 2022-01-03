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
    this->operador = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->resultado = resultado;
}

Cuadrupla::~Cuadrupla()
{
    
}


CuadruplaTipo Cuadrupla::resolverCuadrupla(string op){
    if(op == "+") return QMAS;
    if(op == "-") return QMENOS;
    if(op == "*") return QMUL;
    if(op == "/") return QDIV;
    if(op == "=") return QCOPY;
    if(op == "if") return QIF;
    if(op == "goto") return QGOTO;
    if(op == "label") return QLABEL;
    if(op=="(float)") return QCASTFLOAT;
    if(op=="(int)") return QCASTINT;
}

void Cuadrupla::print(){
    switch(resolverCuadrupla(operador)){
        case QMAS: 
        case QMENOS:
        case QMUL:
        case QDIV:
            cout<<resultado<<"="<<arg1<<operador<<arg2<<endl;
            break;
        case QIF:
            cout<<operador<<" "<<arg1<<" goto "<<resultado<<endl;
            break;
        case QGOTO:
            cout<<operador<<" "<<resultado<<endl;
            break;
        case QCOPY:
            cout<<resultado<<operador<<arg1<<endl;
            break;
        case QLABEL:
            cout<<resultado<<":";
            break;
        case QCASTFLOAT:
        case QCASTINT:
            cout<<resultado<<"="<<operador<<arg1<<endl;
            break;
    }
}


string Cuadrupla::getResultado(){
    return resultado;
}

string Cuadrupla::getArg1(){
    return arg1;
}

string Cuadrupla::getArg2(){
    return arg2;
}

string Cuadrupla::getOperador(){
    return operador;
}

void Cuadrupla::setOperador(string op){
    this->operador = op;
}

void Cuadrupla::setArg1(string a1){
    this->arg1 = a1;
}

void Cuadrupla::setArg2(string a2){
    this->arg2 = a2;
}

void Cuadrupla::setResultado(string resul){
    this->resultado = resul;
}