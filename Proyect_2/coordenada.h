#pragma once  
#include <iostream>  
#include <sstream>  
using namespace std;  
class coordenada {  
private:  
int x;  
int y;  
public:  
coordenada() : x(0), y(0) {} // Constructor predeterminado agregado  
coordenada(int x, int y);  
~coordenada();  
//---------------------------  
int getX();  
int getY();  
string toString();  
//-----------------------------  
void setX(int);  
void setY(int);  
bool moverseIzquierda();
bool moverseDerecha();
bool moverseArriba();
bool moverseAbajo();
bool diagonalDerechaArriba();
bool diagonalDerechaAbajo();
bool diagonalIzquierdaArriba();
bool diagonalIzquierdaAbajo();
//------------------------------  
bool operator==(coordenada otra) {  
	return (this->x == otra.x && this->y == otra.y);  
}  
};
ostream& operator<< (ostream& os ,coordenada& c);