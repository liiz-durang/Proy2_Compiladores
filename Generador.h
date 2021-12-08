//Revisar y/o cambiar 
#ifndef __Generador_HPP__
#define __Generador_HPP__

#include <vector>
#include <fstream>
using namespace std;
#include "Cuadrupla.h"
#include "SimbolosTabla.h"

class Generador{
private:
    ofstream file;
public:
    Generador(/* args */);
    ~Generador();
    void translate(vector<Cuadrupla> icode, SimbolosTabla *ts);
    void translate(Cuadrupla q, int type);
    void translate(map<string, string> cf);
    void translate(SimbolosTabla *ts);
    void openFile(string name);
};

#endif // !__Generador_HPP__
