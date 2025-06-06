#pragma once
#ifndef explorarMapa_h
#define explorarMapa_h
#include "estrategiaMovimiento.h"
class matriz;
class explorarMapa : public estrategiaMovimiento {
public:
	void realizarEstrategia(elemento*, matriz*);
};

#endif

