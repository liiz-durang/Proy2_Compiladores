/**
 * Análisis Semántico
 * Funciones para operar tabla de tipos y tabla de simbolos
 **/
#ifndef __DRIVER_H__
#define __DRIVER_H__

#include <string>
#include <map>
#include <stack>
#include <vector>
#include "SimbolosTabla.h"
#include "TiposTabla.h"
#include "Cuadrupla.h"
#include "Pila.h"


using namespace std;


struct Expresion{
    int tipo;
    string dir;

};

struct Numero{
    string valor;
    int tipo;
};

class Driver
{
private:

    vector<Cuadrupla> icode;

    //Tabla de simbolos global
    SimbolosTabla ts;

    //Tabla de tipos
    TiposTabla tt;

    //Pila de tablas de simbolos 
    Pila pilaTs;

    //Tabla de cadenas 
    map <string, string> tString; 

    //Pila para las etiquetas
    stack <int> pilaEtiquetas;

    //Pila para direcciones
    stack<int> pilaDir;

    //Pila para temporales
    stack<int> pilaTemporales;

    //Dirección. Cada que se crea una nueva se reincia y se guarda en la pila para direcciones
    int dir;

    //Contador variables temporales. Reincia y se guarda en la pilaTemporales
    int numTemporales;

    //Flotantes se deben guardar como constantes para Mips.
    map<std::string, std::string> constantes;

    //Generador de código intermedio
    vector<Cuadrupla> codigo_intermedio;

    //Contador de tipos en tabla tipos
    int idTipo;

    //Contador etiqueta
    int numeroEtiqueta;
    int numeroTemporal;
    int numeroCte;

    int tipoRetorno;
    bool banderaRetorno;




public: 
    Driver();
    ~Driver();

    //*****************Funciones para tabla de tipos************//

    /*
    * Función para agregar un tipo estructura
    * a la tabla de tipos
    * @param name nombre del tipo por lo general struct 
    * @param tabSimbStruct referencia a la tabla de símbolos de la estructura
    */
    void agregar_tipo(std::string nombre, SimbolosTabla *tSimStruct);
    
    /*
    * Función para agregar un tipo nativo a 
    * la tabla de tipos
    * @param name nombre del tipo
    * @param tam_bytes tamaño e bytes del tipo nativo
    */
    void agregar_tipo(std::string nombre, int tam_bytes); 
    
    //*****************Funciones para tabla de simbolos************//

    //Agregar simbolo de tipo variable
    void agregar_simbolo(string id, int tipo);
    
    //Agregar simbolo de tipo funcion 
    void agregar_simbolo(string id, int tipo, vector <int> args);
    


    string nuevaEtiqueta();
    string nuevaTemporal();

    void Driver::_label(string label);
    void Driver::_goto(string label);
    Expresion asignacion(std::string id, Expresion e);
    Expresion disyuncion(Expresion e1, Expresion e2);
    Expresion conjuncion(Expresion e1, Expresion e2);
    Expresion igual(Expresion e1, Expresion e2);
    Expresion distinto(Expresion e1, Expresion e2);
    Expresion menor_que(Expresion e1, Expresion e2);
    Expresion mayor_que(Expresion e1, Expresion e2);
    Expresion menor_o_igual(Expresion e1, Expresion e2);
    Expresion mayor_o_igual(Expresion e1, Expresion e2);
    Expresion suma(Expresion e1, Expresion e2);
    Expresion resta(Expresion e1, Expresion e2);
    Expresion multiplicacion(Expresion e1, Expresion e2);
    Expresion division(Expresion e1, Expresion e2);
    Expresion negacion(Expresion e1);

    //Convertir identificador en expresion
    Expresion identificador(std::string id);
    Expresion floatAconstante(std::string val, int tipo);

    std::string ampliar(string dir, int t1, int t2);
    std::string reducir(string dir, int t1, int t2);
    int maximo (int t1, int t2);
    int minimo(int t1, int t2);
    //Ver que 2 tipos estructurados sean compatibles
    //Compatibles si tienen el mismo num y tipo de campos
    bool compatibles(int t1, int t2);

    void error_semantico(string mensaje);
    void gen_imprimir(string val);
    void gen_lectura(string dir);

    void crear_ambito();
    void destruir_ambito();

    void error_semantico(string msg);
};



#endif // !__DRIVER_HPP__