#include "Simbolo.h"

Simbolo::Simbolo()
{
}

Simbolo::~Simbolo()
{
}

/*
 * Crea un símbolo para una variable o estructura
 * @param dirección de la variable
 * @tipo de dato del simbolo, según la tabla de tipos
 * @categoria categoria del simbolo
 */
Simbolo::Simbolo(int dir, int tipo, string cat)
{
    this->dir = dir;
    this->tipo = tipo;
    this->cat = cat;
}

/*
 * Crea un símbolo para una función
 * @param dirección de la variable
 * @tipo de dato del simbolo, según la tabla de tipos
 * @categoria categoria del simbolo
 */
Simbolo::Simbolo(int dir, int tipo, string cat, vector<int> args)
{
    this->dir = dir;
    this->tipo = tipo;
    this->cat = cat;
    this->args = args;
}

/*
* Getters
*/

int Simbolo::getDireccion()
{
    return dir;
}

int Simbolo::getTipo()
{
    return tipo;
}

string Simbolo::getCategoria()
{
    return cat;
}

vector<int> Simbolo::getArgs()
{
    return args;
}
