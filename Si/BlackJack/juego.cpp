

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "juego.h"
#include "MazoDeCartas.h"
#include "ManoBlackJack.h"
#include "Carta.h"

using namespace::std;

/** \brief
 *
 * \param mazo const MazoDeCartas&
 * \param pilaDeCartas int&
 * \return void
 *
 */
void ActualizarMazo(const MazoDeCartas &mazo,int & pilaDeCartas);


/** \brief
 *
 * \param puntosJ int
 * \param dealer ManoBlackJack&
 * \param mazo MazoDeCartas&
 * \param pilaDeCartas int&
 * \return bool
 *
 */
bool MovDealer(int puntosJ, ManoBlackJack &dealer , MazoDeCartas &mazo ,int &pilaDeCartas);


/** \brief
 *
 * \param jugador ManoBlackJack&
 * \param dealer ManoBlackJack&
 * \param mazo MazoDeCartas&
 * \param perdidas int&
 * \param ganadas int&
 * \return void
 *
 */
void IniciarRonda(ManoBlackJack &jugador ,ManoBlackJack &dealer ,MazoDeCartas &mazo ,int &perdidas ,int &ganadas);


void juego(Color FONDO,Color TEXTO, Color ILUMINADO)
{
    char tecla;
    int pilaDeCartas=4;
    Carta cartaMazo(1,PICAS,13,15);
    MazoDeCartas mazoBlack;
    ManoBlackJack jugador(POS_X_J,POS_Y_J);
    ManoBlackJack dealer(POS_X_D,POS_Y_D);

    mazoBlack.barajar();
    ActualizarMazo(mazoBlack,pilaDeCartas);

    int opcion=1,ganadas=0,perdidas=0;
    bool rondaTerminada=false,salir=false;
    BotonesJuego(FONDO,TEXTO);
    IniciarRonda(jugador,dealer,mazoBlack,perdidas,ganadas);
    do
    {
        switch(opcion)
        {
            case 1:
                IluminarBoton(BotonTomarCarta,FONDO,ILUMINADO);
                break;

            case 2:
                IluminarBoton(BotonConservarMano,FONDO,ILUMINADO);
                break;

            case 3:
                IluminarBoton(BotonReiniciar,FONDO,ILUMINADO);
                break;

            case 4:
                IluminarBoton(BotonVolver,FONDO,ILUMINADO);
                break;
        }
        if(kbhit())
        {
            if(kbhit())
            {
                tecla = getch();
                if( (tecla == ARRIBA || tolower(tecla) == 'w'))
                {
                    BotonesJuego(FONDO,TEXTO);
                    opcion--;
                    if(opcion<1)
                        opcion=4;

                }
                if( (tecla == ABAJO  || tolower(tecla) == 's'))
                {
                    BotonesJuego(FONDO,TEXTO);
                    opcion++;
                    if(opcion>4)
                        opcion=1;
                }

                if(tecla == ENTER)
                {
                    switch(opcion)
                    {
                        case 1:

                            ElegirBoton(BotonTomarCarta,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);

                            jugador.AgregarCarta(mazoBlack.SacarCarta());
                            jugador.ImprimirMano();
                            ActualizarMazo(mazoBlack,pilaDeCartas);

                            if(jugador.GetPuntos()>21)
                                rondaTerminada=true;

                            gotoxy(POS_X_J-15,POS_Y_J+5);
                            std::cout<<"Jugador: "<<jugador.GetPuntos()<<" P";
                            break;

                        //instrucciones
                        case 2:
                            ElegirBoton(BotonConservarMano,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);

                            rondaTerminada=true;
                            break;

                        //creditos
                        case 3:
                            ElegirBoton(BotonReiniciar,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);
                            mazoBlack.barajar();
                            ganadas=perdidas=0;
                            IniciarRonda(jugador,dealer,mazoBlack,perdidas,ganadas);
                            break;

                        //salir
                        case 4:
                            salir=true;
                            ElegirBoton(BotonVolver,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);
                            break;
                    }

                    if(rondaTerminada)
                    {
                        int puntosJ=jugador.GetPuntos();
                        if(puntosJ>21)
                        {
                            perdidas++;
                            gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
                            std::cout<<"Te pasaste";
                        }
                        else
                        {
                            if(!MovDealer(puntosJ,dealer,mazoBlack,pilaDeCartas))
                            {

                                ganadas++;
                                gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
                                std::cout<<"GANASTE";
                            }
                            else
                            {
                                perdidas++;
                                gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
                                std::cout<<"PERDISTE";
                            }
                        }
                        gotoxy(POS_X_D-15,POS_Y_D+2);
                        std::cout<<"Ganadas: "<<perdidas;
                        gotoxy(POS_X_J-15,POS_Y_J+2);
                        std::cout<<"Ganadas: "<<ganadas;

                        int opcionSalir=1;
                        BotonesJuego(FONDO,FONDO);

                        do
                        {
                            BotonVolver(FONDO,TEXTO);
                            BotonReiniciar(FONDO,TEXTO);
                            if(opcionSalir==1)
                                IluminarBoton(BotonReiniciar,FONDO,ILUMINADO);
                            else
                                IluminarBoton(BotonVolver,FONDO,ILUMINADO);
                            tecla = getch();
                            if( (tecla == ARRIBA || tolower(tecla) == 'w'))
                            {
                                opcionSalir--;
                                if(opcionSalir<1)
                                    opcionSalir=2;

                            }
                            if( (tecla == ABAJO  || tolower(tecla) == 's'))
                            {
                                opcionSalir++;
                                if(opcionSalir>2)
                                    opcionSalir=1;
                            }
                        }while(tecla!= ENTER);

                        if(opcionSalir==2)
                        {
                            ElegirBoton(BotonVolver,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);
                            salir=true;
                        }
                        else
                        {
                            ElegirBoton(BotonReiniciar,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);
                            if(mazoBlack.CuantasQuedan()<12)
                            {
                                gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
                                std::cout<<"Barajando mazo, espere...";
                                Sleep(8000);
                                mazoBlack.barajar();
                                ActualizarMazo(mazoBlack,pilaDeCartas);
                                gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
                                std::cout<<"                               ";
                            }
                            IniciarRonda(jugador,dealer,mazoBlack,perdidas,ganadas);
                            rondaTerminada=false;
                            BotonesJuego(FONDO,TEXTO);
                        }
                    }
                }
            }
        }
    }while(!salir);
}


