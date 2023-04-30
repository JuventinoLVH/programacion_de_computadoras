/* Nombre: Gestion.h
   Autor: Luis J. Velasquez Hidalgo
   Fecha: 19/04/20
   Descripción: Archivo de cabecera para la gestion de operaciones con polinomios
*/

#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

#include "Polinomios.h"

//**********************************************************************************************
/** \brief Función que gestiona la suma de dos polinomimos
 *
 */
void GestionSuma();

//**********************************************************************************************
/** \brief Función que gestiona la resta de dos polinomimos
 *
 */
void GestionResta();

//**********************************************************************************************
/** \brief Función que gestiona la multiplicación de dos polinomimos
 *
 */
void GestionMultiplicacion();

//**********************************************************************************************
/** \brief Función que gestiona la división de dos polinomimos
 *
 */
void GestionDividir();

//**********************************************************************************************
/** \brief Función que gestiona la derivada de un polinomio
 *
 */
void GestionDerivar();

//**********************************************************************************************
/** \brief Función que gestiona el evaluar un polinomio
 *
 */
void GestionEvaluar();
#endif // GESTION_H_INCLUDED
