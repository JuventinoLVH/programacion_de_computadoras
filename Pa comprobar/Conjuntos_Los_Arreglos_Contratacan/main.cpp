/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 10/04/2020
   Descripción: Archivo donde se calcularan varias operaciones de conjuntos
*/

#include <iostream>
#include "GestionConjuntos.h"

using namespace std;
/** \brief función que la opcion del menu
 *
 * \return La opción del usuario
 *
 */
int Menu();

int main()
{
    int opcion;
    int tipo=0;

    do
    {
        cout<<"A continuaci\242n se ejecutaran varias operaciones con onjuntos\n ";
        opcion=Menu();

        system("cls");
        switch(opcion)
        {
            case 1:
                GestionUnion(tipo);
                break;
            case 2:
                GestionInterseccion(tipo);
                break;
            case 3:
                GestionDiferencia(tipo);
                break;
            case 4:
                GestionComplemento(tipo);
                break;
            case 5:
                GestionPertenencia(tipo);
                break;
            case 6:
                GestionContencion(tipo);
                break;
            case 0:
                cout<<"Muchas gracias por usar nuestro servicio, vuelva pronto :D";
                break;
        }

        cout<<'\n';
        system("pause");
        system("cls");

    }while(opcion!=0);

    return 0;
}

int Menu()
{
    int opcion;
    do
    {
        cout<<"\nMenu de conjuntos: ";
        cout<<"\nUni\242n: 1";
        cout<<"\nIntersecci\242n: 2";
        cout<<"\nDiferencia: 3";
        cout<<"\nComplemento: 4";
        cout<<"\nPertenencia: 5";
        cout<<"\nContencia: 6";
        cout<<"\nSalir: 0";
        CapturaSegura(opcion,"\nOpci\242n: ");
        if(opcion>6 || opcion<0)
            cout<<"Opci\242n no valida...";

    }while(opcion>6 || opcion<0);
    return opcion;
}
