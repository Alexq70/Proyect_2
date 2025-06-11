#include "gestorArchivos.h"

bool guardar(coleccionVector<elemento>* co)
{
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
                salida << c->getTipo() << DELIMITA_REGISTRO
                    << c->getId() << DELIMITA_REGISTRO
                    << c->getEnergia() << DELIMITA_REGISTRO
                    << c->getCoordenada().getX() << DELIMITA_REGISTRO
                    << c->getCoordenada().getY() << DELIMITA_REGISTRO
                    << c->getEdad() << DELIMITA_ELEMENTO;
                break;
            case'H':
                 h = dynamic_cast<herbivoro*>(e);
                salida << h->getTipo() << DELIMITA_REGISTRO
                    << h->getId() << DELIMITA_REGISTRO
                    << h->getEnergia() << DELIMITA_REGISTRO
                    << h->getCoordenada().getX() << DELIMITA_REGISTRO
                    << h->getCoordenada().getY() << DELIMITA_REGISTRO
                    << h->getEdad() << DELIMITA_ELEMENTO;
                break;
            case 'P':
                 p = dynamic_cast<planta*>(e);
                salida << p->getTipo() << DELIMITA_REGISTRO
                    << p->getId() << DELIMITA_REGISTRO
                    << p->getCoordenada().getX() << DELIMITA_REGISTRO
                    << p->getCoordenada().getY() << DELIMITA_ELEMENTO;
                break;
            case'A':
                 a = dynamic_cast<agua*>(e);
                salida << a->getTipo() << DELIMITA_REGISTRO
                    << a->getId() << DELIMITA_REGISTRO
                    << a->getCoordenada().getX() << DELIMITA_REGISTRO
                    << a->getCoordenada().getY() << DELIMITA_ELEMENTO;
                break;
            case'O':
                 o = dynamic_cast<omnivoro*>(e);
                salida << o->getTipo() << DELIMITA_REGISTRO
                    << o->getId() << DELIMITA_REGISTRO
                    << o->getEnergia() << DELIMITA_REGISTRO
                    << o->getCoordenada().getX() << DELIMITA_REGISTRO
                    << o->getCoordenada().getY() << DELIMITA_REGISTRO
                    << o->getEdad() << DELIMITA_ELEMENTO;
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

#include <sstream>

bool cargar(coleccionVector<elemento>* c)
{
    if (!entrada.is_open()) {
        cout << "Error al abrir el archivo para cargar." << endl;
        return false;
    }

    string linea;
    while (getline(entrada, linea)) {
        elemento* e = nullptr;
        int energiaI = 0;
        int xI = 0;
        int yI = 0;
        int edadI = 0;
        stringstream ss(linea);
        string tipo, id, energia, x, y, edad;

        getline(ss, tipo, DELIMITA_REGISTRO);
        char tipoC = tipo[0];
        switch (tipoC) {
        case 'C':
            getline(ss, id, DELIMITA_REGISTRO);
            getline(ss, energia, DELIMITA_REGISTRO);
            getline(ss, x, DELIMITA_REGISTRO);
            getline(ss, y, DELIMITA_REGISTRO);
            getline(ss, edad, DELIMITA_ELEMENTO);
            energiaI = stringAInt(energia);
            xI = stringAInt(x);
            yI = stringAInt(y);
            edadI = stringAInt(edad);
            e = new carnivoro(tipoC, id, energiaI, edadI, coordenada(xI, yI));
            c->agregarObjeto(*e);
            break;
        case 'H':
            getline(ss, id, DELIMITA_REGISTRO);
            getline(ss, energia, DELIMITA_REGISTRO);
            getline(ss, x, DELIMITA_REGISTRO);
            getline(ss, y, DELIMITA_REGISTRO);
            getline(ss, edad, DELIMITA_ELEMENTO);
            energiaI = stringAInt(energia);
            xI = stringAInt(x);
            yI = stringAInt(y);
            edadI = stringAInt(edad);
           e = new herbivoro(tipoC, id, energiaI, edadI, coordenada(xI, yI));
            c->agregarObjeto(*e);
            break;
        case 'P':
            getline(ss, id, DELIMITA_REGISTRO);
            getline(ss, x, DELIMITA_ELEMENTO);
            getline(ss, y, DELIMITA_REGISTRO);
            xI = stringAInt(x);
            yI = stringAInt(y);
           e = new planta(tipoC, id, coordenada(xI, yI));
            c->agregarObjeto(*e);
            break;
        case 'O':
            getline(ss, id, DELIMITA_REGISTRO);
            getline(ss, energia, DELIMITA_REGISTRO);
            getline(ss, x, DELIMITA_REGISTRO);
            getline(ss, y, DELIMITA_REGISTRO);
            getline(ss, edad, DELIMITA_ELEMENTO);
            energiaI = stringAInt(energia);
            xI = stringAInt(x);
            yI = stringAInt(y);
            edadI = stringAInt(edad);
           e = new omnivoro(tipoC, id, energiaI, edadI, coordenada(xI, yI));
            c->agregarObjeto(*e);
            break;
        case 'A':
            getline(ss, id, DELIMITA_REGISTRO);
            getline(ss, x, DELIMITA_ELEMENTO);
            getline(ss, y, DELIMITA_REGISTRO);
            xI = stringAInt(x);
            yI = stringAInt(y);
           e = new agua(tipoC, id, coordenada(xI, yI));
            c->agregarObjeto(*e);
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
