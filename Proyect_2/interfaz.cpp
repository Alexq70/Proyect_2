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
}

{
	elemento* p2 = new planta('P', "2", coordenada(1, 2));
	elemento* p3 = new planta('P', "3", coordenada(1, 2));
	elemento* a1 = new agua('A', "4", coordenada(1, 2));

	elemento* c2 = new carnivoro('C', "2", 98, 34, coordenada(4, 3));
	elemento* c3 = new herbivoro('H', "3", 56, 33, coordenada(1, 2));
	elemento* c4 = new omnivoro('O', "4", 44, 23, coordenada(1, 2));


	coleccionVector<elemento*>* elementos = new coleccionVector<elemento*>();

	elementos->agregarObjeto(c2);
	elementos->agregarObjeto(c3);
	elementos->agregarObjeto(c4);

	elementos->agregarObjeto(p2);
	elementos->agregarObjeto(p3);
	elementos->agregarObjeto(a1);


	cout << elementos->toString();

}
