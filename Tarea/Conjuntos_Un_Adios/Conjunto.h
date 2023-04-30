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
    /** \brief Operador para calcualar la uni�n de 2 conjuntos
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
    /** \brief Operador para calcular la intersecci�n de 2 conjuntos
     *
     * \param C un conjunto
     * \return la intersecci�n con el conjunto
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
    /** \brief Funci�n que devuelve la cardinalidad del conjunto
     *
     */
	int GetCardinalidad() const ;


//*************************************************************************************************************
    /** \brief Funci�n que imprime un conjunto
     *
     */
	void Imprimir() const ;


//*************************************************************************************************************
    /** \brief Funci�n para capturar un conjunto
     *
     */
	void Capturar();


//*************************************************************************************************************
    /** \brief Funci�n que calcula si un elemento pertenece al conjunto
     *
     * \param elemento elemento a checar
     * \return Si el elemento est� en el conjunto
     *
     */
	bool Pertenece(char elemento) const ;


//*************************************************************************************************************
    /** \brief Funci�n que calcula si un conjunto pertenece al actual
     *
     * \param C un conjunto
     * \return Si el conjunto est� en el conjnto actual
     *
     */
	bool Contiene(const Conjunto &C) const ;


//*************************************************************************************************************
    /** \brief Funci�n que calcula la uni�n con otro conjunto
     *
     * \param C un conjunto
     * \return La uni�n con el conjunto
     *
     */
	Conjunto Unir(const Conjunto &C) const ;


//*************************************************************************************************************
    /** \brief Funci�n que calcula la intersecci�n con otro conjunto
     *
     * \param C un conjunto
     * \return La intersecci�n con el conjunto
     *
     */
	Conjunto Intersectar(const Conjunto &C) const ;


//*************************************************************************************************************
    /** \brief Funci�n que calcula la "resta" con otro conjunto
     *
     * \param C un conjunto
     * \return La "resta" con el conjunto
     *
     */
	Conjunto Restar(const Conjunto &C) const ;

};

#endif // CONJUNTO_H_INCLUDED
