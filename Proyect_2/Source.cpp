#include<iostream>
#include "Recurso.h"
#include "Agua.h"
#include "Planta.h"
#include "Criatura.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"
using namespace std;
int main() {
	recurso* p1 = new recurso("1", "P");
	planta* p2 = new planta("2");
	recurso* p3 = new planta("3");


	cout << p1->toString();
	cout << p2->toString();
	cout << p3->toString();

	criatura* c1 = new criatura("1","C");
	criatura* c2 = new herbivoro("2");
	criatura* c3 = new carnivoro("3");
	criatura* c4 = new omnivoro("4");

	cout << c1->toString();
	cout << c2->toString();
	cout << c3->toString();
	cout << c4->toString();


}