# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Lista Enlazada de Poligonos*

**Prototipos de funciones:**  

void AddVerticeFront (Poligono&, Punto);  
void AddVerticeEnd (Poligono&, Punto);  

void RemoveVerticeEnd (Poligono&);  
void RemoveVerticeFront (Poligono&);  

void GuardarPunto(const Punto,std::ostream&);  
void GuardarPoligono (const Poligono&,std::ostream&);  
void GuardarPuntos (const Poligono&,std::ostream&);  
void GuardarColor (const Color&,std::ostream&);  

unsigned GetCantidadLados (const Poligono&);  
double GetDistancia (Punto,Punto);  
Punto GetVertice (const Poligono&, unsigned);   
double GetPerimetro (const Poligono&);  


bool IsIgualPuntos (Punto, Punto);  
void SetVertice (Poligono&, Punto, unsigned);   
void LiberarEspacio (Poligono&);  

bool ExtraerPunto(std::istream&,Punto&);  
bool ExtraerPoligono(std::istream&, Poligono&);  
bool ExtraerColor(std::istream&, Color&);  
bool ExtraerPuntos(std::istream&, Poligono&);  



void CopiarPoligonosConPerimetrosMayoresA(double,std::string,std::string);  


void CambiarColor (Poligono&, Color);   



**Modelos IPO de las funciones (de polígono):**  

Poligono x Punto -> AddVerticeFront -> Poligono*  
Poligono x Punto -> AddVerticeEnd -> Poligono*  
Poligono -> RemoveVerticeEnd -> Poligono*    
Poligono -> RemoveVerticeFront -> Poligono*    

Punto x Flujo de Salida -> GuardarPunto -> void (nos interesa su efecto de lado)  
Poligono x Flujo de salida -> GuardarPoligono -> void (nos interesa su efecto de lado)  
Poligono x Flujo de salida -> GuardarPuntos -> void (nos interesa su efecto de lado)  
Color x Flujo de salida -> GuardarColor void (nos interesa su efecto de lado)  

Poligono -> GetCantidadLados -> Natural (unsigned)  
Poligono -> GetPerimetro -> real (double)  
Punto x Punto -> GetDistancia -> real (double)  
Poligono x unsigned -> GetVertice -> Punto  

Poligono x Color -> CambiarColor -> Poligono*  

Punto x Punto -> IsIgualPunto -> booleano  
Poligono x Punto x unsigned -> SetVertice -> Poligono*  
Poligono -> LiberarEspacio -> vacío (efecto de lado)  

Punto x flujo de entrada -> ExtraerPunto -> booleano x Punto*  
Poligono x flujo de entrada -> ExtraerPoligono -> booleano x Poligono*  
Color x flujo de entrada -> ExtraerColor -> booleano x Color*  
Poligono x flujo de entrada -> ExtraerPuntos -> booleano x Poligono*  


dobule x string x string -> CopiarPoligonosConPerimetrosMayoresA -> vacío (nos interesa su efecto de lado)  
	

NOTA: Poligono*, Color* y Punto* significa que los mismos que ingresan a la funcion salen modificados; es decir, en estos casos Poligono  y Punto son parámetros inout.  

**Pruebas (main):**

Poligono p1{0},p2{0};  

AddVerticeFront(p1,{2,2});  
assert(IsIgualPuntos(GetVertice(p1,1),{2,2}));  


AddVerticeFront(p1,{3,3});  
assert(IsIgualPuntos(GetVertice(p1,1),{3,3}));  

AddVerticeFront(p1,{-3,0});  
assert(IsIgualPuntos(GetVertice(p1,1),{-3,0}));  

AddVerticeFront(p1,{3.14,127});  
assert(IsIgualPuntos(GetVertice(p1,1),{3.14,127}));  

AddVerticeFront(p1,{0,0});  
assert(IsIgualPuntos(GetVertice(p1,1),{0,0}));  

AddVerticeFront(p1,{0.15,-8});  
assert(IsIgualPuntos(GetVertice(p1,1),{0.15,-8}));  

AddVerticeFront(p1,{-3,1});  
assert(IsIgualPuntos(GetVertice(p1,1),{-3,1}));  

//ImprimirPoligono(p1);  

CambiarColor(p1,rojo);  
assert(p1.color.R == rojo.R);  
assert(p1.color.G == rojo.G);  
assert(p1.color.B == rojo.B);  

RemoveVerticeFront(p1);  
assert( not IsIgualPuntos(GetVertice(p1,1),{-3,1}));  

RemoveVerticeFront(p1);  
assert(not IsIgualPuntos(GetVertice(p1,1),{0.15,-8}));  

//ImprimirPoligono(p1);  

SetVertice(p1,{-2,2},3);  
assert(IsIgualPuntos(GetVertice(p1,3),{-2,2}));  

assert(IsIgualPuntos(GetVertice(p1,GetCantidadLados(p1)),{2,2}));  

assert (GetPerimetro(p1) > 261.3 and GetPerimetro(p1) < 261.5);  

CambiarColor(p2,verde);  
AddVerticeFront(p2,{1,1});  
assert(IsIgualPuntos(GetVertice(p2,1),{1,1}));  

AddVerticeFront(p2,{2,2});  
assert(IsIgualPuntos(GetVertice(p2,1),{2,2}));  

AddVerticeEnd(p2,{3,3});  
assert(IsIgualPuntos(GetVertice(p2,GetCantidadLados(p2)),{3,3}));  


RemoveVerticeFront(p2);  
assert(IsIgualPuntos(GetVertice(p2,1),{1,1}));  

RemoveVerticeEnd(p2);  
assert(IsIgualPuntos(GetVertice(p2,GetCantidadLados(p2)),{1,1}));  


//ImprimirPoligono(p2);  
LiberarEspacio(p1);  
LiberarEspacio(p2);  

/************** prueba con flujos **********************/  

CopiarPoligonosConPerimetrosMayoresA(250,"datos_polig.txt","salida.txt");  
