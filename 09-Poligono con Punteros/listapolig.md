# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Lista Enlazada de Poligonos*

**Prototipos de funciones:**  

void AddVerticeFront (Poligono&, Punto);  
void AddVerticeEnd (Poligono&, Punto);  
void RemoveVerticeEnd (Poligono&);  
void RemoveVerticeFront (Poligono&);  
void ImprimirPunto(Punto);  
void ImprimirPoligono (Poligono&);  
unsigned GetCantidadLados (const Poligono&);  
double GetDistancia (Punto,Punto);  
void CambiarColor (Poligono&, Color);   
double CalculoAnguloInteriorPoligono (const Poligono&);  
bool IsIgualPunto (Punto, Punto);  
void SetVertice (Poligono&, Punto, unsigned); // Poligono, punto nuevo, posicion en array de poligono  
Punto GetVertice (const Poligono&, unsigned);  
double GetPerimetro (const Poligono&);  
void LiberarEspacio (Poligono&);  


bool ExtraerPunto(std::istream&,Punto&);  
bool ExtraerPoligono(std::istream&, Poligono&);  
bool ExtraerColor(std::istream&, Color&);  
bool ExtraerPuntos(std::istream&, Poligono&);  
void GuardarPoligono(std::ostream&,Poligono&);  


Color GetColor (void);  
Color MezclarDosColoresenPIguales (const Color&,const Color&);  
Color MezclarDosColoresProporcion (const Color&, unsigned, const Color&, unsigned); // se asume los unsigned son las proporciones  
Color GetComplementario (const Color&);  
Color Sumar (const Color&,const Color&);  
Color Restar (const Color&,const Color&);  
std::string GetHtmlHex (const Color&);  
std::string GetHtmlRgb (std::string);  
void CrearSvgConTextoEscritoEnAltoContr(std::string, std::string, const Color&);  
bool IsIgual (const Color&, const Color&);  
void ImprimirColor (const Color&);  


**Modelos IPO de las funciones (de polígono):**  

Poligono x Punto -> AddVerticeFront -> Poligono*  
Poligono x Punto -> AddVerticeEnd -> Poligono*  
Poligono -> RemoveVerticeEnd -> Poligono*    
Poligono -> RemoveVerticeFront -> Poligono*    
Punto -> ImprimirPunto -> vacío (efecto de lado)  
Poligono -> ImprimirPoligono -> vacío (efecto de lado)  
Poligono -> GetCantidadLados -> Natural (unsigned)  
Poligono x Color -> CambiarColor -> Poligono*  
Poligono -> CalculoAnguloInteriorPoligono -> Real (double)  
Punto x Punto -> IsIgualPunto -> booleano  
Poligono x Punto x unsigned -> SetVertice -> Poligono*  
Poligono x unsigned -> GetVertice -> Punto  
Poligono -> LiberarEspacio -> vacío (efecto de lado)  


Flujo de entrada x Punto -> ExtraerPunto -> booleano x Punto*  
Flujo de entrada x Poligono -> ExtraerPoligono -> booleano x Poligono*  
Flujo de entrada x Color -> ExtraerColor -> booleano x Color*  
Flujo de entrada x Poligono -> ExtraerPuntos -> booleano x Poligono*  
Flujo de salida x Poligono -> GuardarPoligono -> vacío (nos interesa su efecto de lado)   
Poligono -> GetPerimetro -> real (double)  
Punto x Punto -> GetDistancia -> real (double)  


NOTA: Poligono* y Punto* significa que los mismos que ingresan a la funcion salen modificados; es decir, en estos casos Poligono  y Punto son parámetros inout.  

**Pruebas (main):**

Poligono p1{0},p2{0};  

AddVerticeFront(p1,{2,2});  
assert(GetVertice(p1,1).x == 2);  
assert(GetVertice(p1,1).y == 2);  

AddVerticeFront(p1,{3,3});  
assert(GetVertice(p1,1).x == 3);  
assert(GetVertice(p1,1).y == 3);  
AddVerticeFront(p1,{-3,0});  
assert(GetVertice(p1,1).x == -3);  
assert(GetVertice(p1,1).y == 0);  
AddVerticeFront(p1,{3.14,127});  
assert(GetVertice(p1,1).x == 3.14);  
assert(GetVertice(p1,1).y == 127);  
AddVerticeFront(p1,{0,0});  
assert(GetVertice(p1,1).x == 0);  
assert(GetVertice(p1,1).y == 0);  
AddVerticeFront(p1,{0.15,-8});  
assert(GetVertice(p1,1).x == 0.15);  
assert(GetVertice(p1,1).y == -8);  
AddVerticeFront(p1,{-3,1});  
assert(GetVertice(p1,1).x == -3);  
assert(GetVertice(p1,1).y == 1);  

