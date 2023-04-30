/* Nombre: main.cpp
   Autor: Luis J. Velasquez Hidalgo
   Fecha: 19/04/20
   Descripción: Programa para calcular operaciones con polinomios
*/

#include <iostream>
#include "Gestion.h"

using namespace std;

int main()
{
    int opcion;

    do
    {
        cout<<"Buenas, a continaci\242 se efectuaran operaciones basicas con polinomios\n ";
        cout<<"\nMenu: ";
        cout<<"\nSuma de 2 polinomios: 1";
        cout<<"\nResta de 2 polinomios: 2";
        cout<<"\nMultiplicar 2 polinomios: 3";
        cout<<"\nDividir 2 polinomios: 4";
        cout<<"\nDerivar un polinomio: 5";
        cout<<"\nEvaluar un polinomio: 6";
        cout<<"\nSalir: 0";
        do
        {
            opcion=CapturaSegura("\nOpcion: ");
            if(opcion < 0 ||opcion > 6 )
                cout<<"\nOpci\242n no valida...";

        }while(opcion < 0 ||opcion > 6 );

        system("cls");
        switch(opcion)
        {
            case 1:
                GestionSuma();
                break;

            case 2:
                GestionResta();
                break;

            case 3:
                GestionMultiplicacion();
                break;

            case 4:
                GestionDividir();
                break;

            case 5:
                GestionDerivar();
                break;

            case 6:
                GestionEvaluar();
                break;
            case 0:
                cout<<"Gracias por usar esta aplicacion, vuelva pronto :D";
                break;
        }
        cout<<'\n';
        system("pause");
        system("cls");

    }while(opcion != 0);

    return 0;
}
