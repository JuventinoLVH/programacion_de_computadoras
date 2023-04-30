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

    /** \brief Función que imprime la mano (cartas)
     *
     * \param ocultas=0 int
     * \return void
     *
     */
    void ImprimirMano(int ocultas=0);

    /** \brief Función que controla la sumatoria de las puntuaciones.
     *
     * \return int
     *
     */
    int GetPuntos();

    /** \brief Función para devolver las cartas en la mano.
     *
     * \return int
     *
     */
    int GetTamano() const;

    /** \brief Función que agrega una carta a solicitud del usuario.
     *
     * \param carta const Carta&
     * \return void
     *
     */
    void AgregarCarta(const Carta &carta);

    /** \brief Función que vacía la mano (cartas)
     *
     * \return void
     *
     */
    void VaciarMano();
};

#endif // MANOBLACKJACK_H_INCLUDED
