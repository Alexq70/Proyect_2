#include "interfaz.h"

interfaz::interfaz()
{
	this->comenzar();
}
void interfaz::mostrarMatrizConColores(string matriz) {
	string matrizStr = matriz; // obtener la matriz en string
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (char c : matrizStr) {
		// Cambiar color según el carácter
		if (c == 'H') {
			SetConsoleTextAttribute(hConsole, 10); // verde claro
		}
		else if (c == 'C') {
			SetConsoleTextAttribute(hConsole, 12); // rojo claro
		}
		else if (c == 'O') {
			SetConsoleTextAttribute(hConsole, 9); // azul claro
		}
		else if (c == 'A') {
			SetConsoleTextAttribute(hConsole, 11); // cyan claro
		}
		else if (c == 'K') {
			SetConsoleTextAttribute(hConsole, 13); // magenta claro
		}
		else if (c == 'P') {
			SetConsoleTextAttribute(hConsole, 14); // amarillo claro
		}
		else {
			SetConsoleTextAttribute(hConsole, 7); // color normal (para '.' o '\n' u otro)
		}

		// Mostrar el carácter
		cout << c;
	}

	// Al final, resetear color por seguridad
	SetConsoleTextAttribute(hConsole, 7);
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
	   
		string matriz = eco->getMatriz()->mostrarMatriz();
		mostrarMatrizConColores(matriz);

		system("pause");
	}
}
