#include "busquedas.h"

//BUSQUEDA LINEAL
//------------------------------------------------------------------------
void busqueda_lineal(tLista& lista)
{
	bool c;
	c = false;
	double nota;
	cout << " Ingrese la nota que desea buscar: ";
	cin >> nota;
	ofstream archivo;
	archivo.open("busqueda.txt");
	archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
	archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
	cout << setw(40) << right << "COLEGIO MEJIA" << endl;
	cout << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
	archivo << "Búsqueda de calificaciones" << endl;
	cout << "Búsqueda de calificaciones" << endl;
	cout << "ALGORITMO: Lineal" << endl;
	archivo << "ALGORITMO: Lineal" << endl;
	for (int i = 0; i < lista.contador; i++)
	{
		if (lista.elementos[i].nota == nota)
		{
			cout << " Nota encontrada" << endl;
			cout << " En la posición: " << i + 1 << endl;
			archivo << " Nota encontrada" << endl;
			archivo << " En la posición: " << i + 1 << endl;
			cout << " La calificación a buscar fué: " << nota << endl;
			cout << " Corresponde al estudiante " << lista.elementos[i].nombreEstudiante;
			archivo << " La calificación a buscar fué: " << nota << endl;
			archivo << " Corresponde al estudiante: " << lista.elementos[i].nombreEstudiante;
			c = true;
		}

	}
	if (c == false)
	{
		cout << " Nota no encontrada";
		archivo << " Nota no encontrada";

	}
	cout << endl << endl;
	archivo << endl << endl;
	cout << setw(50) << right << "---------------------------" << endl;
	cout << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	cout << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
	archivo << setw(50) << right << "---------------------------" << endl;
	archivo << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	archivo << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
	archivo << endl;
	archivo.close();
}
//------------------------------------------------------------------------

//BUSQUEDA BINARIA
//------------------------------------------------------------------------
void busquedaBinaria(tEstudiante estudiantes, tLista& lista)
{
	int inicio = 0;
	int fin = lista.contador - 1;
	int medio;
	double notaBuscada;
	cout << "Ingrese la nota que desea buscar: ";
	cin >> notaBuscada;
	ofstream archivo;
	archivo.open("busqueda.txt");
	archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
	archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
	cout << setw(40) << right << "COLEGIO MEJIA" << endl;
	cout << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
	archivo << "Búsqueda de calificaciones" << endl;
	cout << "Búsqueda de calificaciones" << endl;
	cout << "ALGORITMO: Binaria" << endl;
	archivo << "ALGORITMO: Binaria" << endl;
	do
	{
		medio = (inicio + fin) / 2;
		if (lista.elementos[medio].nota <= notaBuscada)
		{
			inicio = medio + 1;
		}
		if (lista.elementos[medio].nota >= notaBuscada)
		{
			fin = medio - 1;
		}
	} while (inicio <= fin);
	if (lista.elementos[medio].nota == notaBuscada)
	{
		cout << " Nota encontrada" << endl;
		cout << " En la posición: " << medio + 1 << endl;
		archivo << " Nota encontrada" << endl;
		archivo << " En la posición: " << medio + 1 << endl;
		cout << " La calificación a buscar fué: " << notaBuscada << endl;
		cout << " Corresponde al estudiante " << lista.elementos[medio].nombreEstudiante;
		archivo << " La calificación a buscar fué: " << notaBuscada << endl;
		archivo << " Corresponde al estudiante: " << lista.elementos[medio].nombreEstudiante;
	}
	else
	{
		cout << " Nota no encontrada";
		archivo << " Nota no encontrada";
	}
	cout << endl << endl;
	archivo << endl << endl;
	cout << setw(50) << right << "---------------------------" << endl;
	cout << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	cout << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
	archivo << setw(50) << right << "---------------------------" << endl;
	archivo << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	archivo << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
	cout << endl;
	archivo << endl;
	archivo.close();
}
//------------------------------------------------------------------------

// BUSQUEDA INTERPOLACION
//------------------------------------------------------------------------
void interpolacion(tEstudiante estudiantes, tLista& lista) {
	ofstream archivo;
	archivo.open("busqueda.txt");
	int primero = 0;
	int ultimo = lista.contador - 1;
	int medio;
	int cont = 0;
	double buscado;

	cout << "Ingrese la nota que desea buscar: ";
	cin >> buscado;
	archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
	archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
	cout << setw(40) << right << "COLEGIO MEJIA" << endl;
	cout << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
	archivo << "Búsqueda de calificaciones" << endl;
	cout << "Búsqueda de calificaciones" << endl;
	cout << "ALGORITMO: Interpolación" << endl;
	archivo << "ALGORITMO: Interpolación" << endl;
	while ((lista.elementos[primero].nota != buscado) && (cont <= lista.contador)) {
		medio = primero + ((buscado - lista.elementos[primero].nota) * (ultimo - primero)) / (lista.elementos[ultimo].nota - lista.elementos[primero].nota);
		if (lista.elementos[medio].nota < buscado) {
			primero = medio + 1;
		}
		else if (lista.elementos[medio].nota > buscado) {
			ultimo = medio - 1;
		}
		else {
			primero = medio;
		}
		cont++;
	}
	if (lista.elementos[primero].nota == buscado) {
		cout << " Nota encontrada" << endl;
		cout << " En la posición: " << primero + 1 << endl;
		archivo << " Nota encontrada" << endl;
		archivo << " En la posición: " << primero + 1 << endl;
		cout << " La calificación a buscar fué: " << buscado << endl;
		cout << " Corresponde al estudiante "<< lista.elementos[primero].nombreEstudiante;
		archivo << " La calificación a buscar fué: " << buscado << endl;
		archivo << " Corresponde al estudiante: " << lista.elementos[primero].nombreEstudiante;
	}
	else {
		cout << " Nota no encontrada";
		archivo << " Nota no encontrada";
	}
	cout << endl << endl;
	archivo << endl << endl;
	cout << setw(50) << right << "---------------------------" << endl;
	cout << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	cout << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
	archivo << setw(50) << right << "---------------------------" << endl;
	archivo << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	archivo << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
	cout << endl;
	archivo << endl;
	archivo.close();
}
//------------------------------------------------------------------------
