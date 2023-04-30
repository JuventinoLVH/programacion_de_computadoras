/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include <iostream>
#include "Ahorcado.h"

const int posX=22;
const int posY=8;
const char palabraSecreta[100]="La ni\244a Ley\242 Una Oraci\242n";

using namespace std;

//*************************************************************************************************************************
/** \brief  Juego del ahorcado infinito
 *
 */
void juegoFacil();

//*************************************************************************************************************************
/** \brief  Juego del ahorcado con 3 intentos
 *
 */
void juegoConErrores();

int main()
{
    char opcion;
    cout<<"Buenas tardes, vamos a jugar al ahorcado(te guste o no) :D\n";

    do
    {
        cout<<"Quieres jugar solo con 3 intentos?(Y/N): ";
        cin>>opcion;
        if(opcion!='Y' && opcion!='N')
        {
            cout<<"Opci\240n no valida...\n";
        }

    }while(opcion!='Y' && opcion!='N');

    system("cls");

    if(opcion=='Y')
        juegoConErrores();
    else
        juegoFacil();

    gotoxy(0,20);
    system("pause");
}

//*************************************************************************************************************************
void juegoConErrores()
{
    int errores=0;
    bool *estadojuego=NULL;
    bool ganar;
    char letra;

    estadojuego=EnmascararPalabra(palabraSecreta,posX,posY,'?');
    do
    {
        gotoxy(0,0);

        cout<<"Letra a destapar:  \b";
        cin>>letra;

        if(!DestaparLetra(palabraSecreta,estadojuego,letra,posX,posY,800))
            errores++;

        ganar=EstadoGanado(palabraSecreta,estadojuego);

    }while(errores<3 && !ganar);

    gotoxy(0,0);
    if(ganar)
    {
        cout<<"Congratulations :D Aquie esta tu recompensa: 'Cupon valido para un pan' ";
    }
    else
    {
        cout<<"Chale, el ahorcado es era un gatito :( (Mataste un gatito...)";
    }
    BorrarArregloB(estadojuego);
}

//*************************************************************************************************************************
void juegoFacil()
{
    int errores=0;
    bool *estadojuego=NULL;
    bool ganar;
    char letra;

    estadojuego=EnmascararPalabra(palabraSecreta,posX,posY,'?');
    do
    {
        gotoxy(0,0);

        cout<<"Letra a destapar:  \b";
        cin>>letra;

        if(!DestaparLetra(palabraSecreta,estadojuego,letra,posX,posY,800))
            errores++;

        ganar=EstadoGanado(palabraSecreta,estadojuego);

    }while(!ganar);

    gotoxy(0,0);
    cout<<"Errores: "<<errores<<" una victoria facil es una victoria vacia...";
    BorrarArregloB(estadojuego);
}
