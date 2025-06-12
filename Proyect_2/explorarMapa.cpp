#include "explorarMapa.h"

void explorarMapa::realizarEstrategia(elemento* e, matriz* m) {

	carnivoro* c = dynamic_cast<carnivoro*>(e);
	herbivoro* h = dynamic_cast<herbivoro*>(e);
	omnivoro* o = dynamic_cast<omnivoro*>(e);

	if (c) {
		c->setCoordenada(c->siguienteMovimiento(m));
		c->masEdad();
		c->menosEnergia();
	}
	if (h) {
		h->setCoordenada(h->siguienteMovimiento(m));
		h->masEdad();
		h->menosEnergia();
	}
	if (o) {
		o->setCoordenada(o->siguienteMovimiento(m));
		o->masEdad();
		o->menosEnergia();
	}
	m->actualizar();
}