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
#include <SimbolosTabla.h>
#include <TiposTabla.h>
#include <Cuadrupla.h>


using namespace std;


struct Expresion{
    int tipo;
    string dir;
    

};

struct Numero{
    std::string valor;
    int tipo;
};

class Driver
{
private:
    vector<Cuadrupla> icode;

    //Tabla de simbolos
    SimbolosTabla ts;

    //Tabla de tipos
    TiposTabla tt;

    //Pila de tablas de simbolos 
    stack <SimbolosTabla> pilaTs;

    //Tabla de cadenas 
    map <std::string, std::string> tString; 

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

    //Contador de tipos
    int idTipo;

    //Contador etiqueta
    int numeroEtiqueta;
    int numeroTemporal;


    //Generador código final 

public: 
    Driver();
    ~Driver();

    //Funciones para tabla de tipos
    void agregar_tipo(std::string nombre, SimbolosTabla *tipo_base); //Para estructuras
    void agregar_tipo(std::string nombre, int tam_bytes); //tipos base
    
    //Funciones para tabla de simbolos
    void agregar_simbolo(std::string id, int dir, int tipo, std::string categoria);
    void agregar_simbolo(std::string id, int dir, int tipo, std::string categoria, std::vector <int> args);


    std::string nuevaEtiqueta();
    std::string nuevaTemporal();

    void asignacion(std::string id, Expresion e);
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
    Expresion numero(std::string val, int tipo);

    std::string ampliar(std::string dir, int t1, int t2);
    std::string reducir(std::string dir, int t1, int t2);
    int maximo (int t1, int t2);
    int minimo(int t1, int t2);
    //Ver que 2 tipos estructurados sean compatibles
    //Compatibles si tienen el mismo num y tipo de campos
    bool compatibles(int t1, int t2);

    void error_semantico(std::string mensaje);
    void gen_imprimir(std::string val);
    void gen_lectura(std::string dir);
    void gen_label(std::string label);

};



#endif // !__DRIVER_HPP__