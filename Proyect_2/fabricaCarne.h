#pragma once
#ifndef fabricaCarne_h
#define fabricaCarne_h
#include "fabricaRecursos.h"
class fabricaCarne : public fabricaRecursos
{
	elemento* crearElemento(char, string, coordenada);
};

#endif 