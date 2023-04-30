
#include <iomanip>
#include <cctype>
#include <conio.h>


#include "Utileria.h"
#include "AnimacionesJuego.h"
#include "juego.h"

#define FONDO AZULCLARO
#define TEXTO GRISCLARO
#define ILUMINADO NEGRO

#define POS_X_MAZO 55
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

/** \brief Función para manipular los botones de inicio
 *
 * \param const char *cadena
 * \param
 * \return
 *
 */

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
                IluminarBoton(BotonJugar,FONDO,ILUMINADO);
                break;

            case 2:
                IluminarBoton(BotonInstruc,FONDO,ILUMINADO);
                break;

            case 3:
                IluminarBoton(BotonCreditos,FONDO,ILUMINADO);
                break;

            case 4:
                IluminarBoton(BotonSalir,FONDO,ILUMINADO);
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
                        juego(FONDO,TEXTO,ILUMINADO);
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



void EntradaBotones(const char *cadena)
{
    char tecla;
    DibujarArchivo(cadena,0,0,FONDO,TEXTO);
    if (cadena != DIR_SALIR)
        IluminarBoton(BotonVolver,FONDO,ILUMINADO);

    do
    {
        if(kbhit())
            tecla = getch();
    }while(tecla!=ENTER);
    return;

}

