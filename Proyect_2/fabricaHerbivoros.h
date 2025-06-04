#pragma once
#ifndef  fabricaHerbivoros_h
#define fabricaHerbivoros_h
#include "fabricaCriaturas.h"

class fabricaHerbivoros : public fabricaCriaturas
{
public:
	elemento* crearElemento(char,string, coordenada);
};
#endif 
