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
	elemento* clonar() const;
	omnivoro(char tipo,string id , int energia, int edad, coordenada c);
	omnivoro(const omnivoro&);
	string toString();
	//-----------------------------------------------------------------
	~omnivoro();
	void comer();
	string getId();
	char getTipo();
	int getEnergia();
	int getEdad();
	coordenada getCoordenada();
	//-----------------------------------------------------------------
	void setTipo(char tipo);
	void setEnergia(int);
	void setEdad(int);
	void setCoordenada(coordenada);
	void menosEnergia();
	void masEdad();
	//-----------------------------------------------------------------
	coordenada observarArriba();
	coordenada observarAbajo();
	coordenada observarIzquierda();
	coordenada observarDerecha();
	coordenada observarD_arriba_I(); // observar diagonal arriba izquierda
	coordenada observarD_arriba_D(); // observar diagonal arriba derecha
	coordenada observarD_abajo_I(); // observar diagonal abajo izquierda
	coordenada observarD_abajo_D(); // observar diagonal abajo derecha
	//-----------------------------------------------------------------
	char observarEntorno(matriz*); // termina que hay cerca de el para cambiar de estrategia
	coordenada observarPosicion(matriz*); //observa una posicion concreta del mapa
	coordenada siguienteMovimiento(matriz*);
	estrategia* cambiarEstrategia(matriz*,string);
	void realizarComportamiento(matriz*);
	void sobrevivir(matriz*,string);
	void consumirRec();

};
ostream& operator<<(ostream&, omnivoro&);

