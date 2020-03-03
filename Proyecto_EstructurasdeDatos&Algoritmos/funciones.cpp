#include "funciones.h"

void insertarDocente(tLista& lista)
{
	char cero(48);
	cout << "Ingrese el nombre del profesor: ";
	cin.ignore();
	getline(cin, lista.nombreProfesor, '\n');
	do{
		cout << "Ingrese el numero de cédula: ";
		getline(cin, lista.cedula);
	} while (lista.cedula.at(0) < cero);
}

void insertarMateria(tLista& lista)
{
	cout << "Ingrese la materia: ";
	cin.ignore();
	getline(cin, lista.materia, '\n');
}

void insertarEstudiante(tEstudiante& estudiantes, tLista& lista)
{
	int max;
	int cont = 0;
	lista.contador = 0;
	cout << "Ingrese el numero de estudiantes: ";
	cin >> max;
	cin.ignore();
	cout << "Ingrese el " << cont + 1 << "°" << " estudiante (\"SALIR\"): ";
	getline(cin, estudiantes.nombreEstudiante);
	while (lista.contador < MAX && estudiantes.nombreEstudiante != "SALIR" && lista.contador < max) {
		estudiantes.nota = -1; // Sin calificar de momento
		lista.elementos[lista.contador] = estudiantes;
		// Insertamos al final
		lista.contador++;
		cont++;
		if (lista.contador < max) {
			cout << "Ingrese el " << cont + 1 << "°" << " estudiante (\"SALIR\"): ";
			getline(cin, estudiantes.nombreEstudiante);
		}
	}
}

void insertarNotasxEstudiante(tLista& lista)
{
	for (int i = 0; i < lista.contador; i++) {
		cout << "Estudiante " << lista.elementos[i].nombreEstudiante << endl;
		do {
			cout << "Ingrese la nota (0-20): ";
			cin >> lista.elementos[i].nota;
			if (lista.elementos[i].nota < 0) {
				cout << "No se puede ingresar notas negativas " << endl;
			}
			if (lista.elementos[i].nota > 20) {
				cout << "No se admite una nota mayor a 20 " << endl;
			}
		} while (lista.elementos[i].nota < 0 || lista.elementos[i].nota > 20);
		cout << endl;
	}
}

void mostrarEstudiante(tEstudiante estudiante)
{
	cout << setw(20) << left << estudiante.nombreEstudiante << " ";
	cout << setw(40) << left << estudiante.nota << " ";
}

void listado(const tLista& lista)
{
	cout << setw(40) << right << "COLEGIO MEJIA" << endl;
	cout << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
	cout << "Materia: " << lista.materia << endl;
	cout << setw(20) << left << " #" << setw(20) << left << "Estudiante" << setw(20) << left << "Calificación" << endl;
	for (int i = 0; i < lista.contador; i++)
	{
		cout << " " << setw(20) << left << i + 1;
		mostrarEstudiante(lista.elementos[i]);
		cout << endl;
	}
	cout << endl;
	cout << "RESUMEN " << endl;
	cout << "Promedio del curso " << setw(40) << right << fixed << setprecision(2) << promedioCurso(lista) << endl;
	cout << setw(10) << right << "Total" << setw(40) << right << "Aprobados (14-20)" << setw(9) << right << aprobados(lista) << endl;
	cout << setw(49) << right << "Suspensos (9-13)" << setw(10) << right << suspensos(lista) << endl;
	cout << setw(49) << right << "Reprobados (0-8)" << setw(10) << right << reprobados(lista) << endl;
	cout << endl << endl;
	cout << setw(50) << right << "---------------------------" << endl;
	cout << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	cout << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
}

double promedioCurso(const tLista& lista)
{
	double total = 0;
	for (int i = 0; i < lista.contador; i++) {
		total = total + lista.elementos[i].nota;
	}
	return  total / lista.contador;
}

int aprobados(const tLista& lista)
{
	int apro = 0;
	for (int i = 0; i < lista.contador; i++) {
		if (lista.elementos[i].nota >= 14 && lista.elementos[i].nota <= 20) {
			apro++;
		}
	}
	return apro;
}

int reprobados(const tLista& lista) {
	int repro = 0;
	for (int i = 0; i < lista.contador; i++) {
		if (lista.elementos[i].nota >= 0 && lista.elementos[i].nota < 9) {
			repro++;
		}
	}
	return repro;
}

int suspensos(const tLista& lista) {
	int susp = 0;
	for (int i = 0; i < lista.contador; i++) {
		if (lista.elementos[i].nota >= 9 && lista.elementos[i].nota < 14) {
			susp++;
		}
	}
	return susp;
}

void guardarSinOrdenar(const tLista& lista)
{
	ofstream archivo;
	archivo.open("calificaciones.txt");
	archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
	archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
	archivo << "Materia: " << lista.materia << endl;
	archivo << setw(20) << left << " #" << setw(20) << left << "Estudiante" << setw(20) << left << "Calificación" << endl;
	for (int i = 0; i < lista.contador; i++)
	{
		archivo << " " << setw(20) << left << i + 1;
		archivo << setw(20) << left << lista.elementos[i].nombreEstudiante << " ";
		archivo << setw(40) << left << lista.elementos[i].nota << " ";
		archivo << endl;
	}
	archivo << endl;
	archivo << "RESUMEN " << endl;
	archivo << "Promedio del curso " << setw(40) << right << fixed << setprecision(2) << promedioCurso(lista) << endl;
	archivo << setw(10) << right << "Total" << setw(40) << right << "Aprobados (14-20)" << setw(9) << right << aprobados(lista) << endl;
	archivo << setw(49) << right << "Suspensos (9-13)" << setw(10) << right << suspensos(lista) << endl;
	archivo << setw(49) << right << "Reprobados (0-8)" << setw(10) << right << reprobados(lista) << endl;
	archivo << endl << endl;
	archivo << setw(50) << right << "---------------------------" << endl;
	archivo << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	archivo << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
	archivo.close();
}

void guardarOrdenado(const tLista& lista)
{
	ofstream archivo;
	archivo.open("ordenamiento.txt", ios::app);
	archivo << "Materia: " << lista.materia << endl;
	archivo << setw(20) << left << " N°" << setw(20) << left << "Estudiante" << setw(20) << left << "Calificación" << endl;
	for (int i = 0; i < lista.contador; i++)
	{
		archivo << " " << setw(20) << left << i + 1;
		archivo << setw(20) << left << lista.elementos[i].nombreEstudiante << " ";
		archivo << setw(40) << left << lista.elementos[i].nota << " ";
		archivo << endl;
	}
	archivo << endl;
	archivo << "RESUMEN " << endl;
	archivo << "Promedio del curso " << setw(40) << right << fixed << setprecision(2) << promedioCurso(lista) << endl;
	archivo << setw(10) << right << "Total" << setw(40) << right << "Aprobados (14-20)" << setw(9) << right << aprobados(lista) << endl;
	archivo << setw(49) << right << "Suspensos (9-13)" << setw(10) << right << suspensos(lista) << endl;
	archivo << setw(49) << right << "Reprobados (0-8)" << setw(10) << right << reprobados(lista) << endl;
	archivo << endl << endl;
	archivo << setw(50) << right << "---------------------------" << endl;
	archivo << setw(35) << "Docente: " << setw(40) << left << lista.nombreProfesor << endl;
	archivo << setw(34) << right << "Cédula: " << setw(42) << left << lista.cedula << endl;
	archivo.close();
}
