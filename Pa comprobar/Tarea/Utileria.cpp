/* Nombre: Utileria.cpp
 Autor: Luis J. Velasquez Hidalgo
 Fecha: 26/04/2020
 Descripción: Funciones de utileria
*/

#include "Utileria.h"

//*************************************************************************************************************************
void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}

//*************************************************************************************************************************
int CapturaEntero(const char solicitud [])
{
    int n;
    while(true){
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

//*******************************************************************************************************************
int * CrearArreglo(int n)
{
    return new int[n];
}

//*******************************************************************************************************************
void BorrarArreglo(int *&Arr)
{
    delete [] Arr;
    Arr=NULL;
    return;
}
