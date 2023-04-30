/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<iostream>
#include<cstdlib>

#define TAM_MAX 1000

using namespace std;


void imprimir(int arreglo[],int tam);

int main(){
    int arreglo[TAM_MAX]={1,2,3,4,5,6,7,8,10};

    //for(int *p=arreglo; p != arreglo+5;p++)
    //    cout<<*p;

    imprimir(arreglo,5);

    system("pause");
    return 0;
}

void imprimir(int arreglo[],int tam)
{
    cout<<arreglo[0];
    for(int i=1;i<tam;i++)
        cout<<','<<arreglo[i];
    cout<<'\n';

    return;
}
