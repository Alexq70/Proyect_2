#include "depredacion.h"

void depredacion::realizarEstrategia(elemento* propio, coordenada otro, matriz* m) {
	elemento* nuevo = nullptr;
	coordenada copiada = otro;
	int x = otro.getX();
	int y = otro.getY();

	if (carnivoro* c = dynamic_cast<carnivoro*>(propio)) {
		nuevo = new carnivoro(*c);
	}
	if (herbivoro* h = dynamic_cast<herbivoro*>(propio)) {
		nuevo = new herbivoro(*h);
	}
	if (omnivoro* o = dynamic_cast<omnivoro*>(propio)) {
		nuevo = new omnivoro(*o);
	}
	nuevo->setCoordenada(otro);
	//Aqui se debe de crar una carne y mandarla a la lista a y a la matriz, algo parecido a lo de reproduccion
	m->eliminarElemento(x, y);
	m->eliminarElemento(propio->getCoordenada().getX(), propio->getCoordenada().getY());
	m->insertarElemneto(nuevo, copiada.getX(), copiada.getY());
}