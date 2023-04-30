/* Nombre: Utileria.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 10/04/2020
   Descripción: Archivo de cabecera para las funciones de utilería
*/

#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include <limits>

//*******************************************************************************************************************
/** \brief función que captura un número de forma segura
 *
 * \param mensaje El mensaje que se dará para pedir el valor a capturar
 * \param n La variable a capturar
 *
 */
template< typename Tipo>
void CapturaSegura(Tipo &n ,const char mensaje[]="");

#include "Utileria.tpp"
#endif // UTILERIA_H_INCLUDED
