#include "reproduccion.h"

void reproduccion::realizarEstrategia(elemento* e, matriz* m) {
	elemento* hijo;
	coordenada cor;
	
	carnivoro* c = dynamic_cast<carnivoro*>(e);
	herbivoro* h = dynamic_cast<herbivoro*>(e);
	omnivoro* o = dynamic_cast<omnivoro*>(e);

	if (c) {
		string id = c->getId();
		string nuevoId = (id+"100"); // cada hijo lleva el id de su padre + 100
		cor = m->coordenadaRandom();
		hijo = new carnivoro(c->getTipo(), id, 100, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
		c->setEnergia(50); // el padre pierde la mitad de su energia al reproducirse)
	}

	if (h) {
		string id = h->getId();
		string nuevoId = (id + "100"); // cada hijo lleva el id de su padre + 100
		cor = m->coordenadaRandom();
		hijo = new herbivoro(h->getTipo(), id, 100, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
		h->setEnergia(50); // el padre pierde la mitad de su energia al reproducirse)
	}
	if (o) {
		string id = o->getId();
		string nuevoId = (id + "100"); // cada hijo lleva el id de su padre + 100
		cor = m->coordenadaRandom();
		hijo = new omnivoro(o->getTipo(), id, 100, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
		o->setEnergia(50); // el padre pierde la mitad de su energia al reproducirse)
	}

}