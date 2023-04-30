/* Nombre: MazoCartas.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 27/05/2020
   Descripción:Funciones de la clase MazoCartas
*/

#include "MazoCartas.h"

//*************************************************************************************************************************
MazoCartas::MazoCartas()
{
    tope=0;

    for(int i=0;i<52;i++)
    {
        mazo[i]=new Carta;
    }

    for(int i=1;i<=13;i++)
    {
        Carta cartaAux(i,TREBOL);
        *mazo[tope++]=cartaAux;
    }
    for(int i=1;i<=13;i++)
    {
        Carta cartaAux(i,PICAS);
        *mazo[tope++]=cartaAux;
    }
    for(int i=1;i<=13;i++)
    {
        Carta cartaAux(i,DIAMANTE);
        *mazo[tope++]=cartaAux;
    }
    for(int i=1;i<=13;i++)
    {
        Carta cartaAux(i,CORAZON);
        *mazo[tope++]=cartaAux;
    }
}

//*************************************************************************************************************************
MazoCartas::MazoCartas(const MazoCartas & mazoAux)
{
    for(int i=0;i<52;i++)
    {
        *mazo[i]=*(mazoAux.mazo[i]);
    }
}


//*************************************************************************************************************************
MazoCartas::~MazoCartas()
{
    for(int i=0;i<52;i++)
    {
        delete mazo[i];
    }
}


//*************************************************************************************************************************
const MazoCartas & MazoCartas::operator=(const MazoCartas &mazoAux)
{
    if(this == &mazoAux) return *this;

    for(int i=0;i<52;i++)
    {
        *mazo[i]=*(mazoAux.mazo[i]);
    }

    return *this;
}


//*************************************************************************************************************************
int MazoCartas::CuantasQuedan()const
{
    return tope;
}


//*************************************************************************************************************************
Carta & MazoCartas::SacarCarta()
{
    if(tope==0) throw "No quedaan Cartas...";
    return *mazo[--tope];
}


//*************************************************************************************************************************
void MazoCartas::barajar()
{
    int indRand;
    tope=52;
    for(int i=0;i<tope;i++)
    {
        indRand=rand()%(tope);
        Carta * aux=mazo[indRand];
        mazo[indRand]=mazo[i];
        mazo[i]=aux;
    }
}
