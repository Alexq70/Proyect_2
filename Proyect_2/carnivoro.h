#pragma once
#include "criatura.h"
#include "coordenada.h"

class matriz;
class estrategia;
class estrategiaMovimineto;
class estrategiaAlimentacion;
class consumirRecurso;
class depredacion;
class explorarMapa;
class reproduccion;

#include <iostream>

class carnivoro : public criatura {
private:
	char tipo = 'C'; // C de carnivoro
	string id;
	int energia;
	int edad;
	coordenada posicion;
	estrategia* estra; // Puntero a la estrategia que se usa para moverse y comer
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
	char observarEntorno(matriz*); //determina que hay cerca de el para cambiar de estrategia
	estrategia* cambiarEstrategia(matriz*);
	void consumirRec();
	void cazar();
	string toString();

};
ostream& operator<<(ostream&, carnivoro& );
