/* Nombre: MazoCartas.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 27/05/2020
   Descripci�n: clase de un mazo de cartas
*/
#ifndef MAZOCARTAS_H_INCLUDED
#define MAZOCARTAS_H_INCLUDED

#include "Carta.h"

class MazoCartas
{
private:
    Carta * mazo[52];
    int tope;

public:

    //*********************************************************************************
    /** \brief constructor por defecto
     *
     */
    MazoCartas();


    //*********************************************************************************
    /** \brief constructor de copias
     *
     * \param mazoAux el mazo a duplicar
     */
    MazoCartas(const MazoCartas & mazoAux);


    //*********************************************************************************
    /** \brief El todopoderosisimo destructor
     *
     */
    ~MazoCartas();


    //*********************************************************************************
    /** \brief operador para igualar un mazo
     *
     * \param mazoAux mazo a duplicar
     *
     * \return const el mazo igualado
     */
    const MazoCartas & operator=(const MazoCartas &mazoAux);


    //*********************************************************************************
    /** \brief Funci�n para obtener cuantas cartas quedan
     *
     * \return cuantas caratas quedan
     */
    int CuantasQuedan()const ;


    //*********************************************************************************
    /** \brief Funcio�n que saca una carta del mazo
     *
     * \return la carta del tope
     *
     */
    Carta & SacarCarta();


    //*********************************************************************************
    /** \brief Funci�n que baraja el mazo
     *
     */
    void barajar();
};

#endif // MAZOCARTAS_H_INCLUDED
