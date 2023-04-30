/* Nombre: Utileria.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 10/04/2020
   Descripci�n: Archivo de cabecera para las funciones de utiler�a
*/

#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include <limits>

//*******************************************************************************************************************
/** \brief funci�n que captura un n�mero de forma segura
 *
 * \param mensaje El mensaje que se dar� para pedir el valor a capturar
 * \param n La variable a capturar
 *
 */
template< typename Tipo>
void CapturaSegura(Tipo &n ,const char mensaje[]="");

#include "Utileria.tpp"
#endif // UTILERIA_H_INCLUDED
