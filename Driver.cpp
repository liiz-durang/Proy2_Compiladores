
#include "Driver.h"
#include <sstream>

Driver::Driver(){
    //Tabla de simbolos
    ts = new SimbolosTabla();

    //Tabla de tipos
    tt = new TiposTabla();

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

    //Contador de tipos
    idTipo = 0;

    //Contador etiquetas
    numeroEtiqueta = 0;

    //Contador Temporal
    numeroTemporal = 0;
}




 //Agregar Tipo struct
void Driver::agregar_tipo(std::string nombre, SimbolosTabla *tipo_base){
    this->tt.addTipo(idTipo++ , nombre, tipo_base->getTam() ,tipo_base);
}

 //Agregar Tipo base
void Driver::agregar_tipo(std::string nombre, int tam_bytes){
    this->tt.addTipo(idTipo++ , nombre, tam_bytes);
}

//Agregar simbolo para variable a tabla simbolos
void Driver::agregar_simbolo(std::string id, int dir ,int tipo, std::string categoria){
    if(!this->ts.is_in(id))
        this->ts.addSimbolo(id, Simbolo(dir,tipo,categoria));
    else
        error("La variable "+id+" ya fue declarada");
}

// Función para agregar un símbolo a la tabla de símbolos (del tipo función)
void Driver::agregar_simbolo(std::string id, int dir ,int tipo, std::string categoria,vector<int> args){
    this->ts.addSimbolo(id, Simbolo(dir,tipo,categoria, args));

}

//Generacion de etiquetas L0, L1 ... Ln
string Driver::nuevaEtiqueta(){
    stringstream label;
    label << "L"<<numeroEtiqueta++;
    return label.str();
}

//Generacion de etiquetas temporales t0, t1 ... tn
string Driver::nuevaTemporal(){
    stringstream tmp;
    tmp<<"t"<<numeroTemporal++;
    return tmp.str();
}

void asignacion(std::string id, Expresion e){
    
}

//Profe 
Expresion Driver::asig(string id, Expresion e)
{
    Expresion e1;
    string alfa;
    //Validar que el id fue declarado
    if(!ts.is_in(id)) error("La variable "+id+" no fue declarada");
    int tipoId = ts.gettipo(id);
    e1.tipo = tipoId; //La expresión de salida siempre tendrá el tipo del id
    if(tipoId == e.tipo){
        alfa = e.dir;
    }
    else if(tipoId>e.tipo)
    {
        alfa = ampliar(e.dir, e.tipo, e1.tipo);
    }
    else if(min(tipoId, e.tipo)!=1)
    {    
        alfa = reducir(e.dir, e.tipo, e1.tipo);        
    }
    else
    {
        error("Los tipos son incompatibles");
    }
    genCode(id, alfa, "=", "");
    e.dir = id;        
    return e1;
}

string Driver::ampliar(std::string dir, int t1, int t2){
    string temp;
    if(t1==t2) return dir;
    else if(t1==0 && t2==1){
        temp = nuevaTemporal();
        icode.push_back(Cuadrupla("(float)",dir, "", temp));
        agregar_simbolo(temp , 1,"temporal");
        return temp;
    }else return "";
}

//
string Driver::reducir(string dir, int t1, int t2)
{
    string temp;
    if(t1==t2) return dir;
    else if(t1==1 && t2==0){
        temp = nuevaTemporal();
        icode.push_back(Cuadrupla("(int)",dir, "", temp));
       agregar_simbolo(temp, 0, "temporal");        
        return temp;
    }else return "";
}

int Driver::max(int t1, int t2)
{
    if(t1==t2) return t1;
    else if(t1==0 && t2==1) return 1;
    else if(t1==1 && t2==0) return 1;
    else return -1;
}

int Driver::min(int t1, int t2)
{
    if(t1==t2) return t1;
    else if(t1==0 && t2==1) return 0;
    else if(t1==1 && t2==0) return 0;
    else return -1;
}


Expresion Driver::disyuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
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
    std::string nombre1 = tt.getName(t1);
    std::string nombre2 = tt.getName(t2);
    if (nombre1 == "struct" && nombre2 == "struct") {
        //Validar la equivalencia de los campos de los tipos estructurados 

        //Contar los campos , si tienen el mismo num de tipos, son compatibles. 
    }
    
    //Checar los tipos de datos
    if(t1 == t2) return true;
    if (t1 == 1 || t2 == 2) return true;
    return false;
}

void Driver::error_semantico(string msg){
    cout<<"Error semántico "<<msg<<endl;
    exit(EXIT_FAILURE);
}




//Duda
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