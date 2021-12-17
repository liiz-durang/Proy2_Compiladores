#ifndef __EXPRESION_H__
#define __EXPRESION_H__
#include <string>
using namespace std;


struct Expresion{
    int type;
    string dir;
    Expresion(string dir, int type=0){
        this->type = type;
        this->dir = dir;
    };

    Expresion(int type=0){
        this->type = type;
        this->dir = "";
    };

};



#endif // !__Expresion_h__