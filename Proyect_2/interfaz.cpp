#include "interfaz.h"

interfaz::interfaz()
{
	this->comenzar();
}

void interfaz::comenzar() {
	ecosistema* eco = new ecosistema();
	elemento* e = eco->crearElemento();
	elemento* aux = eco->crearElementoEspecifico('H');
	elemento* aux1 = eco->crearElementoEspecifico('A');
	elemento* aux2 = eco->crearElementoEspecifico('P');
	elemento* aux3 = eco->crearElementoEspecifico('K');
	while (true) {
		system("cls");
		char tecla = ' ';
		cout << "Bienvenido al ecosistema" << endl;
		cout << "\tSIMBIOLOGIA: \n";
		cout << "a = derecha, s = abajo, d = izquierda, w = arriba\n";
		cout << "Q = diagonal derecha, E = diagonal izquierda\n";
		cout << "R = diagonal abajo derecha, F = diagonal abajo izquierda\n";
		cout << "coordenada actual: " << e->getCoordenada().toString() << endl;
		eco->getMatriz()->actualizar();
		herbivoro* din = dynamic_cast<herbivoro*>(e);
		carnivoro* car = dynamic_cast<carnivoro*>(e);
		omnivoro* om = dynamic_cast<omnivoro*>(e);
		if(din) {
			cout << "Observando\n";
			cout << din->observarEntorno(eco->getMatriz()) << endl;
		}
		else if (car) {
			cout << "Observando\n";
			cout << car->observarEntorno(eco->getMatriz()) << endl;
		}
		else if (om) {
			cout << "Observando\n";
			cout << om->observarEntorno(eco->getMatriz()) << endl;
		}
		cout << eco->getMatriz()->mostrarMatriz() << endl;

		cin >> tecla;
		switch (tecla) {
		case 'a': {
			e->getCoordenada().moverseIzquierda();
		} break;
		case 's': {
			e->getCoordenada().moverseAbajo();
		} break;
		case 'd': {
			e->getCoordenada().moverseDerecha();
		} break;
		case 'w': {
			e->getCoordenada().moverseArriba();
		} break;
		case 'q': {
			e->getCoordenada().diagonalIzquierdaArriba();
		} break;
		case 'e': {
			e->getCoordenada().diagonalDerechaArriba();
		} break;
		case 'r': {
			e->getCoordenada().diagonalDerechaAbajo();
		} break;
		case 'f': {
			e->getCoordenada().diagonalIzquierdaAbajo();
		} break;
		}
	}
}
