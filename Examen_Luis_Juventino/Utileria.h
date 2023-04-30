/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include <windows.h>
#include <iostream>

//*******************************************************************************************************************
/** \brief función que crea un vector de variables booleanas
 *
 * \param n el tamaño del arreglo
 *
 * \exception bad_alloc No hay espacio para el arreglo que se quiere declarar
 *
 * \return la direccion en el heap del arreglo
 *
 */
bool * CrearArregloB(int n);

//*******************************************************************************************************************
/** \brief función que borra un vector de variables double
 *
 * \param n el tamaño del arreglo
 * \param Arr el arreglo que vamos a borrar
 *
 * \exception bad_alloc No hay espacio en la memoria para el polinomio
 *
 */
void BorrarArregloB(bool *&Arr );

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
/** \brief Función que compara dos caracteres
 *
 * \param A un caracter
 * \param B otro caracter
 *
 * \return Si los caracteres son iguales(independientemente de si son mayúsculas, minúsculas, con tilde)
 *
 */
bool CompararLetras(char A ,char B);

//*************************************************************************************************************************
/** \brief función que imprime 3 puntos pausados y después espera un tiempo
 *
 * \param tiempo tiempo que dura la pausa despues de los 3 puntos
 * \param posX posicion en X del primer caracter de la palabra
 * \param posY posicion en y del primer caracter de la palabra
 *
 */
void Suspenso(int tiempo, int posX, int posY);

#endif // UTILERIA_H_INCLUDED
