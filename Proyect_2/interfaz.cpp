#include "interfaz.h"

interfaz::interfaz()
{
	this->comenzar();
}

void interfaz::comenzar() {
	int tick = 0;
	ecosistema* eco = new ecosistema();
	elemento* e = eco->crearElementoEspecifico('H');
	elemento* e2 = eco->crearElementoEspecifico('H');
	
	

	while (true) {
		system("cls");
		cout << "Bienvenido al simulador de ecosistemas.\n";
		cout << "Tick: " << tick++ << endl;


		eco->getMatriz()->actualizar();
		cout << e->toString();
		cout << endl;
		cout << e2->toString();
		cout << endl;

		herbivoro* din = dynamic_cast<herbivoro*>(e);
		carnivoro* car = dynamic_cast<carnivoro*>(e);
		omnivoro* om = dynamic_cast<omnivoro*>(e);

		herbivoro* din2 = dynamic_cast<herbivoro*>(e2);
		carnivoro* car2 = dynamic_cast<carnivoro*>(e2);
		omnivoro* om2 = dynamic_cast<omnivoro*>(e2);

		if (car) {
			car->sobrevivir(eco->getMatriz());
		}

		if (din) {
			din->sobrevivir(eco->getMatriz());
		}
		if (om) {
			om->sobrevivir(eco->getMatriz());
		}

		if (car2) {
			car2->sobrevivir(eco->getMatriz());
		}

		if (din2) {
			din2->sobrevivir(eco->getMatriz());
		}
		if (om2) {
			om2->sobrevivir(eco->getMatriz());
		}
	   
		cout << eco->getMatriz()->mostrarMatriz() << endl;

		system("pause");
	}
}
