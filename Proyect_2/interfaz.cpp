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

		eco->getMatriz()->actualizar();
		herbivoro* din = dynamic_cast<herbivoro*>(e);
		carnivoro* car = dynamic_cast<carnivoro*>(e);
		omnivoro* om = dynamic_cast<omnivoro*>(e);

		if(din) {
			cout << "Observando\n";
			cout << din->observarEntorno(eco->getMatriz()) << endl;
			din->cambiarEstrategia(eco->getMatriz());
		}
		else if (car) {
			cout << "Observando\n";
			cout << car->observarEntorno(eco->getMatriz()) << endl;
			car->cambiarEstrategia(eco->getMatriz());
		}
		else if (om) {
			cout << "Observando\n";
			cout << om->observarEntorno(eco->getMatriz()) << endl;
			om->cambiarEstrategia(eco->getMatriz());
		}

		cout << eco->getMatriz()->mostrarMatriz() << endl;

		cin >> tecla;
	}
}
