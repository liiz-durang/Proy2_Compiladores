
#include "Driver.h"
#include <sstream>


Expresion Driver::disyuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.args1 = e1.dir;
        c.args2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "||";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}

bool Driver::compatibles (int t1, int t2){

    //Si struct, preguntar a la tabla de tipos
    std::string nombre1 = tt.getNombre(t1);
    std::string nombre2 = tt.getNombre(t2);
    if (nombre1 == "struct" && nombre2 == "struct") {
        //Validar la equivalencia de los campos de los tipos estructurados 

        //Contar los campos , si tienen el mismo num de tipos, son compatibles. 
    }
    
    //Checar los tipos de datos
    if(t1 == t2) return true;
    if (t1 == 1 || t2 == 2) return true;
    return false;
}

void Driver::error(string msg)
{
    cout<<"Error semántico "<<msg<<endl;
    exit(EXIT_FAILURE);
}


Expresion Expresion::numero(std::string val, int tipo){
    //Si son float, se debe convertir en cte
    if (tipo == 2)
    {
        stringstream cte;
        cte << "cteFloat" << cteFloat ++ ;
        Numero num;
        num.val = val;
        num.tipo = tipo;
        constantes[cte.str()] = num;
    }
    
}