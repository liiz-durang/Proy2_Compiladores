#ifndef __PILATS_H__
#define _PILATS_H_

#include <vector>
#include "SimbolosTabla.h"
using namespace std;

class PilaTS
{
private:
    /* data */
    vector<SimbolosTabla*> datos;
public:

    PilaTS(/* args */);
    ~PilaTS();
    void Push(SimbolosTabla* tabla);
    SimbolosTabla* Pop();
    
    SimbolosTabla* Top(); //tope pila
    SimbolosTabla* Bottom(); //fondo pila
};



#endif

