#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include <windows.h>
#include <iostream>
#include <limits>


//*************************************************************************************************************************
/** \brief Función que captura de forma segura un número
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
 * \param n Tamaño del arreglo
 *
 * \return dirección del arreglo
 *
 */
int * CrearArreglo(int n);

//*************************************************************************************************************************
/** \brief Funcion que borra un arreglo en el heap
 *
 * \param Arr Dirección del arreglo que se vá a borrar
 *
 */
void BorrarArreglo(double *&Arr);

#endif // UTILERIA_H_INCLUDED
