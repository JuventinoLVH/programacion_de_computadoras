/*
Nombre:
Autor:
Fecha:
Descripción:
*/
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <windows.h>
#include <conio.h>

using namespace std;

#define MINCOL 10
#define MAXCOL 80
#define MINREN 15
#define MAXREN 35

#define FLECHA_ARRIBA 72
#define FLECHA_IZQ 75
#define FLECHA_DER 77
#define FLECHA_ABAJO 80
#define ENTER 13
#define ESPACIO ' '
#define ESCAPE 27
#define RETROCESO 8

#define CARA_BLANCA 1
#define CARA_NEGRA 2

// Establece el tamaño de la ventana de ejecución
void TamVentana(int Ancho, int Alto);
// Mueve el cursor a la posición (x,y)
void gotoxy(short x,short y);

// Estados del cursor
enum estadoCursor{APAGADO, ENCENDIDO};
// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};
// Para cambiar el estado del cursor
void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);

int main()
{
    char tecla;
    char carita = CARA_BLANCA;
    int x = MINCOL, y = MINREN;

    TamVentana(100,45);
    CambiaCursor(APAGADO);

    cout << "Pulse <ESC> para salir..." << endl;
    cout << "\nPulse las flechas arriba, izquierda, abajo y derecha, para extender las caritas." << endl;
    cout << "El mismo efecto se produce con las teclas w, a, s, d." << endl;
    cout << "\nPulsando <ENTER> se imprime un espacio y se mueve la carita hacia abajo" << endl;
    cout << "\nPulsando <BACKSPACE> se imprime un espacio y se mueve la carita hacia atr\240s" << endl;
    cout << "\nPulsando la barra espaciadora se imprime un espacio y se mueve la carita hacia la derecha" << endl;

    cout << "\n\nPulsando <c> cambia la carita" << endl;

    gotoxy(x,y);
    cout << carita << "\b";

    while(true){
        if(kbhit()){
            tecla = getch();
            if(tecla == ESCAPE) break;
            if(tolower(tecla) == 'c') carita = (carita == CARA_BLANCA) ? CARA_NEGRA : CARA_BLANCA;
            if(y < MAXREN && tecla == ENTER){
                cout << ESPACIO;
                gotoxy(x,++y);
            }
            if(x > MINCOL && tecla == RETROCESO){
                cout << ESPACIO;
                gotoxy(--x,y);
            }
            if(x < MAXCOL && tecla == ESPACIO){
                ++x;
                cout << ESPACIO;
            }
            if(y > MINREN && (tecla == FLECHA_ARRIBA || tolower(tecla) == 'w')) gotoxy(x,--y);
            if(x > MINCOL && (tecla == FLECHA_IZQ    || tolower(tecla) == 'a')) gotoxy(--x,y);
            if(y < MAXREN && (tecla == FLECHA_ABAJO  || tolower(tecla) == 's')) gotoxy(x,++y);
            if(x < MAXCOL && (tecla == FLECHA_DER    || tolower(tecla) == 'd')) gotoxy(++x,y);

            cout << carita << "\b";
        }
    }

    CambiaCursor(ENCENDIDO, SOLIDO);
    gotoxy(0, MAXREN + 5);
    system("pause");
    return 0;
}

//****************************************************************************************
void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}
//****************************************************************************************
void TamVentana(int Ancho, int Alto)
{
    _COORD coord;
    coord.X = Ancho;
    coord.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Alto - 1;
    Rect.Right = Ancho - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}
//****************************************************************************************
void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}

