
#include <iostream>
#include "OperacionesConMatrices.h"

using namespace std;

//*************************************************************************************************************************
/** \brief Función que lee una matriz, ya sea por teclado o por archivo
 *
 * \param matriz dirección donde se guardará la matriz
 * \param n variable donde se guardará el numero de renglones
 * \param m variable donde se guardara el numero de columnas
 *
 * \return Si el usuario se dio por vencido
 */
bool leerMat(double **&matriz ,int &n ,int &m);

//*************************************************************************************************************************
/** \brief Función guarda una matriz en un archivo(Si el usuario quiere)
 *
 * \param matriz la matriz
 * \param n el numero de renglones
 * \param m el numero de columnas
 *
 */
void GuardarEnArchivo(double **&matriz ,int &n ,int &m);

int main()
{
    cout<<"Buenas tardes, a continuaci\242n se calcularan operaciones con matrices\n";
    int opcion,nReng1,nColumn1,nReng2,nColumn2,nRengRes,nColumnRes;
    double **matrizaux1,**matrizaux2,**matrizResultante,aux;
    char cadenaAux[100];
    do
    {
        cout<<"Menu: \n";
        cout<<"Guardar Matriz en archivo: 1\n";
        cout<<"Sumar matrices: 2\n";
        cout<<"Restar matrices: 3\n";
        cout<<"Multiplicar matrices: 4\n";
        cout<<"Multiplicar una matriz por un escalar: 5\n";
        cout<<"Encontrar la matriz transpuesta: 6\n";
        cout<<"Encontrar la matriz inversa: 7\n";
        cout<<"Imprimir una matriz de un archivo: 8\n";
        cout<<"Salir: 0\n";


        do
        {
            opcion=CapturaSegura("Opci\242n: ");
            if(opcion>8 || opcion<0)
                cout<<"Opci\242n no valida...";

        }while(opcion>8 || opcion<0);

        system("cls");
        switch(opcion)
        {
            case 0:
                cout<<"Gracias por usar este servicio :D\n";
                break;
            case 1:
                cout<<"Guardar Matriz en archivo:\n";

                nReng1=CapturaSegura("N\243mero de renglones: ");
                nColumn1=CapturaSegura("N\243mero de columnas: ");
                cout<<"Nombre del archivo: ";
                cin>>cadenaAux;

                matrizaux1=CrearMatriz(nReng1,nColumn1);
                CapturarMatriz(matrizaux1,nReng1,nColumn1);
                EscribirMatrizEnArchivo(cadenaAux,matrizaux1,nReng1,nColumn1);
                cout<<"!Exito!\n";
                BorraraMatriz(matrizaux1,nReng1);
                break;
            case 2:
                cout<<"Sumar matrices:\n";

                cout<<"Matriz A():";
                if(leerMat(matrizaux1,nReng1,nColumn1))
                    break;

                cout<<"Matriz B():";
                if(leerMat(matrizaux2,nReng2,nColumn2))
                    break;

                if(!SumaMat(matrizaux1,nReng1,nColumn1,matrizaux2,nReng2,nColumn2,matrizResultante,nRengRes,nColumnRes))
                    break;


                ImprimirMatriz(matrizaux1,nReng1,nColumn1,"A():");
                ImprimirMatriz(matrizaux2,nReng2,nColumn2,"B():");
                ImprimirMatriz(matrizResultante,nRengRes,nColumnRes,"A() + B():");
                GuardarEnArchivo(matrizResultante,nRengRes,nColumnRes);
                break;

            case 3:
                cout<<"Restar matrices:\n";

                cout<<"Matriz A():";
                if(leerMat(matrizaux1,nReng1,nColumn1))
                    break;

                cout<<"Matriz B():";
                if(leerMat(matrizaux2,nReng2,nColumn2))
                    break;

                if(!RestarMat(matrizaux1,nReng1,nColumn1,matrizaux2,nReng2,nColumn2,matrizResultante,nRengRes,nColumnRes))
                    break;


                ImprimirMatriz(matrizaux1,nReng1,nColumn1,"A():");
                ImprimirMatriz(matrizaux2,nReng2,nColumn2,"B():");
                ImprimirMatriz(matrizResultante,nRengRes,nColumnRes,"A() - B():");
                GuardarEnArchivo(matrizResultante,nRengRes,nColumnRes);
                break;

            case 4:
                cout<<"Multiplicar matrices:\n";

                cout<<"Matriz A():";
                if(leerMat(matrizaux1,nReng1,nColumn1))
                    break;

                cout<<"Matriz B():";
                if(leerMat(matrizaux2,nReng2,nColumn2))
                    break;

                if(!MultiplicarMat(matrizaux1,nReng1,nColumn1,matrizaux2,nReng2,nColumn2,matrizResultante,nRengRes,nColumnRes))
                    break;


                ImprimirMatriz(matrizaux1,nReng1,nColumn1,"A():");
                ImprimirMatriz(matrizaux2,nReng2,nColumn2,"B():");
                ImprimirMatriz(matrizResultante,nRengRes,nColumnRes,"A() * B():");
                GuardarEnArchivo(matrizResultante,nRengRes,nColumnRes);
                break;

            case 5:
                cout<<"Multiplicar por escalar:\n";

                cout<<"Matriz A():";
                if(leerMat(matrizaux1,nReng1,nColumn1))
                    break;

                aux=CapturaSegura("Escalar: ");
                MultiplicarPorEscalar(matrizaux1,nReng1,nColumn1,aux,matrizResultante,nRengRes,nColumnRes);


                ImprimirMatriz(matrizaux1,nReng1,nColumn1,"A():");
                ImprimirMatriz(matrizResultante,nRengRes,nColumnRes,"k A():");
                GuardarEnArchivo(matrizResultante,nRengRes,nColumnRes);
                break;

            case 6:
                cout<<"Matriz transpuesta:\n";

                cout<<"Matriz A():";
                if(leerMat(matrizaux1,nReng1,nColumn1))
                    break;

                Transpuesta(matrizaux1,nReng1,nColumn1,matrizResultante,nRengRes,nColumnRes);


                ImprimirMatriz(matrizaux1,nReng1,nColumn1,"A():");
                ImprimirMatriz(matrizResultante,nRengRes,nColumnRes,"A()_t");
                GuardarEnArchivo(matrizResultante,nRengRes,nColumnRes);
                break;

            case 7:
                cout<<"Matriz inversa:\n";

                cout<<"Matriz A():";
                if(leerMat(matrizaux1,nReng1,nColumn1))
                    break;

                if(!Inversa(matrizaux1,nReng1,nColumn1,matrizResultante,nRengRes,nColumnRes))
                    break;

                cout<<"Aqui:";

                ImprimirMatriz(matrizaux1,nReng1,nColumn1,"A():");
                ImprimirMatriz(matrizResultante,nRengRes,nColumnRes,"A()^-1");
                GuardarEnArchivo(matrizResultante,nRengRes,nColumnRes);
                break;

            case 8:
                cout<<"Matriz inversa:\n";

                bool esta;
                char archivo[100];
                do
                {
                    cout<<"Nombre del archivo: ";
                    cin>>archivo;
                    esta=CapturarMatrizDeUnArchivo(archivo,matrizaux1,nReng1,nColumn1);
                    if(!esta)
                    {
                        do
                        {
                            cout<<"\250Te rindes con la operaci\242n?(Y/N): ";
                            cin>>opcion;
                            if(opcion != 'Y' && opcion != 'N')
                                cout<<"Opci\242n no valida...";

                        }while(opcion != 'Y' && opcion != 'N');
                        if(opcion=='Y')
                            break;
                    }
                }while(!esta);

                ImprimirMatriz(matrizaux1,nReng1,nColumn1,archivo);
        }


        system("Pause");
        system("cls");

    }while(opcion!=0);

    return 0;
}

