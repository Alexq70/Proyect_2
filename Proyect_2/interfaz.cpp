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
    bool modoSimbologia = false; // Nuevo: indica si estamos imprimiendo simbología

    // Contar columnas (hasta el primer '\t')
    for (char c : matriz) {
        if (c == '\t') break;
        columnas++;
    }

    // Encabezado de columnas (X)
    SetConsoleTextAttribute(hConsole, 7); // Color por defecto
    cout << "    "; // espacio para Y
    for (int i = 0; i < columnas; ++i) {
        cout << setw(3) << i;
    }
    cout << endl;

    // Mostrar la matriz con índice de fila (Y)
    for (char c : matriz) {
        if (c == '\n') {
            SetConsoleTextAttribute(hConsole, 7);
            cout << endl;
            fila++;
            col = 0;
            modoSimbologia = false; // Reinicia modo simbología al cambiar de línea
            continue;
        }

        if (c == '\t') {
            SetConsoleTextAttribute(hConsole, 7); // Cambia a color por defecto
            modoSimbologia = true;
            continue; // No imprimas el tabulador
        }

        if (col == 0 && !modoSimbologia) {
            SetConsoleTextAttribute(hConsole, 7);
            cout << setw(3) << fila << " ";
        }

        if (modoSimbologia) {
            cout << c; // Imprime la simbología sin color de fondo
        }
        else {
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
            else {
                SetConsoleTextAttribute(hConsole, fondoVerde | 7);
                cout << setw(3) << c;
            }
        }

        if (!modoSimbologia) col++;
    }

    SetConsoleTextAttribute(hConsole, 7);
    cout << endl;
}


void interfaz::mostrarMatrizNoche(string matriz) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int fila = 0;
    int col = 0;
    int columnas = 0;

    // Contar columnas
    for (char c : matriz) {
        if (c == '\t') break;
        columnas++;
    }

    // Encabezado de columnas (X)
    cout << "    ";
    for (int i = 0; i < columnas; ++i) {
        cout << setw(3) << i;
    }
    cout << endl;

    for (char c : matriz) {
        if (col == 0 && c != '\n') {
            cout << setw(3) << fila << " ";
        }

        WORD fondoNoche = (0 << 4); // fondo negro
        WORD colorTexto = 7; // gris claro por defecto

        if (c == 'H') {
            SetConsoleTextAttribute(hConsole, fondoNoche | 15);
            cout << setw(3) << "Z"; // Z representa "Zzz"
        }
        else if (c == 'C') {
            SetConsoleTextAttribute(hConsole, fondoNoche | 12);
            cout << setw(3) << "Z";
        }
        else if (c == 'O') {
            SetConsoleTextAttribute(hConsole, fondoNoche | 9);
            cout << setw(3) << "Z";
        }
        else if (c == 'A') {
            SetConsoleTextAttribute(hConsole, fondoNoche | 11);
            cout << setw(3) << "A";
        }
        else if (c == 'K') {
            SetConsoleTextAttribute(hConsole, fondoNoche | 5);
            cout << setw(3) << "K";
        }
        else if (c == 'P') {
            SetConsoleTextAttribute(hConsole, fondoNoche | 14);
            cout << setw(3) << "P";
        }
        else if (c == '.') {
            char deco = decoracion[fila][col];
            if (deco == '^') {
                SetConsoleTextAttribute(hConsole, fondoNoche | 2);
                cout << setw(3) << "^";
            }
            else {
                SetConsoleTextAttribute(hConsole, fondoNoche | 0);
                cout << setw(3) << ".";
            }
        }
        else if (c == '\n') {
            SetConsoleTextAttribute(hConsole, 7);
            cout << endl;
            fila++;
            col = 0;
            continue;
        }
        else {
            SetConsoleTextAttribute(hConsole, fondoNoche | colorTexto);
            cout << setw(3) << c;
        }

        col++;
    }

    SetConsoleTextAttribute(hConsole, 7);
    cout << endl;
}



