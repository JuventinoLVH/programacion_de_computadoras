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

    /** \brief Funci�n que imprime la mano (cartas)
     *
     * \param ocultas=0 int
     * \return void
     *
     */
    void ImprimirMano(int ocultas=0);

    /** \brief Funci�n que controla la sumatoria de las puntuaciones.
     *
     * \return int
     *
     */
    int GetPuntos();

    /** \brief Funci�n para devolver las cartas en la mano.
     *
     * \return int
     *
     */
    int GetTamano() const;

    /** \brief Funci�n que agrega una carta a solicitud del usuario.
     *
     * \param carta const Carta&
     * \return void
     *
     */
    void AgregarCarta(const Carta &carta);

    /** \brief Funci�n que vac�a la mano (cartas)
     *
     * \return void
     *
     */
    void VaciarMano();
};

#endif // MANOBLACKJACK_H_INCLUDED
