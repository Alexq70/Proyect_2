#include "gestorArchivos.h"
//-----------------------------//
bool guardar(coleccionVector<elemento>* co)
{
    ofstream salida("save.txt", ios::out);
    if (salida.is_open()) {
        carnivoro* c = nullptr;
        herbivoro* h = nullptr;
        planta* p = nullptr;
        agua* a = nullptr;
        omnivoro* o = nullptr;
        for (int i = 0; i < co->getTamano(); i++) {
            elemento* e = co->getObjeto(i);
            switch (e->getTipo()) {
            case 'C':
                 c = dynamic_cast<carnivoro*>(e);
                 salida << c->getTipo() << DELIMITA_REGISTRO;
                 salida << c->getId() << DELIMITA_REGISTRO;
                 salida << c->getEnergia() << DELIMITA_REGISTRO;
                 salida << c->getCoordenada().getX() << DELIMITA_REGISTRO;
                 salida << c->getCoordenada().getY() << DELIMITA_REGISTRO;
                 salida << c->getEdad() << DELIMITA_ELEMENTO;
                break;
            case'H':
                 h = dynamic_cast<herbivoro*>(e);
                 salida << h->getTipo() << DELIMITA_REGISTRO;
                 salida << h->getId() << DELIMITA_REGISTRO;
                 salida << h->getEnergia() << DELIMITA_REGISTRO;
                 salida << h->getCoordenada().getX() << DELIMITA_REGISTRO;
                 salida << h->getCoordenada().getY() << DELIMITA_REGISTRO;
                 salida << h->getEdad() << DELIMITA_ELEMENTO;
                break;
            case 'P':
                 p = dynamic_cast<planta*>(e);
                 salida << p->getTipo() << DELIMITA_REGISTRO;
                 salida << p->getId() << DELIMITA_REGISTRO;
                 salida << p->getCoordenada().getX() << DELIMITA_REGISTRO;
                 salida << p->getCoordenada().getY() << DELIMITA_ELEMENTO;
                break;
            case'A':
                 a = dynamic_cast<agua*>(e);
                 salida << a->getTipo() << DELIMITA_REGISTRO;
                 salida << a->getId() << DELIMITA_REGISTRO;
                 salida << a->getCoordenada().getX() << DELIMITA_REGISTRO;
                 salida << a->getCoordenada().getY() << DELIMITA_ELEMENTO;
                break;
            case'O':
                 o = dynamic_cast<omnivoro*>(e);
                 salida << o->getTipo() << DELIMITA_REGISTRO;
                 salida<< o->getId() << DELIMITA_REGISTRO;
                 salida << o->getEnergia() << DELIMITA_REGISTRO;
                 salida << o->getCoordenada().getX() << DELIMITA_REGISTRO;
                 salida << o->getCoordenada().getY() << DELIMITA_REGISTRO;
                 salida << o->getEdad() << DELIMITA_ELEMENTO;
                break;
            default:
                break;
            }
        }
	}
    else {
        cout << "Error al abrir el archivo para guardar." << endl;
        return false;
    }
    salida.close();
    return true;
    
}

bool cargar(coleccionVector<elemento>* co)
{
    ifstream entrada("save.txt");
    if (!entrada.is_open()) {
        cout << "Error al abrir el archivo para cargar." << endl;
        return false;
    }
    co->limpiarMatriz();
    string tipo, id, energia, x, y, edad;
    elemento* e = nullptr;
    int energiaI = 0;
    int xI = 0;
    int yI = 0;
    int edadI = 0;
    while (entrada.good()) {
        getline(entrada, tipo, DELIMITA_REGISTRO);
        char tipoC = tipo[0];
        switch (tipoC) {
        case 'C':
            getline(entrada, id, DELIMITA_REGISTRO);
            getline(entrada, energia, DELIMITA_REGISTRO);
            getline(entrada, x, DELIMITA_REGISTRO);
            getline(entrada, y, DELIMITA_REGISTRO);
            getline(entrada, edad, DELIMITA_ELEMENTO);
            energiaI = stringAInt(energia);
            xI = stringAInt(x);
            yI = stringAInt(y);
            edadI = stringAInt(edad);
            e = new carnivoro(tipoC, id, energiaI, edadI, coordenada(xI, yI));
            co->agregarObjeto(e);
            break;
        case 'H':
            getline(entrada, id, DELIMITA_REGISTRO);
            getline(entrada, energia, DELIMITA_REGISTRO);
            getline(entrada, x, DELIMITA_REGISTRO);
            getline(entrada, y, DELIMITA_REGISTRO);
            getline(entrada, edad, DELIMITA_ELEMENTO);
            energiaI = stringAInt(energia);
            xI = stringAInt(x);
            yI = stringAInt(y);
            edadI = stringAInt(edad);
            e = new herbivoro(tipoC, id, energiaI, edadI, coordenada(xI, yI));
            co->agregarObjeto(e);
            break;
        case 'P':
            getline(entrada, id, DELIMITA_REGISTRO);
            getline(entrada, x, DELIMITA_REGISTRO);
            getline(entrada, y, DELIMITA_ELEMENTO);
            xI = stringAInt(x);
            yI = stringAInt(y);
           e = new planta(tipoC, id, coordenada(xI, yI));
            co->agregarObjeto(e);
            break;
        case 'O':
            getline(entrada, id, DELIMITA_REGISTRO);
            getline(entrada, energia, DELIMITA_REGISTRO);
            getline(entrada, x, DELIMITA_REGISTRO);
            getline(entrada, y, DELIMITA_REGISTRO);
            getline(entrada, edad, DELIMITA_ELEMENTO);
            energiaI = stringAInt(energia);
            xI = stringAInt(x);
            yI = stringAInt(y);
            edadI = stringAInt(edad);
           e = new omnivoro(tipoC, id, energiaI, edadI, coordenada(xI, yI));
            co->agregarObjeto(e);
            break;
        case 'A':
            getline(entrada, id, DELIMITA_REGISTRO);
            getline(entrada, x, DELIMITA_REGISTRO);
            getline(entrada, y, DELIMITA_ELEMENTO);
            xI = stringAInt(x);
            yI = stringAInt(y);
           e = new agua(tipoC, id, coordenada(xI, yI));
           co->agregarObjeto(e);
            break;
        }
    }
    entrada.close();
    return true;
}


int stringAInt(const string& texto)
{
    return stoi(texto);
}
