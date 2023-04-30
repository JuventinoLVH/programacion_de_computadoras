/* Nombre: Carta.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 27/05/2020
   Descripción: funciones de la carta
*/

#include "Carta.h"
#define alto 13
#define ancho 13


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 1
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar1(char simbolo, int posX, int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 2 de forma vertical
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar2Vertical(char simbolo, int posX, int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 2
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar2(char simbolo, int posX, int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 3
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar3(char simbolo,int posX, int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 4
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar4(char simbolo, int posX,int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 5
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar5(char simbolo,int posX, int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 6
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar6(char simbolo, int posX,int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 7
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar7(char simbolo, int posX,int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 8
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar8(char simbolo, int posX,int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 9
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar9(char simbolo, int posX,int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta 10
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void Dibujar10(char simbolo,int posX, int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta J
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void DibujarJ(char simbolo,int posX, int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta Q
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void DibujarQ(char simbolo,int posX, int posY);


//*********************************************************************************
/** \brief Función auxiliar para imprimir la carta K
 *
 * \param simbolo el simbolo de la carta
 * \param posX la coordenada en X de la equina superior
 * \param posY la coordenada en Y de la esquina superior
 *
 */
void DibujarK(char simbolo,int posX, int posY);


//*********************************************************************************
Carta::Carta(int num ,Simbolo simb)
{
    numeracion=num;
    simbolo=simb;
}


//*********************************************************************************
Carta::Carta(Letra num ,Simbolo simb)
{
    numeracion=num;
    simbolo=simb;
}


//*********************************************************************************
int Carta::GetNumeracion () const
{
    if(numeracion==1) return A;

    return numeracion;
}


//*********************************************************************************
char Carta::GetSimbolo () const
{
    return simbolo;
}


//chale, es cierto que ver los codigos viejos da asco :(
//*********************************************************************************
void Carta::ImprimirFrente(int posX ,int posY )
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
    DibujarMarco(11,9,posX+2,posY+1);

    //Imprimimos los símbolos de la esquina superior izquierda
    posX++,posY++;
    gotoxy(posX,posY+1);
    std::cout<<simbolo;
    gotoxy(posX+10,posY+9);
    std::cout<<simbolo;

    //Imprimimos los símbolos de la esquina inferior derecha
    switch(numeracion)
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

        case A:
            gotoxy(posX,posY);
            std::cout<<numeracion;
            gotoxy(posX+10,posY+10);
            std::cout<<numeracion;
            break;

        default:
            gotoxy(posX,posY);
            std::cout<<numeracion;
            gotoxy(posX+10,posY+10);
            std::cout<<numeracion;
            break;
    }

    //Imprimimos el numero de simbolos
    switch(numeracion)
    {
        case 1:
            Dibujar1(simbolo,posX+5,posY+5);
            break;
        case A:
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


//*********************************************************************************
void Carta::ImprimirReverso(int posX ,int posY )
{

    WORD original=ObtenerColorOriginal();

    EstablecerColor(BLANCO,ROJO);

    for(int i=0;i<alto;i++)
    {
        gotoxy(posX,posY+i);
        for(int j=0;j<ancho;j++)
            std::cout<<" ";
    }

    DibujarMarco(alto,ancho-2,posX+1,posY);
    for(int i=1 ,finX=alto-1;i<finX;i++)
    {
        gotoxy(posX+2,posY+i);
        for(int j=2 ,finY=ancho-2;j<finY;j++)
            std::cout<<(char)178;
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

    //Línea vertical de la letra J
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

    //Borramos el carácter excedente imprimido por las líneas paralelas
    gotoxy(posX+3,posY+4);
    std::cout<<" ";

}

void DibujarK(char simbolo,int posX, int posY)
{
    //Línea vertical de la letra K
    for(int i=0;i<=4;i++)
    {
        gotoxy(posX,posY+i);
        std::cout<<simbolo;
    }

    //Punto que conecta la línea vertical con las líneas diagonales de la letra K
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
