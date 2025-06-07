#ifndef estrategiaAlimentacion_h
#define estrategiaAlimentacion_h

#include "estrategia.h"

class estrategiaAlimentacion : public estrategia {
public:
	virtual void realizarEstrategia(elemento*, elemento*, matriz*) = 0;
};
#endif 