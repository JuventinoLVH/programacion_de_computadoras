/*
Nombre: PolinomioConArreglos.cpp
Autor: Gabriel Andrés Villegas Aguilar
            ----Edicion----
            Marco Antonio Guerrero Vasquez

Fecha: -Creación 01/04/2020- -Edición 02/04/2020-
Descripción: Imprimir un polinomio a través de datos dados por el usuario.
*/

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstdio>


using namespace::std;
//***************************************************//
//         ----- Prototipos de función -----         //
//***************************************************//
/**
 * @brief Funcion que imprime el signo del siguiente valor de un arreglo
 * @param arreglo Arreglo que se usará
 * @param indice Indice anterior del signo que se quiere obtener
 */
char Signo(float num);
//****************************************************//
/**
 * @brief Funcion que convierte el valor de un dato de un arreglo en valor absoluto de acuerdo al indice
 * @param Arreglo Arreglo que se usará
 * @param Indice Indice del arreglo que corresponde al dato a cambiar.
 * @warning Cambia el valor del arreglo.
 */
float ValAbs(float num);
//****************************************************//
/**
 * @brief Función que indica si hay un error en la entrada de datos y detiene el programa en caso de error irrecuperable
 * @return Error Verdadero o falso
 */
bool ErrorCapturaReal();
//****************************************************//
int main() {


    int n = 0, continuar; // Numero de coeficientes que el usuario dará
    char solicitud[100];

    cout << "Bienvenido al programa, usuario. " << endl;
    cout << "Vamos a imprimir un polinomio, pero para eso necesito de tu ayuda" << endl;
    do{
        bool error = true;
        //******************************************************************//
        // -----    Captura del grado de polinomio de manera segura   ----- //
        // -- Nos aseguramos que el valor no sea menor a 1 ni mayor a 20 -- //
        //******************************************************************//
        do {
            while (error) {
                cout << "Dime el grado del polinomio (No mas de 20) (El valor no puede ser menor de 0): ";
                cin >> n;
                error = ErrorCapturaReal();
            }
            if (n < 0 || n > 20) {
                cout << "Se ha salido del rango [0,20]" << endl;
                error = true;
            }

        } while (n < 0 || n > 20);

        float a[n + 1]; //Declaración del arreglo
        //***********************************************************//
        // -----      Datos del arreglo con captura segura     ----- //
        // --  Nos aseguramos que el primer coeficiente no sea 0  -- //
        //***********************************************************//
        bool salir = false;
        do {
            do {
				sprintf(solicitud,"Ingrese el coeficiente a[%d]: ",n);
                cout << solicitud;
                cin >> a[0];
                error = ErrorCapturaReal();
            } while (error);
            if(n > 0 && a[0] != 0) salir = true;
            if(n == 0) salir = true;
            if (n > 0 && a[0] == 0) cout << "El primer coeficiente no puede ser 0..." << endl;
        } while (!salir);

        /* ----- Ciclo que depende del valor de n ----- */
        for (int i = 1; i <= n; i++) {
            do {
				sprintf(solicitud,"Ingrese el coeficiente a[%d]: ",n-i);
                cout << solicitud;
                cin >> a[i];
                error = ErrorCapturaReal();
            } while (error);
        }

        cout << "El polinomio con grado " << n << " quedaria de la siguiente manera: " << endl << endl;
        //************************************************************************//
        //             ----- Procedemos a imprimir el polinomio -----             //
        //************************************************************************//
        /* ----- Impresión del primer término del polinomio ----- */
        if(a[0] < 0) cout << Signo(a[0]);
        if (ValAbs(a[0]) != 1) cout << a[0];
        cout << "x";
        if (n > 1) cout << "^" << n;

        /* ----- Impresión de los terminos [#2 - #n-2] ----- */
        int indicesMedios = n - 1; /* --- Variable declarada para no hacer el calculo dentro del ciclo --- */
        for (int i = 1; i < indicesMedios; i++) {
			if(a[i] != 0){
				cout << " " << Signo(a[i]) << " ";
				if(ValAbs(a[i]) != 1) cout << ValAbs(a[i]);
				cout << "x^" << (n-i);
			}
        }
        /* ----- Impresión del penúltimo término ----- */
        if (n > 1) { /* --- Siempre que el polinomio sea mayor a grado 1 --- */
            cout << " " << Signo(a[n-1]) << " ";
			if(ValAbs(a[n-1]) != 1) cout << ValAbs(a[n-1]);
			cout << "x";
        }
        /* ----- Impresión de la constante ----- */
        if (a[n] != 0) cout << " " << Signo(a[n]) << " " << ValAbs(a[n]);


        cout << endl << endl << endl;
        cout << "Desea ingresar otro polinomio?" << endl;
        cout << "******************************" << endl;
        cout << "* Si --------UwU---------- 1 *" << endl;
        cout << "* No --------UnU---------- 0 *" << endl;
        cout << "******************************" << endl;
        do {
            do {
                cin >> continuar;
                error = ErrorCapturaReal();
            } while (error);
            if (continuar != 0 && continuar != 1) cout << "N\243mero fuera de rango..." << endl;
        }while(continuar != 0 && continuar != 1);
        if (continuar == 1) system("cls");
    }while(continuar == 1);
    return 0;
}

//***************************************************//
//             -----  Funciones  -----              //
//***************************************************//
/**
 * @brief Funcion que imprime el signo del siguiente valor de un arreglo
 * @param arreglo Arreglo que se usará
 * @param indice Indice anterior del signo que se quiere obtener
 */
char Signo(float num){
//    if (num < 0) {
//        cout << " - ";
//    } else {
//        cout << " + ";
//    }
//
    return (num < 0 ? '-': '+');
}
//**************************
/**
 * @brief Funcion que convierte el valor de un dato de un arreglo en valor absoluto de acuerdo al indice
 * @param Arreglo Arreglo que se usará
 * @param Indice Indice del arreglo que corresponde al dato a cambiar.
 * @warning Cambia el valor del arreglo.
 */
float ValAbs(float num ){
    return (num >= 0 ? num : -num);
}
//**************************
/**
 * @brief Función que indica si hay un error en la entrada de datos y detiene el programa en caso de error irrecuperable
 * @return Error Verdadero o falso
 */
bool ErrorCapturaReal()
{
    bool Error = false;
        if(cin.bad()){
            cout << "Ocurri\242 un error irrecuperable en el flujo de entrada" << endl;
            system("pause");
            exit(1);
        }
        if(std::cin.fail()){
            cout << "Error: no es un n\243mero. Introduzca de nuevo..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            Error = true;
        }
        return Error;
}








