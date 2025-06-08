#ifndef depredacion_h
#define depredacion_h
#include "estrategiaAlimentacion.h"

class depredacion : public estrategiaAlimentacion {
public:
	void realizarEstrategia(elemento*,coordenada,matriz*);
};

#endif
