/*
 Nombre: Utileria.cpp
 Autor: Luis J. Velasquez Hidalgo
 Fecha: 02/03/2020
 Descripción: Funciones de utileria
*/

#include "Utileria.h"

//************************************************************************************************************************
void EstablecerColor(WORD colorEst)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorEst);
}

//*************************************************************************************************************************
void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (colorFondo)*16 + colorTexto);
}

//*************************************************************************************************************************
WORD ObtenerColorOriginal()
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsoleHandle, ConsoleInfo);
    WORD original = ConsoleInfo->wAttributes;
    delete ConsoleInfo;
    return original;
}

//*************************************************************************************************************************
void EstablecerTamVentana(SHORT ancho, SHORT alto)
{
	_COORD coord = {--ancho, --alto};
	_SMALL_RECT rect = {0,0,ancho,alto};
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsola, coord);
	SetConsoleWindowInfo(hConsola, true, &rect);
}

//*************************************************************************************************************************
void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}

//*************************************************************************************************************************
void DibujarMarcoDoble(int alto,int ancho,int posX, int posY)
{
    //Primera línea del marco
    gotoxy(posX,posY);
    std::cout<<char(ESID);

    for(int i=2;i<ancho;i++)
        std::cout<<char(BHD);

    std::cout<<char(ESDD)<<'\n';

    //Cuerpo del marco
    for(int i=1;i<alto;i++)
    {
        gotoxy(posX,posY+i);
        std::cout<<char(BVD);

        for(int j=2;j<ancho;j++)
        {
            std::cout<<' ';
        }
        std::cout<<char(BVD)<<'\n';
    }

    //Ultima línea del marco
    gotoxy(posX,posY+alto-1);
    std::cout<<char(EIID);

    for(int i=2;i<ancho;i++)
        std::cout<<char(BHD);

    std::cout<<char(EIDD)<<'\n';
}

void ImprimirMarco(int ancho, int alto, int x, int y)
{
    // Parte superior
    gotoxy(x,y);
    std::cout << (char)ESI;
    for(int i = 2 ; i < ancho ; ++i) std::cout << (char)BH;
    std::cout << (char)ESD;
    // Parte media
    for(int i = 2; i < alto; ++i){
        gotoxy(x, ++y);
        std::cout << (char)BV;
        for (int i=2; i< ancho; ++i) std::cout << " ";
        std::cout << (char)BV;
    }
    // Parte inferior
    gotoxy(x,++y);
    std::cout << (char)EII;
    for(int i = 2 ; i < ancho ; ++i) std::cout << (char)BH;
    std::cout << (char)EID;
}

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
