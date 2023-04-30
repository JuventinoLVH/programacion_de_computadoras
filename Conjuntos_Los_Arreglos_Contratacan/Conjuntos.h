/* Nombre: Conjuntos.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 10/04/2020
   Descripci�n: Archivo de cabecera para las funciones con conjuntos
*/

#ifndef CONJUNTOS_H_INCLUDED
#define CONJUNTOS_H_INCLUDED

#include <stdio.h>
#include "Utileria.h"

const int DIM_MAX = 100;
const int DIM_MAX_UNION =200;

//*******************************************************************************************************************
/** \brief funci�n que calcula la uni�n de 2 conjuntos
 *
 * \param A Un conjunto cualesquiera
 * \param B Otro conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param tamB La cantidad de elementos en B
 * \param Res El conjunto donde se guardar� el resultado
 * \param tamRes variable donde se guardar� el tama�o del conjunto Res
 *
 * \pre El tama�o de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
void UnionAuB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB ,Tipo Res[] ,int &tamRes);

//*******************************************************************************************************************
/** \brief funci�n que calcula la intersecci�n o diferencia de 2 conjuntos
 *
 * \param A Un conjunto cualesquiera
 * \param B Otro conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param tamB La cantidad de elementos en B
 * \param Res El conjunto donde se guardar� el resultado
 * \param tamRes variable donde se guardar� el tama�o del conjunto Res
 * \param PtroCriterio El criterio a seguir
 *
 * \pre El tama�o de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
void OperacionesAyB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB ,Tipo Res[] ,
                    int &tamRes, bool (*PtroCriterio)(const Tipo[],const int,const Tipo) );

//*******************************************************************************************************************
/** \brief funci�n que calcula si X pertenece a A
 *
 * \param A Un conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param X Un elemento cualesquiera
 *
 * \return verdadero si X est� en A, falso en el caso conotrario
 *
 * \pre El tama�o de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
bool PertenenciaXeA(const Tipo A[] ,const int tamA ,Tipo X );

//*******************************************************************************************************************
/** \brief funci�n que calcula si A es conjunto de B
 *
 * \param A Un conjunto cualesquiera
 * \param B Otro conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param tamB La cantidad de elementos en B
 *
 * \return verdadero si A est� en B, falso en el caso conotrario
 *
 * \pre El tama�o de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
bool ContencionAcB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB );

//*******************************************************************************************************************
/** \brief funci�n que imprime un conjunto
 *
 * \param A Un conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param mensaje mensaje a imprimir antes de imprimir el conjunto
 *
 * \pre El tama�o de los conjuntos no puede ser negativo
 * \pre Es recomendable que el mensaje lleve un "%d" en donde se quiera imprimir el �ndice del elemento a insertar
 *
 */
template <typename Tipo>
void ImprimirConjuntoA(const Tipo A[] ,const int tamA ,const char mensaje[] = "");

//*******************************************************************************************************************
/** \brief funci�n que captura un conjunto
 *
 * \param A lugar donde se guardar� el tama�o del conjunto A
 * \param tamA tama�o del conjunto A
 *
 * \pre El tama�o de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
void LeerConjuntoA(Tipo A[] ,const int tamA ,const char mensaje[] = "");

//*******************************************************************************************************************
/** \brief Criterio para la intersecci�n
 *
 * \param A Un conjunto cualesquiera
 * \param tamA La cantidad de elementos en A
 * \param B Un elemento cualesquiera
 *
 * \return Verdad si B est� en A, falso en caso contrario
 *
 * \pre El tama�o de los conjuntos no puede ser negativo
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
 * \return Verdad si B no est� en A, falso en caso contrario
 *
 * \pre El tama�o de los conjuntos no puede ser negativo
 *
 */
template <typename Tipo>
bool Diferencia(const Tipo A[] ,const int tamA ,const Tipo B );

#include "Conjuntos.tpp"
#endif // CONJUNTOS_H_INCLUDED
