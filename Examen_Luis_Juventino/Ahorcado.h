/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#ifndef AHORCADO_H_INCLUDED
#define AHORCADO_H_INCLUDED

#include"Utileria.h"

//*************************************************************************************************************************
/** \brief Función que escribe una frase enmascarada
 *
 * \param palabra una cadena de caracteres
 * \param posX posicion en X del primer caracter de la palabra
 * \param posY posicion en y del primer caracter de la palabra
 * \param caracter Caracter con el que se va a enmascarar
 *
 * \return Un arreglo de booleanos que indica el estado del juego
 *
 */
bool * EnmascararPalabra(const char *palabra ,int posX=0 ,int posY=0 ,char caracter='*');

//*************************************************************************************************************************
/** \brief Función que escribe una frase enmascarada
 *
 * \param palabra una cadena de caracteres
 * \param estdoJuego estado actual del juego
 * \param letra Caracter que se va a destapar
 * \param posX posicion en X del primer caracter de la palabra
 * \param posY posicion en y del primer caracter de la palabra
 *
 * \return Sí la letra esta en la cadena
 */
 bool DestaparLetra(const char *palabra ,bool *estadoJuego ,char letra ,int posX=0 ,int posY=0 ,int suspenso=0);

//*************************************************************************************************************************
/** \brief Función que dice si ya ganaste el juego
 *
 * \param palabra palabra del juego
 * \param estado Estado actua del juego
 *
 * \return Sí ya ganaste el juego
 */
bool EstadoGanado(const char *palabra ,const bool *estado);

#endif // AHORCADO_H_INCLUDED
