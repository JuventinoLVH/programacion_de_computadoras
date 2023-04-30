#ifndef OPR_VECTORES_H_INCLUDED
#define OPR_VECTORES_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Utileria.h"

//*******************************************************************************************************************
/** \brief La funci&oacute;n captura la cantidad indicada de elementos en un vector.
 *
 * \param arreglo Corresponde al vector donde se almacenar&aacute;n los elementos.
 * \param dimension La cantidad de elementos a capturar.
 */
template <typename Tipo>
void CapturarVector(Tipo arreglo[], int dimension);

//*******************************************************************************************************************
/** \brief Proceso encargado de la suma de 2 vectores.
 *
 * \param primerVector Corresponde al primer vector a sumar.
 * \param segundoVector Corresponde al segundo vector para la suma.
 * \param vectorResultante Es el vector donde se almacena el resultado de la suma.
 * \param dimension La cantidad de elementos de los vectores.
 */
template <typename Tipo>
void SumarVectores(const Tipo primerVector[], const Tipo segundoVector[],Tipo vectorResultante[], int dimension);

//*******************************************************************************************************************
/** \brief Imprime a pantalla el vector con un formato definido.
 *
 * \param arreglo[] Es el vector por mostrarse.
 * \param dimension La cantidad de elementos que posee dicho vector.
 */
template <typename Tipo>
void ImprimirVector(const Tipo arreglo[], int dimension);

//*******************************************************************************************************************
/** \brief Proceso encargado de la resta de 2 vectores.
 *
 * \param primerVector Corresponde al primer vector a sumar.
 * \param segundoVector Corresponde al segundo vector para la suma.
 * \param vectorResultante Es el vector donde se almacena el resultado de la resta.
 * \param dimension La cantidad de elementos de los vectores.
 */
template <typename Tipo>
void RestaVectores(const Tipo primerVector[], const Tipo segundoVector[],Tipo vectorResultante[], int dimension);

//*******************************************************************************************************************
/** \brief  Calcula el producto punto de 2 vectores
 *
 * \param primerVector Corresponde al primer vector a sumar.
 * \param segundoVector Corresponde al segundo vector para la suma.
 * \param dimension La cantidad de elementos de los vectores.
 *
 * \return El producto punto
 */
template <typename Tipo>
float ProductoPunto(const Tipo primerVector[], const Tipo segundoVector[], int dimension);

//*******************************************************************************************************************
/** \brief  Multiplica un vector por una constante
 *
 * \param Vector Un vector.
 * \param escalar Constante por la cual se multiplicara el vector
 * \param vectorResultante Es el vector donde se almacena el resultado de la resta.
 * \param dimension La cantidad de elementos de los vectores.
 *
 */
template <typename Tipo>
void ProductoVectorEscalar(const Tipo Vector[] ,Tipo vectorResultante[] ,float escalar ,int dimension);

//*******************************************************************************************************************
/** \brief  Calcula la magnitud de un vector
 *
 * \param Vector Un vector..
 * \param dimension La cantidad de elementos de los vectores.
 *
 * \return La magnitud del vector
 */
template <typename Tipo>
float NormaVector(const Tipo Vector[], int dimension);

#include "Opr_Vectores.tpp"
#endif // OPR_VECTORES_H_INCLUDED
