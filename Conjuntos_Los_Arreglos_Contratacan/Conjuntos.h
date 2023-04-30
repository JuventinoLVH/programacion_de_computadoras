/* Nombre: Conjuntos.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 10/04/2020
   Descripción: Archivo de cabecera para las funciones con conjuntos
*/

#ifndef CONJUNTOS_H_INCLUDED
#define CONJUNTOS_H_INCLUDED

#include <stdio.h>
#include "Utileria.h"

const int DIM_MAX = 100;
const int DIM_MAX_UNION =200;

//*******************************************************************************************************************
/** \brief función que calcula la unión de 2 conjuntos
 *
 * \param A Un conjunto cualesquiera
 * \param B Otro conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param tamB La cantidad de elementos en B
 * \param Res El conjunto donde se guardará el resultado
 * \param tamRes variable donde se guardará el tamaño del conjunto Res
 *
 * \pre El tamaño de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
void UnionAuB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB ,Tipo Res[] ,int &tamRes);

//*******************************************************************************************************************
/** \brief función que calcula la intersección o diferencia de 2 conjuntos
 *
 * \param A Un conjunto cualesquiera
 * \param B Otro conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param tamB La cantidad de elementos en B
 * \param Res El conjunto donde se guardará el resultado
 * \param tamRes variable donde se guardará el tamaño del conjunto Res
 * \param PtroCriterio El criterio a seguir
 *
 * \pre El tamaño de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
void OperacionesAyB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB ,Tipo Res[] ,
                    int &tamRes, bool (*PtroCriterio)(const Tipo[],const int,const Tipo) );

//*******************************************************************************************************************
/** \brief función que calcula si X pertenece a A
 *
 * \param A Un conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param X Un elemento cualesquiera
 *
 * \return verdadero si X está en A, falso en el caso conotrario
 *
 * \pre El tamaño de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
bool PertenenciaXeA(const Tipo A[] ,const int tamA ,Tipo X );

//*******************************************************************************************************************
/** \brief función que calcula si A es conjunto de B
 *
 * \param A Un conjunto cualesquiera
 * \param B Otro conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param tamB La cantidad de elementos en B
 *
 * \return verdadero si A está en B, falso en el caso conotrario
 *
 * \pre El tamaño de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
bool ContencionAcB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB );

//*******************************************************************************************************************
/** \brief función que imprime un conjunto
 *
 * \param A Un conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param mensaje mensaje a imprimir antes de imprimir el conjunto
 *
 * \pre El tamaño de los conjuntos no puede ser negativo
 * \pre Es recomendable que el mensaje lleve un "%d" en donde se quiera imprimir el índice del elemento a insertar
 *
 */
template <typename Tipo>
void ImprimirConjuntoA(const Tipo A[] ,const int tamA ,const char mensaje[] = "");

//*******************************************************************************************************************
/** \brief función que captura un conjunto
 *
 * \param A lugar donde se guardará el tamaño del conjunto A
 * \param tamA tamaño del conjunto A
 *
 * \pre El tamaño de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
void LeerConjuntoA(Tipo A[] ,const int tamA ,const char mensaje[] = "");

//*******************************************************************************************************************
/** \brief Criterio para la intersección
 *
 * \param A Un conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param B Un elemento cualesquiera
 *
 * \return Verdad si B está en A, falso en caso contrario
 *
 * \pre El tamaño de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
bool Interseccion(const Tipo A[] ,const int tamA ,const Tipo B );

//*******************************************************************************************************************
/** \brief Criterio para la diferencia
 *
 * \param A Un conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param B Un elemento cualesquiera
 *
 * \return Verdad si B no está en A, falso en caso contrario
 *
 * \pre El tamaño de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
bool Diferencia(const Tipo A[] ,const int tamA ,const Tipo B );

#include "Conjuntos.tpp"
#endif // CONJUNTOS_H_INCLUDED
