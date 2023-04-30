/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 27/05/2020
   Descripción: juego de guerra de cartas(planeado para una panalla de 168x57 con juente "Mapa de bits" de tamaño 8 x 12)
*/
#include <iostream>
#include <conio.h>

#include "MazoCartas.h"
#include "Utileria.h"

#define ENTER 13
#define ESC 27

#define POS_X_JUGADOR 20
#define POS_Y_JUGADOR 17
#define POS_X_ENEMIGO 120
#define POS_Y_ENEMIGO 17
#define POS_X_MAZO 76
#define POS_Y_MAZO 21

using namespace std;

void ActualizarMazo(const MazoCartas &mazo);

void BorrarCarta(int posX, int posY);

int main()
{
    EstablecerTamVentana(168,57);
    CambiaCursor(APAGADO);

    gotoxy(30,2);
    cout<<"bienvenido a la guerra de cartas, el metodo definitivo para solucionar disputas y guerras entre pa\241ses...";
    gotoxy(25,4);
    cout<<"Las reglas son simples, cada ronda se sacar\240 una del mazo, para destapar la carta del oponente se debe aplastar la tecla";
    gotoxy(13,5);
    cout<<"<ENTEER>, esto indicara una combate y gana la carta que tenga la mayor numeraci\240n(Los empates no suman puntos y J,Q Y K valen 10). Para iniciar";
    gotoxy(13,6);
    cout<<"una ronda se debe aplastar la tecla <ENTER>, para terminar la guerra se debe aplastar la tecla <ESC> (Los puntos se suman al destapar la carta)";
    gotoxy(30,7);


    MazoCartas mazo;
    Carta cartaAux;
    char tecla;


    mazo.barajar();

    //Dibujo del 'Mazo'
    cartaAux.ImprimirReverso(POS_X_MAZO ,POS_Y_MAZO);
    cartaAux.ImprimirReverso(POS_X_MAZO-1 ,POS_Y_MAZO-1);
    cartaAux.ImprimirReverso(POS_X_MAZO-2 ,POS_Y_MAZO-2);

    Carta cartaJugador,cartaEnemigo;
    int victorias=0,derrotas=0,empates=0;
    do
    {

        //Los espacios de más en los cout es para asegurarse de borrar el mensaje anterior
        gotoxy(65,40);
        cout<<"Guerreros . . . Saquen una carta                                                              ";
        tecla = getch();
        if(tecla==ENTER)
        {

            cartaJugador=mazo.SacarCarta();
            cartaEnemigo=mazo.SacarCarta();

            cartaJugador.ImprimirFrente(POS_X_JUGADOR ,POS_Y_JUGADOR);
            cartaEnemigo.ImprimirReverso(POS_X_ENEMIGO ,POS_Y_ENEMIGO);


            //Ilusion de que se está acabando el mazo
            ActualizarMazo(mazo);


            //mensaje para añadir tensión
            gotoxy(65,40);
            cout<<"   Cuanta Tensi\242n en el aire . . .                                                      ";

            tecla = getch();
            if(tecla==ENTER)
            {
                cartaEnemigo.ImprimirFrente(POS_X_ENEMIGO ,POS_Y_ENEMIGO);


                if(cartaJugador.GetNumeracion() == cartaEnemigo.GetNumeracion())
                {
                    empates++;
                    gotoxy(65,40);
                    cout<<"Aires de calma en el campo de batalla . . .                                        ";

                }
                else
                {
                    if(cartaJugador.GetNumeracion() > cartaEnemigo.GetNumeracion())
                    {
                        victorias++;
                        gotoxy(65,40);
                        cout<<"\255Todos tus enemigos temblaran ante tu poder!                                ";
                    }
                    else
                    {
                        derrotas++;
                        gotoxy(65,40);
                        cout<<"Dios da sus peores batallas a sus mejores guerreros . . .                      ";
                    }
                }
                gotoxy(68,42);
                system("pause");

                BorrarCarta(POS_X_JUGADOR,POS_Y_JUGADOR-3);
                BorrarCarta(POS_X_ENEMIGO-3,POS_Y_ENEMIGO-3);

                if(mazo.CuantasQuedan()==0)
                {
                    gotoxy(65,40);
                    cout<<"\255ALTO AL FUEGO¡ El dealer esta barajando el mazo (No te muevas e_e)                   ";
                    Sleep(8000);
                    mazo.barajar();
                    cartaAux.ImprimirReverso(POS_X_MAZO ,POS_Y_MAZO);
                    cartaAux.ImprimirReverso(POS_X_MAZO-1 ,POS_Y_MAZO-1);
                    cartaAux.ImprimirReverso(POS_X_MAZO-2 ,POS_Y_MAZO-2);


                }
            }
        }

    }while(tecla!=ESC);


    system("cls");
    gotoxy(POS_X_MAZO-20,POS_Y_MAZO);

    int rondas=victorias+derrotas+empates;
    if(rondas<3)
    {
        cout<<"Aquellos que abandonan el campo de batalla son considerados escorias...";
        gotoxy(POS_X_MAZO-25,POS_Y_MAZO+2);
        cout<<"\255Pero aquellos que abandonan a sus amigos son considerados peores que escorias!";
    }
    else
    {
        if(victorias-derrotas < 3 && victorias-derrotas > -3 && rondas>8)
        {
            cout<<"Un combate igualado, digno de reyes y caballeros";
            gotoxy(POS_X_MAZO-10,POS_Y_MAZO+2);
            cout<<"Cuanto honor en una guerra";
        }
        else
        {
            if(victorias>derrotas )
            {
                cout<<"Est\240 aplastante victoria sera conocido por todo el reino";
                gotoxy(POS_X_MAZO-17,POS_Y_MAZO+2);
                cout<<"\255Tus enemigos temblaran al escuchar tu nombre!";
            }
            else
            {
                cout<<"Decidiste huir de la batalla....digas lo que digas, no fue una batalla igualada,...";
                gotoxy(POS_X_MAZO-19,POS_Y_MAZO+2);
                cout<<"Humillaci\242n y burlas es todo lo que recibir\240s por parte de tus allgados";
            }
        }
    }
    gotoxy(68,40);
    cout<<" Rondas :"<<rondas<<" Empates: "<<empates;
    gotoxy(POS_X_JUGADOR,40);
    cout<<"Victorias: "<<victorias;
    gotoxy(POS_X_ENEMIGO,40);
    cout<<"Victorias: "<<derrotas;

    gotoxy(0,0);
    system("Pause");
    return 0;
}



void ActualizarMazo(const MazoCartas &mazo)
{
    Carta cartaAux;

    if(mazo.CuantasQuedan()==36)
    {
        BorrarCarta(POS_X_MAZO-3,POS_Y_MAZO-3);

        cartaAux.ImprimirReverso(POS_X_MAZO ,POS_Y_MAZO);
        cartaAux.ImprimirReverso(POS_X_MAZO-1 ,POS_Y_MAZO-1);

    }
    if(mazo.CuantasQuedan()==18)
    {
        BorrarCarta(POS_X_MAZO-3,POS_Y_MAZO-3);

        cartaAux.ImprimirReverso(POS_X_MAZO ,POS_Y_MAZO);
    }
    if(mazo.CuantasQuedan()==0)
    {
        BorrarCarta(POS_X_MAZO-3,POS_Y_MAZO-3);
    }
}


void BorrarCarta(int posX, int posY)
{
    //el tamaño de una carta es aprox 18
    for(int i=0;i<18;i++)
    {
        gotoxy(posX,posY+i);
        for(int i=0;i<18;i++)
            cout<<" ";
    }
}
