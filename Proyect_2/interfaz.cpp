#include "interfaz.h"
#include "windows.h"

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
    elemento* e1 = eco->crearElementoEspecifico('C');
    for (int i = 0; i < 15; i++) {
        eco->crearElemento();
    }

    generarDecoracion();

    while (tick<=1000
        
        ) {
        system("cls");
        cout << "Bienvenido al simulador de ecosistemas.\n";
        cout << "Tick: " << tick++ << endl;
        eco->getMatriz()->actualizar();
        cout << endl << endl;

        if (carnivoro* c = dynamic_cast<carnivoro*>(e1)) {
            c->sobrevivir(eco->getMatriz());
        }
        string matriz = eco->getMatriz()->mostrarMatriz();
        mostrarMatrizConColores(matriz);
        Sleep(1000);
    }
}
