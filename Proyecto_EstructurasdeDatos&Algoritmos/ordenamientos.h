#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include "funciones.h"

void burbuja(tEstudiante estudiantes, tLista& lista);

void ordenamientoInsercion(tEstudiante& estudiantes, tLista &lista);

void heap(tEstudiante estudiantes, tLista& lista, int n, int i);
void heapSort(tEstudiante estudiantes, tLista& lista, int n);

double mitad(tLista& lista, int pinicial, int pfinal);
void ordenar_Quicksort(tLista& lista, int pinicial, int pfinal);

void ordenamientoMerge(tEstudiante estudiantes, tLista& lista, int inicial, int final);
void fusionar(tEstudiante estudiantes, tLista& lista, int pInicial, int pFinal, int medio);

void ordenarnotasSeleccion(tLista& lista, tEstudiante estudiantes);

bool operator<(tEstudiante opIzq, tEstudiante opDer);
bool operator>(tEstudiante opIzq, tEstudiante opDer);

#endif // !ORDENAMIENTOS_H
