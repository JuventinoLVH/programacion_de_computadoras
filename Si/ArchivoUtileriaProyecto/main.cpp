
#include <iostream>
#include"Utileria.h"

using namespace std;

int main()
{
    CambiaCursor(APAGADO);
    EstablecerTamVentana(120,38);

    DibujarMarcoDoble(15,100,9,5,0.0131,BLANCO,AZULCLARO,true,BLANCO);

    AnimarArchivo("Arte\\Titulo",0.08,14,8,BLANCO,AZUL);
    //DibujarMarcoDoble(20,20,5,5,0.03,BLANCO,AZULCLARO,true);

    gotoxy(10,10);
    CambiaCursor(APAGADO);
    system("Pause");
    return 0;
}
