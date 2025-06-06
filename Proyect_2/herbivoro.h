#pragma once
#include"criatura.h"
#include "coordenada.h"
#include "utilesEstrategias.h"
class matriz;
class herbivoro : public criatura{
private:
	char tipo = 'H'; // H de herbivoro
	string id;
	int energia;
	int edad;
	coordenada posicion;
	estrategia* estra;
public:
	bool operator==(herbivoro&);
	herbivoro(char tipo,string id , int energia, int edad, coordenada c);
	string getId();
	char getTipo();
	int getEnergia();
	int getEdad();
	coordenada& getCoordenada();
	//---------------------
	void setTipo(char tipo);
	void setEnergia(int);
	void setEdad(int);
	void setCoordenada(coordenada);
	~herbivoro();
	string toString();
	//---------------------
	char observarEntorno(matriz*); // termina que hay cerca de el para cambiar de estrategia
	estrategia* cambiarEstrategia(matriz*);
};
ostream& operator<<(ostream&, herbivoro&);