void ActualizarMazo(const MazoDeCartas &mazo, int & pilaDeCartas)
{
    Carta cartaMazo(1,PICAS,13,15);

    int quedan=mazo.CuantasQuedan();

    if(quedan==52)
    {
        pilaDeCartas=4;
        cartaMazo.ImprimirReverso(POS_X_MAZO,POS_Y_MAZO);
        cartaMazo.ImprimirReverso(POS_X_MAZO-1,POS_Y_MAZO-1);
        cartaMazo.ImprimirReverso(POS_X_MAZO-2,POS_Y_MAZO-2);
        cartaMazo.ImprimirReverso(POS_X_MAZO-3,POS_Y_MAZO-3);
    }

    if(quedan<43 && pilaDeCartas==4)
    {
        pilaDeCartas--;
        for(int i=-3,fin=cartaMazo.GetAlto();i<fin;i++)
        {
            gotoxy(POS_X_MAZO-3,POS_Y_MAZO+i);
            for(int j=-3,finJ=cartaMazo.GetAncho();j<finJ;j++)
                std::cout<<' ';
        }
        cartaMazo.ImprimirReverso(POS_X_MAZO,POS_Y_MAZO);
        cartaMazo.ImprimirReverso(POS_X_MAZO-1,POS_Y_MAZO-1);
        cartaMazo.ImprimirReverso(POS_X_MAZO-2,POS_Y_MAZO-2);
    }

    if(quedan<33 && pilaDeCartas==3)
    {
        pilaDeCartas--;
        for(int i=-3,fin=cartaMazo.GetAlto();i<fin;i++)
        {
            gotoxy(POS_X_MAZO-3,POS_Y_MAZO+i);
            for(int j=-3,finJ=cartaMazo.GetAncho();j<finJ;j++)
                std::cout<<' ';
        }
        cartaMazo.ImprimirReverso(POS_X_MAZO,POS_Y_MAZO);
        cartaMazo.ImprimirReverso(POS_X_MAZO-1,POS_Y_MAZO-1);
    }
    if(quedan<23 && pilaDeCartas==2)
    {
        pilaDeCartas--;
        for(int i=-3,fin=cartaMazo.GetAlto();i<fin;i++)
        {
            gotoxy(POS_X_MAZO-3,POS_Y_MAZO+i);
            for(int j=-3,finJ=cartaMazo.GetAncho();j<finJ;j++)
                std::cout<<' ';
        }
        cartaMazo.ImprimirReverso(POS_X_MAZO,POS_Y_MAZO);
    }

}

