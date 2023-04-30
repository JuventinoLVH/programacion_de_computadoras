/* Nombre: Polinomios.h
   Autor: Luis J. Velasquez Hidalgo
   Fecha: 19/04/20
   Descripción: archivo de cabecera las operaciones de polinomios
*/

#ifndef POLINOMIOS_H_INCLUDED
#define POLINOMIOS_H_INCLUDED

#include "Utileria.h"
#include <stdio.h>

//**********************************************************************************************
/** \brief Función que calcula la suma de dos polinomimos
 *
 * \param P Un polinomio
 * \param F Un polinomio
 * \param gradoP el grado del polinomio P
 * \param gradoF el grado del polinomio F
 * \param res puntero donde se guardará el arreglo con el resultado de P + F
 * \param gradoRes variable donde se guardará el grado del polinomio Res
 *
 * \exception bad_alloc No hay espacio en la memoria para el polinomio resultante
 *
 */
void SumaDosPolinomios(const double P[] ,const int gradoP ,const double F[] ,const int gradoF ,double *&res ,int &gradoRes);

//**********************************************************************************************
/** \brief Función que calcula la suma de dos polinomimos
 *
 * \param P Un polinomio
 * \param F Un polinomio
 * \param gradoP el grado del polinomio P
 * \param gradoF el grado del polinomio F
 * \param res puntero donde se guardará el arreglo con el resultado de P - F
 * \param gradoRes variable donde se guardará el grado del polinomio Res
 *
 * \exception bad_alloc No hay espacio en la memoria para el polinomio resultante
 *
 */
void RestaDosPolinomios(const double P[] ,const int gradoP ,const double F[] ,const int gradoF ,double *&res ,int &gradoRes);

//**********************************************************************************************
/** \brief Función que calcula el producto de dos polinomimos
 *
 * \param P Un polinomio
 * \param F Un polinomio
 * \param gradoP el grado del polinomio P
 * \param gradoF el grado del polinomio F
 * \param res puntero donde se guardará el arreglo con el resultado de P . F
 * \param gradoRes variable donde se guardará el grado del polinomio Res
 *
 * \exception bad_alloc No hay espacio en la memoria para el polinomio resultante
 *
 */
void MultiplicarDosPolinomios(const double P[] ,const int gradoP ,const double F[] ,const int gradoF ,double *&res ,int &gradoRes);

//**********************************************************************************************
/** \brief Función que calcula la división de dos polinomimos
 *
 * \param P Un polinomio
 * \param F Un polinomio
 * \param gradoP el grado del polinomio P
 * \param gradoF el grado del polinomio F
 * \param cos puntero donde se guardará el arreglo con el resultado de P / F
 * \param res puntero donde se guardará el Arreglo con el residuo de P / F
 * \param gradoCos variable donde se guardará el grado del polinomio cos
 * \param gradoRes variable donde se guardará el grado del polinomio res
 *
 * \exception bad_alloc No hay espacio en la memoria para el polinomio resultante
 * \exception int Se intento dividir entre 0
 */
void DividirDosPolinomios(const double P[] ,const int gradoP ,const double F[] ,const int gradoF ,
                            double *&cos ,int &gradoCos ,double *&res ,int &gradoRes );

//**********************************************************************************************
/** \brief Función que deriva el polinomio P
 *
 * \param P Un polinomio
 * \param gradoP el grado del polinomio P
 * \param res puntero donde se guardará el Arreglo con el resultado
 * \param gradoRes variable donde se guardará el grado del polinomio Res
 *
 * \exception bad_alloc No hay espacio en la memoria para el polinomio resultante
 *
 */
void DerivarP(const double P[] ,const int gradoP ,double *&res ,int &gradoRes);

//**********************************************************************************************
/** \brief Función que calcula el producto de dos polinomimos
 *
 * \param P Un polinomio
 * \param gradoP el grado del polinomio P
 * \param x valor con el que se va a evaluar al polinomio
 *
 */
double EvaluarP(const double P[] ,const int gradoP ,float x);

//**********************************************************************************************
/** \brief Función que captura un polinomio
 *
 * \param P Arreglo donde se guardará el polinomio
 * \param gradoP el grado del polinomio
 * \param mensaje Mensaje que se imprimirá al capturar un elemento del arreglo
 *
 * \exception bad_alloc El grado a declarar es muy grande o ya no hay espacio en la memoria
 *
 * \pre se recomienda que el mensaje utilice '%d' en el lugar donde va el indice del elemento a capturar
 *
 */
void CapturarP(double *&P ,const int gradoP ,const char mensaje[]="");

//**********************************************************************************************
/** \brief Función que imprime un polinomio
 *
 * \param P un polinomio
 * \param gradoP el grado del polinomio
 * \param mensaje nombre del polinomio
 *
 */
void ImprimirP(const double P[] ,const int gradoP ,const char mensaje[]="");

//**********************************************************************************************
/** \brief Función para efectuar la suma de dos polinomios
 *
 * \param P un polinomio
 * \param gradoP el grado del polinomio
 *
 */
double OperacionSuma(const double A, const double B);

//**********************************************************************************************
/** \brief Función para efectuar la resta de dos polinomios
 *
 * \param P un polinomio
 * \param gradoP el grado del polinomio
 *
 */
double OperacionResta(const double A, const double B);

#endif // POLINOMIOS_H_INCLUDED
