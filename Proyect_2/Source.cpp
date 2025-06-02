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
	recurso* p1 = new recurso("1", "P");
	recurso* p2 = new planta("2");
	recurso* p3 = new planta("3");
	recurso* a1 = new agua("4");

	criatura* c1 = new criatura("1", "C", 100,13);
	criatura* c2 = new carnivoro("2", 98,34);
    criatura* c3 = new herbivoro("3",56,33);
	criatura* c4 = new omnivoro("4",44,23);

	 
	recurso* conejillo = new recurso("5","P");
	coleccionVector<recurso*>* recursos = new coleccionVector<recurso*>();
	coleccionVector<criatura*>* criaturas = new coleccionVector<criatura*>();
	
	recursos->agregarObjeto(p1);
	recursos->agregarObjeto(p2);
	recursos->agregarObjeto(p3);
	recursos->agregarObjeto(a1);


	cout<<recursos->toString();

	cout << "Mostrar objeto" << endl;
	cout << recursos->mostrarObjeto(p2) << endl;
	
	cout << "Buscando objeto" << endl;
	cout<<recursos->buscarObjeto(p2);


	coordenada* c1Coord = new coordenada(1, 2);
	cout << c1Coord->toString() << endl;
}