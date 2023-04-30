/*
 Nombre: .cpp
 Autor:
 Fecha:
 Descripción:
*/

#include <iostream>
#include <cstdlib>
#include "Carta.h"

using namespace std;

//*********************************************************************************
/** \brief Función que simula el juego del 21
 *
 */
void Juego21();

//**************************************************************************
/** \brief Imprime todas las cartas de la baraja inglesa en forma de cascada
 *
 * \param posX Coordenada en x donde imprimir la primera carta
 * \param posY Coordenada en y donde imprimir la primera carta
 * \param pausa Si la siguiente carta se imprimirá al aplastar un botón o por tiempo
 *
 * \pre posX y posY no pueden ser negativos
 */
void ImprimirCascada(int posX,int posY, bool pausa);

//***************************************************************************
/** \brief Imprime cartas al azar en la pantalla
 *
 * \param cuantas el numero de cartas a imprimir
 * \param pausa Si la siguiente carta se imprimirá al aplastar un botón o por tiempo
 *
 */
void BoncheDeCartas(int cuantas,bool pausa);

//***************************************************************************
/** \brief Imprime cartas simulando un baile
 *
 * \param segundos segundos que duraran bailando
 *
 */
void ImprimirCartasBailarinas(int segundos);


int main()
{
    WORD original=ObtenerColorOriginal();
    EstablecerTamVentana(111,46);
    EstablecerColor(AGUAMARINA,BLANCO);
    system("cls");

    int pausa;
    int selec;
    do
    {
        //Menu
        cout<<"Buenas, a continuaci\242n le repartiremos cartas como usted dese\202\n";
        cout<<"Cascada: 1\n";
        cout<<"Bonche de cartas: 2\n";
        cout<<"Cartas bailarinas: 3\n";
        cout<<"Juego de cartas: 4\n";
        cout<<"Salir: 0\n";

        //capturar la opción
        do
        {
            selec=CapturaEntero("Opci\242n: ");
            if(selec<0 || selec>4)
            {
                cout<<"Opci\242n invalida\n";
            }
        }while(selec<0 || selec>4);

        //Ejecuta la opción pedida
        system("cls");
        switch(selec)
        {
            case 1:
                //Validar la entrada
                do
                {
                    pausa=CapturaEntero("Se imprimir\240n pausadamente?(0 No, 1 Si): ");
                    if(pausa!=0 && pausa!=1)
                    {
                        cout<<"Opci\242n invalida\n";
                    }
                }while(pausa!=0 && pausa!=1);

                ImprimirCascada(2,2,pausa);
                break;

            case 2:
                //Validar el número de cartas a imprimir
                int cantidad;
                do
                {
                    cantidad=CapturaEntero("N\243mero de cartas que se quiere imprimir: ");
                    if(cantidad<0)
                    {
                        cout<<"No se puede imprimir una cantidad negativa de cartas...\n";
                    }
                }while(cantidad<0);

                //Validar la entrada
                do
                {
                    pausa=CapturaEntero("Se imprimir\240n pausadamente?(0 No, 1 Si): ");
                    if(pausa!=0 && pausa!=1)
                    {
                        cout<<"Opci\242n invalida\n";
                    }
                }while(pausa!=0 && pausa!=1);

                BoncheDeCartas(cantidad,pausa);
                break;

            case 3:
                //Validar los segundos
                int segundos;
                do
                {
                    segundos=CapturaEntero("N\243mero de segundos que van a bailar: ");
                    if(segundos<0)
                    {
                        cout<<"No hay tiempo negativo en este programa...\n";
                    }
                }while(segundos<0);

                ImprimirCartasBailarinas(segundos);
                break;

            case 4:
                Juego21();
                break;
        }

    system("cls");
    }while(selec!=0);

    gotoxy(0,0);
    system("pause");
    EstablecerColor(original);

    return 0;
}

void ImprimirCascada(int posX,int posY, bool pausa)
{
    int tiempo=720;
    //Imprime todas las cartas de corazon
    for(int i=0,carta=1;i<13;i++,carta++)
    {
        ImprimirCarta(carta,CORAZON,posX+i*2,posY+i*2);
        gotoxy(0,0);

        if(pausa)
            system("pause");
        else
            Sleep(tiempo-=15);

        ImprimirReversoCarta(posX+i*2,posY+i*2);
    }

    //imprime todas las cartas de tréboles
    for(int i=0,carta=1;i<13;i++,carta++)
    {
        ImprimirCarta(carta,TREBOL,posX+11+i*2,posY+1+i*2);
        gotoxy(0,0);

        if(pausa)
            system("pause");
        else
            Sleep(tiempo-=14);

        ImprimirReversoCarta(posX+11+i*2,posY+1+i*2);
    }

    //imprime todas las cartas de picas
    for(int i=0,carta=1;i<13;i++,carta++)
    {
        ImprimirCarta(carta,PICAS,posX+22+i*2,posY+2+i*2);
        gotoxy(0,0);

        if(pausa)
            system("pause");
        else
            Sleep(tiempo-=10);

        ImprimirReversoCarta(posX+22+i*2,posY+2+i*2);
    }

    //imprime todas las cartas de diamante
    for(int i=0,carta=1;i<13;i++,carta++)
    {
        ImprimirCarta(carta,DIAMANTE,posX+33+i*2,posY+3+i*2);
        gotoxy(0,0);

        if(pausa)
            system("pause");
        else
            Sleep(tiempo-=10);

        ImprimirReversoCarta(posX+33+i*2,posY+3+i*2);
    }

    //Momento para apreciar las cartas
    gotoxy(0,0);
    system("pause");
}

