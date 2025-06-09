#include "reproduccion.h"

void reproduccion::realizarEstrategia(elemento* e, matriz* m) {
	elemento* hijo;
	coordenada cor;
	
	carnivoro* c = dynamic_cast<carnivoro*>(e);
	herbivoro* h = dynamic_cast<herbivoro*>(e);
	omnivoro* o = dynamic_cast<omnivoro*>(e);

	if (c) {
		string id = c->getId();
		int nuevoId = stoi(id.substr(1)) + 100; // cada hijo lleva el id de su padre + 100
		id = to_string(nuevoId);
		cor = m->coordenadaRandom();
		hijo = new carnivoro(c->getTipo(), id, c->getEnergia() / 2, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
	}
	if (h) {
		string id = c->getId();
		int nuevoId = stoi(id.substr(1)) + 100; // cada hijo lleva el id de su padre + 100
		id = to_string(nuevoId);
		cor = cor = m->coordenadaRandom();
		hijo = new herbivoro(h->getTipo(), id, c->getEnergia() / 2, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
	}
	if (o) {
		string id = c->getId();
		int nuevoId = stoi(id.substr(1)) + 100; // cada hijo lleva el id de su padre + 100
		id = to_string(nuevoId);
		cor = m->coordenadaRandom();
		hijo = new omnivoro(o->getTipo(), id, c->getEnergia() / 2, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
	}

}