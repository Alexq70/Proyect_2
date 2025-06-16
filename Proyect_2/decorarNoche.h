#pragma once
#include "decoradorInterfaz.h"
class decorarNoche : public decoradorInterfaz
{
public:
	decorarNoche(interfazAbstracta* inter) : decoradorInterfaz(inter) {}

	void cambiarModoMatriz(string modo,string matriz) {
		interfaz->cambiarModoMatriz(modo,matriz);
	}
};

