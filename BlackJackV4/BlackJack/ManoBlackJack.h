#ifndef MANOBLACKJACK_H_INCLUDED
#define MANOBLACKJACK_H_INCLUDED

#include "Carta.h"

class ManoBlackJack
{
private:
    int posX,posY;
    Carta cartas[20];
    int cartasEnMano;

public:
    ManoBlackJack(int x,int y);

    void ImprimirMano(int ocultas=0);
    int GetPuntos();
    int GetTamano() const;
    void AgregarCarta(const Carta &carta);
    void VaciarMano();
};

#endif // MANOBLACKJACK_H_INCLUDED
