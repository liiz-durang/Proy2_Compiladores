#ifndef __NUMERO_H__
#define __NUMERO_H__

#include <string>
using namespace std;


struct Numero{
    
    string valor;
    int type;
    Numero(string valor, int type=0){
        this->type = type;
        this->valor = valor;
    };

    Numero(int type=0){
        this->type = type;
        this->valor = "";
    };

};



#endif // !__NUMERO_H__