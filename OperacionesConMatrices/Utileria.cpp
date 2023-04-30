/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include"Utileria.h"

//*************************************************************************************************************************
double ** CrearMatriz(int n ,int m)
{
    double **matriz;
    try
    {
        matriz=new double*[n];
    }
    catch(...)
    {
        std::cout<<"Error inesperado en la memoria...";
        exit(1);
    }

    for(int i=0;i<n;i++)
    {
        try
        {
            matriz[i]=new double[m];
        }
        catch(...)
        {
            for(int j=i-1;j>=0;j--)
                delete [] matriz[j];
            std::cout<<"Error inesperado en la memoria...";
            exit(1);
        }
    }
    return matriz;
}

//*************************************************************************************************************************
void BorraraMatriz(double **&matriz ,int n)
{
    for(int i=0;i<n;i++)
        delete [] matriz[i];
    delete [] matriz;
    matriz=NULL;
}

//*************************************************************************************************************************

double CapturaSegura(const char *solicitud)
{
    double n;
    while(true)
    {
        std::cout << solicitud;
        std::cin >> n;

        if(std::cin.bad()){
            std::cout << "Ocurri\242 un error irrecuperable en el flujo de entrada\n";
            system("pause");
            exit(1);
        }
        if(std::cin.fail()){
            std::cout << "Error: no es un n\243mero. Introduzca de nuevo...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        return n;
    }
}













