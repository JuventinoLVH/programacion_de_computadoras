/* Nombre: Utileria.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 27/05/2020
   Descripción:Funciones de utileria
*/

#include "Utileria.h"

//*************************************************************************************************************************
void DibujarMarcoDoble(int alto,int ancho,int posX, int posY )
{

    //Primera línea del marco
    gotoxy(posX,posY);

    std::cout<<char(ESID);
    for(int i=2;i<ancho;i++)
    {
        std::cout<<char(BHD);
    }
    std::cout<<char(ESDD)<<'\n';

    //Lado derecho
    for(int i=2;i<alto;i++)
    {
        gotoxy(posX+ancho-1,posY+i-1);
        std::cout<<char(BVD);
    }

    //Ultima línea del marco
    gotoxy(posX+ancho-1,posY+alto-1);
    std::cout<<char(EIDD);

    for(int i=2;i<ancho;i++)
    {
        gotoxy(posX+ancho-i,posY+alto-1);
        std::cout<<char(BHD);
    }

    gotoxy(posX,posY+alto-1);
    std::cout<<char(EIID)<<'\n';

   //Lado izquierdo
    for(int i=2;i<alto;i++)
    {
        gotoxy(posX,posY+alto-i);
        std::cout<<char(BVD);
    }

}


//*************************************************************************************************************************
void DibujarMarco(int alto,int ancho,int posX, int posY )
{

    //Primera línea del marco
    gotoxy(posX,posY);

    std::cout<<char(ESI);
    for(int i=2;i<ancho;i++)
    {
        std::cout<<char(BH);
    }
    std::cout<<char(ESD)<<'\n';

    //Lado derecho
    for(int i=2;i<alto;i++)
    {
        gotoxy(posX+ancho-1,posY+i-1);
        std::cout<<char(BV);
    }

    //Ultima línea del marco
    gotoxy(posX+ancho-1,posY+alto-1);
    std::cout<<char(EID);

    for(int i=2;i<ancho;i++)
    {
        gotoxy(posX+ancho-i,posY+alto-1);
        std::cout<<char(BH);
    }

    gotoxy(posX,posY+alto-1);
    std::cout<<char(EII)<<'\n';

   //Lado izquierdo
    for(int i=2;i<alto;i++)
    {
        gotoxy(posX,posY+alto-i);
        std::cout<<char(BV);
    }

}


//************************************************************************************************************************
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
void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}