void BoncheDeCartas(int cuantas,bool pausa)
{
    for(int i=1;i<=cuantas;i++)
    {
        ImprimirCartaRandom(rand()%85+2,rand()%25+2);
        gotoxy(0,0);
        if(pausa)
            system("pause");
        else
            Sleep(360);
    }
}

void ImprimirCartasBailarinas(int segundos)
{
    bool paso1=true;

    for(int i=1;i<=segundos;i++)
    {
        for(int i=0;i<3;i++)
        {
            if(paso1)
            {
                ImprimirCartaRandom(2+i*32 ,2);
                ImprimirReversoCarta(2+16+i*32 ,2);

                ImprimirCartaRandom(2+16+i*32 ,2+16);
                ImprimirReversoCarta(2+i*32 ,2+16);
            }
            else
            {
                ImprimirCartaRandom(2+16+i*32 ,2);
                ImprimirReversoCarta(2+i*32 ,2);

                ImprimirCartaRandom(2+i*32 ,2+16);
                ImprimirReversoCarta(2+16+i*32 ,2+16);
            }
        }
        paso1=!paso1;
        Sleep(760);
    }
}

void Juego21()
{
    int cuenta=0;
    int eleccion;
    int cartaNum;

    //Mensaje de presentación
    cout<<"El rey de ning\243n lugar a invitado a los mejores matem\240ticos del reino para ver cu\240l de ellos era el m\240s \napto "<<
        "para manejar las cuentas en su reino.\nPara ello ideo un juego de habilidad matem\240tica en donde se tiene que maximizar "<<
            "los puntos obtenidos, pero sin pasarse del n\243mero 21 (puesto que el rey sabe que la codicia es mala).\n";
    cout<<"El juego consiste en una pila de cartas y tu deber es elegir en si agarrar la carta de hasta el frente o no.\n"<<
        "Los puntos que vale la carta es igual a su numeraci\242n.\nComo es costumbre en los reinos, si fallas morir\240s(Sin presi\242n)\n";
    cout<<"Para hacer del juego un desaf\241o, tu mismo tendr\240s que contar la suma de las cartas\n"<<
        "(El rey simplemente quiere ver rodar cabezas)...\n";

    system("pause");
    system("cls");

    //Imprime "todo" el mazo
    ImprimirReversoCarta(53,10);
    gotoxy(0,0);

    do
    {
        //valida la elección
        do
        {
            gotoxy(0,0);
            eleccion=CapturaEntero("Te atreves a tomar la siguiente carta?(0 No, 1 Si): ");
            if(eleccion!=0 && eleccion!=1)
            {
                cout<<"Opci\242n invalida\n";
            }
        }while(eleccion!=0 && eleccion!=1);

        //"Revelas" la siguiente carta y la sumas
        cartaNum=rand()%13+1;
        cuenta+=cartaNum;

        if(eleccion)
            ImprimirCarta(cartaNum,rand()%4 +3, 37, 10);
        else
            ImprimirCarta(cartaNum,rand()%4 +3, 53, 10);

    }while(cuenta <=21 && eleccion);

    //Mensaje de game over
    gotoxy(0,0);
    //Si tomaste la carta y te pasaste, entonces....
    if(cuenta>21 && eleccion)
    {
        cout<<"Lo sentimos, te pasaste de 21 y ahora tu cabeza va a rodar\n";
        cout<<"Vuelve pronto por favor.\nSuma de las cartas: "<<cuenta<<'\n';
    }
    else
    {
        //Si no tomaste la carta puede que pasen 2 cosas, que ganes o que no ganes
        if(cuenta>21)
        {
            cout<<"FELICIDADES, si tomabas la carta tendr\241as una suma de "<<cuenta<<'\n';
            cout<<"Igual moriras pero, ahora te haran comida para reyes (El rey cree que si te comes una persona \nobtendras todos sus "<<
                "conocimientos)\nuna forma mas digna de morir\n";
        }
        else
        {
            cout<<"Muy mal,si tomabas la carta tendr\241as una suma de "<<cuenta<<'\n';
            cout<<"como el rey quiere a la persona que pueda sacar la mejor suma entonces seras purgado\n"<<
                "y tu cabeza rodara\n";
        }
    }
    system("Pause");
}
