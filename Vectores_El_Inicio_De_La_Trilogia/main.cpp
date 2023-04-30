/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include <iostream>
#include<cstdlib>
#include "Opr_Vectores.h"
#include "Utileria.h"

#define LIMIT_MAX 100

using namespace std;

//****************************************************************************
/** \brief Captura la dimension en el rango [1,IMIT_MAX]
 *
 * \return La dimension
 */
int capturarDim();

//****************************************************************************
/** \brief Imprime el menú y captura la opción
 *
 * \return Imprime el menú y devuelve la opción del usuario
 */
int Menu();

//****************************************************************************
/** \brief Procesos para calcular la suma de dos vectores
 *
 */
void Gestion1();

//****************************************************************************
/** \brief Procesos para calcular la resta de dos vectores
 *
 */
void Gestion2();

//****************************************************************************
/** \brief Procesos para calcular el producto punto de dos vectores
 *
 */
void Gestion3();

//****************************************************************************
/** \brief Procesos para multiplicar un vector por un escalar
 *
 */
void Gestion4();

//****************************************************************************
/** \brief Procesos para calcular la norma de un vector
 *
 */
void Gestion5();


int main()
{
    int opcion;
    cout<<"Buenas, a continuaci\242n calcularemos operaciones con vectores";

    do
    {
        opcion=Menu();

        system("cls");
        switch(opcion)
        {
            case 1:
                Gestion1();
            break;

            case 2:
                Gestion2();
            break;

            case 3:
                Gestion3();
            break;

            case 4:
                Gestion4();
            break;

            case 5:
                Gestion5();
            break;

            case 0:
                cout<<"Vuelva Pronto, adi\242s :D";
            break;
        }

        cout<<'\n';
        system("Pause");
        system("cls");
    }while(opcion);

    return 0;
}

void Gestion1()
{
    //Suma de vectores

    int dim;
    float vector1[LIMIT_MAX],vector2[LIMIT_MAX],vectorAux[LIMIT_MAX];
    cout<<"Suma de vectores:\n";

    dim=capturarDim();
    cout<<"Elementos del primer vector: \n";
    CapturarVector(vector1,dim);
    cout<<"Elementos del segundo vector: \n";
    CapturarVector(vector2,dim);

    SumarVectores(vector1,vector2,vectorAux,dim);

    cout<<"A = ";
    ImprimirVector(vector1,dim);
    cout<<"\nB = ";
    ImprimirVector(vector2,dim);
    cout<<"\nA + B = ";
    ImprimirVector(vectorAux,dim);
}

void Gestion2()
{
    //Resta de vectores
    int dim;
    float vector1[LIMIT_MAX],vector2[LIMIT_MAX],vectorAux[LIMIT_MAX];
    cout<<"Resta de vectores:\n";

    dim=capturarDim();
    cout<<"Elementos del primer vector: \n";
    CapturarVector(vector1,dim);
    cout<<"Elementos del segundo vector: \n";
    CapturarVector(vector2,dim);

    RestaVectores(vector1,vector2,vectorAux,dim);

    cout<<"A = ";
    ImprimirVector(vector1,dim);
    cout<<"\nB = ";
    ImprimirVector(vector2,dim);
    cout<<"\nA - B = ";
    ImprimirVector(vectorAux,dim);

}

void Gestion3()
{
    //Producto Punto
    int dim;
    float vector1[LIMIT_MAX],vector2[LIMIT_MAX],resultado;
    cout<<"Producto punto:\n";

    dim=capturarDim();
    cout<<"Elementos del primer vector: \n";
    CapturarVector(vector1,dim);
    cout<<"Elementos del segundo vector: \n";
    CapturarVector(vector2,dim);

    resultado=ProductoPunto(vector1,vector2,dim);

    cout<<"A = ";
    ImprimirVector(vector1,dim);
    cout<<"\nB = ";
    ImprimirVector(vector2,dim);
    cout<<"\nA * B = "<<resultado;
}

void Gestion4()
{
    //Multiplicar por un escalar
    float vector1[LIMIT_MAX],vectorAux[LIMIT_MAX],escalar;
    int dim;
    cout<<"Multiplicaci\242n por escalar:\n";

    dim=capturarDim();
    cout<<"Vector a multiplicar: \n";
    CapturarVector(vector1,dim);
    cout<<"Escalar: \n";
    escalar=CapturaSegura("Escalar por el cual se multiplicara: ");

    ProductoVectorEscalar(vector1,vectorAux,escalar,dim);

    cout<<"\nA = ";
    ImprimirVector(vector1,dim);
    cout<<"\nkA = ";
    ImprimirVector(vectorAux,dim);

}

void Gestion5()
{
    //Magnitud
    float vector1[LIMIT_MAX],resultado;
    int dim;
    cout<<"Magnitud(norma) de un vector:\n";

    dim=capturarDim();
    cout<<"Vector a multiplicar: \n";
    CapturarVector(vector1,dim);

    resultado=NormaVector(vector1,dim);

    cout<<"\nA = ";
    ImprimirVector(vector1,dim);
    cout<<"\n||A|| = "<<resultado;

}
int Menu()
{
    int opcion;
    do
    {
        cout<<"Opciones\n";
        cout<<"Suma de dos vectores: 1\n";
        cout<<"Resta de dos vectores: 2\n";
        cout<<"Producto punto de dos vectores: 3\n";
        cout<<"Producto de un vector por un escalar: 4\n";
        cout<<"Norma (magnitud) de un vector: 5\n";
        opcion=CapturaSegura("Opcion: ");

        if(opcion < 0 || opcion > 5)
            cout<<"Esa opci\242n no es valida...";

    }while(opcion < 0 || opcion >5);

    return opcion;
}

int capturarDim()
{
    int dim;
    do{
        dim=CapturaSegura("Dimensi\242n del vector: ");
        if(dim<1 || dim > LIMIT_MAX)
            cout<<"El rango de la dimencion es de [1,100]";

    }while(dim<1 || dim > LIMIT_MAX);

    return dim;
}
