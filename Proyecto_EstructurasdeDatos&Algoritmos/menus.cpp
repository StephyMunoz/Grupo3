#include "menus.h"

char menu(string cadena, char primero) {


	char segundo(55);


	while (cadena.at(0) < primero || cadena.at(0) > segundo) {
		cout << endl;
		cout << "-------------------------Menu---------------------------" << endl;
		cout << "|1| - Ingrese el nombre del docente" << endl;
		cout << "|2| - Ingrese la materia" << endl;
		cout << "|3| - Ingrese el número de estudiantes" << endl;
		cout << "|4| - Ingresar las notas por cada estudiante" << endl;
		cout << "|5| - Orden de las notas de los estudiantes" << endl;
		cout << "|6| - Buscar una calificacion" << endl;
		cout << "|7| - Mostrar lista (*Incompleta)" << endl;
		cout << "|0| - Salir" << endl;
		cout << "Opcion: ";
		cin >> cadena;
	}

	return cadena.at(0);
}

char menu1(string cadena1, char primero) {


	char segun(54);


	while (cadena1.at(0) < primero || cadena1.at(0) > segun) {
		cout << "-------------------------ORDENAMIENTO---------------------------" << endl;
		cout << "Elija la opcion para proceder con la ejecuion" << endl;
		cout << "|1| - Ordenamiento Burbuja (Bubblesort)" << endl;
		cout << "|2| - Ordenamiento por Selección" << endl;
		cout << "|3| - Ordenamiento por Inserción" << endl;
		cout << "|4| - Ordenamiento Rápido (Quicksort)" << endl;
		cout << "|5| - Ordenamiento por Mezcla (MergeSort)" << endl;
		cout << "|6| - Ordenamiento por HeapSort" << endl; // falta implementar
		cout << "|0| - Salir" << endl;
		cout << "Opcion: ";
		cin >> cadena1;
	}

	return cadena1.at(0);
}

char menu2(string cadena2, char primero) {

	char seg(51);
	while (cadena2.at(0) < primero || cadena2.at(0) > seg) {
		cout << "-------------------------BUSQUEDA---------------------------" << endl;
		cout << "Elija la opcion para proceder con la ejecuion" << endl;
		cout << "|1| - Lineal" << endl;
		cout << "|2| - Binaria (*LISTA ORDENADA)" << endl;
		cout << "|3| - Interpolacion" << endl;
		cout << "|0| - Salir" << endl;
		cout << "Opcion: ";
		cin >> cadena2;
	}

	return cadena2.at(0);
}
