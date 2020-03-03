#include "ordenamientos.h"

//ORDENAMIENTO POR BURBUJA
//------------------------------------------------------------------------
void burbuja(tEstudiante estudiantes, tLista& lista) {
	for (int i = 0; i < lista.contador; i++)
	{
		int min;
		tEstudiante aux;
		min = i;
		for (int j = i + 1; j < lista.contador; j++) {

			if (lista.elementos[j].nota < lista.elementos[min].nota) {
				min = j;
			}
		}
		aux = lista.elementos[i];
		lista.elementos[i] = lista.elementos[min];
		lista.elementos[min] = aux;
	}
}
//------------------------------------------------------------------------

//ORDENAMIENTO POR INSERCION
//------------------------------------------------------------------------
void ordenamientoInsercion(tEstudiante &estudiantes, tLista &lista) {
	int pos;
	tEstudiante aux;
	for (int i = 0; i < lista.contador; i++) {
		pos = i;
		aux = lista.elementos[i];
		while ((pos > 0) && (lista.elementos[pos - 1] > aux)) {
			lista.elementos[pos] = lista.elementos[pos - 1];
			pos--;
		}
		lista.elementos[pos] = aux;
	}
}

bool operator>(tEstudiante opIzq, tEstudiante opDer)
{
	return (opIzq.nota > opDer.nota);
}
//------------------------------------------------------------------------

//ORDENAMIENTO POR HEAPSORT
//------------------------------------------------------------------------
void heap(tEstudiante estudiantes, tLista& lista, int n, int i)
{
	int valor = i;
	int izquierdo = 2 * i + 1;
	int derecho = 2 * i + 2;

	if (izquierdo < n && lista.elementos[izquierdo] > lista.elementos[valor])
		valor = izquierdo;

	if (derecho < n && lista.elementos[derecho] > lista.elementos[valor])
		valor = derecho;

	if (valor != i)
	{
		swap(lista.elementos[i], lista.elementos[valor]);

		heap(estudiantes, lista, n, valor);
	}
}

void heapSort(tEstudiante estudiantes, tLista& lista, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heap(estudiantes, lista, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(lista.elementos[0], lista.elementos[i]);
		heap(estudiantes, lista, i, 0);
	}
}
//------------------------------------------------------------------------

//ORDENAMIENTO POR QUICKSORT
//------------------------------------------------------------------------
double mitad(tLista& lista, int pinicial, int pfinal)
{

	return lista.elementos[(pinicial + pfinal) / 2].nota;

}

void ordenar_Quicksort(tLista& lista, int pinicial, int pfinal)
{
	int i = pinicial;
	int j = pfinal;
	int temp;

	double piv = mitad(lista, pinicial, pfinal);

	do
	{
		while (lista.elementos[i].nota < piv)
		{

			i++;

		}
		while (lista.elementos[j].nota > piv)
		{

			j--;
		}

		if (i <= j)
		{
			temp = lista.elementos[i].nota;
			lista.elementos[i].nota = lista.elementos[j].nota;
			lista.elementos[j].nota = temp;

			string name = lista.elementos[i].nombreEstudiante;
			lista.elementos[i].nombreEstudiante = lista.elementos[j].nombreEstudiante;
			lista.elementos[j].nombreEstudiante = name;

			i++;
			j--;

		}


	} while (i <= j);

	if (pinicial < j)
	{

		ordenar_Quicksort(lista, pinicial, j);

	}

	if (i < pfinal)
	{

		ordenar_Quicksort(lista, i, pfinal);

	}

}
//------------------------------------------------------------------------

//ORDENAMIENTO POR MERGESORT
//------------------------------------------------------------------------
void ordenamientoMerge(tEstudiante estudiantes, tLista& lista, int inicial, int final)
{
	int mid = 0;

	if (inicial == final)
	{
		return;
	}
	else
	{
		mid = (inicial + final) / 2;

		ordenamientoMerge(estudiantes, lista, inicial, mid);

		ordenamientoMerge(estudiantes, lista, mid + 1, final);

		fusionar(estudiantes, lista, inicial, final, mid);
	}
}

void fusionar(tEstudiante estudiantes, tLista& lista, int pInicial, int pFinal, int medio)
{
	int i;
	int izquierda = pInicial;
	int derecha = medio + 1;
	int combinados = pInicial;
	tEstudiante tempA[MAX];

	while (izquierda <= medio && derecha <= pFinal)
	{
		if (lista.elementos[izquierda] < lista.elementos[derecha])
		{
			tempA[combinados++] = lista.elementos[izquierda++];
		}
		else
		{
			tempA[combinados++] = lista.elementos[derecha++];
		}
	}

	if (izquierda == medio + 1)
	{
		while (derecha <= pFinal)
		{
			tempA[combinados++] = lista.elementos[derecha++];
		}
	}
	else
	{
		while (izquierda <= pFinal)
		{
			tempA[combinados++] = lista.elementos[izquierda++];
		}
	}

	for (i = pInicial; i <= pFinal; i++)
	{
		lista.elementos[i] = tempA[i];
	}
}

bool operator<(tEstudiante opIzq, tEstudiante opDer)
{
	return (opIzq.nota < opDer.nota);
}
//------------------------------------------------------------------------

//ORDENAMIENTO POR SELECCION
//------------------------------------------------------------------------
void ordenarnotasSeleccion(tLista& lista, tEstudiante estudiantes) {
	int i, j, minimo;
	tEstudiante aux;

	for (i = 0; i < lista.contador; i++) {
		minimo = i;
		for (j = i + 1; j < lista.contador; j++) {
			if (lista.elementos[j].nota < lista.elementos[minimo].nota) {
				minimo = j;
			}
		}
		aux = lista.elementos[minimo];
		lista.elementos[minimo] = lista.elementos[i];
		lista.elementos[i] = aux;
	}
}
//------------------------------------------------------------------------
