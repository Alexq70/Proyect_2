#include "interfaz.h"
#include "ecosistema.h"
#include "iomanip"
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
    int fila = 0;
    int col = 0;
    int columnas = 0;

    // Contar columnas (hasta el primer '\n')
    for (char c : matriz) {
        if (c == '\n') break;
        columnas++;
    }

    // Encabezado de columnas (X)
    cout << "    "; // espacio para Y
    for (int i = 0; i < columnas; ++i) {
        cout << setw(3) << i;
    }
    cout << endl;

    // Mostrar la matriz con índice de fila (Y)
    for (char c : matriz) {
        if (col == 0 && c != '\n') {
            cout << setw(3) << fila << " ";
        }

        WORD fondoVerde = (2 << 4); // fondo verde

        if (c == 'H') SetConsoleTextAttribute(hConsole, fondoVerde | 15), cout << setw(3) << "H";
        else if (c == 'C') SetConsoleTextAttribute(hConsole, fondoVerde | 12), cout << setw(3) << "C";
        else if (c == 'O') SetConsoleTextAttribute(hConsole, fondoVerde | 9), cout << setw(3) << "O";
        else if (c == 'A') SetConsoleTextAttribute(hConsole, fondoVerde | 11), cout << setw(3) << "A";
        else if (c == 'K') SetConsoleTextAttribute(hConsole, fondoVerde | 5), cout << setw(3) << "K";
        else if (c == 'P') SetConsoleTextAttribute(hConsole, fondoVerde | 14), cout << setw(3) << "P";
        else if (c == '.') {
            char deco = decoracion[fila][col];
            if (deco == '^') SetConsoleTextAttribute(hConsole, (2 << 4) | 10), cout << setw(3) << "^";
            else SetConsoleTextAttribute(hConsole, fondoVerde | 0), cout << setw(3) << ".";
        }
        else if (c == '\n') {
            SetConsoleTextAttribute(hConsole, 7);
            cout << endl;
            fila++;
            col = 0;
            continue;
        }
        else {
            SetConsoleTextAttribute(hConsole, fondoVerde | 7);
            cout << setw(3) << c;
        }

        col++;
    }

    SetConsoleTextAttribute(hConsole, 7);
    cout << endl;
}


void interfaz::procesarEcosistema(ecosistema* eco) {
    auto ite = eco->getColoeccion()->getIterador();
    ite->first();

    while (ite->isDone()) {
            elemento * aux = ite->current();
        if (carnivoro* c = dynamic_cast<carnivoro*>(aux)) {
            if (c->getEnergia() <= 0) {
                eco->getMatriz()->eliminarElemento(c->getCoordenada().getX(), c->getCoordenada().getY());
            }
            else {
                c->sobrevivir(eco->getMatriz());
            }
        }
        if (omnivoro* o = dynamic_cast<omnivoro*>(aux)) {
            if (o->getEnergia() <= 0) {
                eco->getMatriz()->eliminarElemento(o->getCoordenada().getX(), o->getCoordenada().getY());
            }
            else {
                o->sobrevivir(eco->getMatriz());
            }
        }
        if (herbivoro* h = dynamic_cast<herbivoro*>(aux)) {
            if (h->getEnergia() <= 0) {
                eco->getMatriz()->eliminarElemento(h->getCoordenada().getX(), h->getCoordenada().getY());
            }
            else {
                h->sobrevivir(eco->getMatriz());
            }
        }
        ite->next();
    }
}
void interfaz::comenzar() {

    ecosistema* eco = new ecosistema();
    eco->iniciarSimulacion();
   
    generarDecoracion();
    system("pause");
    tick t;
    int opcion = 0;
    while (t.getTick() <= 100) {
        system("cls");
        cout << "Bienvenido al simulador de ecosistemas.\n";
        cout << "Tick: " << t.getTick() << endl;
        cout << "Simbologia: " << endl;
        cout << "C: carnivoro  H: Herbivoro  O: Onmivoro  A: Agua  P: Planta  K: carne" << endl;
        t.setTick(t.getTick()+1); 
        eco->getMatriz()->actualizar();
        cout << endl << endl;
        if (t.getTick() == 15 || t.getTick() == 25 || t.getTick() == 50 || t.getTick() == 75) {
            system("cls");
            cout << "guardar la partida actual digite 1" << endl;
            cout << "cargar la partida anterior digite 2" << endl;
            cout << "seguir la partida actual digite 3" << endl;
            cin >> opcion;
            switch (opcion) {
            case 1:
                guardar(eco->getColoeccion(),t);
                break;
            case 2:
                cargar(eco->getColoeccion(),t);
                break;
            default:
                break;
            }
            system("cls");
        }
        auto ite = eco->getColoeccion()->getIterador();
        ite->first();

        while (!ite->isDone()) {
            elemento* aux = ite->current();
            if (carnivoro* c = dynamic_cast<carnivoro*>(aux)) {
                if (c->getEnergia() <= 0) {
                    eco->getMatriz()->eliminarElemento(c->getCoordenada().getX(), c->getCoordenada().getY());
                }
                else {
                    c->sobrevivir(eco->getMatriz());
                }
            }
            if (omnivoro* o = dynamic_cast<omnivoro*>(aux)) {
                if (o->getEnergia() <= 0) {
                    eco->getMatriz()->eliminarElemento(o->getCoordenada().getX(), o->getCoordenada().getY());
                }
                else {
                    o->sobrevivir(eco->getMatriz());
                }
            }
            if (herbivoro* h = dynamic_cast<herbivoro*>(aux)) {
                if (h->getEnergia() <= 0) {
                    eco->getMatriz()->eliminarElemento(h->getCoordenada().getX(), h->getCoordenada().getY());
                }
                else {
                    h->sobrevivir(eco->getMatriz());
                }
            }
            ite->next();
        }

        string matriz = eco->getMatriz()->mostrarMatriz();
        mostrarMatrizConColores(matriz);
        cout << endl;
        cout << "estadisticas de las criaturas actuales :" << endl;
        cout << eco->getColoeccion()->toString() << endl;
        Sleep(1000);
    }
    system("cls");
    cout << "Simulacion finalizada...";
    system("pause");
    cout << "digite enter para salir " << endl;
}
