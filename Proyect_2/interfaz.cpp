#include "interfaz.h"

interfaz::interfaz()
{
	this->comenzar();
}

void interfaz::comenzar() {
	int tick = 0;
	ecosistema* eco = new ecosistema();
	

	elemento* e = eco->crearElemento();
	elemento* e2 = eco->crearElemento();
	elemento* e3 = eco->crearElemento();
	elemento* e4 = eco->crearElemento();
	elemento* e5 = eco->crearElemento();
	
	while (true) {
		system("cls");
		cout << "Bienvenido al simulador de ecosistemas.\n";
		cout << "Tick: " << tick++ << endl;
		eco->getMatriz()->actualizar();
		herbivoro* din = dynamic_cast<herbivoro*>(e);
		carnivoro* car = dynamic_cast<carnivoro*>(e);
		omnivoro* om = dynamic_cast<omnivoro*>(e);

		if(din) {
			cout << "Observando\n";
			cout << din->observarEntorno(eco->getMatriz()) << endl;
			din->cambiarEstrategia(eco->getMatriz());
			din->sobrevivir(eco->getMatriz());
		}
		if (car) {
			cout << "Observando\n";
			cout << car->observarEntorno(eco->getMatriz()) << endl;
			car->cambiarEstrategia(eco->getMatriz());
			car->sobrevivir(eco->getMatriz());
		}
		if (om) {
			cout << "Observando\n";
			cout << om->observarEntorno(eco->getMatriz()) << endl;
			om->cambiarEstrategia(eco->getMatriz());
			om->sobrevivir(eco->getMatriz());
		}

		cout << eco->getMatriz()->mostrarMatriz() << endl;
		system("pause");
	}
}
