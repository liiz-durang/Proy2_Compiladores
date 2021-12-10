//revisar y/o acompletar 

#include "Generador.h"

Generador::Generador(/* args */){

}

Generador::~Generador()
{
}

/* 
 * Función para escribir la tabla de símbolos como variales globales en MIPS
 * @param ts tabla de símbolos a convertir
 */
void Generador::translate(SimbolosTabla *ts)
{
    openFile("prueba.mips");
    file<<".data"<<endl;
    map<string,Simbolo> syms = ts->getSimbolos();
    for(map<string,Simbolo>::iterator sym=syms.begin();sym!=syms.end(); sym++ )
    {
        if(sym->second.getTipo()==0){
            file<<"\t"<<sym->first<<": .word 0"<<endl;
        }else{
            file<<"\t"<<sym->first<<": .float 0.0"<<endl;            
        }
    }

}


void Generador::translate(vector<Cuadrupla> icode, SimbolosTabla *ts)
{
    
    file<<".text"<<endl;
    for(vector<Cuadrupla>::iterator q = icode.begin(); q!=icode.end(); q++){
        translate(*q, ts->getTipo(q->getResultado()));
    }
    // Código final para terminar  la ejecución del programa en ensamblador
    file<<"\tli $v0, 10"<<endl;
    file<<"\tsyscall"<<endl;
    file.close();
}

void Generador::translate(Cuadrupla q, int type){
    switch (q.resolverCuadrupla())
    {
        case QMAS: 
            if(type ==0){
                file<<"\tlw $t0,"<<q.getArg1()<<endl; //Aqui ademas se debe comparar si es un entero o una variable
                //file<<"\tli $t0,"<<q.getArg1()<<endl; //En caso de ser un número
                file<<"\tlw $t1,"<<q.getArg2()<<endl;//Aqui ademas se debe comparar si es un entero o una variable
                file<<"\tadd $t2, $t0, $t1"<<endl;
                file<<"\tsw $t2, "<<q.getResultado()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\tla $t1,"<<q.getArg2()<<endl;
                file<<"\tl.s $f1, ($t1)"<<endl;
                file<<"\tadd.s $f2, $f0, $f1"<<endl;
                file<<"\ts.s $f2, "<<q.getResultado()<<endl;
            }
            break;
        case QMENOS:
            if(type ==0){ //Hacer la mismas comprobaciones que para la suma
                file<<"\tli $t0,"<<q.getArg1()<<endl;
                file<<"\tli $t1,"<<q.getArg2()<<endl;
                file<<"\tsub $t2, $t0, $t1"<<endl;
                file<<"\tsw $t2, "<<q.getResultado()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\tla $t1,"<<q.getArg2()<<endl;
                file<<"\tl.s $f1, ($t1)"<<endl;
                file<<"\tsub.s $f2, $f0, $f1"<<endl;
                file<<"\ts.s $f2, "<<q.getResultado()<<endl;
            }
            break;
        case QMUL:
            if(type ==0){//Hacer la mismas comprobaciones que para la suma
                file<<"\tli $t0,"<<q.getArg1()<<endl;
                file<<"\tli $t1,"<<q.getArg2()<<endl;
                file<<"\tmul $t2, $t0, $t1"<<endl;
                file<<"\tsw $t2, "<<q.getResultado()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\tla $t1,"<<q.getArg2()<<endl;
                file<<"\tl.s $f1, ($t1)"<<endl;
                file<<"\tmul.s $f2, $f0, $f1"<<endl;
                file<<"\ts.s $f2, "<<q.getResultado()<<endl;
            }
            break;
        case QDIV:
            if(type ==0){//Hacer la mismas comprobaciones que para la suma
                file<<"\tli $t0,"<<q.getArg1()<<endl;
                file<<"\tli $t1,"<<q.getArg2()<<endl;
                file<<"\tdiv.s $t2, $t0, $t1"<<endl;
                file<<"\tsw $t2, "<<q.getResultado()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\tla $t1,"<<q.getArg2()<<endl;
                file<<"\tl.s $f1, ($t1)"<<endl;
                file<<"\tdiv.s $f2, $f0, $f1"<<endl;
                file<<"\ts.s $f2, "<<q.getResultado()<<endl;
            }
            break;
            
        case QIF:            
            file<<"\tlw $t0,"<<q.getArg1()<<endl;
            file<<"\tbge $t0, 0, "<<q.getResultado()<<endl;                
            break;

        case QGOTO:
            file<<"\tb "<<q.getResultado()<<endl;
            break;
        case QCOPY:
            if(type == 0){
                file<<"\tlw $t0,"<<q.getArg1()<<endl;
                file<<"\tsw $t0,  "<<q.getResultado()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\ts.s $f0,  "<<q.getResultado()<<endl;
            }
            break;
        case QLABEL:
            file<<q.getResultado()<<":";
            break;
        case QCASTFLOAT:
            file<<"\tlw $t0,"<<q.getArg1()<<endl;            
            file<<"\tmtc1 $t0,$f0"<<endl;
            file<<"\tcvt.s.w $f0,$f0"<<endl;
            file<<"\ts.s $f0, "<<q.getResultado()<<endl;
            break;

        case QCASTINT:            
            file<<"\tla $t0,"<<q.getArg1()<<endl;
            file<<"\tl.s $f0, ($t0)"<<endl;
            file<<"\tcvt.w.s $f0,$f0"<<endl;
            file<<"\tmfc1 $t0,$f0"<<endl;            
            file<<"\tlw $t0, "<<q.getResultado()<<endl;
            break;
    }
}

void Generador::openFile(string name){
    file.open(name, ios::out);
}

void Generador::translate(map<string, string> cf){
    for(map<string,string>::iterator c = cf.begin(); c != cf.end(); c++){
        file<<"\t"<<c->first<<": .float "<<c->second<<endl;
    }
}