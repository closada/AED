/* Camila Victoria Losada
20200605
Años Bisiestos */

#include <cassert>

bool IsBisiesto (unsigned);

int main() {

assert (true == IsBisiesto(2020));
assert (true == IsBisiesto(2000));
assert (true == IsBisiesto(1600));
assert (true == IsBisiesto(2400));
assert (true == IsBisiesto(2016));

assert (false == IsBisiesto(1582));
assert (false == IsBisiesto(2021));
assert (false == IsBisiesto(1700));
assert (false == IsBisiesto(1800));
assert (false == IsBisiesto(1900));
assert (false == IsBisiesto(2100));
}

bool IsBisiesto (unsigned anio) {return 
anio>=1582 and anio%4==0 and(anio%100!=0 or (anio%100==0 and anio%400==0)) ? true : false;}
