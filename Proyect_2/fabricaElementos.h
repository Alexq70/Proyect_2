#pragma once
#ifndef FABRICA_ELEMENTOS_H
#define FABRICA_ELEMENTOS_H
#include "elemento.h"
#include "carnivoro.h"
#include "herbivoro.h"
#include "omnivoro.h"
#include "recurso.h"
#include "agua.h"
#include "planta.h"
#include "carne.h"
class fabricaElementos {
public:
	virtual elemento* crearElemento(char, string, coordenada) = 0;
};
#endif 
