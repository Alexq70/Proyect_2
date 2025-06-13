#include "consumirRecurso.h"

void consumirRecurso::realizarEstrategia(elemento* propio,coordenada otro, matriz* m){

	coordenada copiada = otro;
	int x = otro.getX();
	int y = otro.getY();
	
	m->eliminarElemento(x, y);
    if (carnivoro* c = dynamic_cast<carnivoro*>(propio)) {
		c->consumirRec();
    }
    if (omnivoro* o = dynamic_cast<omnivoro*>(propio)) {
		o->consumirRec();
    }
    if (herbivoro* h = dynamic_cast<herbivoro*>(propio)) {
		h->consumirRec();
    }
	propio->setCoordenada(otro);
	m->actualizar();
	
}