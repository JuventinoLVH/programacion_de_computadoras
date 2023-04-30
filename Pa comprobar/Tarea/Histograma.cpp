/* Nombre: Histograma.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 25/04/2020
   Descripción: Funciones para imprimir histogramas
*/

#include "Histograma.h"

//*************************************************************************************************************************
void Histograma(const int arreglo[] ,int largo ,int posY ,int posX ,char caracter)
{
    for(int i=0;i<MAX_ALTURA;i++)
    {
        gotoxy(posX,posY++);

        for(int j=0;j<largo;j++)
        {
            if(arreglo[j] >= MAX_ALTURA-i)
                std::cout<<caracter;
            else
                std::cout<<' ';
        }
    }
    return;
}

//*************************************************************************************************************************
void Intercambiar2ColumnasHistograma(const int arreglo[] ,int columna1 ,int columna2 ,int posY ,int posX ,char caracter)
{
    DibujarColumna(arreglo[columna2] ,posY ,posX+columna1 ,caracter);

    DibujarColumna(arreglo[columna1] ,posY ,posX+columna2 ,caracter);
}

//*************************************************************************************************************************
void DibujarColumna(int altura ,int posY ,int posX ,char caracter)
{
    int diferencia= MAX_ALTURA-altura;

    for(int i=0;i<diferencia;i++)
    {
        gotoxy(posX,posY+i);
        std::cout<<' ';
    }
    for(int i=diferencia;i<MAX_ALTURA;i++)
    {
        gotoxy(posX,posY+i);
        std::cout<<caracter;
    }
}
