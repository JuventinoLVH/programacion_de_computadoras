
#include <iomanip>
#include <cctype>
#include <conio.h>

#include "MazoDeCartas.h"
#include "Utileria.h"
#include "ManoBlackJack.h"
#include "AnimacionesJuego.h"

#define FONDO AZULCLARO
#define TEXTO GRISCLARO
#define ILLUMINADO NEGRO

#define POS_X_MAZO 80
#define POS_Y_MAZO 22
#define POS_X_J 17
#define POS_Y_J 34
#define POS_X_D 17
#define POS_Y_D 2

#define ARRIBA 72
#define IZQ 75
#define DER 77
#define ABAJO 80
#define ENTER 13
#define ESPACIO ' '

using namespace std;

void Instrucciones(int x, int y);
void Creditos(int x, int y);
void Salir();


void juego();
void ActualizarMazo(const MazoDeCartas &mazo,int & pilaDeCartas);
bool MovDealer(int puntosJ, ManoBlackJack &dealer , MazoDeCartas &mazo,int &pilaDeCartas);


void EntradaBotones(const char *cadena);

int main()
{
    WORD colorOriginal=(ObtenerColorOriginal());
    CambiaCursor(APAGADO);
    EstablecerColor(FONDO,TEXTO);
    EstablecerTamVentana(169,58);
    system("cls");


    int opcion=1;
    bool salir=false;
    char tecla;
    int frame=1;
    char archivo[100];


    presentacion();
    BotonesTitulo(FONDO,TEXTO);

    do
    {
        if(frame>16) frame=1;

        sprintf(archivo,"Arte\\Titulo\\Frame%i.txt",frame);
        DibujarArchivo(archivo,MARGEN_COLUMNA_INF+4,MARGEN_FILA_SUP+2,BLANCO,AZUL);
        Sleep(18);
        frame++;

        switch(opcion)
        {
            case 1:
                IluminarBoton(BotonJugar,FONDO,ILLUMINADO);
                break;

            case 2:
                IluminarBoton(BotonInstruc,FONDO,ILLUMINADO);
                break;

            case 3:
                IluminarBoton(BotonCreditos,FONDO,ILLUMINADO);
                break;

            case 4:
                IluminarBoton(BotonSalir,FONDO,ILLUMINADO);
                break;
        }
        if(kbhit())
        {
            tecla = getch();

            if( (tecla == ARRIBA || tolower(tecla) == 'w'))
            {
                BotonesTitulo(FONDO,TEXTO);
                opcion--;
                if(opcion<1)
                    opcion=4;

            }
            if( (tecla == ABAJO  || tolower(tecla) == 's'))
            {
                BotonesTitulo(FONDO,TEXTO);
                opcion++;
                if(opcion>4)
                    opcion=1;
            }

            if(tecla == ENTER)
            {
                switch(opcion)
                {
                    //jugar
                    case 1:
                        ElegirBoton(BotonJugar,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);


                        Parpadeo();
                        juego();
                        Parpadeo();


                        PantallaDeTitulo(FONDO,TEXTO);

                        break;

                    //instrucciones
                    case 2:
                        ElegirBoton(BotonInstruc,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);

                        Parpadeo();
                        EntradaBotones(DIR_INSTRUCCIONES);
                        Parpadeo();

                        PantallaDeTitulo(FONDO,TEXTO);
                        break;

                    //creditos
                    case 3:
                        ElegirBoton(BotonCreditos,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);

                        Parpadeo();
                        EntradaBotones(DIR_CREDITOS);
                        Parpadeo();

                        PantallaDeTitulo(FONDO,TEXTO);
                        break;

                    //salir
                    case 4:
                        ElegirBoton(BotonSalir,1.9,FONDO,AMARILLO,7,FONDO,AMARILLOCLARO);
                        Parpadeo();
                        salir=true;

                        EntradaBotones(DIR_SALIR);

                        break;
                }
            }
        }

    }while(!salir);

    CambiaCursor(ENCENDIDO);
    EstablecerColor(colorOriginal);
    return 0;
}

