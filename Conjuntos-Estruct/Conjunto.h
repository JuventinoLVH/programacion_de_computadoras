/*
Nombre: .h
Autor: Manuel I Gómez G
Fecha: 5/22/20
Descripción:
*/

#ifndef CONJUNTOCLASES_CONJUNTO_H
#define CONJUNTOCLASES_CONJUNTO_H

class Conjunto {
public:
	Conjunto();
	//Conjunto(int card);<-
	//Conjunto(const Conjunto &C);<-

	//void operator=(const Conjunto &C);<-

	//~Conjunto();<- Necesarios ya que se tiene un elemento con memoria dinamica

	void Imprimir();
	void Capturar();
	Conjunto Unir(Conjunto C);
	bool Pertenece(char elemento);
	Conjunto Intersectar(Conjunto C);
	Conjunto Restar(Conjunto C);
	bool Contiene(Conjunto C);

private:
	int card;
	char *elementos;

};

#endif //CONJUNTOCLASES_CONJUNTO_H
