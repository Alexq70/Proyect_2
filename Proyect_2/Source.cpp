#include<iostream>
#include "Recurso.h"
#include "Agua.h"
#include "Planta.h"
#include "Criatura.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"
#include "coleccionVector.h"
using namespace std;
int main() {
	recurso* p1 = new recurso("1", "P");
	recurso* p2 = new planta("2");
	recurso* p3 = new planta("3");
	recurso* a1 = new agua("4");

	criatura* c1 = new criatura("1", "C");
	criatura* c2 = new carnivoro("2");
    criatura* c3 = new herbivoro("3");
	criatura* c4 = new omnivoro("4");



	coleccionVector<recurso*>* recursos;

	recursos->agregarObjeto(p1);
	recursos->agregarObjeto(p2);
	recursos->agregarObjeto(p3);
	recursos->agregarObjeto(a1);

	cout<<recursos->toString();



	return 0;


}