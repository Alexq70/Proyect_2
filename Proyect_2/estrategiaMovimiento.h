#pragma once
#ifndef estrategiaMoviento_h
#define estrategiaMoviento_h
#include "estrategia.h"

class estrategiaMovimiento : public estrategia{
public:
	virtual ~estrategiaMovimiento() = default;
	virtual void realizarEstrategia() = 0;
};
#endif 
