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


    /** \brief Funci�n para conseguir la numeraci�n de una carta.
     *
     * \param
     * \param
     * \return Regresa la numeraci�n
     *
     */
    int GetNumeracion () const;

    /** \brief  Funci�n para conseguir el s�mbolo a una carta
     *
     * \param
     * \param
     * \return Regresa el s�mbolo.
     *
     */
    char GetSimbolo () const;

    /** \brief Funci�n para conseguir el ancho de una carta.
     *
     * \param
     * \param
     * \return Regresa el valor del ancho.
     *
     */
    int GetAncho () const;

    /** \brief Funci�n para conseguir el alto de una carta.
     *
     * \param
     * \param
     * \return Regresa el valor del alto.
     *
     */
    int GetAlto () const;


    /** \brief Funci�n para la impresi�n del frente de una carta.
     *
     * \param posX int
     * \param posY int
     * \param borde=ROJO Color
     * \param fondo=BLANCO Color
     * \return void
     *
     */
    void ImprimirFrente(int posX ,int posY ,Color borde=ROJO ,Color fondo=BLANCO);
    /** \brief Funci�n para la impresi�n del reverso de una carta.
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
