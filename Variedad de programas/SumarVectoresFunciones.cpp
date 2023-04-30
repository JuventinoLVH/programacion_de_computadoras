/*
Nombre: MIGG-SumarArreglos.cpp
Autor: Manuel I Gómez G
Fecha: 30/Mar/2020
Descripción: Programa para la suma de arreglos a través de funciones.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/** \brief La funci&oacute;n captura la cantidad indicada de elementos en un vector.
 *
 * \param arreglo[] Corresponde al vector donde se almacenar&aacute;n los elementos.
 * \param dimension La cantidad de elementos a capturar.
 */
void CapturarVector(float arreglo[], int dimension);

/** \brief Proceso encargado de la suma de 2 vectores.
 *
 * \param primerVector[] Corresponde al primer vector a sumar.
 * \param segundoVector[] Corresponde al segundo vector para la suma.
 * \param vectorResultante[] Es el vector donde se almacena el resultado de la suma.
 * \param dimension La cantidad de elementos de los vectores.
 */
void SumarVectores(const float primerVector[], const float segundoVector[],
					float vectorResultante[], int dimension);

/** \brief Imprime a pantalla el vector con un formato definido.
 *
 * \param arreglo[] Es el vector por mostrarse.
 * \param dimension La cantidad de elementos que posee dicho vector.
 */
void ImprimirVector(const float arreglo[], int dimension);

int main()
{
	cout << "\n El siguiente programa nos permite sumar dos vectores dados.\n" << endl;

	//Obtenemos las dimensiones del vector
	int dimension;
	cout << " Antes de comenzar, es necesario saber la dimensi\242n del vector.\n" <<
			" Indique su dimensi\242n: ";
	cin >> dimension;

	//Capturamos los datos del primero.
	float primerVector[dimension];
	cout << "\n Lo siquiente es ingresar los datos del primer vector." << endl;
	CapturarVector(primerVector, dimension);

	//Capturamos los datos del segundo.
	float segundoVector[dimension];
	cout << " Ahora, los datos del segundo vector." << endl;
    CapturarVector(segundoVector, dimension);

    //Sumamos ambos.
    float vectorResultado[dimension];
    SumarVectores(primerVector, segundoVector, vectorResultado, dimension);

	//Mostramos el resultado.
    cout << " La suma de los vectores se muestra a continuaci\242n:\n\n ";

    ImprimirVector(primerVector, dimension);
    cout << " + ";
    ImprimirVector(segundoVector, dimension);
    cout << " = ";
    ImprimirVector(vectorResultado, dimension);

    cout << "\n\n \255Hasta luego!" << endl;

    system("pause");
	return 0;
}

void ImprimirVector(const float arreglo[], int dimension)
{
	cout << '(';
	for(int i = 0; i < dimension; ++i)
		cout << arreglo[i] << ", ";

	cout << "\b\b)";

	return;
}

void CapturarVector(float arreglo[], int dimension)
{
	for(int i = 0; i < dimension; ++i){
		cout << " Ingrese el elemento " << i+1 << ": ";
		cin >> arreglo[i];	//Implementar "captura segura"
	}
	cout << endl;

	return;
}

void SumarVectores(const float primerVector[], const float segundoVector[],
					float vectorResultante[], int dimension)
{
	for(int i = 0; i < dimension; ++i)
		vectorResultante[i] = primerVector[i] + segundoVector[i];

	return;
}