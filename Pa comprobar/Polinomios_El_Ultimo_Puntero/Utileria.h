/* Nombre: Utileria.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 19/04/2020
   Descripción: Archivo de cabecera para las funciones de utilería
*/

#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include <limits>
#include <new>

//*******************************************************************************************************************
/** \brief función que captura un número de forma segura
 *
 * \param mensaje El mensaje que se dará para pedir el valor a capturar
 *
 */
double CapturaSegura(const char mensaje[]="");

//*******************************************************************************************************************
/** \brief función que imprime el signo de un numero
 *
 * \param n Un numero
 *
 */
void SignoN(double n);

//*******************************************************************************************************************
/** \brief función que calcula el valor absoluto de un numero con plunto flotante
 *
 * \param n Un numero
 *
 * \return El valor absoluto de n
 *
 */
double AbsD(double n);

//*******************************************************************************************************************
/** \brief función que crea un vector de variables double
 *
 * \param n el tamaño del arreglo
 *
 * \exception bad_alloc No hay espacio para el arreglo que se quiere declarar
 *
 * \return la direccion en el heap del arreglo
 *
 */
double * CrearArregloD(int n);

//*******************************************************************************************************************
/** \brief función que borra un vector de variables double
 *
 * \param n el tamaño del arreglo
 * \param Arr el arreglo que vamos a borrar
 *
 * \exception bad_alloc No hay espacio en la memoria para el polinomio
 *
 */
void BorrarArregloD(double *&Arr );


#endif // UTILERIA_H_INCLUDED
