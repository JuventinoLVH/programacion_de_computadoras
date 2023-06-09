/*
 Nombre: Carta.cpp
 Autor: Luis J. Velasquez Hidalgo
 Fecha: 02/03/2020
 Descripci�n: Imprime cartas de una baraja
*/

#include "Carta.h"


void ImprimirCartaRandom(int posX, int posY)
{
    int cartaNum=rand()%13+1;
    int cartaSimb=rand()%4+3;
    ImprimirCarta(cartaNum,cartaSimb,posX,posY);
}

void ImprimirReversoCarta(int posX, int posY)
{
    WORD original=ObtenerColorOriginal();
    EstablecerColor(BLANCO,ROJO);

    ImprimirMarco(13,13,posX,posY);
    for(int i=posY+1;i<=posY+11;i++)
    {
        gotoxy(posX+1,i);
        for(int j=1;j<=11;j++)
            std::cout<<(char)178;
    }

    EstablecerColor(original);
}

void ImprimirCarta(int numero, char simbolo, int posX, int posY)
{
    WORD original=ObtenerColorOriginal();

    //Establecer el color de la carta
    if(simbolo==CORAZON || simbolo==DIAMANTE)
        EstablecerColor(BLANCO,ROJO);
    else
        EstablecerColor(BLANCO,NEGRO);


    //Marco de la carta
    for(int i=posY;i<=posY+12;i++)
    {
        gotoxy(posX,i);
        for(int j=0;j<=12;j++)
            std::cout<<" ";
    }
    ImprimirMarco(9,11,posX+2,posY+1);

    //Imprimimos los s�mbolos de la esquina superior izquierda
    posX++,posY++;
    gotoxy(posX,posY+1);
    std::cout<<simbolo;
    gotoxy(posX+10,posY+9);
    std::cout<<simbolo;

    //Imprimimos los s�mbolos de la esquina inferior derecha
    switch(numero)
    {
        case 10:
            gotoxy(posX,posY);
            std::cout<<"10";
            gotoxy(posX+9,posY+10);
            std::cout<<"10";
            break;
        case J:
            gotoxy(posX,posY);
            std::cout<<'J';
            gotoxy(posX+10,posY+10);
            std::cout<<'J';
            break;
        case Q:
            gotoxy(posX,posY);
            std::cout<<'Q';
            gotoxy(posX+10,posY+10);
            std::cout<<'Q';
            break;
        case K:
            gotoxy(posX,posY);
            std::cout<<'K';
            gotoxy(posX+10,posY+10);
            std::cout<<'K';
            break;
        default:
            gotoxy(posX,posY);
            std::cout<<numero;
            gotoxy(posX+10,posY+10);
            std::cout<<numero;
            break;
    }

    //Imprimimos el numero de simbolos
    switch(numero)
    {
        case 1:
            Dibujar1(simbolo,posX+5,posY+5);
            break;
        case 2:
            Dibujar2Vertical(simbolo,posX+5,posY+3);
            break;
        case 3:
            Dibujar3(simbolo,posX+8,posY+3);
            break;
        case 4:
             Dibujar4(simbolo,posX+3,posY+2);
             break;
        case 5:
            Dibujar5(simbolo,posX+3,posY+2);
            break;
        case 6:
            Dibujar6(simbolo,posX+3,posY+2);
            break;
        case 7:
            Dibujar7(simbolo,posX+3,posY+2);
            break;
        case 8:
            Dibujar8(simbolo,posX+3,posY+2);
            break;
        case 9:
            Dibujar9(simbolo,posX+3,posY+2);
            break;
        case 10:
            Dibujar10(simbolo,posX+3,posY+2);
            break;
        case 11:
            DibujarJ(simbolo,posX+3,posY+3);
            break;
        case 12:
            DibujarQ(simbolo,posX+4,posY+2);
            break;
        case 13:
            DibujarK(simbolo,posX+3,posY+3);
            break;
    }

    EstablecerColor(original);
}

void Dibujar1(char simbolo, int posX, int posY)
{
    gotoxy(posX,posY);
    std::cout<<simbolo;
}

void Dibujar2Vertical(char simbolo, int posX, int posY)
{
    gotoxy(posX,posY);
    std::cout<<simbolo;
    gotoxy(posX,posY+4);
    std::cout<<simbolo;
}

