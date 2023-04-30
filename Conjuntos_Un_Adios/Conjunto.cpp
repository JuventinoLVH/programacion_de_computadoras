

#include "Conjunto.h"

Conjunto::Conjunto()
{
	card = 0,
	elementos = NULL;
}


//*************************************************************************************************************
Conjunto::Conjunto(int card)
{
	if (card < 0) throw "Valor no v\240lido";

	this->card = card;

	if (card != 0) elementos = new char [card];

	for (int i = 0; i < card; ++i)
		elementos[i] = '\0';
}


//*************************************************************************************************************
Conjunto::Conjunto(const Conjunto &C)
{
	card = C.card;


	if (card != 0) elementos = new char [card];

	for (int i = 0; i < card; ++i)
		elementos[i] = C.elementos[i];
}


//*************************************************************************************************************
Conjunto::~Conjunto()
{
	if (elementos != NULL) delete [] elementos;
}


//*************************************************************************************************************
const Conjunto & Conjunto::operator=(const Conjunto &C)
{
	if (this == &C) return *this;


	delete [] elementos;

	card = C.card;

	if (card != 0) elementos = new char [card];

	for (int i = 0; i < card; ++i)
		elementos[i] = C.elementos[i];

    return *this;
}


//*************************************************************************************************************
const Conjunto Conjunto::operator+(const Conjunto &C) const
{
	return (Unir(C));
}


//*************************************************************************************************************
const Conjunto Conjunto::operator-(const Conjunto &C) const
{
	return (Restar(C));
}


//*************************************************************************************************************
const Conjunto Conjunto::operator*(const Conjunto &C) const
{
	return (Intersectar(C));
}


//*************************************************************************************************************
char & Conjunto::operator[](int i)
{
    if(i<0 || i>=card) throw "Indice invalido...";

    return elementos[i];
}


//*************************************************************************************************************
char Conjunto::operator[](int i) const
{
    if(i<0 || i>=card) throw "Indice invalido...";

    return elementos[i];
}


//*************************************************************************************************************
int Conjunto::GetCardinalidad() const
{
    return card;
}


//*************************************************************************************************************
void Conjunto::Imprimir() const
{
	std::cout << " {";

	for (int i = 0; i < card; ++i)
		std::cout << elementos[i] << ", ";

	if (card != 0) std::cout << "\b\b}";
	else std::cout << " }";
}


//*************************************************************************************************************
void Conjunto::Capturar()
{
	bool valorRepetido;

	for (int i = 0; i < card; ) {
		std::cout << " Ingrese el elemento " << (i + 1) << ": ";
		std::cin >> elementos[i];

		valorRepetido = false;

		for (int j = 0; j < i; ++j)
			if (elementos[j] == elementos[i]) {
				valorRepetido = true;
				break;
			}

		if (valorRepetido) {
			std::cout << " \255El elemento ingresado ya es parte del conjunto!\n";
			continue;
		} else ++i;
	}
}


//*************************************************************************************************************
bool Conjunto::Pertenece(char elemento) const
{
	for (int i = 0; i < card; ++i)
		if (elemento == elementos[i]) return true;

	return false;
}


//*************************************************************************************************************
bool Conjunto::Contiene(const Conjunto &C) const
{
	for (int i = 0; i < C.card; ++i)
		if (!Pertenece(C.elementos[i])) return false;

	return true;
}


//*************************************************************************************************************
Conjunto Conjunto::Unir(const Conjunto &C) const
{
	Conjunto UnionAux(card+C.card);
    int cardAux=0;
    for(;cardAux<card;cardAux++)
        UnionAux.elementos[cardAux]=elementos[cardAux];


	for (int i = 0; i < C.card; ++i)
		if (!Pertenece(C.elementos[i]))
			UnionAux.elementos[cardAux++] = C.elementos[i];


    Conjunto Union(cardAux);
    for(int i=0;i<cardAux;i++)
        Union.elementos[i]=UnionAux.elementos[i];

	return Union;
}


//*************************************************************************************************************
Conjunto Conjunto::Intersectar(const Conjunto &C) const
{
	Conjunto InterseccionAux((card  < C.card) ? card : C.card);
	int cardAux = 0;

	for (int i = 0; i < C.card; ++i)
		if (Pertenece(C.elementos[i]))
			InterseccionAux.elementos[cardAux++] = C.elementos[i];

    Conjunto Interseccion(cardAux);

    for(int i=0;i<cardAux;i++)
        Interseccion.elementos[i]=InterseccionAux.elementos[i];

	return Interseccion;
}


//*************************************************************************************************************
Conjunto Conjunto::Restar(const Conjunto &C) const
{
	Conjunto RestaAux(card);
	int cardAux = 0;

	for (int i = 0; i < card; ++i)
		if (!C.Pertenece(elementos[i]))
			RestaAux.elementos[cardAux++] = elementos[i];

	Conjunto Resta(cardAux);
	for(int i=0;i<cardAux;i++)
        Resta.elementos[i]=RestaAux.elementos[i];

	return Resta;
}


//*************************************************************************************************************
std::ostream & operator<<(std::ostream &salida, const Conjunto &C)
{
    salida << " {";

	for (int i = 0; i < C.card; ++i)
		salida << C.elementos[i] << ", ";

	if (C.card != 0) salida << "\b\b}";
	else salida << " }";

	return salida;
}


//*************************************************************************************************************
std::istream & operator>>(std::istream &entrada, const Conjunto &C)
{
    bool valorRepetido;

	for (int i = 0; i < C.card; ) {
		std::cout << " Ingrese el elemento " << (i + 1) << ": ";
		entrada >> C.elementos[i];

		valorRepetido = false;

		for (int j = 0; j < i; ++j)
			if (C.elementos[j] == C.elementos[i]) {
				valorRepetido = true;
				break;
			}

		if (valorRepetido) {
			std::cout << " \255El elemento ingresado ya es parte del conjunto!\n";
			continue;
		} else ++i;
	}

	return entrada;
}



