/* Nombre: Gestion.cpp
   Autor: Luis J. Velasquez Hidalgo
   Fecha: 19/04/20
   Descripción: Funciones para la gestion de operaciones con polinomios
*/

#include "Gestion.h"

//**********************************************************************************************
void GestionSuma()
{
    int gradoP,gradoF,gradoRes;
    double *P=NULL,*F=NULL,*res=NULL;
    std::cout<<"Suma de dos polinomios:\n\n";

    try
    {
        do
        {
            gradoP=CapturaSegura("Grado del primer polinomio (P): ");
            if(gradoP<0)
                std::cout<<"No existe un polinomio de grado negativo....\n";

        }while(gradoP<0);
        CapturarP(P,gradoP,"Coeficiente del termino grado %d del polinomio P: ");

        std::cout<<'\n';
        do
        {
            gradoF=CapturaSegura("Grado del segundo polinomio (F): ");
            if(gradoF<0)
                std::cout<<"No existe un polinomio de grado negativo...\n";

        }while(gradoF<0);
        CapturarP(F,gradoF,"Coeficiente del termino grado %d del polinomio F: ");

        SumaDosPolinomios(P,gradoP,F,gradoF,res,gradoRes);

        ImprimirP(P,gradoP,"\nP = ");
        ImprimirP(F,gradoF,"\nF = ");
        ImprimirP(res,gradoRes,"\nP + F = ");

    }
    catch(std::bad_alloc)
    {
        std::cout<<"Ocurrio un error, el programa se apagar\240...";
    }
    BorrarArregloD(res);
    BorrarArregloD(P);
    BorrarArregloD(F);
    return;
}

//**********************************************************************************************
void GestionResta()
{
    int gradoP,gradoF,gradoRes;
    double *P=NULL,*F=NULL,*res=NULL;
    std::cout<<"Resta de dos polinomios:\n\n";

    try
    {
        do
        {
            gradoP=CapturaSegura("Grado del primer polinomio (P): ");
            if(gradoP<0)
                std::cout<<"No existe un polinomio de grado negativo....\n";

        }while(gradoP<0);
        CapturarP(P,gradoP,"Coeficiente del termino grado %d del polinomio P: ");

        std::cout<<'\n';
        do
        {
            gradoF=CapturaSegura("Grado del segundo polinomio (F): ");
            if(gradoF<0)
                std::cout<<"No existe un polinomio de grado negativo...\n";

        }while(gradoF<0);
        CapturarP(F,gradoF,"Coeficiente del termino grado %d del polinomio F: ");

        RestaDosPolinomios(P,gradoP,F,gradoF,res,gradoRes);

        ImprimirP(P,gradoP,"\nP = ");
        ImprimirP(F,gradoF,"\nF = ");
        ImprimirP(res,gradoRes,"\nP - F = ");

    }
    catch(std::bad_alloc)
    {
        std::cout<<"Ocurrio un error, el programa se apagar\240...";
    }
    BorrarArregloD(res);
    BorrarArregloD(P);
    BorrarArregloD(F);
    return;
}

//**********************************************************************************************
void GestionMultiplicacion()
{
    int gradoP,gradoF,gradoRes;
    double *P=NULL,*F=NULL,*res=NULL;
    std::cout<<"Multiplicaci\242n de dos polinomios:\n\n";

    try
    {
        do
        {
            gradoP=CapturaSegura("Grado del primer polinomio (P): ");
            if(gradoP<0)
                std::cout<<"No existe un polinomio de grado negativo....\n";

        }while(gradoP<0);
        CapturarP(P,gradoP,"Coeficiente del termino grado %d del polinomio P: ");

        std::cout<<'\n';
        do
        {
            gradoF=CapturaSegura("Grado del segundo polinomio (F): ");
            if(gradoF<0)
                std::cout<<"No existe un polinomio de grado negativo...\n";

        }while(gradoF<0);
        CapturarP(F,gradoF,"Coeficiente del termino grado %d del polinomio F: ");

        MultiplicarDosPolinomios(P,gradoP,F,gradoF,res,gradoRes);

        ImprimirP(P,gradoP,"\nP = ");
        ImprimirP(F,gradoF,"\nF = ");
        ImprimirP(res,gradoRes,"\nP * F = ");

    }
    catch(std::bad_alloc)
    {
        std::cout<<"Ocurrio un error, el programa se apagar\240...";
    }
    BorrarArregloD(res);
    BorrarArregloD(P);
    BorrarArregloD(F);
    return;
}

