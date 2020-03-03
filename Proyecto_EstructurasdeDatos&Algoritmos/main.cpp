#include "menus.h"
#include "ordenamientos.h"
#include "busquedas.h"

int main()
{
	setlocale(LC_ALL, "Spanish");
	tEstudiante estudiantes;
	tLista lista;
	char primero(48);
	string cadena = " ";
	char aux;
	aux = menu(cadena, primero);
	while (aux != primero) {
		switch (aux)
		{
			case char(49) :

				insertarDocente(lista);

				break;
			case char(50) :

				insertarMateria(lista);

				break;
			case char(51) :

				insertarEstudiante(estudiantes, lista);

				break;
			case char(52) :
				insertarNotasxEstudiante(lista);
				guardarSinOrdenar(lista);
				listado(lista);
				break;
			case char(53) :
				{
					string cadena1 = " ";
					char aux1;
					aux1 = menu1(cadena1, primero);
					switch (aux1)
					{
						case char(49) : //OPCION 1
						{
							ofstream archivo;
							archivo.open("ordenamiento.txt");
							archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
							archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
							archivo << "Calificaciones ordenadas" << endl;
							cout << "Calificaciones ordenadas" << endl;
							burbuja(estudiantes, lista);
							cout << "ALGORITMO: Burbuja" << endl;
							archivo << "ALGORITMO: Burbuja" << endl;
							listado(lista);
							guardarOrdenado(lista);
							archivo.close();
						}
						break;
					    case char(50): //OPCION 2
						{
							ofstream archivo;
							archivo.open("ordenamiento.txt");
							archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
							archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
							archivo << "Calificaciones ordenadas" << endl;
							cout << "Calificaciones ordenadas" << endl;
							ordenarnotasSeleccion(lista, estudiantes);
							cout << "ALGORITMO: Selecciòn" << endl;
							archivo << "ALGORITMO: Selecciòn" << endl;
							listado(lista);
							guardarOrdenado(lista);
							archivo.close();
						}
						break;
					    case char(51): //OPCION 3
						{
							ofstream archivo;
							archivo.open("ordenamiento.txt");
							archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
							archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
							archivo << "Calificaciones ordenadas" << endl;
							cout << "Calificaciones ordenadas" << endl;
							ordenamientoInsercion(estudiantes, lista);
							cout << "ALGORITMO: Inserciòn" << endl;
							archivo << "ALGORITMO: Inserciòn" << endl;
							listado(lista);
							guardarOrdenado(lista);
							archivo.close();
						}
						break;
					    case char(52): //OPCION 4
						{
							ofstream archivo;
							archivo.open("ordenamiento.txt");
							archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
							archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
							archivo << "Calificaciones ordenadas" << endl;
							cout << "Calificaciones ordenadas" << endl;
							cout << "ALGORITMO: Quicksort" << endl;
							ordenar_Quicksort(lista, 0, lista.contador - 1);
							archivo << "ALGORITMO: Quicksort" << endl;
							listado(lista);
							guardarOrdenado(lista);
							archivo.close();
						}
						break;
					    case char(53) : //OPCION 5
						{
							ofstream archivo;
							archivo.open("ordenamiento.txt");
							archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
							archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
							archivo << "Calificaciones ordenadas" << endl;
							cout << "Calificaciones ordenadas" << endl;
							ordenamientoMerge(estudiantes, lista, 0, lista.contador - 1);
							cout << "ALGORITMO: MergeSort" << endl;
							archivo << "ALGORITMO: MergeSort" << endl;
							listado(lista);
							guardarOrdenado(lista);
							archivo.close();
						}
						break;
					    case char(54): //OPCION 6
						{
							ofstream archivo;
							archivo.open("ordenamiento.txt");
							archivo << setw(40) << right << "COLEGIO MEJIA" << endl;
							archivo << setw(45) << right << "REPORTE DE CALIFICACIONES" << endl;
							archivo << "Calificaciones ordenadas" << endl;
							cout << "Calificaciones ordenadas" << endl;
							heapSort(estudiantes, lista, lista.contador);
							cout << "ALGORITMO: HeapSort" << endl;
							archivo << "ALGORITMO: HeapSort" << endl;
							listado(lista);
							guardarOrdenado(lista);
							archivo.close();
						}
						break;
					}
				}
				break;
			case char(54) : // OPCION 6
				{
				    string cadena2 = " ";
					char aux2;
					aux2 = menu2(cadena2, primero);
					switch (aux2)
					{
					case char(49): //OPCION 1
						{
							busqueda_lineal(lista);
						}
						break;
					case char(50) : // OPCION 2
						{
							busquedaBinaria(estudiantes, lista);
						}
						break;
						case char(51) : // OPCION 3
						{
							interpolacion(estudiantes, lista);
						}
						break;
					}
				}
				break;
			case char(55) :
			{
				listado(lista);
			}
			break;
		}
		aux = menu(cadena, primero);
	}

	return 0;
}
