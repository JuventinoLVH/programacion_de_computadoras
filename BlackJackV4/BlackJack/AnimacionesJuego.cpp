/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include "AnimacionesJuego.h"
#


//*************************************************************************************************************************
void presentacion()
{

    PlaySound((LPCSTR)"Musica\\Soccer.wav", NULL, SND_ASYNC );
    Sleep(980);
    DibujarMarcoDoble(13,100,MARGEN_COLUMNA_INF,MARGEN_FILA_SUP,0.015,BLANCO,AZULCLARO,true,BLANCO);

    AnimarArchivo("Arte\\Titulo",0.018,140,MARGEN_COLUMNA_INF+4,MARGEN_FILA_SUP+2,BLANCO,AZUL);

}


//*************************************************************************************************************************
void PantallaDeTitulo(Color fondo, Color texto)
{
    DibujarMarcoDoble(13,98,MARGEN_COLUMNA_INF,MARGEN_FILA_SUP,0,BLANCO,AZULCLARO,true,BLANCO);
    BotonesTitulo(fondo,texto);
}


//*************************************************************************************************************************
void BotonesTitulo(Color fondo, Color texto)
{
    DibujarArchivo("Arte\\ManualDeUsuario.txt",115,20,fondo,texto);

    BotonJugar(fondo,texto);
    BotonInstruc(fondo,texto);
    BotonCreditos(fondo,texto);
    BotonSalir(fondo,texto);
}


//*************************************************************************************************************************
void BotonesJuego(Color fondo, Color texto)
{

    BotonTomarCarta(fondo,texto);
    BotonConservarMano(fondo,texto);
    BotonReiniciar(fondo,texto);
    BotonVolver(fondo,texto);
}


//*************************************************************************************************************************
void Parpadeo(Color fondo ,double milseg)
{
    WORD colorOriginal=ObtenerColorOriginal();
    EstablecerColor(fondo,BLANCO);

    system("cls");
    Sleep(milseg);

    EstablecerColor(colorOriginal);
    system("cls");
}


//*************************************************************************************************************************
void IluminarBoton(void (* Boton)(Color,Color) ,Color fondo ,Color texto)
{
    Boton(fondo,texto);
}


//*************************************************************************************************************************
void ElegirBoton(void (* Boton)(Color , Color) ,double segundos ,Color fondo ,Color texto ,
                     unsigned int vecesParpadeo ,Color fondoParp ,Color textoParp)
{
    segundos*=1000;

    //FIXME
    PlaySound((LPCSTR)"Musica\\EfectoDeBala2.wav", NULL, SND_ASYNC );

    if(vecesParpadeo==0)
    {
        Boton(fondo,texto);
        Sleep(segundos);
    }
    else
    {
        segundos/=vecesParpadeo*2;
        for(int i=0;i<5;i++)
        {
            Boton(fondo,texto);
            Sleep(segundos);
            Boton(fondoParp,textoParp);
            Sleep(segundos);
        }
    }

}


//*************************************************************************************************************************
void BotonJugar(Color fondo, Color texto)
{
    DibujarArchivo(DIR_BOTON_JUGAR,POSX_BOTON_JUEGO ,POSY_BOTON_JUEGO ,fondo ,texto);
}


//*************************************************************************************************************************
void BotonInstruc(Color fondo, Color texto)
{
    DibujarArchivo(DIR_BOTON_INSTRUCCIONES,POSX_BOTON_INSTRUCCIONES,POSY_BOTON_INSTRUCCIONES ,fondo ,texto);
}


//*************************************************************************************************************************
void BotonCreditos(Color fondo, Color texto)
{
    DibujarArchivo(DIR_BOTON_CREDITOS,POSX_BOTON_CREDITOS ,POSY_BOTON_CREDITOS ,fondo ,texto);
}


//*************************************************************************************************************************
void BotonSalir(Color fondo, Color texto)
{
    DibujarArchivo(DIR_BOTON_SALIR,POSX_BOTON_SALIR ,POSY_BOTON_SALIR ,fondo ,texto);
}


//*************************************************************************************************************************
void BotonTomarCarta(Color fondo, Color texto )
{
    DibujarArchivo(DIR_BOTON_TOMAR_CARTA ,POSX_BOTON_TOMAR_CARTA ,POSY_BOTON_TOMAR_CARTA ,fondo ,texto);
}


//*************************************************************************************************************************
void BotonConservarMano(Color fondo, Color texto )
{
    DibujarArchivo(DIR_BOTON_CONSERVAR_MANO ,POSX_BOTON_CONSERVAR_MANO ,POSY_BOTON_CONSERVAR_MANO ,fondo ,texto);
}


//*************************************************************************************************************************
void BotonReiniciar(Color fondo, Color texto )
{
    DibujarArchivo(DIR_BOTON_REINICIAR ,POSX_BOTON_REINICIAR ,POSY_BOTON_REINICIAR ,fondo ,texto);
}


//*************************************************************************************************************************
void BotonVolver(Color fondo , Color texto)
{
    DibujarArchivo(DIR_BOTON_VOLVER ,POSX_BOTON_VOLVER ,POSY_BOTON_VOLVER ,fondo ,texto);
}

