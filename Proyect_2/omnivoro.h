#pragma once
#include "criatura.h"
class omnivoro : public criatura{
public:
	omnivoro(); // constructor por defecto
	omnivoro(char tipo,string id , int energia, int edad, coordenada c);
	void comer();
	string getId();
	char getTipo();
	int getEnergia();
	int getEdad();
	coordenada getCoordenada();
	//---------------------
	void setTipo(char tipo);
	void setEnergia(int);
	void setEdad(int);
	void setCoordenada(coordenada);
	~omnivoro();
	string toString();
};
