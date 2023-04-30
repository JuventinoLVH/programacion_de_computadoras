#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include <windows.h>
#include <iostream>
#include <limits>


//*************************************************************************************************************************
/** \brief Funci�n que captura de forma segura un n�mero
 *
 * \param solicitud Mensaje de solicitud para la captura
 *
 * \return numero capturado
 */
int CapturaEntero(const char solicitud []);

//*************************************************************************************************************************
/** \brief Mueve el cursor a la posici&oacute;n indicada
 *
 * \param x Posici&oacute;n en x a la que se mueve el cursor
 * \param y Posici&oacute;n en y a la que se mueve el cursor
 *
 * \pre Las posiciones (x,y) deben ser no negativas
 */
void gotoxy(SHORT x,SHORT y);

//*************************************************************************************************************************
/** \brief Funcion que declara un arreglo en el heap
 *
 * \param n Tama�o del arreglo
 *
 * \return direcci�n del arreglo
 *
 */
int * CrearArreglo(int n);

//*************************************************************************************************************************
/** \brief Funcion que borra un arreglo en el heap
 *
 * \param Arr Direcci�n del arreglo que se v� a borrar
 *
 */
void BorrarArreglo(double *&Arr);

#endif // UTILERIA_H_INCLUDED
