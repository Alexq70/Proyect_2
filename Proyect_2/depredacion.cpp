#include "depredacion.h"

void depredacion::realizarEstrategia(elemento* propio, coordenada otro, matriz* m) {
	
	coordenada copiada = otro;
	int x = otro.getX();
	int y = otro.getY();


	m->eliminarElemento(x, y);
	propio->setCoordenada(otro);
	//Aqui se debe de crar una carne y mandarla a la lista a y a la matriz, algo parecido a lo de reproduccion
	
}