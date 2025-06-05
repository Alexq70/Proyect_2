#pragma once
#include "criatura.h"
#include "coordenada.h"
#include "matriz.h"
#include "utilesEstrategias.h"

#include <iostream>
class matriz;
class carnivoro : public criatura {
private:
	char tipo = 'C'; // C de carnivoro
	string id;
	int energia;
	int edad;
	coordenada posicion;
	estrategia* estrategia; // Puntero a la estrategia que se usa para moverse y comer
public:
	bool operator==(carnivoro& );
	carnivoro(char tipo,string id , int energia, int edad, coordenada c);
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
	~carnivoro();
	//---------------------
	char observarEntorno(matriz*); // termina que hay cerca de el para cambiar de estrategia
	
	string toString();

};
ostream& operator<<(ostream&, carnivoro& );
