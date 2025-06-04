#pragma once
#ifndef FABRICA_PLANTA_H
#define FABRICA_PLANTA_H
#include "fabricaRecursos.h"
class fabricaPlanta : public fabricaRecursos
{
	elemento* crearElemento(char,string,coordenada);
};

#endif 