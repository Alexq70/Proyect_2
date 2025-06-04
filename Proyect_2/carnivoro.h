#pragma once
#include "criatura.h"
class carnivoro : public criatura {
private:
	bool rapidez;
public:
	carnivoro();
	carnivoro(char tipo,string id , int energia, int edad, coordenada c);
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
	~carnivoro();

	void setRapidez(bool);
	string toString();

};

