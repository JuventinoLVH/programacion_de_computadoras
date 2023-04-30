#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include "Utileria.h"

#define TAMANO_DEFAULT 13
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
class Carta
{
private:

    int numeracion;
    char simbolo;
    int ancho,alto;

    void Imprimir2Simbolos(int posX ,int posY );

public:

    Carta();

    Carta(int num,Simbolo simb);
    Carta(int num,Simbolo simb,int altoCar,int anchoCar);


    /** \brief Función para conseguir la numeración de una carta.
     *
     * \param
     * \param
     * \return Regresa la numeración
     *
     */
    int GetNumeracion () const;

    /** \brief  Función para conseguir el símbolo a una carta
     *
     * \param
     * \param
     * \return Regresa el símbolo.
     *
     */
    char GetSimbolo () const;

    /** \brief Función para conseguir el ancho de una carta.
     *
     * \param
     * \param
     * \return Regresa el valor del ancho.
     *
     */
    int GetAncho () const;

    /** \brief Función para conseguir el alto de una carta.
     *
     * \param
     * \param
     * \return Regresa el valor del alto.
     *
     */
    int GetAlto () const;


    /** \brief Función para la impresión del frente de una carta.
     *
     * \param posX int
     * \param posY int
     * \param borde=ROJO Color
     * \param fondo=BLANCO Color
     * \return void
     *
     */
    void ImprimirFrente(int posX ,int posY ,Color borde=ROJO ,Color fondo=BLANCO);
    /** \brief Función para la impresión del reverso de una carta.
     *
     * \param posX int
     * \param posY int
     * \param borde=ROJO Color
     * \param fondo=BLANCO Color
     * \param relleno=ROJO Color
     * \return void
     *
     */
    void ImprimirReverso(int posX ,int posY ,Color borde=ROJO ,Color fondo=BLANCO ,Color relleno=ROJO);
};

#endif // CARTA_H_INCLUDED
