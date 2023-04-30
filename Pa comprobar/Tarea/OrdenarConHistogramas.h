/* Nombre: OrdenarConHistogramas.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 26/04/20
   Descripción: Funciones que ordenan un arreglo e imprimen los pasos
*/

#ifndef ORDENARCONHISTOGRAMAS_H_INCLUDED
#define ORDENARCONHISTOGRAMAS_H_INCLUDED

#include"Histograma.h"

const int espera=100;

//*************************************************************************************************************************
/** \brief Función que ordena un arreglo (con el método burbuja) e imprimé los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param largo tamaño del arreglo
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprimé el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void BurbujaHistograma(int arr[] ,const int largo ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

//*************************************************************************************************************************
/** \brief Función que ordena un arreglo (con el método de inserción) e imprimé los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param largo tamaño del arreglo
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprimé el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void InsercionHistograma(int arr[] ,const int largo ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

//*************************************************************************************************************************
/** \brief Función que ordena un arreglo (con el método quickshort) e imprimé los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param izq límite inferior
 * \param der límite superior
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprimé el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void ShortHistograma(int arr[] ,int izq ,int der ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

//*************************************************************************************************************************
/** \brief Función que ordena un arreglo (con el método merge sort) e imprimé los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param largo tamaño del arreglo
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprimé el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void MergeHistograma(int arr[] ,int largo ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

//*************************************************************************************************************************
/** \brief Función que ordena un arreglo (con el método de selección) e imprimé los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param largo tamaño del arreglo
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprimé el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void SeleccionHistograma(int arr[] ,int largo ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

#endif // ORDENARCONHISTOGRAMAS_H_INCLUDED
