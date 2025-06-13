#include "depredacion.h"
#include "carne.h"
void depredacion::realizarEstrategia(elemento* propio, coordenada otro, matriz* m) {
	elemento* c = nullptr;
	coordenada copiada = otro;

	coordenada car;
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


	//generar carne
	string id = propio->getId();
	string nuevoId = (id + "200"); // el id del depredador +200
	car = m->coordenadaRandom();
	c = new carne('K', nuevoId, car);
	int otroX = c->getCoordenada().getX();
	int otroY = c->getCoordenada().getY();


	m->insertarElemneto(c, otroX, otroY);
	m->actualizar();
	

}