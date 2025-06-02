#pragma once
#include "recurso.h"
class planta : public recurso {
public:
	planta(string,coordenada); //soloo recibe el id
	~planta();
	string toString();
};

