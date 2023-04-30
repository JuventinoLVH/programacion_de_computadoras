#ifndef ANIMACIONESJUEGO_H_INCLUDED
#define ANIMACIONESJUEGO_H_INCLUDED


#include "Utileria.h"


#define MARGEN_FILA_SUP 2
#define MARGEN_COLUMNA_INF 33

#define SANGRIA_COLUMNA_BOTON 20
#define SANGRIA_FILA_BOTON 2
#define ALTURA_BOTON 8
#define SANGRIA_X_JUEGO 100
#define SANGRIA_Y_JUEGO 8

#define POSX_BOTON_TOMAR_CARTA SANGRIA_X_JUEGO
#define POSY_BOTON_TOMAR_CARTA SANGRIA_Y_JUEGO
#define POSX_BOTON_CONSERVAR_MANO SANGRIA_X_JUEGO
#define POSY_BOTON_CONSERVAR_MANO SANGRIA_Y_JUEGO+SANGRIA_FILA_BOTON+ALTURA_BOTON
#define POSX_BOTON_REINICIAR SANGRIA_X_JUEGO
#define POSY_BOTON_REINICIAR SANGRIA_Y_JUEGO+(SANGRIA_FILA_BOTON*2)+(ALTURA_BOTON*2)
#define POSX_BOTON_VOLVER SANGRIA_X_JUEGO
#define POSY_BOTON_VOLVER SANGRIA_Y_JUEGO+(SANGRIA_FILA_BOTON*3)+(ALTURA_BOTON*3)


#define POSX_BOTON_JUEGO MARGEN_COLUMNA_INF+SANGRIA_COLUMNA_BOTON
#define POSY_BOTON_JUEGO (MARGEN_FILA_SUP+12)+SANGRIA_FILA_BOTON
#define POSX_BOTON_CREDITOS MARGEN_COLUMNA_INF+SANGRIA_COLUMNA_BOTON
#define POSY_BOTON_CREDITOS (MARGEN_FILA_SUP+12)+(SANGRIA_FILA_BOTON*3)+(ALTURA_BOTON*2)
#define POSX_BOTON_INSTRUCCIONES MARGEN_COLUMNA_INF+SANGRIA_COLUMNA_BOTON
#define POSY_BOTON_INSTRUCCIONES (MARGEN_FILA_SUP+12)+(SANGRIA_FILA_BOTON*2)+ALTURA_BOTON
#define POSX_BOTON_SALIR MARGEN_COLUMNA_INF+SANGRIA_COLUMNA_BOTON
#define POSY_BOTON_SALIR (MARGEN_FILA_SUP+12)+(SANGRIA_FILA_BOTON*4)+(ALTURA_BOTON*3)

const char DIR_BOTON_CREDITOS[]="Arte\\BotonCreditos.txt";
const char DIR_BOTON_JUGAR[]="Arte\\BotonJugar.txt";
const char DIR_BOTON_SALIR[]="Arte\\BotonSalir.txt";
const char DIR_BOTON_INSTRUCCIONES[]="Arte\\BotonInstrucciones.txt";
const char DIR_BOTON_TOMAR_CARTA[]="Arte\\BotonTomarCarta.txt";
const char DIR_BOTON_CONSERVAR_MANO[]="Arte\\BotonConservarMano.txt";
const char DIR_BOTON_REINICIAR[]="Arte\\BotonReiniciar.txt";
const char DIR_BOTON_VOLVER[]="Arte\\BotonRegresar.txt";

const char DIR_CREDITOS[]="Arte\\Creditos.txt";
const char DIR_INSTRUCCIONES[]="Arte\\Instrucciones2.txt";
const char DIR_SALIR[]="Arte\\Logo.txt";



//*************************************************************************************************************************
/** \brief Función que presenta el juego
 *
 * \pre Se recomienda que el tamaño de la pantalla sea de 1366 x 768
 *
 */
void presentacion();


//*************************************************************************************************************************
/** \brief Función que imprime la pantalla de titulo
 *
 * \pre Se recomienda que el tamaño de la pantalla sea de 1366 x 768
 *
 */
void PantallaDeTitulo(Color fondo, Color texto);


//*************************************************************************************************************************
/** \brief Función que imprime la pantalla de titulo
 *
 * \pre Se recomienda que el tamaño de la pantalla sea de 1366 x 768
 *
 */
void BotonesTitulo(Color fondo, Color texto);


//*************************************************************************************************************************
/** \brief Función que imprime la pantalla de titulo
 *
 * \pre Se recomienda que el tamaño de la pantalla sea de 1366 x 768
 *
 */
void BotonesJuego(Color fondo, Color texto);


//*************************************************************************************************************************
/** \brief Función que limpia la pantalla con un parpadeo
 *
 *  \param fondo Color del parpadeo
 *  \param miliseg milisegundos que durará el parpadeo
 *
 */
void Parpadeo(Color fondo=BLANCO,double milseg=60);


//*************************************************************************************************************************
/** \brief Función ilumina un boton
 *
 *  \param Boton Boton a iluminar
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void IluminarBoton( void (* Boton)(Color , Color) ,Color fondo=VERDE ,Color texto=ROJO);


//*************************************************************************************************************************
/** \brief Pendiente
 *
 *  \param Boton Boton a iluminar
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *  \param segundos Segunos que dura iluminado el boton
 *  \param durParpadeo Milisegundos que dura el parpadeo
 *  \
 *
 */
void ElegirBoton(void (* Boton)(Color , Color ) ,double segundos=1.9 ,Color fondo=AMARILLO ,Color texto=ROJO ,
                    unsigned int VecesParpadeo=7 ,Color fondoParp=AMARILLOCLARO ,Color textoParp=ROJO);

//*************************************************************************************************************************
/** \brief Función imprime el boton de inicio
 *
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void BotonJugar(Color fondo=BLANCO, Color texto=AZUL );


//*************************************************************************************************************************
/** \brief Función imprime el boton de instrucciones
 *
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void BotonInstruc(Color fondo=BLANCO, Color texto=AZUL );


//*************************************************************************************************************************
/** \brief Función imprime el boton de salir
 *
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void BotonCreditos(Color fondo=BLANCO, Color texto=AZUL );


//*************************************************************************************************************************
/** \brief Función imprime el boton de salir
 *
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void BotonSalir(Color fondo=BLANCO, Color texto=AZUL );


//*************************************************************************************************************************
/** \brief Función imprime el boton de salir
 *
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void BotonTomarCarta(Color fondo=BLANCO, Color texto=AZUL );


//*************************************************************************************************************************
/** \brief Función imprime el boton de salir
 *
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void BotonConservarMano(Color fondo=BLANCO, Color texto=AZUL );


//*************************************************************************************************************************
/** \brief Función imprime el boton de salir
 *
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void BotonReiniciar(Color fondo=BLANCO, Color texto=AZUL );


//*************************************************************************************************************************
/** \brief Función imprime el boton de salir
 *
 *  \param fondo Color del fondo
 *  \param texto Color del texto
 *
 */
void BotonVolver(Color fondo=BLANCO, Color texto=AZUL );

#endif // ANIMACIONESJUEGO_H_INCLUDED
