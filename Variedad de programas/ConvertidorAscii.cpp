/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<bits/stdc++.h>

using namespace std;


int main()
{


    cin.tie(0);
    ios_base::sync_with_stdio(0);

    char caracter[100]={0};
    while(true)
    {

        cin.getline(caracter,90);
        if(caracter[0]=='Q')
        {
            break;
        }
        cout<<"cout<<\"";

        int tam=strlen(caracter);
        for(int i=0;i<tam;i++)
        {
            if(caracter[i]=='\\')
            {
                cout<<"\\";
            }
            cout<<caracter[i];
        }
        cout<<"\\n\";\n";
    }
    return 0;
}
