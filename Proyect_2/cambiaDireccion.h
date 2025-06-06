#pragma once
#ifndef cambiaDireccion_h
#define cambiaDireccion_h
#include "estrategiaMovimiento.h"
class matriz;
class cambiaDireccion : public estrategiaMovimiento {
public:
	void realizarEstrategia(elemento*, matriz*);
};

#endif

