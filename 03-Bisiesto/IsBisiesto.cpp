/* Camila Victoria Losada
20200605
Años Bisiestos */

#include <cassert>

bool IsBisiesto (unsigned);

int main() {

assert (true == IsBisiesto(2020));
assert (IsBisiesto(2000));
assert (IsBisiesto(1600));
assert (IsBisiesto(2400));
assert (IsBisiesto(2016));
assert (IsBisiesto(1996));

assert (not IsBisiesto(1582));
assert (not IsBisiesto(2021));
assert (not IsBisiesto(1700));
assert (not IsBisiesto(1800));
assert (not IsBisiesto(1900));
assert (not IsBisiesto(2100));
}

bool IsBisiesto (unsigned anio) {return 
anio>=1582 and anio%4==0 and(anio%100!=0 or (anio%100==0 and anio%400==0));}
