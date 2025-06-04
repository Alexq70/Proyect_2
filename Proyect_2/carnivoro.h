#pragma once
#include "criatura.h"
#include "coordenada.h"
#include <iostream>
class carnivoro : public criatura {
private:
	char tipo = 'C'; // C de carnivoro
	string id;
	int energia;
	int edad;
	coordenada posicion;
	bool rapidez;
public:
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
ostream& operator<<(ostream&, carnivoro& );
