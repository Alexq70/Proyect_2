#include "consumirRecurso.h"

void consumirRecurso::realizarEstrategia(elemento* propio,coordenada otro, matriz* m){

	coordenada copiada = otro;
	int x = otro.getX();
	int y = otro.getY();

	m->eliminarElemento(x, y);
	propio->setCoordenada(otro);
	m->actualizar();
	
}