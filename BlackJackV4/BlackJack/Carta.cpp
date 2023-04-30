/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include "Carta.h"



//*************************************************************************************************************************
Carta::Carta()
{
    numeracion=1;
    simbolo=CORAZON;
    alto=TAMANO_DEFAULT;
    ancho=TAMANO_DEFAULT+2;
}


//*************************************************************************************************************************
Carta::Carta(int num,Simbolo simb)
{
    numeracion=num;
    simbolo=simb;
    alto=TAMANO_DEFAULT;
    ancho=TAMANO_DEFAULT+2;
}


//*************************************************************************************************************************
Carta::Carta(int num,Simbolo simb,int altoCar,int anchoCar)
{
    numeracion=num;
    simbolo=simb;
    alto=altoCar;
    ancho=anchoCar;
}


//*************************************************************************************************************************
int Carta::GetNumeracion () const
{
    int numAux=numeracion;
    return numAux;
}


//*************************************************************************************************************************
int Carta::GetAncho () const
{
    return ancho;
}


//*************************************************************************************************************************
int Carta::GetAlto () const
{
    return alto;
}


//*************************************************************************************************************************
char Carta::GetSimbolo () const
{
    return simbolo;
}


//*************************************************************************************************************************
void Carta::ImprimirFrente(int posX ,int posY ,Color borde ,Color fondo)
{
    WORD original=ObtenerColorOriginal();

    //Establecer el color de la carta
    if(simbolo==CORAZON || simbolo==DIAMANTE)
        EstablecerColor(fondo,ROJO);
    else
        EstablecerColor(fondo,NEGRO);


    //Marco de la carta
    for(int i=0;i<alto;i++)
    {
        gotoxy(posX,posY+i);
        for(int j=0;j<ancho;j++)
            std::cout<<" ";
    }
    DibujarMarco(alto-2,ancho-4,posX+2,posY+1,0,fondo,borde,false);

    //Imprimimos los símbolos
    gotoxy(posX+1,posY+2);
    std::cout<<simbolo;
    gotoxy(posX+(ancho-1)-1 ,posY+(alto-1)-1);
    std::cout<<simbolo;

    //Imprimimos la numeracion
    switch(numeracion)
    {
        case 1:
            gotoxy(posX+1,posY+1);
            std::cout<<'A';
            gotoxy(posX+(ancho-1)-1 ,posY+(alto-1)-2);
            std::cout<<'A';
            break;
        case 10:
            gotoxy(posX,posY+1);
            std::cout<<numeracion;
            gotoxy(posX+(ancho-1)-1 ,posY+(alto-1)-2);
            std::cout<<"10";
            break;
        case J:
            gotoxy(posX+1,posY+1);
            std::cout<<'J';
            gotoxy(posX+(ancho-1)-1 ,posY+(alto-1)-2);
            std::cout<<'J';
            break;
        case Q:
            gotoxy(posX+1,posY+1);
            std::cout<<'Q';
            gotoxy(posX+(ancho-1)-1 ,posY+(alto-1)-2);
            std::cout<<'Q';
            break;
        case K:
            gotoxy(posX+1,posY+1);
            std::cout<<'K';
            gotoxy(posX+(ancho-1)-1 ,posY+(alto-1)-2);
            std::cout<<'K';
            break;
        default:
            gotoxy(posX+1,posY+1);
            std::cout<<numeracion;
            gotoxy(posX+(ancho-1)-1 ,posY+(alto-1)-2);
            std::cout<<numeracion;
            break;
    }

    //Imprimimos el numero de simbolos
    int posYMarco=posY+1;
    int altoAux=alto-4;
    int posXMarco=posX+2;
    int anchoAux=ancho-6;

    switch(numeracion)
    {
        case 1:

            gotoxy(posXMarco+1+(anchoAux/2) , posYMarco+1+(altoAux/2));
            std::cout<<simbolo;
            break;
        case 2:
            Imprimir2Simbolos(posX , posYMarco+1+(altoAux/2));
            break;
        case 3:
            gotoxy(posXMarco+(anchoAux/2)+1 , posYMarco+1+(altoAux/2));
            std::cout<<simbolo;

            gotoxy(posXMarco+anchoAux+1-(anchoAux/3) , posYMarco+(altoAux/3));
            std::cout<<simbolo;

            gotoxy(posXMarco+(anchoAux/3) , posYMarco+altoAux+1-(altoAux/3));
            std::cout<<simbolo;
            break;
        case 4:
             Imprimir2Simbolos(posX , posYMarco+(altoAux/4));
             Imprimir2Simbolos(posX , posYMarco+altoAux+1-(altoAux/4));
             break;
        case 5:
            Imprimir2Simbolos(posX , posYMarco+(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+altoAux+1-(altoAux/4));
            gotoxy(posXMarco+1+(anchoAux/2) , posYMarco+1+(altoAux/2));
            std::cout<<simbolo;
            break;
        case 6:
            Imprimir2Simbolos(posX , posYMarco+1+(altoAux/2));
            Imprimir2Simbolos(posX , posYMarco+(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+altoAux+1-(altoAux/4));

            break;
        case 7:
            Imprimir2Simbolos(posX , posYMarco+1+(altoAux/2));
            Imprimir2Simbolos(posX , posYMarco+(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+altoAux+1-(altoAux/4));

            gotoxy(posXMarco+1+(anchoAux/2) ,posYMarco+(altoAux/3));
            std::cout<<simbolo;

            break;
        case 8:
            Imprimir2Simbolos(posX , posYMarco+1+(altoAux/2));
            Imprimir2Simbolos(posX , posYMarco+(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+altoAux+1-(altoAux/4));

            gotoxy(posXMarco+1+(anchoAux/2) ,posYMarco+(altoAux/3));
            std::cout<<simbolo;

            gotoxy(posXMarco+1+(anchoAux/2) ,posYMarco+altoAux+1-(altoAux/3));
            std::cout<<simbolo;
            break;
        case 9:
            Imprimir2Simbolos(posX , posYMarco+(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+2*(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+altoAux+1-(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+altoAux+1-2*(altoAux/4));

            gotoxy(posXMarco+1+(anchoAux/2) , posYMarco+1+(altoAux/2));
            std::cout<<simbolo;

            break;
        case 10:
            Imprimir2Simbolos(posX , posYMarco+(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+2*(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+altoAux+1-(altoAux/4));
            Imprimir2Simbolos(posX , posYMarco+altoAux+1-2*(altoAux/4));

            gotoxy(posXMarco+1+(anchoAux/2) ,posYMarco+(altoAux/3));
            std::cout<<simbolo;

            gotoxy(posXMarco+1+(anchoAux/2) ,posYMarco+altoAux+1-(altoAux/3));
            std::cout<<simbolo;

            break;
        case 11:
            //DibujarJ(simbolo,posX+3,posY+3);
            break;
        case 12:
            //DibujarQ(simbolo,posX+4,posY+2);
            break;
        case 13:
            //DibujarK(simbolo,posX+3,posY+3);
            break;
    }

    EstablecerColor(original);
}


//*************************************************************************************************************************
void Carta::ImprimirReverso(int posX ,int posY ,Color borde ,Color fondo ,Color relleno)
{
    WORD original=ObtenerColorOriginal();

    EstablecerColor(fondo,relleno);

    for(int i=0;i<alto;i++)
    {
        gotoxy(posX,posY+i);
        for(int j=0;j<ancho;j++)
            std::cout<<" ";
    }

    DibujarMarco(alto,ancho-2,posX+1,posY,0,fondo,borde,true,fondo);
    for(int i=1 ,finX=alto-1;i<finX;i++)
    {
        gotoxy(posX+2,posY+i);
        for(int j=2 ,finY=ancho-2;j<finY;j++)
            std::cout<<(char)178;
    }

    EstablecerColor(original);
}


//*************************************************************************************************************************
void Carta::Imprimir2Simbolos(int posX ,int posY)
{
    int anchoAux;
    anchoAux=ancho-6;

    gotoxy(posX+2+anchoAux/3 ,posY);
    std::cout<<simbolo;

    gotoxy(posX+ancho-3-anchoAux/3 ,posY);
    std::cout<<simbolo;
}
