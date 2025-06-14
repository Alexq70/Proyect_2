#include "reproduccion.h"

void reproduccion::realizarEstrategia(elemento* e, matriz* m) {
	elemento* hijo;
	coordenada cor;
	

	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(100,200);



	int id = dis(gen);
	carnivoro* c = dynamic_cast<carnivoro*>(e);
	herbivoro* h = dynamic_cast<herbivoro*>(e);
	omnivoro* o = dynamic_cast<omnivoro*>(e);

	if (c) {

		string nuevoId = to_string(id); // secrean del 100 en adelante
		cor = m->coordenadaRandom();
		hijo = new carnivoro(c->getTipo(), nuevoId, 100, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
		c->setEnergia(50); // el padre pierde la mitad de su energia al reproducirse)
	}

	if (h) {
		string nuevoId = to_string(id); // secrean del 100 en adelante
		cor = m->coordenadaRandom();
		hijo = new herbivoro(h->getTipo(), nuevoId, 100, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
		h->setEnergia(50); // el padre pierde la mitad de su energia al reproducirse)
	}
	if (o) {
		string nuevoId = to_string(id); // secrean del 100 en adelante
		cor = m->coordenadaRandom();
		hijo = new omnivoro(o->getTipo(), nuevoId, 100, 0, cor);
		int x = hijo->getCoordenada().getX();
		int y = hijo->getCoordenada().getY();
		m->insertarElemneto(hijo, x, y);
		o->setEnergia(50); // el padre pierde la mitad de su energia al reproducirse)
	}
	m->actualizar();
}