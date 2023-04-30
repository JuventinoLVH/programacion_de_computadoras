#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

#include <iostream>

class Conjunto {
//*************************************************************************************************************
    /** \brief Operador para imprimir un conjunto
     *
     * \param salida el flujo de salida
     * \param C El  conjunto a imprimir
     * \return el flujo de salida
     *
     */
    friend std::ostream & operator<<(std::ostream &salida, const Conjunto &C);


//*************************************************************************************************************
    /** \brief Operador para capturar un conjunto
     *
     * \param flujo flujo de entrada
     * \param C el conjunto a capturar
     * \return el flujo de entrada
     *
     */
    friend std::istream & operator>>(std::istream &entrada, const Conjunto &C);


private:

	int card;
	char *elementos;

public:

//*************************************************************************************************************
    /** \brief Constructor por defecto
     *
     */
	Conjunto();


//*************************************************************************************************************
    /** \brief Constructor de un conjunto de cardinalidad 'card'
     *
     * \param card la cardinalidad del conjunto
     *
     */
	Conjunto(int card);


//*************************************************************************************************************
    /** \brief Constructor de copias
     *
     * \param C el conjunto a copiar
     *
     */
	Conjunto(const Conjunto &C);


//*************************************************************************************************************
    /** \brief El poderosisimo destructor
     *
     */
	~Conjunto();


//*************************************************************************************************************
    /** \brief Operador para asignar un conjunto a otro
     *
     * \param C un conjunto
     * \return una copia del conjunto C
     *
     */
	const Conjunto & operator=(const Conjunto &C);


//*************************************************************************************************************
    /** \brief Operador para calcualar la unión de 2 conjuntos
     *
     * \param C un conjunto
     * \return la union con el conjunto C
     *
     */
    const Conjunto operator+(const Conjunto &C) const;


//*************************************************************************************************************
    /** \brief Operador para calcular la resta de 2 conjuntos
     *
     * \param C un conjunto
     * \return la resta con el conjunto C
     *
     */
    const Conjunto operator-(const Conjunto &C) const;


//*************************************************************************************************************
    /** \brief Operador para calcular la intersección de 2 conjuntos
     *
     * \param C un conjunto
     * \return la intersección con el conjunto
     *
     */
    const Conjunto operator*(const Conjunto &C) const;


//*************************************************************************************************************
    /** \brief Operador de acceso para los elementos del conjunto
     *
     * \param i indice del elemento
     * \return El elemento
     *
     */
    char & operator[](int i);


//*************************************************************************************************************
    /** \brief Operador de acceso para los elementos del conjunto
     *
     * \param i indice del elemento
     * \return El valor del elemento
     *
     */
    char operator[](int i) const ;


//*************************************************************************************************************
    /** \brief Función que devuelve la cardinalidad del conjunto
     *
     */
	int GetCardinalidad() const ;


//*************************************************************************************************************
    /** \brief Función que imprime un conjunto
     *
     */
	void Imprimir() const ;


//*************************************************************************************************************
    /** \brief Función para capturar un conjunto
     *
     */
	void Capturar();


//*************************************************************************************************************
    /** \brief Función que calcula si un elemento pertenece al conjunto
     *
     * \param elemento elemento a checar
     * \return Si el elemento está en el conjunto
     *
     */
	bool Pertenece(char elemento) const ;


//*************************************************************************************************************
    /** \brief Función que calcula si un conjunto pertenece al actual
     *
     * \param C un conjunto
     * \return Si el conjunto está en el conjnto actual
     *
     */
	bool Contiene(const Conjunto &C) const ;


//*************************************************************************************************************
    /** \brief Función que calcula la unión con otro conjunto
     *
     * \param C un conjunto
     * \return La unión con el conjunto
     *
     */
	Conjunto Unir(const Conjunto &C) const ;


//*************************************************************************************************************
    /** \brief Función que calcula la intersección con otro conjunto
     *
     * \param C un conjunto
     * \return La intersección con el conjunto
     *
     */
	Conjunto Intersectar(const Conjunto &C) const ;


//*************************************************************************************************************
    /** \brief Función que calcula la "resta" con otro conjunto
     *
     * \param C un conjunto
     * \return La "resta" con el conjunto
     *
     */
	Conjunto Restar(const Conjunto &C) const ;

};

#endif // CONJUNTO_H_INCLUDED
