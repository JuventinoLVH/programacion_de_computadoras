/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 25/04/2020
   Descripción: Programa que imprime un histograma y lo ordena
*/

#include <iostream>
#include <stdio.h>
#include "OrdenarConHistogramas.h"

const int posX=20;
const int posY=7;

using namespace std;

//*******************************************************************************************************************
/** \brief Función que captura un arreglo
 *
 * \param arr arreglo a capturar
 * \param tam tamaño del arreglo
 *
 */
void CapturarArreglo(int arr[] ,int tam);

//*******************************************************************************************************************
/** \brief Función que asigna valores random a un arreglo
 *
 * \param arr arreglo a randomizar
 * \param tam tamaño del arreglo
 *
 */
void RandomizarArreglo(int arr[] ,int tam);

int main()
{
    int opcion=0;
    char eleccion;

    do
    {
        cout<<"A continuaci\242 se ordenar\240 un arreglo de forma divertida(Con histograma) :D\n";
        cout<<"\nM\202todo de ordenamiento: ";
        cout<<"\nBurbuja: 1";
        cout<<"\nInserci\242n: 2";
        cout<<"\nQuickShort: 3";
        cout<<"\nSelecci\242n: 4";
        cout<<"\nMerge Short: 5";
        cout<<"\nSalir: 0";
        do
        {
            opcion=CapturaEntero("\nOpci\242n: ");
            if(opcion<0 || opcion>5)
                cout<<"Opci\242n no valida...\n";

        }while(opcion<0 || opcion>5);

        system("cls");
        if(opcion)
        {
            try
            {
                int *arreglo;
                int largo;
                char caracter;
                bool pausa;

                do
                {
                    largo=CapturaEntero("Largo del arreglo a imprimir[0,70]: ");
                    if(largo<0 || largo >70)
                        cout<<"Valor fuera del rango...\n";

                }while(largo<0 || largo >70);
                arreglo=CrearArreglo(largo);

                do
                {
                    cout<<"Quiere valores al azar en el arreglo?(Y/N): ";
                    cin>>eleccion;
                    if(eleccion != 'Y' && eleccion !='N')
                        cout<<"Opci\242n no valida...\n";

                }while(eleccion != 'Y' && eleccion !='N');
                if(eleccion=='Y')
                    RandomizarArreglo(arreglo,largo);
                else
                    CapturarArreglo(arreglo,largo);

                do
                {
                    cout<<"El histograma avanza manualmente?(Y/N): ";
                    cin>>eleccion;
                    if(eleccion != 'Y' && eleccion !='N')
                        cout<<"Opci\242n no valida...\n";

                }while(eleccion != 'Y' && eleccion !='N');
                if(eleccion=='Y')
                    pausa=true;
                else
                    pausa=false;

                cout<<"Caracter con el que se imprimir\240 el histograma: ";
                cin>>caracter;

                system("cls");
                Histograma(arreglo,largo,posY,posX,caracter);
                switch(opcion)
                {
                    case 1:
                        BurbujaHistograma(arreglo,largo,posY,posX,caracter,pausa);
                        break;

                    case 2:
                        InsercionHistograma(arreglo,largo,posY,posX,caracter,pausa);
                        break;

                    case 3:
                        ShortHistograma(arreglo,0,largo-1,posY,posX,caracter,pausa);
                        break;

                    case 4:
                        SeleccionHistograma(arreglo,largo,posY,posX,caracter,pausa);
                        break;

                    case 5:
                        MergeHistograma(arreglo,largo,posY,posX,caracter,pausa);
                        break;
                }
                BorrarArreglo(arreglo);
            }
            catch(bad_alloc)
            {
                cout<<"Error en la memoria...";
                return 1;
            }
        }
        gotoxy(0,0);
        cout<<"Fin\n";
        system("pause");
        system("cls");

    }while(opcion);

    cout<<"Gracias por usar esta app\n";
    system("pause");
    return 0;
}

//*******************************************************************************************************************
void CapturarArreglo(int arr[] ,int tam)
{
    char mensaje[50];
    for(int i=0 ; i<tam  ;i++)
    {
        do
        {
            sprintf(mensaje,"Elemento %d del arreglo[0,%d]: ",i,MAX_ALTURA);
            arr[i]=CapturaEntero(mensaje);
            if(arr[i]<0 || arr[i]>MAX_ALTURA)
                cout<<"valor fuera del rango...\n";

        }while(arr[i]<0 || arr[i]>MAX_ALTURA);
    }
}

//*******************************************************************************************************************
void RandomizarArreglo(int arr[] ,int tam)
{
    for(int i=0;i<tam;i++)
    {
        arr[i]=rand()%(MAX_ALTURA+1);
    }
}
