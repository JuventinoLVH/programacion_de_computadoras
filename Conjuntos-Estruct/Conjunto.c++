/*
Nombre: .h
Autor: Manuel I Gómez G
Fecha: 5/22/20
Descripción: 
*/
#include <iostream>

#include "Conjunto.h"

using std::cout;
using std::cin;
using std::endl;

// Funciones pertenecientes a la clase 'Conjunto'.

Conjunto::Conjunto() {
	card = 0,
	elementos = NULL;
}

Conjunto::Conjunto(int card) {
	if (card < 0) throw "Valor no v\240lido";
	
	this->card = card;
	
	if (card != 0) elementos = new char [card];
	
	for (int i = 0; i < card; ++i)
		elementos[i] = '\0';
}

Conjunto::Conjunto(const Conjunto &C) {
	card = C.card;
	
	if (card != 0) elementos = new char [card];
	
	for (int i = 0; i < card; ++i)
		elementos[i] = C.elementos[i];
}

void Conjunto::operator=(const Conjunto &C) {  // A = A
	if (this == &C) return;
	
	delete [] elementos;
	
	card = C.card;
	
	if (card != 0) elementos = new char [card];
	
	for (int i = 0; i < card; ++i)
		elementos[i] = C.elementos[i];
}

Conjunto::~Conjunto() {
	if (elementos != NULL) delete [] elementos;
}

void Conjunto::Imprimir() {
	cout << " {";
	
	for (int i = 0; i < card; ++i)
		cout << elementos[i] << ", ";
	
	if (card != 0) cout << "\b\b}";
	else cout << " }";
}

void Conjunto::Capturar() {
	bool valorRepetido;
	
	for (int i = 0; i < card; ) {
		cout << " Ingrese el elemento " << (i + 1) << ": ";
		cin >> elementos[i];
		
		valorRepetido = false;
		
		for (int j = 0; j < i; ++j)
			if (elementos[j] == elementos[i]) {
				valorRepetido = true;
				break;
			}
		
		if (valorRepetido) {
			cout << " \255El elemento ingresado ya es parte del conjunto!" << endl;
			continue;
		} else ++i;
	}
}

Conjunto Conjunto::Unir(Conjunto C) {
	Conjunto Union = *this;
	
	for (int i = 0; i < C.card; ++i)
		if (!Pertenece(C.elementos[i]))
			Union.elementos[Union.card++] = C.elementos[i];
	
	return Union;
}

bool Conjunto::Pertenece(char elemento) {
	for (int i = 0; i < card; ++i)
		if (elemento == elementos[i]) return true;
	
	return false;
}

Conjunto Conjunto::Intersectar(Conjunto C) {
	Conjunto Interseccion((card < C.card) ? card : C.card);
	
	int cardTemporal = 0;
	
	for (int i = 0; i < C.card; ++i)
		if (Pertenece(C.elementos[i]))
			Interseccion.elementos[cardTemporal++] = C.elementos[i];
	
	Interseccion.card = cardTemporal;
	
	
	return Interseccion;
}

Conjunto Conjunto::Restar(Conjunto C) {
	Conjunto Resta(card);
	
	int cardTemporal = 0;
	
	for (int i = 0; i < card; ++i)
		if (!C.Pertenece(elementos[i]))
			Resta.elementos[cardTemporal++] = elementos[i];
	
	Resta.card = cardTemporal;
	
	return Resta;
}

bool Conjunto::Contiene(Conjunto C) {
	for (int i = 0; i < C.card; ++i)
		if (!Pertenece(C.elementos[i])) return false;
	
	return true;
}
