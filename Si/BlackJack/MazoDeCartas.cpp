/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include "MazoDeCartas.h"


//*************************************************************************************************************************
MazoDeCartas::MazoDeCartas()
{
    tope=0;

    for(int i=0;i<52;i++)
    {
        mazo[i]=new Carta;
    }

    for(int i=1;i<=13;i++)
    {
        Carta cartaAux(i,TREBOL,19,19);
        *mazo[tope++]=cartaAux;
    }
    for(int i=1;i<=13;i++)
    {
        Carta cartaAux(i,PICAS,19,19);
        *mazo[tope++]=cartaAux;
    }
    for(int i=1;i<=13;i++)
    {
        Carta cartaAux(i,DIAMANTE,19,19);
        *mazo[tope++]=cartaAux;
    }
    for(int i=1;i<=13;i++)
    {
        Carta cartaAux(i,CORAZON,19,19);
        *mazo[tope++]=cartaAux;
    }
}

//*************************************************************************************************************************
MazoDeCartas::MazoDeCartas(const MazoDeCartas & mazoAux)
{
    for(int i=0;i<52;i++)
    {
        *mazo[i]=*(mazoAux.mazo[i]);
    }
}


//*************************************************************************************************************************
MazoDeCartas::~MazoDeCartas()
{
    for(int i=0;i<52;i++)
    {
        delete mazo[i];
    }
}


//*************************************************************************************************************************
const MazoDeCartas & MazoDeCartas::operator=(const MazoDeCartas &mazoAux)
{
    if(this == &mazoAux) return *this;

    for(int i=0;i<52;i++)
    {
        *mazo[i]=*(mazoAux.mazo[i]);
    }

    return *this;
}


//*************************************************************************************************************************
int MazoDeCartas::CuantasQuedan()const
{
    return tope;
}


//*************************************************************************************************************************
Carta & MazoDeCartas::SacarCarta()
{
    if(tope==0) throw "No quedaan Cartas...";
    return *mazo[--tope];
}


//*************************************************************************************************************************
void MazoDeCartas::barajar()
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


//*************************************************************************************************************************
void MazoDeCartas::Ordenar()
{
    tope=0;
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
