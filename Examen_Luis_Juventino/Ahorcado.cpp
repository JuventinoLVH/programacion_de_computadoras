/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include"Ahorcado.h"

//*************************************************************************************************************************
bool * EnmascararPalabra(const char *palabra ,int posX ,int posY ,char caracter)
{
    try
    {
        gotoxy(posX,posY);
        bool *estadoJuego=CrearArregloB(sizeof(palabra));

        for(int i=0;palabra[i];i++)
        {
            if(palabra[i] !=' ')
            {
                estadoJuego[i]=false;
                std::cout<<caracter;
            }
            else
            {
                estadoJuego[i]=true;
                std::cout<<palabra[i];
            }
        }

        return estadoJuego;
    }
    catch(...)
    {
        std::cout<<"Problema inesperado, no puedes jugar...";
        return NULL;
    }


}

//*************************************************************************************************************************
bool DestaparLetra(const char *palabra ,bool *estadoJuego ,char letra ,int posX ,int posY ,int suspenso)
{

    gotoxy(posX,posY);
    bool esta=false;

    Suspenso(suspenso,posX,posY+2);
    std::cout<<"                               ";

    for(int i=0; palabra[i] ;i++)
    {
        if( !estadoJuego[i] && CompararLetras(palabra[i] ,letra))
        {
            estadoJuego[i]=true;
            esta=true;

            gotoxy(posX+i ,posY);
            std::cout<<palabra[i];

            gotoxy(posX+4,posY+2);
            std::cout<<"S\241 est\240!";
            Suspenso(suspenso,posX,posY+2);
            gotoxy(posX+4,posY+2);
            std::cout<<"     ";
        }
    }

    if(!esta)
    {
        gotoxy(posX+4,posY+2);
        std::cout<<"No destapaste ninguna letra :(";
    }
    else
    {
        gotoxy(posX+4,posY+2);
        std::cout<<"Son todas";
    }

    return esta;
}

//*************************************************************************************************************************
bool EstadoGanado(const char *palabra ,const bool *estado)
{
    for(int i=0; palabra[i] ;i++)
    {
        if(!estado[i])
            return false;
    }
    return true;
}
