/* Camila Victoria Losada
20200628
Funciones Recursivas con Operador Condicional */

#include <cassert>

unsigned Fibonacci (unsigned);

int main () {

assert (1 == Fibonacci(1));
assert (1 == Fibonacci(2));
assert (8 == Fibonacci(6));
assert (21 == Fibonacci(8));
assert (55 == Fibonacci(10));
assert (233 == Fibonacci(13));
}


unsigned Fibonacci (unsigned n){return
n <2 ? n : Fibonacci(n-1) + Fibonacci(n-2);}

