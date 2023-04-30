/* Nombre: GestionConjuntos.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 13/04/2020
   Descripci�n: Funciones de gestion para los conjuntos
*/
#ifndef GESTIONCONJUNTOS_H_INCLUDED
#define GESTIONCONJUNTOS_H_INCLUDED

#include "Conjuntos.h"

//*******************************************************************************************************************
/** \brief funci�n que gestiona la uni�n de 2 conjuntos
 *
 * \param tipoConjuntos tipo de dato de los conjuntos
 *
 */
template <typename Tipo>
void GestionUnion(Tipo tipoConjuntos);

//*******************************************************************************************************************
/** \brief funci�n que gestiona la intersecci�n o diferencia de 2 conjuntos
 *
 * \param tipoConjuntos tipo de dato de los conjuntos
 *
 */
template <typename Tipo>
void GestionInterseccion(Tipo tipoConjuntos);

//*******************************************************************************************************************
/** \brief funci�n que gestiona la intersecci�n o diferencia de 2 conjuntos
 *
 * \param tipoConjuntos tipo de dato de los conjuntos
 *
 */
template <typename Tipo>
void GestionDiferencia(Tipo tipoConjuntos);

//*******************************************************************************************************************
/** \brief funci�n que gestiona la intersecci�n o diferencia de 2 conjuntos
 *
 * \param tipoConjunto tipo de dato del conjunto y el universo
 *
 */
template <typename Tipo>
void GestionComplemento(Tipo tipoConjunto);

//*******************************************************************************************************************
/** \brief funci�n que gestiona si X pertenece a A
 *
 * \param tipoConjunto tipo de dato de los conjuntos y del elemento a buscar
 *
 */
template <typename Tipo>
void GestionPertenencia(Tipo tipoConjunto);

//*******************************************************************************************************************
/** \brief funci�n que gestiona s� A contiene a B
 *
 * \param tipoConjuntos tipo de dato de los conjuntos
 *
 */
template <typename Tipo>
void GestionContencion(Tipo tipoConjuntos);

#include "GestionConjuntos.tpp"
#endif // GESTIONCONJUNTOS_H_INCLUDED
