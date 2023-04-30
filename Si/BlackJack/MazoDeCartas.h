#ifndef MAZODECARTAS_H_INCLUDED
#define MAZODECARTAS_H_INCLUDED

#include "Carta.h"

class MazoDeCartas
{
private:
    Carta * mazo[52];
    int tope;

public:

    //*********************************************************************************
    /** \brief constructor por defecto
     *
     */
    MazoDeCartas();


    //*********************************************************************************
    /** \brief constructor de copias
     *
     * \param mazoAux el mazo a duplicar
     */
    MazoDeCartas(const MazoDeCartas & mazoAux);


    //*********************************************************************************
    /** \brief El todopoderosisimo destructor
     *
     */
    ~MazoDeCartas();


    //*********************************************************************************
    /** \brief operador para igualar un mazo
     *
     * \param mazoAux mazo a duplicar
     *
     * \return const el mazo igualado
     */
    const MazoDeCartas & operator=(const MazoDeCartas &mazoAux);


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

    //*********************************************************************************
    /** \brief
     *
     * \return void
     *
     */
    void Ordenar();
};

#endif // MAZODECARTAS_H_INCLUDED
