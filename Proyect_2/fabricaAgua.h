#pragma once
#ifndef FABRICA_AGUA_H
#define FABRICA_AGUA_H
#include "fabricaRecursos.h"
class fabricaAgua : public fabricaRecursos
{
	elemento* crearElemento(char, string, coordenada);
};
#endif
