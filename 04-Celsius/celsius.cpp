/* Camila Victoria Losada
20200603
Funciones y Operador Condicional */

#include <cassert>

double celsius (double);
bool AreNear (double, double, double);

int main () {

assert (true == AreNear(1.1111,celsius(34), 0.001));
assert (true == AreNear(37.7777,celsius(100), 0.001));
}

double celsius (double f) {return (5.0/9.0)*(f-32.0);}

bool AreNear (double n1, double n2, double t){return
n1<n2 ? n2-n1 < t ? true : false : n1-n2<t? true : false;}

