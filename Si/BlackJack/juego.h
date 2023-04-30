#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED


#include "MazoDeCartas.h"
#include "ManoBlackJack.h"
#include "Carta.h"
#include "Utileria.h"
#include "AnimacionesJuego.h"
#include <conio.h>

#define POS_X_MAZO 55
#define POS_Y_MAZO 23
#define POS_X_J 17
#define POS_Y_J 37
#define POS_X_D 17
#define POS_Y_D 1

#define ARRIBA 72
#define IZQ 75
#define DER 77
#define ABAJO 80
#define ENTER 13
#define ESPACIO ' '


/** \brief Función que controla el juego.
 *
 * \param FONDO Color
 * \param TEXTO Color
 * \param ILUMINADO Color
 * \return void
 *
 */
void juego(Color FONDO, Color TEXTO, Color ILUMINADO);



#endif // JUEGO_H_INCLUDED
