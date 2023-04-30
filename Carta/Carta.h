#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED



#include "Utileria.h"

const int TAMANOCARTA=13;

//*********************************************************************************
enum Letra
{
    J=11,
    Q,
    K,
};
//*********************************************************************************
enum Simbolo
{
    CORAZON=3,
    DIAMANTE,
    TREBOL,
    PICAS
};

//*********************************************************************************
/** \brief Imprime el dorso de una carta
 *
 * \param posX Coordenadas en X de la esquina superior izquierda
 * \param posY Coordenadas en y de la esquina superior izquierda
 *
 * \pre posX y posY no pueden ser negativos
 *
 */
void ImprimirReversoCarta(int posX, int posY);

//*********************************************************************************
/** \brief Imprime una carta de la baraja inglesa
 *
 * \param numero Carta a imprimir
 * \param simbolo
 * \param posX Coordenadas en X de la esquina superior izquierda
 * \param posY Coordenadas en y de la esquina superior izquierda
 *
 * \pre posX y posY no pueden ser negativos. simbolo solo puede tomar los valores enteros de 3,4,5 y 6. numero solo puede tomar
 *         valores desde 1 a 13
 */
void ImprimirCarta(int numero, char simbolo, int posX, int posY);

//*********************************************************************************
/** \brief Dibuja un solo caracter
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el símbolo
 * \param posY Coordenada en y donde imprimir el símbolo
 *
 * \pre PosX y posY no pueden ser negativos
 */
void Dibujar1(char simbolo, int posX, int posY);

//*********************************************************************************
/** \brief Dibuja dos caracteres separados por 3 espacios
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar2(char simbolo, int posX, int posY);

//*********************************************************************************
/** \brief Dibuja dos caracteres separados por 3 espacios de forma vertical
 *
* \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar2Vertical(char simbolo, int posX, int posY);

//*********************************************************************************
/** \brief Dibuja tres caracteres de forma diagonal
 *
* \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar3(char simbolo,int posX, int posY);

//*********************************************************************************
/** \brief Dibuja cuatro caracteres formando un cuadro
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar4(char simbolo, int posX,int PosY);

//*********************************************************************************
/** \brief Dibuja 5 caracteres en forma de X
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar5(char simbolo,int posX, int posY);

//*********************************************************************************
/** \brief Dibuja 6 caracteres en 3 filas de 2 columnas
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar6(char simbolo, int posX,int PosY);

//*********************************************************************************
/** \brief Dibuja 7 caracteres en 3 filas de 2 columnas y un caracter en medio
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar7(char simbolo, int posX,int PosY);

//*********************************************************************************
/** \brief Dibuja 8 caracteres formando 2 'X' muy raras
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar8(char simbolo,int posX, int posY);

//*********************************************************************************
/** \brief Dibuja 9 caracteres en 4 filas de 2 columnas y un caracter en medio
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer simbolo
 * \param posY Coordenada en y donde imprimir el primer simbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar9(char simbolo, int posX,int PosY);

//*********************************************************************************
/** \brief Dibuja 10 caracteres en forma de 2 'X'
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void Dibujar10(char simbolo, int posX,int posY);

//*********************************************************************************
/** \brief Dibuja una 'J' usando símbolos
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void DibujarJ(char simbolo,int posX, int posY);

//*********************************************************************************
/** \brief Dibuja una 'Q' usando símbolos
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void DibujarQ(char simbolo,int posX, int posY);

//*********************************************************************************
/** \brief Dibuja una 'K' usando símbolos
 *
 * \param simbolo Caracter a imprimir
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void DibujarK(char simbolo,int posX, int posY);

//**************************************************************************
/** \brief Imprime una carta aleatoria
 *
 * \param posX Coordenada en x donde imprimir el primer símbolo
 * \param posY Coordenada en y donde imprimir el primer símbolo
 *
 * \pre posX y posY no pueden ser negativos
 */
void ImprimirCartaRandom(int posX, int posY);

#endif // CARTA_H_INCLUDED
