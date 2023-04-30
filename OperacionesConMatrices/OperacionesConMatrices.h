#ifndef OPERACIONESCONMATRICES_H_INCLUDED
#define OPERACIONESCONMATRICES_H_INCLUDED

#include "Utileria.h"
#include <fstream>
#include <iomanip>

const int SEPARACION=12;

enum marco
{
    EID=217,
    ESI,
    ESD=191,
    EII,
    BV=179,
};

//*************************************************************************************************************************
/** \brief Función que escribe una matriz en un archivo
 *
 * \param cadena el nombre del archivo donde se guardará la matriz(De preferencia sin extensión)
 * \param matriz La matriz a guardar
 * \param n la altura de la matriz
 * \param m el ancho de la matriz
 *
 */
void EscribirMatrizEnArchivo(const char *cadena ,double * const * matriz ,int n ,int m);

//*************************************************************************************************************************
/** \brief Función que captura una matriz de n*m
 *
 * \param matriz La matriz a capturar
 * \param n la altura de la matriz
 * \param m el ancho de la matriz
 *
 */
void CapturarMatriz(double **matriz ,int n ,int m);

//*************************************************************************************************************************
/** \brief Función iguala el contenido de una matriz a el contenido de un archivo
 *
 * \param cadena el nombre del archivo a leer
 * \param matriz La matriz en donde se guardara el archivo leído
 * \param n la altura de la matriz
 * \param m el ancho de la matriz
 *
 */
bool CapturarMatrizDeUnArchivo(const char *cadena ,double **&matriz ,int &n ,int &m);

//*************************************************************************************************************************
/** \brief función que imprime una matriz
 *
 * \param matriz matriz a imprimir
 * \param n el alto de la matriz
 * \param m el ancho de la matriz
 * \param nombre lo que se quiere que se imprima antes de imprimir la matriz
 *
 */
void ImprimirMatriz(double * const * matriz ,int n, int m ,const char *nombre=" ");

//*************************************************************************************************************************
/** \brief Función que suma dos matrices
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz 1
 * \param matriz2 otra matriz
 * \param n2 El alto de matriz2
 * \param m2 El ancho de matriz2
 * \param matrizRes el puntero donde se guardará la matriz resultante
 * \param rn variable donde se guardará la altura de matrizRez
 * \param rm variable donde se guardará el ancho de matrizRez
 *
 * \return si se pudo realizar la operación
 *
 */
bool SumaMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes ,int &rn ,int &rm);

//*************************************************************************************************************************
/** \brief Función que suma dos matrices
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz 1
 * \param matriz2 otra matriz
 * \param n2 El alto de matriz2
 * \param m2 El ancho de matriz2
 * \param matrizRes el puntero donde se guardará la matriz resultante
 *
 * \return si se pudo realizar la operación
 *
 */
bool SumaMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes);

//*************************************************************************************************************************
/** \brief Función que resta dos matrices
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz 1
 * \param matriz2 otra matriz
 * \param n2 El alto de matriz2
 * \param m2 El ancho de matriz2
 * \param matrizRes el puntero donde se guardará la matriz resultante
 * \param rn variable donde se guardará la altura de matrizRez
 * \param rm variable donde se guardará el ancho de matrizRez
 *
 * \return si se pudo realizar la operación
 *
 */
bool RestarMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes ,int &rn ,int &rm);

//*************************************************************************************************************************
/** \brief Función que resta dos matrices
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz 1
 * \param matriz2 otra matriz
 * \param n2 El alto de matriz2
 * \param m2 El ancho de matriz2
 * \param matrizRes el puntero donde se guardará la matriz resultante
 *
 * \return si se pudo realizar la operación
 *
 */
bool RestarMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes);

//*************************************************************************************************************************
/** \brief Función que multiplica dos matrices
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz 1
 * \param matriz2 otra matriz
 * \param n2 El alto de matriz2
 * \param m2 El ancho de matriz2
 * \param matrizRes el puntero donde se guardará la matriz resultante de matriz1*matriz2
 * \param rn variable donde se guardará la altura de matrizRez
 * \param rm variable donde se guardará el ancho de matrizRez
 *
 * \return si se pudo realizar la operación
 *
 */
bool MultiplicarMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes ,int &rn ,int &rm);

//*************************************************************************************************************************
/** \brief Función que multiplica dos matrices
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz 1
 * \param matriz2 otra matriz
 * \param n2 El alto de matriz2
 * \param m2 El ancho de matriz2
 * \param matrizRes el puntero donde se guardará la matriz resultante de matriz1*matriz2
 *
 * \return si se pudo realizar la operación
 *
 */
bool MultiplicarMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes);

//*************************************************************************************************************************
/** \brief Función que multiplica una matriz por un escalar
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz 1
 * \param matrizRes el puntero donde se guardará la matriz resultante
 * \param rn variable donde se guardará la altura de matrizRez
 * \param rm variable donde se guardará el ancho de matrizRez
 *
 */
void MultiplicarPorEscalar(double * const *  matriz1 ,int n1 ,int m1 ,double k ,double **&matrizRes ,int &rn ,int &rm);

//*************************************************************************************************************************
/** \brief Función que multiplica una matriz por un escalar
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz 1
 * \param matrizRes el puntero donde se guardará la matriz resultante
 *
 */
void MultiplicarPorEscalar(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes);

//*************************************************************************************************************************
/** \brief Función que calcula la matriz transpuesta de otra
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz1
 * \param matrizRes el puntero donde se guardará la matriz resultante
 * \param rn variable donde se guardará la altura de matrizRez
 * \param rm variable donde se guardará el ancho de matrizRez
 *
 */
void Transpuesta(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes ,int &rn ,int &rm);

//*************************************************************************************************************************
/** \brief Función que calcula la matriz transpuesta de otra
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz1
 * \param matrizRes el puntero donde se guardará la matriz resultante
 *
 */
void Transpuesta(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes);

//*************************************************************************************************************************
/** \brief Función que calcula la matriz inversa de otra
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz1
 * \param matrizRes el puntero donde se guardará la matriz resultante
 * \param rn variable donde se guardará la altura de matrizRez
 * \param rm variable donde se guardará el ancho de matrizRez
 *
 * \return si la matriz tiene inversa
 *
 */
bool Inversa(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes ,int &rn ,int &rm);

//*************************************************************************************************************************
/** \brief Función que calcula la matriz inversa de otra
 *
 * \param matriz1 Una matriz
 * \param n1 El alto de matriz1
 * \param m1 El ancho de matriz1
 * \param matrizRes el puntero donde se guardará la matriz resultante
 *
 * \return Si la matriz tiene inversa
 */
bool Inversa(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes);

#endif // OPERACIONESCONMATRICES_H_INCLUDED
