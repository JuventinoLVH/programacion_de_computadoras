/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include "ManoBlackJack.h"

//************************************************************************************************************************
ManoBlackJack::ManoBlackJack(int x,int y)
{
    posX=x;
    posY=y;
    cartasEnMano=0;
}


//************************************************************************************************************************
void ManoBlackJack::ImprimirMano(int ocultas)
{
    //FIXME
    int sangriaCarta=2*(cartas[0].GetAncho())/5;
    for(int i=0;i<ocultas;i++)
    {
        cartas[i].ImprimirReverso(posX+sangriaCarta*i,posY);
    }
    for(int i=ocultas;i<cartasEnMano;i++)
    {
        cartas[i].ImprimirFrente(posX+sangriaCarta*i,posY);
    }
}


//************************************************************************************************************************
int ManoBlackJack::GetPuntos ()
{
    int puntos=0;
    int azes=0;
    for(int i=0;i<cartasEnMano;i++)
    {
        int numCarta=cartas[i].GetNumeracion();
        switch (numCarta)
        {
            case J:
                puntos+=10;
                break;

            case Q:
                puntos+=10;
                break;

            case K:
                puntos+=10;
                break;

            case 1:
                puntos+=11;
                azes++;
                break;

            default:
                puntos+=numCarta;
                break;
        }
        if(puntos>22)
        {
            while(puntos>22 && azes>0)
            {
                azes--;
                puntos-=10;
            }
        }
    }
    return puntos;
}


//************************************************************************************************************************
int ManoBlackJack::GetTamano () const
{
    return cartasEnMano;
}

//************************************************************************************************************************
void ManoBlackJack::AgregarCarta(const Carta &carta)
{
    cartas[cartasEnMano]=carta;
    cartasEnMano++;
}


//************************************************************************************************************************
void ManoBlackJack::VaciarMano()
{
    int sangriaCarta=2*(cartas[0].GetAncho())/5;
    int finJ=sangriaCarta*(cartasEnMano-1)+cartas[0].GetAncho();
    int finI=cartas[0].GetAlto();
    for(int i=0; i<finI ;i++)
    {
        gotoxy(posX,posY+i);
        for(int j=0;j<finJ;j++)
            std::cout<<' ';
    }
    cartasEnMano=0;
}
