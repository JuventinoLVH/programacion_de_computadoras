/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include"Utileria.h"

//*******************************************************************************************************************
void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}

//*******************************************************************************************************************
bool * CrearArregloB(int n)
{
    return new bool[n];
}

//*******************************************************************************************************************
void BorrarArregloB(bool *&Arr)
{
    delete []  Arr;
    Arr=NULL;
    return;
}

//*******************************************************************************************************************
bool CompararLetras(char A ,char B)
{
    //Letras con tildes a Mayúscula
    switch(A)
    {
        //á
        case -96:
            A=65;
            break;
        //í
        case -95:
            A=73;
            break;
        //é
        case -126:
            A=69;
            break;
        //ó
        case -94:
            A=79;
            break;
        //ú
        case -93:
            A=85;
            break;

        //Á
        case -75:
            A=65;
            break;
        //É
        case -112:
            A=69;
            break;
        //Ó
        case -32:
            A=79;
            break;
        //Ú
        case -23:
            A=85;
            break;
        //Í
        case -42:
            A=73;
            break;
        //ñ
        case -92:
            A=-91;
            break;
    }

    switch(B)
    {
        //á
        case -96:
            B=65;
            break;
        //í
        case -95:
            B=73;
            break;
        //é
        case -126:
            B=69;
            break;
        //ó
        case -94:
            B=79;
            break;
        //ú
        case -93:
            B=85;
            break;

        //Á
        case -75:
            B=65;
            break;
        //É
        case -112:
            B=69;
            break;
        //Ó
        case -32:
            B=79;
            break;
        //Ú
        case -23:
            B=85;
            break;
        //Í
        case -42:
            B=73;
            break;
        //ñ
        case -92:
            B=-91;
            break;
    }

    //letras minúsculas a mayúsculas
    if(A>=97 && A<=122)
        A=A-32;
    if(B>=97 && B<=122)
        B=B-32;

    return A==B;
}

//*******************************************************************************************************************
void Suspenso(int tiempo, int posX, int posY)
{
    gotoxy(posX,posY);
    std::cout<<'.';
    Sleep(600);
    std::cout<<'.';
    Sleep(600);
    std::cout<<'.';
    Sleep(tiempo);
}
