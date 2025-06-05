#pragma once
#ifndef estrategiaAmlimentacion_h
#define estrategiaAlimentacion_h
#include "estrategia.h"

class estrategiaAlimentacion : public estrategia {
public:
	virtual ~estrategiaAlimentacion() = default;
	virtual void realizarEstrategia() = 0;
};
#endif 
