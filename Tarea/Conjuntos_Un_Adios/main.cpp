
#include <iostream>
#include <windows.h>
#include "Conjunto.h"
#include "Utileria.h"

using namespace std;

int main()
{
    bad_alloc;
    int cardAux=10;
    int opcion;
    cout
    Conjunto A(3),B(3);
    (A+B).Imprimir();
    return 0;
    cout<<"Buenas noches, a continuaci\242n se realizar\240n operaciones con conjuntos\n";

    do
    {
        cout<<"Menu:\n";
        cout<<"Uni\240n de 2 conjuntos: 1\n";
        cout<<"Intersecci\240n de 2 conjuntos: 1\n";
        cout<<"Resta de 2 conjuntos: 3\n";
        cout<<"Complemento de un conjunto respecto al universo: 4\n";
        cout<<"Ordenar un conjunto: 5\n";
        cout<<"Salir: 0\n";
        do
        {
            opcion=CapturaEntero("Opci\242n: ");
            if(opcion<0 || opcion >5)
                cout<<"Opci\242n no valida...\n";

        }while(opcion<0 || opcion >5);


        if(opcion==0)
                cout<<"Vuelva pronto :D\n\n ";

        try
        {
            if(opcion==1)
            {
                cardAux=CapturaEntero("Cardinalidad del primer conjunto A: ");
                Conjunto A(cardAux);
                cin>>A;

                cardAux=CapturaEntero("Cardinalidad del segundo conjunto B: ");
                Conjunto B(cardAux);
                cin>>B;

                cout<<"A+B = "<<A+B;
                (A.Unir(B))=B;
            }

            if(opcion==2)
            {
                cardAux=CapturaEntero("Cardinalidad del primer conjunto A: ");
                Conjunto A(cardAux);
                cin>>A;

                cardAux=CapturaEntero("Cardinalidad del segundo conjunto B: ");
                Conjunto B(cardAux);
                cin>>B;

                cout<<"A * B = "<<A*B;
            }

            if(opcion==3)
            {
                cardAux=CapturaEntero("Cardinalidad del primer conjunto A: ");
                Conjunto A(cardAux);
                cin>>A;

                cardAux=CapturaEntero("Cardinalidad del segundo conjunto B: ");
                Conjunto B(cardAux);
                cin>>B;


                cout<<"A-B = "<<A-B;
            }

            if(opcion==4)
            {
                cardAux=CapturaEntero("Cardinalidad del Universo: ");
                Conjunto universo(cardAux);
                cin>>universo;

                bool contiene;
                do
                {
                    cardAux=CapturaEntero("Cardinalidad de un conjunto A: ");
                    Conjunto A(cardAux);
                    cin>>A;

                    contiene=universo.Contiene(A);
                    if(!contiene)
                        cout<<"El universo debe contener a A...\n";
                    else
                        cout<<"A' = "<<universo-A;

                }while(!contiene);

            }

            if(opcion==5)
            {
                cardAux=CapturaEntero("Cardinalidad de un conjunto A: ");
                Conjunto A(cardAux);
                cin>>A;

                cout<<"Conjunto sin ordenar : "<<A<<'\n';

                bool ordenado=false;
                int cardA=A.GetCardinalidad();
                for(int i=0;!ordenado;i++)
                {
                    ordenado=true;
                    for(int j=0 ,fin=cardA-i-1;j<fin;j++)
                    {
                        if(A[j] > A[j+1])
                        {
                            char aux=A[j];
                            A[j]=A[j+1];
                            A[j+1]=aux;
                            ordenado=false;
                        }
                    }
                }

                cout<<"Conjunto ordenado : "<<A<<'\n';
            }
            system("pause");
            system("cls");
        }
        catch(bad_alloc)
        {
            cout<<"Error al asignar la memoria...\n";
        }
        catch(...)
        {
            cout<<"Ocurrio un error inesperado...\n";
        }

    }while(opcion!=0);
    return 0;
}
