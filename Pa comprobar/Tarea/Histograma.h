/* Nombre: Histograma.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 25/04/2020
   Descripción: Funciones de cabezera para imprimir histogramas
*/

#ifndef HISTOGRAMA_H_INCLUDED
#define HISTOGRAMA_H_INCLUDED

#include "Utileria.h"

const int MAX_ALTURA=20;

//*************************************************************************************************************************
/** \brief Función que imprimé un histograma
 *
 * \param arreglo arreglo a imprimir
 * \param largo largo del arreglo
 * \param caracter caracter con el que se imprimirá el arreglo
 * \param posY coordenada en Y de la esquina superior del histograma
 * \param posX coordenada en X de la esquina superior del histograma
 *
 */
void Histograma(const int arreglo[] ,int largo ,int posY=0 ,int posX=0 ,char caracter ='*' );

//*************************************************************************************************************************
/** \brief Función que intercambia 2 columnass de un histograma
 *
 * \param arreglo
 * \param caracter
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 *
 */
void Intercambiar2ColumnasHistograma(const int arreglo[] ,int columna1 ,int columna2 ,
                                    int posY=0 ,int posX=0 ,char caracter ='*' );

//*************************************************************************************************************************
/** \brief función que imprimé una columna
 *
 * \param altura altura de la columna
 * \param posY coordenada en Y del tope de la columna
 * \param posX coordenada en X del tope de la columna
 * \param caracter caracter de la columna
 *
 */
void DibujarColumna(int altura ,int posY ,int posX ,char caracter);

#endif // HISTOGRAMA_H_INCLUDED