void interfaz::comenzar() {

    ecosistema* eco = new ecosistema();
    tick t;
    int switch1 = 0, seguir = 0;
    eco->iniciarSimulacion();
    eco->getMatriz()->actualizar();
    generarDecoracion();
    system("cls");
    do {
        cout << "\n--- Menu del Programa ---\n";
        cout << "1. Iniciar simulacion" << endl;
        cout << "2: Modificacion de Criaturas" << endl;
        cout << "3. salir del Programa" << endl;
        cout << "Seleccione una opcion: ";
        cin >> switch1;
        seguir = 0;
        switch (switch1) {
        case 1:
            iniciaPrograma(eco, t,seguir);
            break;
        case 2:
            seteos(eco);
            break;
        case 3:
            switch1 = 3;
            break;
        default:
            cout << "numero incorrecto" << endl;
            system("pause");
            cout << "digite enter para salir " << endl;
            break;
        }
    } while (switch1 != 3);
    system("cls");
    cout << "Simulacion finalizada...";
    system("pause");
    cout << "digite enter para salir " << endl;
}

void interfaz::iniciaPrograma(ecosistema* eco, tick& t, int seguir)
{
    int estadisticass=0;
    system("cls");
    cout << "Desea mostrar las estadisticas ?" << endl;
    cout << "1. si" << endl;
    cout << "2. no" << endl;
    cin >> estadisticass;
    while (t.getTick() <= 100 && seguir == 0) {
        mostrarEncabezado(eco, t);
        if (t.getTick() == 15 || t.getTick() == 25 || t.getTick() == 50 || t.getTick() == 75) {
            mostrarGuardado(eco, t);
            system("cls");
            cout << "\n--- Continuacion del Programa ---\n";
            cout << "1. Salir al menu" << endl;
            cout << "0. continuar" << endl;
            cout << "Seleccione una opcion: ";
            cin >> seguir;
            system("cls");
            if (seguir == 0) {
                cout << "Desea mostrar las estadisticas ?" << endl;
                cout << "1. si" << endl;
                cout << "2. no" << endl;
                cin >> estadisticass;
                system("cls");
            }
        }
        iniciarUpervivencia(eco);
        cambiarHorario(eco, t);
        switch (estadisticass) {
        case 1:
            estadisticas(eco);
            break;
        case 2:
            break;
        default:
            cout << "Numero digitado incorrecto" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}

void interfaz::seteos(ecosistema* eco)
{
    system("cls");
    int carnivoroNum = 0, herviboroNum = 0, onmivoroNum = 0, planmtaNum = 0, aguaNum = 0, carneNum = 0, x = 0, y = 0, nuevaEnergia = 0;
    string id = " ", nuevoId = " ";
    carnivoro* c = nullptr;
    herbivoro* h = nullptr;
    omnivoro* o = nullptr;
    planta* p = nullptr;
    agua* a = nullptr;
    carne* k = nullptr;
    estadisticas(eco);
    cout << endl << "Digite el id del personaje que desea modificar " << endl;
    cin >> id;
    elemento* e = eco->getColoeccion()->buscarObjetoId(id);
    if (e == nullptr) {
        system("cls");
        cout << "Id no encontrado " << endl;
        system("pause");
        cout << "Digite enter para continuar" << endl;
        system("cls");
    }
    else {
        system("cls");
        switch (e->getTipo()) {
        case 'C':
            do {
                system("cls");
                cout << "\n--- Modificar Carnivoro ---\n";
                cout << "1. Cambiar ID\n";
                cout << "2. Cambiar energia\n";
                cout << "3. Cambiar posicion\n";
                cout << "4. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> carnivoroNum;
                c = dynamic_cast<carnivoro*>(e);
                switch (carnivoroNum) {
                case 1: {
                    system("cls");
                    cout << "Nuevo ID: ";
                    cin >> nuevoId;
                    if (eco->getColoeccion()->buscarObjetoId(nuevoId)) {
                        cout << "Ese ID ya existe. Intente con otro." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        c->setId(nuevoId);
                        cout << "ID actualizado correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 2: {
                    system("cls");
                    int nuevaEnergia;
                    cout << "Nueva energia: ";
                    cin >> nuevaEnergia;
                    if (nuevaEnergia < 0 && nuevaEnergia < 101) {
                        cout << "La energia no puede ser negativa ni mas de 100." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        c->setEnergia(nuevaEnergia);
                        cout << "Energia actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 3: {
                    system("cls");
                    int x, y;
                    cout << "Nueva posicion X (0-14): ";
                    cin >> x;
                    cout << "Nueva posicion Y (0-14): ";
                    cin >> y;
                    system("cls");
                    if (x < 0 || x > 14 || y < 0 || y > 14) {
                        cout << "Posicion fuera de rango." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else if (eco->getMatriz()->verificarCoordenada(coordenada(x, y)) != nullptr) {
                        cout << "La posicion ya esta ocupada." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        c->setCoordenada(coordenada(x, y));
                        cout << "Posicion actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 4:
                    system("cls");
                    cout << "Saliendo de la modificacion." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                    break;
                default:
                    system("cls");
                    cout << "Opcion invalida." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                }
            } while (carnivoroNum != 4);
            break;
        case 'H':
            do {
                system("cls");
                cout << "\n--- Modificar Herviboro ---\n";
                cout << "1. Cambiar ID\n";
                cout << "2. Cambiar energia\n";
                cout << "3. Cambiar posicion\n";
                cout << "4. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> carnivoroNum;
                system("cls");
                h = dynamic_cast<herbivoro*>(e);
                switch (herviboroNum) {
                case 1: {
                    system("cls");
                    cout << "Nuevo ID: ";
                    cin >> nuevoId;
                    if (eco->getColoeccion()->buscarObjetoId(nuevoId)) {
                        cout << "Ese ID ya existe. Intente con otro." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        h->setId(nuevoId);
                        cout << "ID actualizado correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 2: {
                    system("cls");
                    int nuevaEnergia;
                    cout << "Nueva energia: ";
                    cin >> nuevaEnergia;
                    if (nuevaEnergia < 0 && nuevaEnergia < 101) {
                        cout << "La energia no puede ser negativa ni mas de 100." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        h->setEnergia(nuevaEnergia);
                        cout << "Energia actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 3: {
                    system("cls");
                    int x, y;
                    cout << "Nueva posicion X (0-14): ";
                    cin >> x;
                    cout << "Nueva posicion Y (0-14): ";
                    cin >> y;
                    system("cls");
                    if (x < 0 || x > 14 || y < 0 || y > 14) {
                        cout << "Posicion fuera de rango." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else if (eco->getMatriz()->verificarCoordenada(coordenada(x, y)) != nullptr) {
                        cout << "La posicion ya esta ocupada." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        h->setCoordenada(coordenada(x, y));
                        cout << "Posicion actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 4:
                    system("cls");
                    cout << "Saliendo de la modificacion." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                }
                break;
            } while (herviboroNum != 4);
        case 'O':
            do {
                system("cls");
                cout << "\n--- Modificar Omnivoro ---\n";
                cout << "1. Cambiar ID\n";
                cout << "2. Cambiar energia\n";
                cout << "3. Cambiar posicion\n";
                cout << "4. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> carnivoroNum;
                o = dynamic_cast<omnivoro*>(e);
                system("cls");
                switch (carnivoroNum) {
                case 1: {
                    system("cls");
                    cout << "Nuevo ID: ";
                    cin >> nuevoId;
                    if (eco->getColoeccion()->buscarObjetoId(nuevoId)) {
                        cout << "Ese ID ya existe. Intente con otro." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        o->setId(nuevoId);
                        cout << "ID actualizado correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 2: {
                    system("cls");
                    int nuevaEnergia;
                    cout << "Nueva energia: ";
                    cin >> nuevaEnergia;
                    if (nuevaEnergia < 0 && nuevaEnergia < 101) {
                        cout << "La energia no puede ser negativa ni mas de 100." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        o->setEnergia(nuevaEnergia);
                        cout << "Energia actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 3: {
                    system("cls");
                    int x, y;
                    cout << "Nueva posicion X (0-14): ";
                    cin >> x;
                    cout << "Nueva posicion Y (0-14): ";
                    cin >> y;
                    system("cls");
                    if (x < 0 || x > 14 || y < 0 || y > 14) {
                        cout << "Posicion fuera de rango." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else if (eco->getMatriz()->verificarCoordenada(coordenada(x, y)) != nullptr) {
                        cout << "La posicion ya esta ocupada." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        o->setCoordenada(coordenada(x, y));
                        cout << "Posicion actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 4:
                    system("cls");
                    cout << "Saliendo de la modificacion." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                }
                break;
            } while (onmivoroNum != 4);
        case 'P':
            do {
                system("cls");
                cout << "\n--- Modificar Planta ---\n";
                cout << "1. Cambiar ID\n";
                cout << "2. Cambiar posicion\n";
                cout << "3. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> carnivoroNum;
                p = dynamic_cast<planta*>(e);
                system("cls");
                switch (carnivoroNum) {
                case 1: {
                    system("cls");
                    cout << "Nuevo ID: ";
                    cin >> nuevoId;
                    if (eco->getColoeccion()->buscarObjetoId(nuevoId)) {
                        cout << "Ese ID ya existe. Intente con otro." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        p->setId(nuevoId);
                        cout << "ID actualizado correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 2: {
                    system("cls");
                    int x, y;
                    cout << "Nueva posicion X (0-14): ";
                    cin >> x;
                    cout << "Nueva posicion Y (0-14): ";
                    cin >> y;
                    system("cls");
                    if (x < 0 || x > 14 || y < 0 || y > 14) {
                        cout << "Posicion fuera de rango." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else if (eco->getMatriz()->verificarCoordenada(coordenada(x, y)) != nullptr) {
                        cout << "La posicion ya esta ocupada." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        p->setCoordenada(coordenada(x, y));
                        cout << "Posicion actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 3:
                    system("cls");
                    cout << "Saliendo de la modificacion." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                }
                break;
            } while (planmtaNum != 4);
        case 'A':
            do {
                system("cls");
                cout << "\n--- Modificar Agua ---\n";
                cout << "1. Cambiar ID\n";
                cout << "2. Cambiar posicion\n";
                cout << "3. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> carnivoroNum;
                a = dynamic_cast<agua*>(e);
                system("cls");
                switch (carnivoroNum) {
                case 1: {
                    system("cls");
                    cout << "Nuevo ID: ";
                    cin >> nuevoId;
                    if (eco->getColoeccion()->buscarObjetoId(nuevoId)) {
                        cout << "Ese ID ya existe. Intente con otro." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        a->setId(nuevoId);
                        cout << "ID actualizado correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 2: {
                    system("cls");
                    int x, y;
                    cout << "Nueva posicion X (0-14): ";
                    cin >> x;
                    cout << "Nueva posicion Y (0-14): ";
                    cin >> y;
                    system("cls");
                    if (x < 0 || x > 14 || y < 0 || y > 14) {
                        cout << "Posicion fuera de rango." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else if (eco->getMatriz()->verificarCoordenada(coordenada(x, y)) != nullptr) {
                        cout << "La posicion ya esta ocupada." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        a->setCoordenada(coordenada(x, y));
                        cout << "Posicion actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 3:
                    system("cls");
                    cout << "Saliendo de la modificacion." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                }
                break;
            } while (aguaNum != 4);
        case 'K':
            do {
                system("cls");
                cout << "\n--- Modificar Carne ---\n";
                cout << "1. Cambiar ID\n";
                cout << "2. Cambiar posicion\n";
                cout << "3. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> carnivoroNum;
                system("cls");
                k = dynamic_cast<carne*>(e);
                switch (carnivoroNum) {
                case 1: {
                    system("cls");
                    cout << "Nuevo ID: ";
                    cin >> nuevoId;
                    if (eco->getColoeccion()->buscarObjetoId(nuevoId)) {
                        cout << "Ese ID ya existe. Intente con otro." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        k->setId(nuevoId);
                        cout << "ID actualizado correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 2: {
                    system("cls");
                    int x, y;
                    cout << "Nueva posicion X (0-14): ";
                    cin >> x;
                    cout << "Nueva posicion Y (0-14): ";
                    cin >> y;
                    system("cls");
                    if (x < 0 || x > 14 || y < 0 || y > 14) {
                        cout << "Posicion fuera de rango." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else if (eco->getMatriz()->verificarCoordenada(coordenada(x, y)) != nullptr) {
                        cout << "La posicion ya esta ocupada." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    else {
                        k->setCoordenada(coordenada(x, y));
                        cout << "Posicion actualizada correctamente." << endl;
                        system("pause");
                        cout << "Digite enter para continuar" << endl;
                    }
                    break;
                }
                case 3:
                    system("cls");
                    cout << "Saliendo de la modificacion." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
                    system("pause");
                    cout << "Digite enter para continuar" << endl;
                }
                break;
        default:
            break;
            } while (carneNum != 4);
        }
    }
}

void interfaz::mostrarEncabezado(ecosistema* eco, tick& t)
{
    system("cls");
    cout << "Bienvenido al simulador de ecosistemas.\n";
    cout << "Horario: "; (eco->getHorario() == "dia") ? cout << "Diurno\n" : cout << "Nocturno\n";
    cout << "Tick: " << t.getTick() + 1 << endl;
    t.setTick(t.getTick() + 1);
    eco->getMatriz()->actualizar();
    cout << endl << endl;
}

void interfaz::iniciarUpervivencia(ecosistema* eco)
{
    auto ite = eco->getColoeccion()->getIterador();
    ite->first();
    while (!ite->isDone()) {
        elemento* aux = ite->current();
        if (carnivoro* c = dynamic_cast<carnivoro*>(aux)) {
            if (c->getEnergia() <= 0) {
                eco->getMatriz()->eliminarElemento(c->getCoordenada().getX(), c->getCoordenada().getY());
            }
            else {
                c->sobrevivir(eco->getMatriz(), eco->getHorario());
            }
        }
        if (omnivoro* o = dynamic_cast<omnivoro*>(aux)) {
            if (o->getEnergia() <= 0) {
                eco->getMatriz()->eliminarElemento(o->getCoordenada().getX(), o->getCoordenada().getY());
            }
            else {
                o->sobrevivir(eco->getMatriz(), eco->getHorario());
            }
        }
        if (herbivoro* h = dynamic_cast<herbivoro*>(aux)) {
            if (h->getEnergia() <= 0) {
                eco->getMatriz()->eliminarElemento(h->getCoordenada().getX(), h->getCoordenada().getY());
            }
            else {
                h->sobrevivir(eco->getMatriz(), eco->getHorario());
            }
        }

        ite->next();
    }
}

void interfaz::cambiarHorario(ecosistema* eco, tick& t)
{
    string matriz = eco->getMatriz()->mostrarMatriz();
    if (t.getTick() % 5 == 0) {
        eco->setHorario();
    }
    (eco->getHorario() == "noche") ? mostrarMatrizNoche(matriz) : mostrarMatrizConColores(matriz);
}

void interfaz::estadisticas(ecosistema* eco)
{
    cout << endl;
    cout << "estadisticas de las criaturas actuales :" << endl;
    cout << eco->getColoeccion()->toString() << endl;
}

void interfaz::mostrarGuardado(ecosistema* eco,tick& t)
{
    int opcion = 0;
        system("cls");
        cout << "guardar la partida actual digite 1" << endl;
        cout << "cargar la partida anterior digite 2" << endl;
        cout << "seguir la partida actual sin guardar digite 3" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            guardar(eco->getColoeccion(), t);
            break;
        case 2:
            cargar(eco->getColoeccion(), t);
            break;
        case 3:
            system("cls");
            break;
        default:
            cout << "digite enter para salir " << endl;
            system("pause");
            break;
        }
    
}
