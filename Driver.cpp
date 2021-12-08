
#include "Driver.h"
#include <sstream>
#include <iostream>

Driver::Driver(){
    //Tabla de simbolos
    ts = SimbolosTabla();

    //Tabla de tipos
    tt = TiposTabla();

    //Pila de tablas de simbolos 
    pilaTs = Pila() ;

    //Tabla de cadenas 
    map <std::string, std::string> tString; 

    //Pila para las etiquetas
    pilaEtiquetas = stack<int>();

    //Pila para direcciones
    pilaDir = stack<int>();

    //Pila para temporales
    pilaTemporales = stack<int>();

    //Dirección. Cada que se crea una nueva se reincia y se guarda en la pila para direcciones
    dir = 0;

    //Contador variables temporales. Reincia y se guarda en la pilaTemporales

    //Contador de tipos
    idTipo = 0;

    //Contador etiquetas
    numeroEtiqueta = 0;

    //Contador variables temporales. Reincia y se guarda en la pilaTemporales
    numeroTemporal = 0;
}



void Driver::crear_ambito(){
    SimbolosTabla *ts = new SimbolosTabla();
    pilaTs.push(ts);
    pilaDir.push(dir);
    dir = 0;
    pilaTemporales.push(numeroTemporal);
    numTemporales = 0;    
}

void Driver::destruir_ambito(){
    pilaTs.pop();
}

//pendiente
void Driver::_label(string label){
    icode.push_back(Cuadrupla("label","","",label ));
}

//pendiente
void Driver::_goto(string label){
    icode.push_back(Cuadrupla("goto","","",label ));
}


/*
* Función para agregar tipo de estructura
* a la tabla de tipos
* @param name nombre del tipo por lo general struct 
* @param tabSimbStruct referencia a la tabla de símbolos de la estructura
*/
void Driver::agregar_tipo(string nombre, SimbolosTabla *tSimStruct){
    tt.addTipo(idTipo++ , nombre ,tSimStruct);
}

/*
* Función para agregar un tipo nativo a 
* la tabla de tipos
* @param name nombre del tipo por lo general struct 
* @param tabSimbStruct referencia a la tabla de símbolos de la estructura
*/
void Driver::agregar_tipo(string nombre, int tam_bytes){
    tt.addTipo(idTipo++ , nombre, tam_bytes);
}

//Agregar simbolo para variable a tabla simbolos
void Driver::agregar_simbolo(std::string id, int dir ,int tipo, string categoria){
    if(!ts.is_in(id))
        ts.addSimbolo(id, Simbolo(dir,tipo,categoria));
    else
        error_semantico("La variable " + id + " ya fue declarada");
}

// Función para agregar un símbolo a la tabla de símbolos (del tipo función)
void Driver::agregar_simbolo(string id,int tipo, string categoria ,vector<int> args){
    
    if (!pilaTs.lookTop()->is_in(id))
    {
        pilaTs.lookTop()->addSimbolo(id, Simbolo(dir,tipo,categoria, args));


        //Incrementa variable global dir de acuerdo al tamñao de la  var de tipos. 
        //No tiene caso dek
    }else
        error_semantico("El simbolo " + id + " ya existe");
    
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
Expresion Driver::asignacion(string id, Expresion e)
{
    Expresion e1;
    string alfa;
    //Validar que el id fue declarado
    if(!ts.is_in(id)) error_semantico("La variable "+id+" no fue declarada");
    int tipoId = ts.getTipo(id);
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
        error_semantico("Los tipos son incompatibles");
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
string Driver::reducir(string dir, int t1, int t2){
    string temp;
    if(t1==t2) return dir;
    else if(t1==1 && t2==0){
        temp = nuevaTemporal();
        icode.push_back(Cuadrupla("(int)",dir, "", temp));
       agregar_simbolo(temp, 0, "temporal");        
        return temp;
    }else return "";
}

int Driver::maximo(int t1, int t2){
    if(t1==t2) return t1;
    else if(t1==0 && t2==1) return 1;
    else if(t1==1 && t2==0) return 1;
    else return -1;
}

int Driver::minimo(int t1, int t2){
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
Expresion Driver::conjuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "&&";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}

Expresion Driver::igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "==";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}

Expresion Driver::distinto(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "!=";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}

Expresion Driver::menor_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "<";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}

Expresion Driver::mayor_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = ">";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}
Expresion Driver::mayor_o_igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "=>";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}

Expresion Driver::menor_o_igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "<=";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}

Expresion Driver::suma(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "+";
        codigo_intermedio.push_back(c);
    }
    else{
        error_semantico("Tipos de operandos no compatibles");
    }
}

Expresion Driver::negacion(Expresion e1)
{
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();
    Cuadrupla c;
    c.arg1 = e1.dir;
    c.resultado = e.dir();
    c.operador = "!";
    codigo_intermedio.push_back(c);
    //genCode(e.dir,  "!", e1);
   
    return e;
}

Expresion Driver::multiplicacion(Expresion e1, Expresion e2)
{
    Expresion e;
    e.type = max(e1.type, e2.type);
    if(e.type!=-1){
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "*", alfa2);
    }else{
        error("Los tipos son incompatibles");
    }
    return e;
}

Expresion Driver::division(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; //Depende de la tabla de tipos  
    e.dir= nuevaTemporal();

    //Validar e1 y e2 mismo tipo
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "/";
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
    std::cout<<"Error semántico "<<msg<<endl;
    exit(EXIT_FAILURE);
}




//Duda
Expresion Driver::numero(std::string val, int tipo){
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