#pragma once
#include <iostream>
#include <sstream>
#include "coordenada.h"
using namespace std;
class recurso :public elemento {
private:
	coordenada posicion;
public:
	recurso(char tipo, string id, coordenada);

};

