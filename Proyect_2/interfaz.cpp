#include "interfaz.h"

interfaz::interfaz()
{
	this->comenzar();
}

void interfaz::comenzar()
{
	ecosistema* eco = new ecosistema();
	for (int i = 0; i < 2; i++) {
		eco->crearElementoEspecifico('A');
		eco->crearElementoEspecifico('P');
		eco->crearElementoEspecifico('C');
		eco->crearElementoEspecifico('H');
		eco->crearElementoEspecifico('O');
	}
	for (int i = 0; i < 5; i++) {
		eco->crearElemento();
	}
	cout << eco->getMatriz()->mostrarMatriz() << endl;
	
}
