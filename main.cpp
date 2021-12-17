/*
* Analizador Léxico
* Compiladores 2022-1
* Grupo: 1
* Integrantes: Durán González Lizeth        |   García Meneses jeremy   
            Mendoza de la Vega Elizabeth    |   Parada Pérez Jesús Bryan
*
* Descripción:  Llamada a los métodos del análisis léxico. Código que
*               abre el archivo prueba y lo pasa al analizador léxico.
*/

#include <iostream>
#include <fstream>
#include "Driver.h"

using namespace std;

int main(int argc, char *argv[]){
	
	Driver driver;
    if (argc == 2)
    {
        driver.parse(argv[1]);
    }
    else
    {
        /** exit with failure condition **/
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}