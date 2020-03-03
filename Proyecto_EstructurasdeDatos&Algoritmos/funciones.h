#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>

using namespace std;

#include <fstream>
#include <iomanip>
#include <locale.h>
#include <stdlib.h>


const int MAX = 100;

typedef struct {
	string nombreEstudiante;
	double nota;
}tEstudiante;

typedef tEstudiante tArray[MAX];

typedef struct {
	tArray elementos;
	string nombreProfesor;
	string materia;
	string cedula;
	int contador;
}tLista;

void insertarDocente(tLista& lista);
void insertarMateria(tLista& lista);
void insertarEstudiante(tEstudiante& estudiantes, tLista& lista);
void insertarNotasxEstudiante(tLista& lista);
void mostrarEstudiante(tEstudiante estudiantes);
void listado(const tLista& lista);
double promedioCurso(const tLista& lista);
int aprobados(const tLista& lista);
int reprobados(const tLista& lista);
int suspensos(const tLista& lista);
void guardarSinOrdenar(const tLista& lista);
void guardarOrdenado(const tLista& lista);

#endif // !FUNCIONES_H
