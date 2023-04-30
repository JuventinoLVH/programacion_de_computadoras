/* Nombre:.cpp
   Autor:
   Fecha:
   Descripci�n:
*/

#include "AnimacionesJuego.h"



//*************************************************************************************************************************
//Funci�n de la introducci�n al juego
void presentacion()
{

    PlaySound((LPCSTR)"Musica\\Soccer.wav", NULL, SND_ASYNC );
    Sleep(980);
    DibujarMarcoDoble(13,100,MARGEN_COLUMNA_INF,MARGEN_FILA_SUP,0.015,BLANCO,AZULCLARO,true,BLANCO);

    AnimarArchivo("Arte\\Titulo",0.018,140,MARGEN_COLUMNA_INF+4,MARGEN_FILA_SUP+2,BLANCO,AZUL);

}


//*************************************************************************************************************************
//Funci�n que Imprime la Pantalla de t�tulo
void PantallaDeTitulo(Color fondo, Color texto)
{
    DibujarMarcoDoble(13,98,MARGEN_COLUMNA_INF,MARGEN_FILA_SUP,0,BLANCO,AZULCLARO,true,BLANCO);
    BotonesTitulo(fondo,texto);
}


//*************************************************************************************************************************
//Funci�n que imprime los botones del t�tulo principal, o la interfaz.
void BotonesTitulo(Color fondo, Color texto)
{
    DibujarArchivo("Arte\\ManualDeUsuario.txt",115,20,fondo,texto);

    BotonJugar(fondo,texto);
    BotonInstruc(fondo,texto);
    BotonCreditos(fondo,texto);
    BotonSalir(fondo,texto);
}


//*************************************************************************************************************************
//Funci�n para los botones una vez se est� en juego.
void BotonesJuego(Color fondo, Color texto)
{

    BotonTomarCarta(fondo,texto);
    BotonConservarMano(fondo,texto);
    BotonReiniciar(fondo,texto);
    BotonVolver(fondo,texto);
}


//*************************************************************************************************************************
//Funci�n que causa un parpadeo dandole un efecto de transici�n al juego.
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
//Funci�n que ilumina un bot�n, que en el programa es usada para saber sobre qu� bot�n se est� navegando.
void IluminarBoton(void (* Boton)(Color,Color) ,Color fondo ,Color texto)
{
    Boton(fondo,texto);
}


//*************************************************************************************************************************
//Funci�n que da un efecto de bala al saber que se seleccion� el bot�n
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
//Funci�n que dibuja el bot�n de jugar.
void BotonJugar(Color fondo, Color texto)
{
    DibujarArchivo(DIR_BOTON_JUGAR,POSX_BOTON_JUEGO ,POSY_BOTON_JUEGO ,fondo ,texto);
}


//*************************************************************************************************************************
//Funci�n que dibuja el bot�n de instrucciones.
void BotonInstruc(Color fondo, Color texto)
{
    DibujarArchivo(DIR_BOTON_INSTRUCCIONES,POSX_BOTON_INSTRUCCIONES,POSY_BOTON_INSTRUCCIONES ,fondo ,texto);
}


//*************************************************************************************************************************
//Funci�n que dibuja el bot�n de cr�ditos.
void BotonCreditos(Color fondo, Color texto)
{
    DibujarArchivo(DIR_BOTON_CREDITOS,POSX_BOTON_CREDITOS ,POSY_BOTON_CREDITOS ,fondo ,texto);
}


//*************************************************************************************************************************
//Funci�n que dibuja el bot�n de salir.
void BotonSalir(Color fondo, Color texto)
{
    DibujarArchivo(DIR_BOTON_SALIR,POSX_BOTON_SALIR ,POSY_BOTON_SALIR ,fondo ,texto);
}


//*************************************************************************************************************************
//Funci�n que dibuja el bot�n de tomar una carta
void BotonTomarCarta(Color fondo, Color texto )
{
    DibujarArchivo(DIR_BOTON_TOMAR_CARTA ,POSX_BOTON_TOMAR_CARTA ,POSY_BOTON_TOMAR_CARTA ,fondo ,texto);
}


//*************************************************************************************************************************
//Funci�n que dibuja el bot�n de quedarte con tu mano.
void BotonConservarMano(Color fondo, Color texto )
{
    DibujarArchivo(DIR_BOTON_CONSERVAR_MANO ,POSX_BOTON_CONSERVAR_MANO ,POSY_BOTON_CONSERVAR_MANO ,fondo ,texto);
}


//*************************************************************************************************************************
//Funci�n que dibuja el bot�n de reiniciar la partida.
void BotonReiniciar(Color fondo, Color texto )
{
    DibujarArchivo(DIR_BOTON_REINICIAR ,POSX_BOTON_REINICIAR ,POSY_BOTON_REINICIAR ,fondo ,texto);
}


//*************************************************************************************************************************
//Funci�n que dibuja el bot�n de regresar, para devolverse a la posici�n previa.
void BotonVolver(Color fondo , Color texto)
{
    DibujarArchivo(DIR_BOTON_VOLVER ,POSX_BOTON_VOLVER ,POSY_BOTON_VOLVER ,fondo ,texto);
}

