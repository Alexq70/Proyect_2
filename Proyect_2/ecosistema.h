#pragma once
#ifndef ecosistema_h
#define ecosistema_h
#include "interfaz.h"

class ecosistema {
private:
	fabricaElementos* fabrica;
	matriz* elementos; // matriz de elementos que contiene el ecosistema
	int indice = 0; //representa el id actual del iterador
public:
	ecosistema();
	~ecosistema();

	elemento* crearElemento();
	elemento* crearElementoEspecifico(char); // si es carne o lo que sea simplemente se buca una coordenada disponible y vamonos
	coordenada coordenadaDisponible(); //verifica en la matriz si un a coordenada rnadom esta disponible
    coordenada coordenadaRandom(); 

};
#endif // !1
