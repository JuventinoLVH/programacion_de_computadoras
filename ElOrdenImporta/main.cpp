/*
 Nombre: main.h
 Autor: Luis Juventino Velasquez Hidalgo
 Fecha: 3/19/2020
 Descripción: Programa que pide 3 valores y los ordena de forma ascendente y descendente
*/

#include <iostream>
#include "Utileria.h"

using namespace std;

int main()
{
    char val1,val2,val3;
    cout<<"Buenas, a continuaci\242n se ordenaran 3 valores tanto de"<<
        "forma ascendente como de forma descendente\n";

    cout<<"Valor 1: ";
    cin>>val1;
    cout<<"Valor 2: ";
    cin>>val2;
    cout<<"valor 3: ";
    cin>>val3;

    cout<<"Aqu\241 est\240n sus 3 valores ordenadas de forma ascendente:\n";
    OrdenarTres(val1,val2,val3,Ascendente);
    cout<<val1<<" < "<<val2<<" < "<<val3<<"\n\n";
    system("pause");

    cout<<"\nAqu\241 est\240n sus 3 valores ordenadas de forma descendiente:\n";
    OrdenarTres(val1,val2,val3,Descendente);
    cout<<val1<<" > "<<val2<<" > "<<val3<<"\n\n";
    system("pause");

    return 0;
}
