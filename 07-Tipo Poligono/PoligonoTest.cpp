#include "Poligono.h"
#include <cassert>

int main () {
Poligono p1 {
 3,
 {{ {2,2}, {0,0}, {-2,2}   }},
 {127,0,45},
};

Color negro{0,0,0};


CambiarColor(p1,negro);
assert (p1.color.R == 0);
assert (p1.color.G == 0);
assert (p1.color.B == 0);

AddVertice(p1, {13,-2.3});
assert (IsIgualPunto(GetVertice(p1,p1.cant_puntos),{13,-2.3}));
assert (GetCantidadLados(p1) == 4);

RemoveVerticeEnd(p1);
assert (GetCantidadLados(p1) == 3);
assert (IsIgualPunto(GetVertice(p1,p1.cant_puntos),{-2,2}));


assert (60 == CalculoAnguloInteriorPoligono(p1));

assert (9.7 > GetPerimetro(p1) and GetPerimetro(p1) > 9.6);

SetVertice(p1,{3,-5},2);
assert (IsIgualPunto(GetVertice(p1,2),{3,-5}));

}