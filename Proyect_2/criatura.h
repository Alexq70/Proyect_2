#pragma once
#include <iostream>
#include <sstream>
#include "coordenada.h"
using  namespace std;
class criatura {
protected:
	string id;
	string tipo;
	int energia;
	int edad;
	coordenada posicion;
public:
	criatura(char tipo, string id, coordenada p);

};

