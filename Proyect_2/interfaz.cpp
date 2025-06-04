#include "interfaz.h"
#include "recurso.h"
#include "agua.h"
#include "planta.h"
#include "criatura.h"
#include "herbivoro.h"
#include "carnivoro.h"
#include "omnivoro.h"
#include "coleccionVector.h"
#include "coordenada.h"
#include "elemento.h"

interfaz::interfaz()
{
	this->mostrar();
}

void interfaz::mostrar()
{

	elemento* c2 = new carnivoro('C', "2", 98, 34, coordenada(4, 3));


	coleccionVector<elemento*>* elementos = new coleccionVector<elemento*>();

	elementos->agregarObjeto(c2);
	elementos->agregarObjeto(c3);
	elementos->agregarObjeto(c4);

	elementos->agregarObjeto(p2);
	elementos->agregarObjeto(p3);
	elementos->agregarObjeto(a1);


	cout << elementos->toString();
}
