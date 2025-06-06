#pragma once
#ifndef depredacion_h
#define depredacion_h
#include "estrategiaAlimentacion.h"
class matriz;

class depredacion : public estrategiaAlimentacion {
public:
	void realizarEstrategia(elemento*, elemento*, matriz*);
};

#endif
