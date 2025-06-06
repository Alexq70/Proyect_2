#pragma once
#ifndef reproduccion_h
#define reproduccion_h
#include "estrategiaAlimentacion.h"

class matriz;
class consumirRecurso : public estrategiaAlimentacion {
public:
	void realizarEstrategia(elemento*,elemento*, matriz*);
};

#endif
