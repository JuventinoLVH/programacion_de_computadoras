/* Nombre: OrdenanConHistogramas.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 26/04/20
   Descripción: Funciones que ordenan un arreglo e imprimen los pasos
*/

#include"OrdenarConHistogramas.h"

//*************************************************************************************************************************
/** \brief Función que pausa el programa
 *
 * \param opcion Forma en la que se pausa el programa, false= por tiempo, true=manual
 *
 */
void Pausa(bool opcion);

//*************************************************************************************************************************
/** \brief función que intercambia 2 números enteros
 *
 * \param A un numero
 * \param B otro numero
 *
 */
void Intercambiar(int &A ,int &B);

//*************************************************************************************************************************
/** \brief Función que parte un arreglo con un pivote
 *
 * \param arr arreglo a ordenar
 * \param izq límite inferior
 * \param der límite superior
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprimé el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 * \return el pivote
 *
 */
int Particion(int arr[] ,int izq ,int der ,int posY ,int posX ,char caracter ,bool tipoPausa);

//*************************************************************************************************************************
/** \brief Función que mezcla 2 arreglos
 *
 * \param arr arreglo a ordenar
 * \param izq arreglo izquierdo
 * \param larIzq tamaño del arreglo izquierdo
 * \param der arreglo derecho
 * \param larDer tamaño del arreglo derecho
 * \param posY coordenada en Y de la esquina superior del histograma original
 * \param posX coordenada en X de la esquina superior del histograma original
 * \param caracter caracter con el que se imprimé el histograma original
 * \param tipoPausa Tipo de la pausa entre cada movimiento
 *
 */
void Merge(int arr[] ,int izq[] ,int larIzq ,int der[] ,int larDer ,int posY ,int posX ,char caracter, bool tipoPausa);


//*************************************************************************************************************************
void BurbujaHistograma(int arr[] ,const int largo ,int posY ,int posX ,char caracter ,bool tipoPausa)
{
    for(int i=1;i<largo;i++)
    {
        for(int j=0;j<largo-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                Intercambiar2ColumnasHistograma(arr,j,j+1,posY,posX,caracter);
                Intercambiar(arr[j],arr[j+1]);
                Pausa(tipoPausa);
            }
        }

    }
}

//*************************************************************************************************************************
void InsercionHistograma(int arr[] ,const int largo ,int posY ,int posX ,char caracter ,bool tipoPausa)
{
    for(int i=1;i<largo;i++)
    {
        int aux=arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>aux)
            {
                arr[j+1]=arr[j];
                DibujarColumna(arr[j],posY,posX+j+1,caracter);
                Pausa(tipoPausa);
            }
            else
                break;
        }
        arr[j+1]=aux;
        DibujarColumna(aux,posY,posX+j+1,caracter);
        Pausa(tipoPausa);

    }
}

//*************************************************************************************************************************
void ShortHistograma(int arr[] ,int izq ,int der ,int posY ,int posX ,char caracter ,bool tipoPausa)
{
   int pivote;
   if(izq < der)
   {
       pivote=Particion(arr ,izq ,der ,posY ,posX,caracter,tipoPausa);
       ShortHistograma(arr ,izq ,pivote-1 ,posY ,posX,caracter,tipoPausa);
       ShortHistograma(arr ,pivote+1 ,der ,posY ,posX,caracter,tipoPausa);
   }
}

//*************************************************************************************************************************
void MergeHistograma(int arr[] ,int largo ,int posY ,int posX ,char caracter ,bool tipoPausa)
{
    if(largo==1)
        return;
    try
    {
        int mitad=largo/2;
        int *izq=CrearArreglo(mitad);
        int *der=CrearArreglo(largo-mitad);

        for(int i=0;i<mitad;i++)
           izq[i]=arr[i];

        for(int i=mitad;i<largo;i++)
            der[i-mitad]=arr[i];

        MergeHistograma(izq,mitad,posY,posX,caracter,tipoPausa);
        MergeHistograma(der,largo-mitad,posY,posX+mitad,caracter,tipoPausa);

        Merge(arr,izq,mitad,der,largo-mitad,posY,posX,caracter,tipoPausa);

        BorrarArreglo(izq);
        BorrarArreglo(der);

    }
    catch(std::bad_alloc )
    {
        std::cout<<"Error. Memoria insuficiente...";
        return;
    }

}

//*************************************************************************************************************************
void SeleccionHistograma(int arr[] ,int largo ,int posY ,int posX ,char caracter ,bool tipoPausa)
{
    int menor;
    for(int i=1;i<largo;i++)
    {
        menor=i-1;
        for(int j=i;j<largo;j++)
            if(arr[j]<arr[menor]) menor=j;

        Intercambiar2ColumnasHistograma(arr,i-1,menor,posY,posX,caracter);
        Intercambiar(arr[menor],arr[i-1]);
        Pausa(tipoPausa);
    }
}

//*************************************************************************************************************************
int Particion(int arr[] ,int izq ,int der ,int posY ,int posX ,char caracter ,bool tipoPausa)
{
    int i=izq ,j=der ,pivote=arr[izq];
    while(i<j)
    {
        while(arr[i]<=pivote) i++;
        while(arr[j]>pivote) j--;

        if(i<j)
        {
            Intercambiar2ColumnasHistograma(arr,i,j,posY,posX,caracter);
            Intercambiar(arr[i] ,arr[j]);
            Pausa(tipoPausa);
        }
    }
    Intercambiar2ColumnasHistograma(arr,izq,j,posY,posX,caracter);
    Intercambiar(arr[izq] ,arr[j]);
    Pausa(tipoPausa);
    return j;
}

//*************************************************************************************************************************
void Merge(int arr[] ,int izq[] ,int larIzq ,int der[] ,int larDer ,int posY ,int posX ,char caracter ,bool tipoPausa)
{
    int i=0,j=0,k=0;

    while(i<larIzq && j<larDer)
    {
        if(izq[i] <= der[j])
        {
            DibujarColumna(izq[i],posY,posX+k,caracter);
            arr[k++]=izq[i++];
            Pausa(tipoPausa);
        }
        else
        {
            DibujarColumna(der[j],posY,posX+k,caracter);
            arr[k++]=der[j++];
            Pausa(tipoPausa);
        }
    }

    while(i<larIzq)
    {
        DibujarColumna(izq[i],posY,posX+k,caracter);
        arr[k++]=izq[i++];
        Pausa(tipoPausa);
    }

    while(j<larDer)
    {
        DibujarColumna(der[j],posY,posX+k,caracter);
        arr[k++]=der[j++];
        Pausa(tipoPausa);
    }
}

//*************************************************************************************************************************
void Intercambiar(int &A ,int &B)
{
    int aux=A;
    A=B;
    B=aux;
    return;
}

//*************************************************************************************************************************
void Pausa(bool opcion)
{
    if(opcion)
    {
        gotoxy(0,0);
        system("pause");
    }
    else
        Sleep(espera);
}
