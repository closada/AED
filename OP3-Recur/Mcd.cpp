/* Camila Victoria Losada
20200628
Funciones Recursivas con Operador Condicional */

#include <cassert>

unsigned Mcd (unsigned, unsigned);

int main () {

assert (6 == Mcd(270,192));
assert (14 == Mcd(42,56));
assert (10 == Mcd(20,10));
assert (20 == Mcd(40,60));
assert (1 ==  Mcd(457,1014));

}


unsigned Mcd (unsigned a, unsigned b){
return
a == 0 ? b: b== 0? a: Mcd(b, a%b);}

 