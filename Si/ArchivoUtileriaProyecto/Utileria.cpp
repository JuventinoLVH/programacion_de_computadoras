/*
 Nombre: Utileria.cpp
 Autor: Luis J. Velasquez Hidalgo
 Fecha: 02/03/2020
 Descripción: Funciones de utileria
*/

#include "Utileria.h"

//*************************************************************************************************************************
void DibujarMarcoDoble(int alto,int ancho,int posX, int posY ,double segundos,Color colFondo ,Color colTex ,bool relleno ,Color colRell)
{
    WORD colorOriginal=ObtenerColorOriginal();
    EstablecerColor(colFondo,colTex);
    segundos*=1000;


    //Primera línea del marco
    gotoxy(posX,posY);

    std::cout<<char(ESID);
    for(int i=2;i<ancho;i++)
    {
        Sleep(segundos);
        std::cout<<char(BHD);
    }
    Sleep(segundos);
    std::cout<<char(ESDD)<<'\n';

    //Lado derecho
    for(int i=2;i<alto;i++)
    {
        gotoxy(posX+ancho-1,posY+i-1);
        Sleep(segundos);
        std::cout<<char(BVD);
    }

    //Ultima línea del marco
    gotoxy(posX+ancho-1,posY+alto-1);
    Sleep(segundos);
    std::cout<<char(EIDD);

    for(int i=2;i<ancho;i++)
    {
        gotoxy(posX+ancho-i,posY+alto-1);
        Sleep(segundos);
        std::cout<<char(BHD);
    }

    gotoxy(posX,posY+alto-1);
    Sleep(segundos);
    std::cout<<char(EIID)<<'\n';

   //Lado izquierdo
    for(int i=2;i<alto;i++)
    {
        gotoxy(posX,posY+alto-i);
        Sleep(segundos);
        std::cout<<char(BVD);
    }

    if(relleno)
    {
        segundos*=.3;
        for(int i=2;i<alto;i++)
            for(int j=2;j<ancho;j++)
            {
                gotoxy(posX+j-1 ,posY+i-1);
                Sleep(segundos);
                std::cout<<' ';
            }
    }

    EstablecerColor(colorOriginal);
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
void DibujarArchivo(char direccion[] ,int posX ,int posY ,Color colFondo ,Color colTex)
{
    WORD colorOriginal=ObtenerColorOriginal();
    EstablecerColor(colFondo,colTex);

    std::ifstream archivo(direccion);
    std::string texto;

    if(!archivo)
    {
        std::cout<<"El archivo no se encontr\242\n";
        archivo.close();
        return;
    }

    for(int i=0;!archivo.eof();i++)
    {
        getline(archivo,texto);
        for(int j=0,fin=texto.size();j<fin;j++)
        {
            /*if((int)texto[j]==61)
            {
                j++;
                texto[j]=(int)texto[j]+(int)texto[j-1];
            }
            //td::cout<<texto[j];
            std::cout<<(int)texto[j]<<" : "<<texto[j];
            std::cout<<" ->"<<(int)normalizarCaracter(texto[j])<<" : "<<normalizarCaracter(texto[j])<<'\n';*/
            gotoxy(posX+j,posY+i);
            std::cout<<texto[j];
        }
    }

    archivo.close();
    EstablecerColor(colorOriginal);
}


//************************************************************************************************************************
void AnimarArchivo(char direccion[] ,double segundos ,int posX ,int posY ,Color colFondo ,Color colTex)
{
    WORD colorOriginal=ObtenerColorOriginal();
    EstablecerColor(colFondo,colTex);

    segundos*=1000;
    char frame[100];
    sprintf(frame,"%s\\Frame%i.txt",direccion,1);
    std::ifstream archivo(frame);
    std::string texto;

    if(!archivo)
    {
        std::cout<<"El archivo no se encontr\242\n";
        archivo.close();
        return;
    }

    for(int i=2;true;i++)
    {
        DibujarArchivo(frame,posX,posY,colFondo,colTex);
        Sleep(segundos);

        archivo.close();
        sprintf(frame,"%s\\Frame%i.txt",direccion,i);
        std::ifstream archivo(frame);
        if(!archivo)
        {
            i=1;
            archivo.close();
            sprintf(frame,"%s\\Frame%i.txt",direccion,i);
            std::ifstream archivo(frame);
        }
    }

    EstablecerColor(colorOriginal);
}

//************************************************************************************************************************
char normalizarCaracter(char A)
{
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
            A=-38;
            break;
        //Í
        case -42:
            A=73;
            break;
        //Ñ
        case -91:
            A=-91;
            break;
        //ñ
        case -92:
            A=-92;
            break;
    }
    return A;
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
