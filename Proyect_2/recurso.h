#pragma once
#ifndef RECURSO_H
#define RECURSO_H	
#include <iostream>
#include <sstream>
#include "coordenada.h"
#include "elemento.h"
using namespace std;
class recurso :public elemento {
private:
	coordenada posicion;
public:
	recurso(char tipo, string id, coordenada);

};
#endif // !RECURSO_H	