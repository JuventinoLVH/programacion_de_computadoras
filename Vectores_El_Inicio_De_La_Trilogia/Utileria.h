#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include <limits>

//*******************************************************************************************************************
/** \brief función que captura de forma segura
 *
 * \param mensaje El mensaje de error cuando se ingrese un valor no correspondido
 *
 * \return El valor capturado
 */

float CapturaSegura(const char mensaje[]);
#endif // UTILERIA_H_INCLUDED