void juego()
{
    int pilaDeCartas=4;
    Carta cartaMazo(1,PICAS,13,15);
    MazoDeCartas mazoBlack;
    mazoBlack.barajar();
    ActualizarMazo(mazoBlack,pilaDeCartas);

    ManoBlackJack jugador(POS_X_J,POS_Y_J);
    ManoBlackJack dealer(POS_X_D,POS_Y_D);


    //2 cartas principales del jugador
    jugador.AgregarCarta(mazoBlack.SacarCarta());
    jugador.AgregarCarta(mazoBlack.SacarCarta());
    jugador.ImprimirMano();

    //2 cartas principales del dealer
    dealer.AgregarCarta(mazoBlack.SacarCarta());
    dealer.AgregarCarta(mazoBlack.SacarCarta());
    dealer.ImprimirMano(1);

    char tecla;
    int opcion=1,ganadas=0,perdidas=0,empates=0;
    bool rondaTerminada=false,salir=false;
    BotonesJuego(FONDO,TEXTO);

    gotoxy(POS_X_D-15,POS_Y_D+2);
    cout<<"Ganadas: "<<perdidas;
    gotoxy(POS_X_J-15,POS_Y_J+2);
    cout<<"Ganadas: "<<ganadas;
    gotoxy(POS_X_D-15,POS_Y_D+5);
    cout<<"Dealer: ? P";
    gotoxy(POS_X_J-15,POS_Y_J+5);
    cout<<"Jugador: "<<jugador.GetPuntos()<<" P";

    do
    {
        switch(opcion)
        {
            case 1:
                IluminarBoton(BotonTomarCarta,FONDO,ILLUMINADO);
                break;

            case 2:
                IluminarBoton(BotonConservarMano,FONDO,ILLUMINADO);
                break;

            case 3:
                IluminarBoton(BotonReiniciar,FONDO,ILLUMINADO);
                break;

            case 4:
                IluminarBoton(BotonVolver,FONDO,ILLUMINADO);
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
                            cout<<"Jugador: "<<jugador.GetPuntos()<<" P";
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
                            jugador.VaciarMano();
                            dealer.VaciarMano();

                            jugador.AgregarCarta(mazoBlack.SacarCarta());
                            jugador.AgregarCarta(mazoBlack.SacarCarta());
                            jugador.ImprimirMano();

                            //2 cartas principales del dealer
                            dealer.AgregarCarta(mazoBlack.SacarCarta());
                            dealer.AgregarCarta(mazoBlack.SacarCarta());
                            dealer.ImprimirMano(1);


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
                            gotoxy(POS_X_MAZO+2,POS_Y_MAZO+15);
                            cout<<"Te pasaste";
                        }
                        else
                        {
                            if(!MovDealer(puntosJ,dealer,mazoBlack,pilaDeCartas))
                            {
                                ganadas++;
                                gotoxy(POS_X_MAZO+2,POS_Y_MAZO+15);
                                cout<<"GANASTE";
                            }
                            else
                            {
                                perdidas++;
                                gotoxy(POS_X_MAZO+2,POS_Y_MAZO+15);
                                cout<<"PERDISTE";
                            }
                        }

                        gotoxy(POS_X_D-15,POS_Y_D+2);
                        cout<<"Ganadas: "<<perdidas;
                        gotoxy(POS_X_J-15,POS_Y_J+2);
                        cout<<"Ganadas: "<<ganadas;

                        system("pause");

                        jugador.VaciarMano();
                        dealer.VaciarMano();

                        if(mazoBlack.CuantasQuedan()<12)
                        {
                            gotoxy(POS_X_MAZO-4,POS_Y_MAZO+15);
                            cout<<"Barajando mazo, espere...";
                            Sleep(8000);
                            mazoBlack.barajar();
                            ActualizarMazo(mazoBlack,pilaDeCartas);
                        }

                        gotoxy(POS_X_MAZO-4,POS_Y_MAZO+15);
                        cout<<"                               ";

                        jugador.AgregarCarta(mazoBlack.SacarCarta());
                        jugador.AgregarCarta(mazoBlack.SacarCarta());
                        jugador.ImprimirMano();

                        //2 cartas principales del dealer
                        dealer.AgregarCarta(mazoBlack.SacarCarta());
                        dealer.AgregarCarta(mazoBlack.SacarCarta());
                        dealer.ImprimirMano(1);

                        ActualizarMazo(mazoBlack,pilaDeCartas);

                        gotoxy(POS_X_D-15,POS_Y_D+5);
                        cout<<"Dealer: ? P";
                        gotoxy(POS_X_J-15,POS_Y_J+5);
                        cout<<"Jugador: "<<jugador.GetPuntos()<<" P";

                        rondaTerminada=false;
                    }

                }
            }
        }
    }while(!salir);
}

void EntradaBotones(const char *cadena)
{
    char tecla;
    DibujarArchivo(cadena,0,0,FONDO,TEXTO);
    IluminarBoton(BotonVolver,FONDO,ILLUMINADO);
    do
    {
        if(kbhit())
            tecla = getch();
    }while(tecla!=ENTER);
    return;
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
                cout<<' ';
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
                cout<<' ';
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
                cout<<' ';
        }
        cartaMazo.ImprimirReverso(POS_X_MAZO,POS_Y_MAZO);
    }

}


bool MovDealer(int puntosJ, ManoBlackJack &dealer , MazoDeCartas &mazo ,int &pilaDeCartas)
{
    gotoxy(POS_X_MAZO-4,POS_Y_MAZO+14);
    cout<<"Turno del dealrer";
    gotoxy(POS_X_D-15,POS_Y_D+5);
    cout<<"Dealer: "<<dealer.GetPuntos()<<" P";
    dealer.ImprimirMano();

    while(puntosJ>=dealer.GetPuntos())
    {
        gotoxy(POS_X_MAZO-4,POS_Y_MAZO+15);
        cout<<'.';
        Sleep(1000);
        cout<<'.';
        Sleep(1000);
        cout<<'.';

        dealer.AgregarCarta(mazo.SacarCarta());
        gotoxy(POS_X_D-15,POS_Y_D+5);
        cout<<"Dealer: "<<dealer.GetPuntos()<<" P";
        dealer.ImprimirMano();

        ActualizarMazo(mazo,pilaDeCartas);

        if(dealer.GetPuntos()>21)
        {
            gotoxy(POS_X_MAZO-4,POS_Y_MAZO+15);
            cout<<"                        ";
            gotoxy(POS_X_MAZO-4,POS_Y_MAZO+14);
            cout<<"                        ";
            return false;
        }
    }
    gotoxy(POS_X_MAZO-4,POS_Y_MAZO+15);
    cout<<"                        ";
    gotoxy(POS_X_MAZO-4,POS_Y_MAZO+14);
    cout<<"                        ";
    return true;
}
