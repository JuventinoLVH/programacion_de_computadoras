/* Nombre: Polinomios.cpp
   Autor: Todo el salon
   Fecha: La cuarentena me privo de la nocion del tiempo
   Descripción: Este programa imprimira un polinomio dado por el usuario
*/

#include<iostream>
#include<cstdlib>
#define GRADO_MAX 1002
using namespace std;
int main()
{
    int polinomio[GRADO_MAX];
    int grado;
    cout<<"A continuaci\242n se pedir\240 un polinomio\n";

    do
    {
        cout<<"Grado del polinomio: ";
        cin>>grado;
        if(grado<0)
            cout<<"No existen polinomios de grados negativos...";

    }while(grado<0);


    //Evaluó que exista el término grado “n”
    do
    {
        cout<<"coeficiente del termino grado "<<grado<<": ";
        cin>>polinomio[grado];
        if(!polinomio[grado])
            cout<<"El coeficiente no puede ser 0, pues el polinomio es de grado "<<grado<<'\n';

    }while(!polinomio[grado]);

    for(int i=grado-1 ; i>0 ;i--)
    {
        cout<<"coeficiente del termino grado "<<i<<": ";
        cin>>polinomio[i];
    }

    //pido el término independiente
    cout<<"coeficiente del termino independiente: ";
    cin>>polinomio[0];


    cout<< "Polinomio: \n";
    for(int i=grado; i>0 ;i--)
    {
        if(polinomio[i])
            if(polinomio[i]!=1)
                cout<<polinomio[i]<<"x^"<<i<<" + ";
            else
                cout<<"x^"<<i<<" + ";
    }
    //A diferencia de los demas términos, si imprimo el termino independiente cuando es 1
    if(polinomio[0])
        cout<<polinomio[0]<<'\n';


    system("pause");
    return 0;
}
