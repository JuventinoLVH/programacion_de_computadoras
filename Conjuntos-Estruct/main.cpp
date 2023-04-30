// BIBLIOTECAS
#include <iostream>

#include "Conjunto.h"

// ESPACIOS DE NOMBRE
using std::cout;
using std::cin;
using std::endl;
using std::bad_alloc;

int main(){
	try {
		// Obtenemos la cardinalidad del conjunto A.
		int card;
		
		cout << "\n Indique la cardinalidad de A: ";
		cin >> card;    //NOTA: Verificar que la cardinalidad sea un valor mayor o igual a 0 y menor o igual que el máximo.
		
		// Se crea el conjunto A.
		Conjunto A(card);
		
		// Capturamos el conjunto A.
		A.Capturar();
		
		// Obtenemos la cardinalidad del conjunto B.
		cout << "\n Indique la cardinalidad de B: ";
		cin >> card;    //NOTA: Verificar que la cardinalidad sea un valor mayor o igual a 0 y menor o igual que el máximo.
		
		// Se crea el conjunto B.
		Conjunto B(card);
		
		// Capturamos el conjunto B.
		B.Capturar();
		
		// Se aplican operaciones entre ambos conjuntos.
		// INTERSECCIÓN.
		cout << "\n La intersecci\240n de A con B\n" <<
				"   Conjunto A =";
		
		A.Imprimir();
		
		cout << "\n   Conjunto B =";
		
		B.Imprimir();
		
		Conjunto Interseccion;
		Interseccion = A.Intersectar(B);
		
		cout << "\n   A n B =";
		
		Interseccion.Imprimir();
		
		cout << endl;
		
		/* Conjunto (Interseccion = A.Intersectar(B)).Imprimir(); */     // FUNCIONARÁ?
	
		// CONTENENCIA.
		cout << "\n Verificaremos si A contiene a B\n" <<
				"   B C A" << endl;
		
		if (A.Contiene(B)) cout << "\n   B SÍ es subconjunto de A" << endl;
		else cout << "\n   B NO es subconjunto de A" << endl;
		
		// DIFERENCIA.
		Conjunto Resta = A.Restar(B);
		
		cout << "\n La diferencia entre A y B\n" <<
				"   A - B =";
		
		Resta.Imprimir();
		
		cout << endl;
	} catch (bad_alloc &) {
		cout << "\n ¡Ha ocurrido un error al asignar memoria!" << endl;
	} catch (...) {
		cout << "\n ¡Ha ocurrido un error inesperado!" << endl;
	}
	
	return 0;
}