//**********************************************************************************************
void GestionDividir()
{
    int gradoP,gradoF,gradoRes,gradoCos;
    double *P=NULL,*F=NULL,*cos=NULL,*res=NULL;
    std::cout<<"Divisi\242n de dos polinomios:\n\n";

    try
    {
        do
        {
            gradoP=CapturaSegura("Grado del primer polinomio (P): ");
            if(gradoP<0)
                std::cout<<"No existe un polinomio de grado negativo....\n";

        }while(gradoP<0);
        CapturarP(P,gradoP,"Coeficiente del termino grado %d del polinomio P: ");

        std::cout<<'\n';
        do
        {
            gradoF=CapturaSegura("Grado del segundo polinomio (F): ");
            if(gradoF<0)
                std::cout<<"No existe un polinomio de grado negativo...\n";

        }while(gradoF<0);
        CapturarP(F,gradoF,"Coeficiente del termino grado %d del polinomio F: ");

        DividirDosPolinomios(P,gradoP,F,gradoF,cos,gradoCos,res,gradoRes);

        ImprimirP(P,gradoP,"\nP = ");
        ImprimirP(F,gradoF,"\nF = ");
        ImprimirP(cos,gradoCos,"\nP / F = ");
        ImprimirP(res,gradoRes,"\nP % F = ");

    }
    catch(std::bad_alloc)
    {
        std::cout<<"Ocurrio un error, el programa se apagar\240...";
    }
    catch(int)
    {
        std::cout<<"No se puede dividir entre 0...\n";
    }
    BorrarArregloD(res);
    BorrarArregloD(P);
    BorrarArregloD(F);
    return;
}

//**********************************************************************************************
void GestionDerivar()
{
    int gradoP,gradoRes;
    double *P=NULL,*res=NULL;
    std::cout<<"Derivar un polinomio:\n";

    try
    {
        do
        {
            gradoP=CapturaSegura("Grado del polinomio a derivar (P): ");
            if(gradoP<0)
                std::cout<<"No existe un polinomio de grado negativo....\n";

        }while(gradoP<0);
        CapturarP(P,gradoP,"Coeficiente del termino grado %d del polinomio P: ");


        DerivarP(P,gradoP,res,gradoRes);

        ImprimirP(P,gradoP,"\nP = ");
        ImprimirP(res,gradoRes,"\nP' = ");

    }
    catch(std::bad_alloc)
    {
        std::cout<<"Ocurrio un error, el programa se apagar\240...";
    }
    BorrarArregloD(res);
    BorrarArregloD(P);
    return;
}
//**********************************************************************************************
void GestionEvaluar()
{
    int gradoP;
    char opcion;
    double *P=NULL,X;
    std::cout<<"Derivar un polinomio:\n";

    try
    {
        do
        {
            gradoP=CapturaSegura("Grado del polinomio a evaluar [P(x) ]: ");
            if(gradoP<0)
                std::cout<<"No existe un polinomio de grado negativo....\n";

        }while(gradoP<0);
        CapturarP(P,gradoP,"Coeficiente del termino grado %d del polinomio P: ");


        do
        {
            X=CapturaSegura("Valor con el que se evaluar\240 la funcion: ");

            ImprimirP(P,gradoP,"\nP = ");
            std::cout<<"\nP("<<X<<") = "<<EvaluarP(P,gradoP,X);

            do
            {
                std::cout<<"\n\250Quieres seguir evaluando el mismo polinomio(Y/N)? : ";
                std::cin>>opcion;
                if(opcion!='Y' && opcion!='N')
                    std::cout<<"Opci\202n no valida(Y/N)...\n";

            }while(opcion!='Y' && opcion!='N');

        }while(opcion!='N');
    }
    catch(std::bad_alloc)
    {
        std::cout<<"Ocurrio un error, el programa se apagar\240...";
    }
    BorrarArregloD(P);
    return;
}
