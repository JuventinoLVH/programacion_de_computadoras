/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<iostream>
#include<cstdlib>

using namespace std;
int main(){
    int arreglo[5][3];

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
            arreglo[i][j]=(j+1)+(i*3);
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arreglo[i][j]<<" ";
        }
        cout<<'\n';
    }

    system("pause");
    return 0;
}
