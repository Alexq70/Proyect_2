#include "consumirRecurso.h"

void consumirRecurso::realizarEstrategia(elemento* propio,elemento* otro, matriz* m){
	coordenada nueva = otro->getCoordenada();
	int x = nueva.getX();
	int y = nueva.getY();

	m->eliminarElemento(x,y);
	
	carnivoro* c = dynamic_cast<carnivoro*>(propio);
	herbivoro* h = dynamic_cast<herbivoro*>(propio);
	omnivoro* o = dynamic_cast<omnivoro*>(propio);

	if (c) {
		c->setCoordenada(nueva);
	}
	if (h) {
		h->setCoordenada(nueva);
	}
	if (o) {
		o->setCoordenada(nueva);
	}

	m->insertarElemneto(propio, x,y);
}