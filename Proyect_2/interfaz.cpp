#include "interfaz.h"

interfaz::interfaz()
{
	this->comenzar();
}

void interfaz::generarDecoracion() {
    // Inicializar todo vacío
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            decoracion[i][j] = ' ';
        }
    }

    // Poner bastante pasto alto (^)
    int cantidadPasto = 40; // puedes ajustar este número

    for (int k = 0; k < cantidadPasto; k++) {
        int x = rand() % 15;
        int y = rand() % 15;
        decoracion[x][y] = '^';
    }
}

void interfaz::mostrarMatrizConColores(string matriz) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Opción PRO: limpiar consola al inicio (solo si quieres que siempre refresque bonito)
    // system("cls");

    int fila = 0;
    int col = 0;

    for (char c : matriz) {
        WORD fondoVerde = (2 << 4); // fondo verde (pasto base)

        if (c == 'H') {
            SetConsoleTextAttribute(hConsole, fondoVerde | 15);
            cout << "H";
        }
        else if (c == 'C') {
            SetConsoleTextAttribute(hConsole, fondoVerde | 12);
            cout << "C";
        }
        else if (c == 'O') {
            SetConsoleTextAttribute(hConsole, fondoVerde | 9);
            cout << "O";
        }
        else if (c == 'A') {
            SetConsoleTextAttribute(hConsole, fondoVerde | 11);
            cout << "A";
        }
        else if (c == 'K') {
            SetConsoleTextAttribute(hConsole, fondoVerde | 5);
            cout << "K";
        }
        else if (c == 'P') {
            SetConsoleTextAttribute(hConsole, fondoVerde | 14);
            cout << "P";
        }
        else if (c == '.') {
            // Consultar decoracion[fila][col]
            char deco = decoracion[fila][col];

            if (deco == '^') {
                // Pasto alto
                SetConsoleTextAttribute(hConsole, (2 << 4) | 10); // fondo verde, texto verde claro
                cout << "^";
            }
            else {
                // Pasto normal
                SetConsoleTextAttribute(hConsole, fondoVerde | 0);
                cout << ".";
            }
        }
        else if (c == '\n') {
            // Muy importante: resetear color ANTES de hacer endl
            SetConsoleTextAttribute(hConsole, 7);
            cout << endl;
            fila++;
            col = 0;
            continue;
        }
        else {
            // Cualquier otro carácter no esperado
            SetConsoleTextAttribute(hConsole, fondoVerde | 7);
            cout << c;
        }

        col++;
    }

    // Resetear color al final por seguridad
    SetConsoleTextAttribute(hConsole, 7);
    cout << endl;
}

void interfaz::comenzar() {
	int tick = 0;
	ecosistema* eco = new ecosistema();
	elemento* e = eco->crearElementoEspecifico('H');
	elemento* e2 = eco->crearElementoEspecifico('C');
	elemento* e3 = eco->crearElementoEspecifico('P');
	elemento* e4 = eco->crearElementoEspecifico('O');
	elemento* e5 = eco->crearElementoEspecifico('A');
	elemento* e6 = eco->crearElementoEspecifico('K');
    generarDecoracion();
	
	

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