//*************************************************************************************************************************
bool leerMat(double **&matriz ,int &n ,int &m)
{
    char opcion;
    do
    {
        cout<<"\n\250Se desea leer la matriz de un archivo?(Y/N): ";
        cin>>opcion;
        if(opcion != 'Y' && opcion != 'N')
            cout<<"Opci\242n no valida...";

    }while(opcion != 'Y' && opcion != 'N');

    if(opcion=='Y')
    {
        bool esta;
        char archivo[100];
        do
        {
            cout<<"Nombre del archivo: ";
            cin>>archivo;
            esta=CapturarMatrizDeUnArchivo(archivo,matriz,n,m);
            if(!esta)
            {
                do
                {
                    cout<<"\250Te rindes con la operaci\242n?(Y/N): ";
                    cin>>opcion;
                    if(opcion != 'Y' && opcion != 'N')
                        cout<<"Opci\242n no valida...";

                }while(opcion != 'Y' && opcion != 'N');
                if(opcion=='Y')
                    return true;
            }

        }while(!esta);

    }
    else
    {
        n=CapturaSegura("N\243mero de renglones: ");
        m=CapturaSegura("N\243mero de columnas: ");


        matriz=CrearMatriz(n,m);
        CapturarMatriz(matriz,n,m);
    }
    return false;
}

void GuardarEnArchivo(double **&matriz ,int &n ,int &m)
{
    char opcion;
    do
    {
        cout<<"\n\250Quieres guardar la matriz en un archivo?(Y/N): ";
        cin>>opcion;
        if(opcion != 'Y' && opcion != 'N')
            cout<<"Opci\242n no valida...";

    }while(opcion != 'Y' && opcion != 'N');
    if(opcion=='Y')
    {
        char archivo[100];
        cout<<"Nombre del archivo: ";
        cin>>archivo;
        EscribirMatrizEnArchivo(archivo,matriz,n,m);

    }
    else
    {
        cout<<"Okey\n";
    }
}
