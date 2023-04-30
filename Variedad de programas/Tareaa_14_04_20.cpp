/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<iostream>
#include<cstdlib>
#include<math.h>

const int ALT_MAX = 20;

//*****************************************************************************************************************
int * CrearVector(int tamano);

//*****************************************************************************************************************
void Histograma(int *arreglo ,int largo ,int alturaMax ,char caracter);

//*****************************************************************************************************************
void Alterar(int *arreglo ,int tamano);

using namespace std;
int main()
{
    int *arreglo,tamano;
    char caracter;
    cout<<"A continuaci\242n se dibujaran cosas muy bonitas :D (Histograma)\n";

    cout<<"Caracter del histograma: ";
    cin>>caracter;
    cout<<"Largo del histograma: ";
    cin>>tamano;
    arreglo=CrearVector(tamano);

    for(int i=0;i<tamano;i++)
    {
        arreglo[i]=i+1;
    }

    Alterar(arreglo,tamano);

    cout<<'\n';
    Histograma(arreglo,tamano,tamano,caracter);

    cout<<'\t';
    for(int i=0;i<tamano;i++)
        cout<<'\t'<<arreglo[i];

    return 0;
}

int * CrearVector(int tamano)
{
    return new int [tamano];
}

void Histograma(int *arreglo ,int largo ,int alturaMax ,char caracter)
{
    /* ->(Se imprime en está direccion)
    *   ^    ^  .    ^ .      .  ^              ^          ^
    *   |    |  .    | .      .  |         (Se imprime)    |
    *   |    6  .    | .      .  AltM-x     AltM-(x-1)  altM-(x+1)
    *   |    |  .    8 .      .  |              |     (No se imprime)
    * AltM=9 |  .    | .      .  | ............ v          |
    *   |    v  .    | .      .  v                         |
    *   |    ^  #    | .      #  ^ ....................... v
    *   |    3  #    v .      #  x
    *   v    v  #      #      #  v
    *           3      1      x
    */
    for(int alt=0;alt<alturaMax;alt++)
    {
        //Tabulador para que se vea bonito
        cout<<'\t';

        for(int i=0;i<largo;i++)
        {
            cout<<'\t';

            if(alturaMax-alt>arreglo[i])
                cout<<' ';
            else
                cout<<caracter;
        }
        cout<<'\n';
    }
}

void Alterar(int *arreglo ,int tamano)
{
    int aux,aleatorio;
    for(int i=0;i<tamano;i++)
    {
        aleatorio=rand()%tamano;
        aux=arreglo[i];

        arreglo[i]=arreglo[aleatorio];
        arreglo[aleatorio]=aux;
    }
}
