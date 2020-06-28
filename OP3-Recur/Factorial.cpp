/* Camila Victoria Losada
20200628
Funciones Recursivas con Operador Condicional */

#include <cassert>

unsigned Factorial (unsigned);

int main () {

assert (1 == Factorial(1));
assert (2 == Factorial(2));
assert (120 == Factorial(5));
assert (3628800 == Factorial(10));
assert (39916800 == Factorial(11));
assert (479001600 == Factorial(12));
}


unsigned Factorial (unsigned n){return
n <2 ? 1 :n * Factorial(n-1);}

