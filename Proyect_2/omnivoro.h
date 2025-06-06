#pragma once
#include "criatura.h"
#include "coordenada.h"
#include "utilesEstrategias.h"
class matriz;
class omnivoro : public criatura{
private:
	char tipo = 'O'; // O de omnivoro
	string id;
	int energia;
	int edad;
	coordenada posicion;
	estrategia* estra;
public:
	bool operator==(omnivoro&);
	omnivoro(char tipo,string id , int energia, int edad, coordenada c);
	void comer();
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
	~omnivoro();
	string toString();
	//----------------------
	char observarEntorno(matriz*); // termina que hay cerca de el para cambiar de estrategia
	estrategia* cambiarEstrategia(matriz*);
};
ostream& operator<<(ostream&, omnivoro&);

