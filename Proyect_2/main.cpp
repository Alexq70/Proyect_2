#include <iostream>
#include "Lista.h"
#include "Persona.h"
#include "GestorArchivos.h"
#include "Nodo.h"
using namespace std;
int menuPrincipal() {
	int op;
	system("cls");
	
	cout << "\tMenu principal" << endl;
	cout << "======================" << endl;
	cout << "1- Agregar Usuario" << endl;
	cout << "2- Buscar usuario por cedula" << endl;
	cout << "3- Eliminar usuario" << endl;
	cout << "4- Mostrar Usuarios" << endl;
	cout << "5- Guardar info usuarios" << endl;
	cout << "6- Cargar info usuarios" << endl;
	cout << "7- Salir" << endl;
	cin >> op;
	return op;
}
Persona* crearPersona() {
	string nombre, cedula;
	int edad;
	cin.ignore();

	cout << "Ingrese el nombre de la persona: ";
	getline(cin, nombre);
	//--------------------------------------
	cout << "Ingrese la cedula de la persona: ";
	getline(cin, cedula);
	//--------------------------------------
	cout << "Ingrese la edad de la persona: ";
	cin >> edad;
	//--------------------------------------
	return new Persona(nombre, cedula, edad);
}

Persona* buscarP() {
	string id;
	cout << "Ingrese el id de la persona que desea buscar: ";
	cin >> id;
	return new Persona("", id, 0); //Persona aux para buscar
}
int main() {
	Lista<Persona*>* lista = new Lista<Persona*>();
	int op;
	do {
		op = menuPrincipal();
		switch (op) {
		case 1: {
			Persona* p = crearPersona();
			if (p) {
				lista->agregarElemento(p);
				cout << "Persona agregada exitosamente\n";
			}
			else
				cout << "No se pudo agregar al pibe\n";
		} break;

		case 2: {
			if (lista->buscarElemento(buscarP()))
				cout << "Persona localizada...\n";
			else
				cout << "La persona no existe...\n";
		}break;
		case 3: {
			if (lista->eliminarElemento(buscarP()))
				cout << "Persona borrada...\n";
			else
				cout << "La persona no existe...\n";
		}break;
		case 4: {
			cout << lista->mostrarLista();
		}break;
		case 5: {                                                   // le pasamos la lista a guardar
			GestorArchivos::guardarPersonas(lista, "personas.txt"); // le ponemos nombre al archivo
		} break;

		case 6: {
			GestorArchivos::cargarPersonas(lista, "personas.txt"); // le pasamos la lista en la que vamos a recuperar los datos
		}break;

		case 7: {
			return -1;
		}break;
		default: {
			cout << "Opcion incorrecta, digite de nuevo...\n";
		}break;
		}
		system("pause");
	} while (op != 7);
	delete lista;
	return 0;
}