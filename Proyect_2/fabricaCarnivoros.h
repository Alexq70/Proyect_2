#pragma once
#ifndef fabricaCarnivoros_h
#define fabricaCarnivoros_h
#include "fabricaCriaturas.h"	

class fabricaCarnivoros : public fabricaCriaturas {
public:
	elemento* crearElemento(char,string, coordenada);
};


#endif 