/* Camila Victoria Losada
20200531
Funciones y Operador Condicional */

#include <cassert>

double funcion (double);

int main () {

assert(-3 == funcion(3));
assert(3.1 == funcion(3.1));
assert(3 == funcion(-3));
assert(4.1 == funcion(4.1));
assert(2 == funcion(-2));
assert(-1 == funcion(1));

}

double funcion(double x){return x>=-3 and x<=3 ? -x : x;}