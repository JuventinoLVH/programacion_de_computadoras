
#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include <windows.h>
#include <iostream>
#include <limits>


//*************************************************************************************************************************
/** \brief Función que captura de forma segura un numero double
 *
 * \param solicitud Mensaje de solicitud para la captura
 * \param var La variable a capturar
 *
 * \return Entero capturado
 */
double CapturaSegura(const char *solicitud);

//*************************************************************************************************************************
/** \brief Función que crea una matriz de forma dinamica
 *
 * \param n La altura de la matriz
 * \param m El ancho de la matriz
 *
 * \return La dirección de la matriz
 *
 */
double ** CrearMatriz(int n ,int m);

//*************************************************************************************************************************
/** \brief Función que libera una matriz en la memoria
 *
 * \param matriz la matriz a borrar
 * \param n la altura de la matriz
 *
 */
void BorraraMatriz(double **&matriz ,int n);

#endif // UTILERIA_H_INCLUDED
