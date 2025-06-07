#ifndef estrategiaMovimiento_h
#define estrategiaMovimiento_h

#include "estrategia.h"
class estrategiaMovimiento : public estrategia {
public:
	virtual void realizarEstrategia(elemento*, matriz*) = 0;
};

#endif 
