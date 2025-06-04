#pragma once
#ifndef fabricaOmnivoros_h
#define fabricaOmnivoros_h
#include "fabricaCriaturas.h"

class fabricaOmnivoros : public fabricaCriaturas {
public:
	elemento* crearElemento(char,string, coordenada);
};
#endif 
