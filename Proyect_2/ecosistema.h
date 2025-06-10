#pragma once
#ifndef ecosistema_h
#define ecosistema_h
#include "interfaz.h"
#include "coleccionVector.h"
class ecosistema {
private:
	fabricaElementos* fabrica;
	coleccionVector<elemento*>* coleccion; // coleccion de elementos que contiene el ecosistema
	matriz* elementos; // matriz de elementos que contiene el ecosistema
	int indice; //representa el id actual del iterador
public:
	ecosistema();
	~ecosistema();

	elemento* crearElemento();
	elemento* crearElementoEspecifico(char); // si es carne o lo que sea simplemente se buca una coordenada disponible y vamonos
	bool coordenadaDisponible(coordenada c); //verifica en la matriz si un a coordenada rnadom esta disponible
    coordenada coordenadaRandom(); 
	//-------------------------------------
	void iniciarSimulacion();
	matriz* getMatriz();

	void setIndice();

	string procesarSupervivencia();
};
#endif // !1
