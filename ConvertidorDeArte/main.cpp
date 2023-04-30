/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    {
        ifstream archivo;
        string texto;
        archivo.open("Texto.txt",ios::in);

        if(archivo.fail())
        {
            cout<<"Dominacion total del mundo a manos de que los textos fallen\n";
            cout<<"Error Fatal\n";
            system("Pause");
            exit(1);
        }
        cout<<'\n';
        for(int i=0;!archivo.eof();i++)
        {

            getline(archivo,texto);
            cout<<"gotoxy(x,y+"<<i<<");\n";
            cout<<"cout<<\"";

            for(int i=0,fin=texto.size();i<fin;i++)
            {
                if(texto[i]=='\\')
                {
                    cout<<"\\";
                }
                cout<<texto[i];
            }
            cout<<"\\n\";\n";
        }

        archivo.close();

        cout<<"\n";
        system("Pause");
        system("cls");
    }

    cout<<"\n";
    system("Pause");
    return 0;
}
