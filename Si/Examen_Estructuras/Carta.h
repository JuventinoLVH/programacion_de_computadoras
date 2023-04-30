/* Nombre: Carta.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 27/05/2020
   Descripci�n: clase de carta
*/
#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include "Utileria.h"

//*********************************************************************************
enum Letra
{
    J=11,
    Q,
    K,
    A,
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

public:
    //*********************************************************************************
    /** \brief constructor por defecto
     *
     * \param num la numeraci�n de la carta
     * \param simb simbolo de la carta
     *
     */
    Carta(int num=0,Simbolo simb=CORAZON);


    //*********************************************************************************
    /** \brief Constuctor que acepta "Letras"
     *
     * \param num la numeraci�n de la carta
     * \param simb el simbolo de la carta
     *
     */
    Carta(Letra num,Simbolo simb=CORAZON);


    //*********************************************************************************
    /** \brief Funci�n que regresa la numeracion
     *
     * \return la numeraci�n de la carta
     */
    int GetNumeracion () const;


    //*********************************************************************************
    /** \brief funci�n que regresa el simbolo
     *
     * \return el simbolo de la carta
     */
    char GetSimbolo () const;

    //*********************************************************************************
    /** \brief Funci�n que imprime el frente de la carta
     *
     * \param posX la coordenada en X de la esquina superior
     * \param posY la coordenada en Y de la esquina superior
     *
     */
    void ImprimirFrente(int posX ,int posY );


    //*********************************************************************************
    /** \brief Funci�n que imprime el reverso de la carta
     *
     * \param posX la coordenada en X de la esquina superior
     * \param posY la coordenada en Y de la esquina superior
     *
     */
    void ImprimirReverso(int posX ,int posY );
};

#endif // CARTA_H_INCLUDED
