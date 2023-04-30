/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<iostream>
#include<cstdlib>

using namespace std;

const int ALTO=10;
const int ANCHO=10;
int main()
{
    int arr[ALTO][ANCHO]={};
    int coX,coY;

    for(int i=0;i<ALTO;i++)
    {
        for(int j=0;j<ANCHO;j++)
        {
            cout<<arr[i][j];
        }
        cout<<'\n';
    }

    cout<<"Coordenada en X: ";
    cin>>coX;
    cout<<"Coordenada en Y: ";
    cin>>coY;

    system("cls");

    for(int i=-1; i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(coY+i>=0 && coX+j>=0 && coY+i<ALTO && coX+j<ANCHO)
                arr[coY+i][coX+j]=1;
        }
    }

    /*
    arr[coY][coX]=1;

    if(coY-1>=0)
        arr[coY-1][coX]=1;

    if(coX-1>=0)
        arr[coY][coX-1]=1;

    if(coY+1<ALTO)
        arr[coY+1][coX]=1;

    if(coX+1<ANCHO)
        arr[coY][coX+1]=1;

    if(coY-1>=0 && coX-1>=0)
        arr[coY-1][coX-1]=1;

    if(coY-1>=0 && coX+1>=0)
        arr[coY-1][coX+1]=1;

    if(coY+1>=0 && coX-1>=0)
        arr[coY+1][coX-1]=1;

    if(coY+1>=0 && coX+1>=0)
        arr[coY+1][coX+1]=1;
    */

    for(int i=0;i<ALTO;i++)
    {
        for(int j=0;j<ANCHO;j++)
        {
            cout<<arr[i][j];
        }
        cout<<'\n';
    }

    system("pause");
    return 0;
}
