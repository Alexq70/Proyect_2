#pragma once
#include"criatura.h"
#include "coordenada.h"

class matriz;
class estrategia;
class estrategiaMovimineto;
class estrategiaAlimentacion;
class consumirRecurso;
class depredacion;
class explorarMapa;
class reproduccion;

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
	~herbivoro();
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
	coordenada observarArriba();
	coordenada observarAbajo();
	coordenada observarIzquierda();
	coordenada observarDerecha();
	coordenada observarD_arriba_I(); // observar diagonal arriba izquierda
	coordenada observarD_arriba_D(); // observar diagonal arriba derecha
	coordenada observarD_abajo_I(); // observar diagonal abajo izquierda
	coordenada observarD_abajo_D(); // observar diagonal abajo derecha
	//------------------------------------------------------------
	char observarEntorno(matriz*); // termina que hay cerca de el para cambiar de estrategia
	estrategia* cambiarEstrategia(matriz*);
	void consumirRec();
};
ostream& operator<<(ostream&, herbivoro&);