void Dibujar2(char simbolo, int posX, int posY)
{
    gotoxy(posX,posY);
    std::cout<<simbolo;
    gotoxy(posX+4,posY);
    std::cout<<simbolo;
}

void Dibujar3(char simbolo,int posX, int posY)
{
    gotoxy(posX-1,posY-1);
    std::cout<<simbolo;
    gotoxy(posX-3,posY+2);
    std::cout<<simbolo;
    gotoxy(posX-5,posY+5);
    std::cout<<simbolo;
}

void Dibujar4(char simbolo, int posX,int posY)
{
    Dibujar2(simbolo,posX,posY);
    Dibujar2(simbolo,posX,posY+6);
}
void Dibujar5(char simbolo,int posX, int posY)
{
    Dibujar4(simbolo,posX,posY);
    Dibujar1(simbolo,posX+2,posY+3);
}

void Dibujar6(char simbolo, int posX,int posY)
{
    Dibujar4(simbolo,posX,posY);
    Dibujar2(simbolo,posX,posY+3);
}

void Dibujar7(char simbolo, int posX,int posY)
{
    Dibujar6(simbolo,posX,posY);
    Dibujar1(simbolo,posX+2,posY+1);
}

void Dibujar8(char simbolo, int posX,int posY)
{
    Dibujar2Vertical(simbolo,posX+2,posY+1);
    Dibujar6(simbolo,posX,posY);
}

void Dibujar9(char simbolo, int posX,int posY)
{
    Dibujar2(simbolo,posX,posY);
    Dibujar2(simbolo,posX,posY+2);
    Dibujar1(simbolo,posX+2,posY+3);
    Dibujar2(simbolo,posX,posY+4);
    Dibujar2(simbolo,posX,posY+6);

}

void Dibujar10(char simbolo,int posX, int posY)
{
    Dibujar2(simbolo,posX,posY);
    Dibujar2(simbolo,posX,posY+2);
    Dibujar2(simbolo,posX,posY+4);
    Dibujar2(simbolo,posX,posY+6);
    Dibujar2Vertical(simbolo,posX+2,posY+1);
}

void DibujarJ(char simbolo,int posX, int posY)
{
    //Parte superior de la letra J
    gotoxy(posX,posY);
    for(int i=0;i<5;i++)
    {
        std::cout<<simbolo;
    }

    //L�nea vertical de la letra J
    for(int i=1;i<=3;i++)
    {
        gotoxy(posX+2,posY+i);
        std::cout<<simbolo;
    }

    //Curva inferior de la letra J
    gotoxy(posX,posY+3);
    std::cout<<simbolo;
    gotoxy(posX+1,posY+4);
    std::cout<<simbolo;
}

void DibujarQ(char simbolo,int posX, int posY)
{
    //Parte superior de la letra Q
    gotoxy(posX,posY);
    for(int i=0;i<3;i++)
        std::cout<<simbolo;

    //Lineas paralelas de la letra Q
    for(int i=1;i<=4;i++)
    {
        gotoxy(posX-1,posY+i);
        std::cout<<simbolo;
        gotoxy(posX+3,posY+i);
        std::cout<<simbolo;
    }

    //colita de la letra Q
    gotoxy(posX,posY+5);
    for(int i=0;i<2;i++)
        std::cout<<simbolo;

    gotoxy(posX+1,posY+6);
    for(int i=0;i<2;i++)
        std::cout<<simbolo;

    gotoxy(posX+2,posY+4);
    std::cout<<simbolo;

    //Borramos el car�cter excedente imprimido por las l�neas paralelas
    gotoxy(posX+3,posY+4);
    std::cout<<" ";

}

void DibujarK(char simbolo,int posX, int posY)
{
    //L�nea vertical de la letra K
    for(int i=0;i<=4;i++)
    {
        gotoxy(posX,posY+i);
        std::cout<<simbolo;
    }

    //Punto que conecta la l�nea vertical con las l�neas diagonales de la letra K
    gotoxy(posX+3,posY+1);
    std::cout<<simbolo;

    //Lineas diagonales de la letra K
    for(int i=0;i<3;i++)
    {
        gotoxy(posX+2+i,posY+i+2);
        std::cout<<simbolo;
    }
    for(int i=0;i<2;i++)
    {
        gotoxy(posX+3+i,posY-i+1);
        std::cout<<simbolo;
    }
}