bool MovDealer(int puntosJ, ManoBlackJack &dealer , MazoDeCartas &mazo ,int &pilaDeCartas)
{
    gotoxy(POS_X_MAZO+20,POS_Y_MAZO+4);
    std::cout<<"Turno del dealer";
    gotoxy(POS_X_D-15,POS_Y_D+5);
    std::cout<<"Dealer: "<<dealer.GetPuntos()<<" P";
    dealer.ImprimirMano();

    while(puntosJ>=dealer.GetPuntos())
    {
        gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
        std::cout<<'.';
        Sleep(1000);
        std::cout<<'.';
        Sleep(1000);
        std::cout<<'.';
        Sleep(1000);

        dealer.AgregarCarta(mazo.SacarCarta());
        gotoxy(POS_X_D-15,POS_Y_D+5);
        std::cout<<"Dealer: "<<dealer.GetPuntos()<<" P";
        dealer.ImprimirMano();

        ActualizarMazo(mazo,pilaDeCartas);

        if(dealer.GetPuntos()>21)
        {
            gotoxy(POS_X_MAZO+20,POS_Y_MAZO+4);
            std::cout<<"                        ";
            gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
            std::cout<<"                        ";
            return false;
        }
    }
    gotoxy(POS_X_MAZO+20,POS_Y_MAZO+4);
    std::cout<<"                        ";
    gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
    std::cout<<"                        ";
    return true;
}

void IniciarRonda(ManoBlackJack &jugador ,ManoBlackJack &dealer ,MazoDeCartas &mazo ,int &perdidas ,int &ganadas)
{
    gotoxy(POS_X_MAZO+20,POS_Y_MAZO+5);
    std::cout<<"                        ";
    jugador.VaciarMano();
    dealer.VaciarMano();

    jugador.AgregarCarta(mazo.SacarCarta());
    jugador.AgregarCarta(mazo.SacarCarta());
    jugador.ImprimirMano();

    dealer.AgregarCarta(mazo.SacarCarta());
    dealer.AgregarCarta(mazo.SacarCarta());
    dealer.ImprimirMano(1);

    gotoxy(POS_X_D-15,POS_Y_D+2);
    std::cout<<"Ganadas: "<<perdidas;
    gotoxy(POS_X_J-15,POS_Y_J+2);
    std::cout<<"Ganadas: "<<ganadas;
    gotoxy(POS_X_D-15,POS_Y_D+5);
    std::cout<<"Dealer: ? P";
    gotoxy(POS_X_J-15,POS_Y_J+5);
    std::cout<<"Jugador: "<<jugador.GetPuntos()<<" P";
}

