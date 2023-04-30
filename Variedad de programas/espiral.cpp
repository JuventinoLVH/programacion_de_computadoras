/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

int main()
{
    int limiteInfVert=0 ,limiteSupVert=3 ,limiteInfHor=0 ,limiteSupHor=5 ,cont=0;
    int arr[5][3];
    int maximo=limiteSupVert*limiteSupHor;
    while(cont<maximo)
    {
        //Línea inferior horizontal (>)
        for(int i=limiteInfHor ,j=limiteInfVert ;j<limiteSupVert && cont<maximo ;j++)
            arr[i][j]=cont++;
        limiteInfHor++;

        //Línea superior vertical (v)
        for(int i=limiteInfHor ,j=limiteSupVert-1 ;i<limiteSupHor && cont<maximo ;i++)
            arr[i][j]=cont++;
        limiteSupVert--;

        //Línea superior horizontal (<)
        for(int i=limiteSupHor-1 ,j=limiteSupVert-1 ;j>=limiteInfVert && cont<maximo ;j--)
            arr[i][j]=cont++;
        limiteSupHor--;

        //Línea inf vertical (^)
        for(int i=limiteSupHor-1 ,j=limiteInfVert ;i>=limiteInfHor && cont<maximo ;i--)
            arr[i][j]=cont++;
        limiteInfVert++;
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
            cout<<setw(4)<<arr[i][j];
        cout<<'\n';
    }
    return 0;
}