//ImprimirPoligono(p1);  

CambiarColor(p1,rojo);  
assert(p1.color.R == rojo.R);  
assert(p1.color.G == rojo.G);  
assert(p1.color.B == rojo.B);  

RemoveVerticeFront(p1);  
assert(GetVertice(p1,1).x != -3);  
assert(GetVertice(p1,1).y != 1);  

RemoveVerticeFront(p1);  
assert(GetVertice(p1,1).x != 0.15);  
assert(GetVertice(p1,1).y != -8);  

//ImprimirPoligono(p1);  

SetVertice(p1,{-2,2},3);  
assert(GetVertice(p1,3).x == -2);  
assert(GetVertice(p1,3).y == 2);  

//ImprimirPoligono(p1);  

/*ImprimirPunto(GetVertice(p1,3));  
ImprimirPunto(GetVertice(p1,1));  
ImprimirPunto(GetVertice(p1,GetCantidadLados(p1)));*/  
assert(GetVertice(p1,GetCantidadLados(p1)).x == 2);  
assert(GetVertice(p1,GetCantidadLados(p1)).y == 2);  

assert (GetPerimetro(p1) > 261.3 and GetPerimetro(p1) < 261.5);  

CambiarColor(p2,verde);  
AddVerticeFront(p2,{1,1});  
assert(GetVertice(p2,1).x == 1);  
assert(GetVertice(p2,1).y == 1);  

AddVerticeFront(p2,{2,2});  
assert(GetVertice(p2,1).x == 2);  
assert(GetVertice(p2,1).y == 2);  

AddVerticeEnd(p2,{3,3});  
assert(GetVertice(p2,GetCantidadLados(p2)).x == 3);  
assert(GetVertice(p2,GetCantidadLados(p2)).y == 3);  


RemoveVerticeFront(p2);  
assert(GetVertice(p2,1).x == 1);  
assert(GetVertice(p2,1).y == 1);  

RemoveVerticeEnd(p2);  
assert(GetVertice(p2,GetCantidadLados(p2)).x == 1);  
assert(GetVertice(p2,GetCantidadLados(p2)).y == 1);  


//ImprimirPoligono(p2);  
LiberarEspacio(p1);  
LiberarEspacio(p2);  

/************** prueba con flujos **********************/  
Punto p;  
Poligono pol{0};  

	while( ExtraerPoligono(std::cin,pol) )   
		if(GetPerimetro(pol) > VALOR ) /*VALOR es una variable externa (definida en 100)*/  
		GuardarPoligono(std::cout,pol);  
		


/**************** pruebas Color **************************/  
assert (IsIgual(rojo,Sumar(rojo,rojo)));  
assert(IsIgual({255,0,255},Restar(amarillo,cyan)));  

assert (IsIgual(MezclarDosColoresenPIguales(negro,blanco),{127,127,127}));  
assert (IsIgual(MezclarDosColoresenPIguales(azul,amarillo),{127,127,127}));  

assert(IsIgual(MezclarDosColoresProporcion(azul,100,amarillo,100),{127,127,127}));  
assert (IsIgual(MezclarDosColoresProporcion(azul,80,amarillo,20), {25,25,102}));  

assert (IsIgual(GetComplementario(rojo), {0,255,255}));  
assert (IsIgual(GetComplementario(negro),blanco));  


assert( "#0000ff" == GetHtmlHex(azul));  
assert ("#ff0000" == GetHtmlHex(rojo));  
assert ("#000000" == GetHtmlHex(negro));  



assert("rgb(0,0,255)" == GetHtmlRgb(GetHtmlHex(azul)));  
assert("rgb(0,255,0)" == GetHtmlRgb(GetHtmlHex(verde)));  
assert("rgb(255,255,255)" == GetHtmlRgb(GetHtmlHex(blanco)));  

CrearSvgConTextoEscritoEnAltoContr("mensajever", "A ver si esto funciona bien!!",blanco);  
CrearSvgConTextoEscritoEnAltoContr("mensaje", "Veo todo bien! :)",amarillo);  

assert (not IsIgual(amarillo,negro));  
assert (IsIgual(blanco, {255,255,255}));  