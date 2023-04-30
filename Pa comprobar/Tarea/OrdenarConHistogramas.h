/* Nombre: OrdenarConHistogramas.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 26/04/20
   Descripci�n: Funciones que ordenan un arreglo e imprimen los pasos
*/

#ifndef ORDENARCONHISTOGRAMAS_H_INCLUDED
#define ORDENARCONHISTOGRAMAS_H_INCLUDED

#include"Histograma.h"

const int espera=100;

//*************************************************************************************************************************
/** \brief Funci�n que ordena un arreglo (con el m�todo burbuja) e imprim� los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param largo tama�o del arreglo
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprim� el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void BurbujaHistograma(int arr[] ,const int largo ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

//*************************************************************************************************************************
/** \brief Funci�n que ordena un arreglo (con el m�todo de inserci�n) e imprim� los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param largo tama�o del arreglo
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprim� el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void InsercionHistograma(int arr[] ,const int largo ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

//*************************************************************************************************************************
/** \brief Funci�n que ordena un arreglo (con el m�todo quickshort) e imprim� los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param izq l�mite inferior
 * \param der l�mite superior
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprim� el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void ShortHistograma(int arr[] ,int izq ,int der ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

//*************************************************************************************************************************
/** \brief Funci�n que ordena un arreglo (con el m�todo merge sort) e imprim� los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param largo tama�o del arreglo
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprim� el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void MergeHistograma(int arr[] ,int largo ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

//*************************************************************************************************************************
/** \brief Funci�n que ordena un arreglo (con el m�todo de selecci�n) e imprim� los pasos en un histograma ya existente
 *
 * \param arr arreglo a ordenar
 * \param largo tama�o del arreglo
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprim� el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void SeleccionHistograma(int arr[] ,int largo ,int posY=0 ,int posX=0 ,char caracter='*' ,bool tipoPausa=true);

#endif // ORDENARCONHISTOGRAMAS_H_INCLUDED
