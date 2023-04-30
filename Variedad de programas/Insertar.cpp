/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<iostream>
#include<cstdlib>

void inser(int arr[],int tam);

using namespace std;
int main()
{
    int arr[20]{1,9,6,4,3,5,7,8,2,10,0};
    //for(int i=0;i<=10;i++)
     //   arr[i]=rand()%20;

    for(int i=0;i<=10;i++)
        cout<<arr[i]<<" ";
    cout<<'\n';

    inser(arr,10);

    for(int i=0;i<=10;i++)
        cout<<arr[i]<<" ";
    cout<<'\n';

    return 0;
}

void inser(int arr[],int tam)
{
    int aux;
    for(int i=1;i<=tam;i++)
    {
        aux=arr[i];
        int j=i-1;
        for(;j>=0 && aux<arr[j];j--)
                arr[j+1]=arr[j];
        arr[j+1]=aux;
    }
}
