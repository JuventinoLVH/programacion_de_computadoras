/* Nombre: Utileria.tpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 19/04/2020
   Descripción: Archivo para las funciones de utilería
*/

#include "Utileria.h"

//*******************************************************************************************************************
double CapturaSegura(const char mensaje[])
{
    double aux;
    while(true)
    {
        std::cout<<mensaje;
        std::cin>>aux;
        if(std::cin.bad())
        {
            std::cout << "Ocurri\242 un error irrecuperable en el flujo de entrada\n";
            system("pause");
            exit(1);
        }
        if(std::cin.fail())
        {
            std::cout << "Eso no es un numero..." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        return aux;
    }
}
//*******************************************************************************************************************
void SignoN(double n)
{
    if(n>0) std::cout<<'+';
    else std::cout<<'-';

    return;
}

//*******************************************************************************************************************
double AbsD(double n)
{
    return n >= 0 ? n : -n;
}

//*******************************************************************************************************************
double * CrearArregloD(int n)
{
    return new double[n];
}

//*******************************************************************************************************************
void BorrarArregloD(double *&Arr)
{
    delete [] Arr;
    Arr=NULL;
    return;
}
