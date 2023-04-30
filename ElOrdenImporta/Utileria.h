/*
 Nombre: Utileria.h
 Autor: Luis Juventino Velasquez Hidalgo
 Fecha: 3/19/2020
 Descripción: Archivo de cabecera
*/

#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

//*************************************************************************************************************
/** \brief ordena 3 valores del mismo tipo
 *
 * \param Val1 El primer valor a ordenar
 * \param Val2 El segundo valor a ordenar
 * \param val3 El tercer valor a ordenar
 * \param Criterio El criterio que se usara para ordenar los valores (ascendente o descendente)
 *
 */
template<typename Tipo1>
void OrdenarTres(Tipo1 &val1 ,Tipo1 &val2 ,Tipo1 &val3 ,bool (*Criterio)(Tipo1,Tipo1));

//*************************************************************************************************************
/** \brief Intercambia el contenido de 2 variables
 *
 * \param a El primer valor a intercambiar
 * \param b El segundo valor a intercambiar
 *
 */
template<typename Tipo1>
inline void Intercambiar(Tipo1 &a ,Tipo1 &b);

//*************************************************************************************************************
/** \brief
 * Criterio que se debe de seguir si se quiere ordenar 2 valores de forma ascendente
 *
 * \param a El primer valor
 * \param b El segundo valor
 *
 * \return Si los valores se deben de intercambiar o no
 *
 */
template<typename Tipo1>
bool Ascendente(Tipo1 a ,Tipo1 b);

//*************************************************************************************************************
/** \brief
 * Criterio que se debe de seguir si se quiere ordenar 2 valores de forma descendente
 *
 * \param a El primer valor
 * \param b El segundo valor
 *
 * \return Si los valores se deben de intercambiar o no
 *
 */
template<typename Tipo1>
bool Descendente(Tipo1 a ,Tipo1 b);

#include "Utileria.tpp"
#endif // UTILERIA_H_INCLUDED
