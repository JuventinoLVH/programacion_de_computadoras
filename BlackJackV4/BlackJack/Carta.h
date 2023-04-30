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


    int GetNumeracion () const;
    char GetSimbolo () const;
    int GetAncho () const;
    int GetAlto () const;

    void ImprimirFrente(int posX ,int posY ,Color borde=ROJO ,Color fondo=BLANCO);
    void ImprimirReverso(int posX ,int posY ,Color borde=ROJO ,Color fondo=BLANCO ,Color relleno=ROJO);
};

#endif // CARTA_H_INCLUDED
