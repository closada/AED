/* Camila Victoria Losada
20200531
Funciones y Operador Condicional */

#include <cassert>

double F3 (double);

int main () {

assert(-3 == F3(3));
assert(3.1 == F3(3.1));
assert(3 == F3(-3));
assert(4.1 == F3(4.1));
assert(2 == F3(-2));
assert(-1 == F3(1));

}

double F3(double x){return x>=-3 and x<=3 ? -x : x;}
