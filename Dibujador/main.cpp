/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<bits/stdc++.h>
#include"Utileria.h"

using namespace std;

bool DibujarAltaRes(const char* carpeta);

int main()
{
    estadoCursor(APAGADO);
    char nomCarp[100];
    char aux;
    while(true)
    {
        cin>>nomCarp;

        DibujarAltaRes(nomCarp);

        system("pause");
        system("cls");
    }

    system("pause");
    return 0;
}

bool DibujarAltaRes(const char* carpeta)
{
    char DirLin[100],DirCol[100];
    WORD colorOriginal=ObtenerColorOriginal();
    int posY=0,posX=0, ancho,alto,maxAlto=-1;


    for(int i=1; i<=2;i++)
    {
        sprintf(DirLin,"%s\\Lin%i",carpeta,i);

        int j=1;
        while(true)
        {

            sprintf(DirCol,"%s\\Col%i.txt",DirLin,j);
            ifstream archivo(DirCol);

            if(!archivo)
            {
                archivo.close();
                break;
            }

            DibujarArchivoAColor(ancho,alto,DirCol,posX,posY,BLANCO,ROJOCLARO);
            archivo.close();

            posX+=ancho;
            maxAlto= maxAlto > alto ? maxAlto=maxAlto : maxAlto = alto;
            j++;

        }


        posY=maxAlto-1;
        posX=0;
    }

    EstablecerColor(colorOriginal);
    return true;
}
