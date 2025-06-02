#include<iostream>
#include "recurso.h"
#include "agua.h"
#include "planta.h"
#include "criatura.h"
#include "herbivoro.h"
#include "carnivoro.h"
#include "omnivoro.h"
#include "coleccionVector.h"
#include "coordenada.h"
using namespace std;
int main() {
	recurso* p1 = new recurso("1", "P", coordenada(1, 2));
	recurso* p2 = new planta("2",coordenada(1,2));
	recurso* p3 = new planta("3", coordenada(1, 2));
	recurso* a1 = new agua("4", coordenada(1, 2));

	criatura* c1 = new criatura("1", "C", 100,13, coordenada(1, 2));
	criatura* c2 = new carnivoro("2", 98,34,coordenada(4,3));
    criatura* c3 = new herbivoro("3",56,33, coordenada(1, 2));
	criatura* c4 = new omnivoro("4",44,23, coordenada(1, 2));

	 
	recurso* conejillo = new recurso("5","P", coordenada(1, 2));
	coleccionVector<recurso*>* recursos = new coleccionVector<recurso*>();
	coleccionVector<criatura*>* criaturas = new coleccionVector<criatura*>();
	

	criaturas->agregarObjeto(c1);
	criaturas->agregarObjeto(c2);
	criaturas->agregarObjeto(c3);
	criaturas->agregarObjeto(c4);

	recursos->agregarObjeto(p1);
	recursos->agregarObjeto(p2);
	recursos->agregarObjeto(p3);
	recursos->agregarObjeto(a1);


	cout<<criaturas->toString();
	cout << recursos->toString();
}