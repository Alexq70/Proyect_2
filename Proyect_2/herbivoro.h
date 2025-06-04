#pragma once
#include"criatura.h"
#include "coordenada.h"
class herbivoro : public criatura{
private:
	char tipo = 'H'; // H de herbivoro
	string id;
	int energia;
	int edad;
	coordenada posicion;
public:
	bool operator==(herbivoro&);
	herbivoro(char tipo,string id , int energia, int edad, coordenada c);
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
	~herbivoro();
	string toString();
};
ostream& operator<<(ostream&, herbivoro&);

