#pragma once
#ifndef REPRODUCCION_H
#define REPRODUCCION_H


#include "estrategiaMovimiento.h"

class reproduccion : public estrategiaMovimiento {
public:
	void realizarEstrategia(elemento*,matriz*);
};


#endif 

