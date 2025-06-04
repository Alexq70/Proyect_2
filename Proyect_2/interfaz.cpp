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
	this->comenzar();
}

void interfaz::comenzar()
{
	elemento* p2 = new planta('P', "2", coordenada(6,10));
	elemento* p3 = new planta('P', "3", coordenada(4,8));
	elemento* a1 = new agua('A', "4", coordenada(8,12));

	elemento* c2 = new carnivoro('C', "2", 98, 34, coordenada(4, 3));
	elemento* c3 = new herbivoro('H', "3", 56, 33, coordenada(7, 14));
	elemento* c4 = new omnivoro('O', "4", 44, 23, coordenada(1, 3));


	coleccionVector<elemento*>* elementos = new coleccionVector<elemento*>();

	elementos->agregarObjeto(c2);
	elementos->agregarObjeto(c3);
	elementos->agregarObjeto(c4);

	elementos->agregarObjeto(p2);
	elementos->agregarObjeto(p3);
	elementos->agregarObjeto(a1);
	matriz* m = new matriz(elementos->getIterador());
	cout<<m->mostrarMatriz()<<endl<<endl;
	//cout << elementos->toString();
}
