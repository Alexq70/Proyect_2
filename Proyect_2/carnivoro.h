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
	~carnivoro();
	string toString();
	//------------------------------------------------------------
	string getId();
	char getTipo();
	int getEnergia();
	int getEdad();
	coordenada& getCoordenada();
	//------------------------------------------------------------
	void setTipo(char tipo);
	void setEnergia(int);
	void setEdad(int);
	void setCoordenada(coordenada);
	//------------------------------------------------------------
	//Metodos de observacion del animal
	coordenada observarArriba();
	coordenada observarAbajo();
	coordenada observarIzquierda();
	coordenada observarDerecha();
	coordenada observarD_arriba_I(); // observar diagonal arriba izquierda
	coordenada observarD_arriba_D(); // observar diagonal arriba derecha
	coordenada observarD_abajo_I(); // observar diagonal abajo izquierda
	coordenada observarD_abajo_D(); // observar diagonal abajo derecha
	//------------------------------------------------------------
	char observarEntorno(matriz*); //determina que hay cerca de el para cambiar de estrategia
	coordenada siguienteMovimiento(matriz*);
	estrategia* cambiarEstrategia(matriz*);
	void consumirRec();


};
ostream& operator<<(ostream&, carnivoro& );
