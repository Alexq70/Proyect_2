#pragma once
#include<iostream>
#include "iteradorVector.h"
#include "recurso.h"
#include "agua.h"
#include "planta.h"
#include "criatura.h"
#include "herbivoro.h"
#include "carnivoro.h"
#include "carne.h"
#include "omnivoro.h"
#include "coleccionVector.h"
#include "coordenada.h"
#include "elemento.h"
#include "matriz.h"
#include "fabricaRecursos.h"
#include "fabricaCriaturas.h"
#include "fabricaElementos.h"
#include "fabricaAgua.h"
#include "fabricaPlanta.h"
#include "fabricaCarne.h"
#include "fabricaHerbivoros.h"
#include "fabricaCarnivoros.h"
#include "fabricaOmnivoros.h"
#include "ecosistema.h"
#include "gestorArchivos.h"
#include "tick.h"
#include "interfazAbstracta.h"
class ecosistema;

using namespace std;
#include <iostream>
using namespace std;
class interfaz : public interfazAbstracta
{
private:
	char decoracion[15][15];
public:
	interfaz();
	void mostrarMatrizConColores(string);
	void mostrarMatrizNoche(string);
	void cambiarModoMatriz(string,string);
	void generarDecoracion();
	void comenzar();
	void iniciaPrograma(ecosistema*, tick&,int);
	void seteos(ecosistema*);
	void mostrarEncabezado(ecosistema* ,tick&);
	void mostrarGuardado(ecosistema*, tick&);
	void iniciarUpervivencia(ecosistema*);
	void cambiarHorario(ecosistema*,tick& t);
	void estadisticas(ecosistema*);
};

