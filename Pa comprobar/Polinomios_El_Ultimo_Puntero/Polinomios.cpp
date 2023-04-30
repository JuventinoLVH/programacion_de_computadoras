/* Nombre: Polinomios.h
   Autor: Luis J. Velasquez Hidalgo
   Fecha: 19/04/20
   Descripción: funciones con polinomios
*/

#include"Polinomios.h"

//******************************************************************************************************************************
void SumaDosPolinomios(const double P[] ,const int gradoP ,const double F[] ,const int gradoF ,double *&res ,int &gradoRes)
{
    int separacion=abs(gradoF-gradoP);
    int gradoMayor = gradoP>gradoF ? gradoP : gradoF;
    const double *PolMayor = gradoP>gradoF ? P : F;
    const double *PolMenor = gradoP<gradoF ? P : F;

    try
    {
        gradoRes=gradoMayor;
        res=CrearArregloD(gradoRes+1);

        for(int i=0;i<separacion;i++)
            res[i]=PolMayor[i];


        for(int i=separacion;i<=gradoMayor;i++)
            res[i]=PolMayor[i]+PolMenor[i-separacion];

    }
    catch(std::bad_alloc &bad)
    {
        std::cout<<"No hay espacio en la memoria para el polinomio resultante...\n";
        throw bad;
    }
}

//******************************************************************************************************************************
void RestaDosPolinomios(const double P[] ,const int gradoP ,const double F[] ,const int gradoF ,double *&res ,int &gradoRes)
{
    int separacion=abs(gradoF-gradoP) ,gradosMenos=0;
    int gradoMayor = gradoP>gradoF ? gradoP : gradoF;

    for(int i=0; !separacion && !(P[i]-F[i]) && i<gradoP;i++)
        gradosMenos++;

    try
    {
        gradoRes=gradoMayor-gradosMenos;
        res=CrearArregloD(gradoRes+1);

        for(int i=0;i<separacion;i++)
        {
            if(gradoP>gradoF)
                res[i]=P[i];
            else
                res[i]=-F[i];
        }

        for(int i=separacion+gradosMenos;i<=gradoMayor;i++)
        {
            if(gradoP>gradoF)
                res[i-gradosMenos]=P[i]-F[i-separacion];
            else
                res[i-gradosMenos]=P[i-separacion]-F[i];
        }

    }
    catch(std::bad_alloc &bad)
    {
        std::cout<<"No hay espacio en la memoria para el polinomio resultante...\n";
        throw bad;
    }
}

//******************************************************************************************************************************
void MultiplicarDosPolinomios(const double P[] ,const int gradoP ,const double F[] ,const int gradoF ,double *&res ,int &gradoRes)
{
    gradoRes=gradoP+gradoF;

    try
    {

        if((!gradoF && !F[0]) || (!gradoP && !P[0]))
        {
            res=CrearArregloD(1);
            res[0]=0;
            gradoRes=0;
            return;
        }

        res=CrearArregloD(gradoRes+1);
        for(int i=0;i<=gradoRes;i++)
            res[i]=0;


        for(int i=0;i<=gradoP;i++)
        {
            for(int j=0;j<=gradoF;j++)
            {
                res[i+j]+=(P[i]*F[j]);
            }
        }
    }
    catch(std::bad_alloc &bad)
    {
        std::cout<<"No hay espacio en la memoria para el polinomio resultante...";
        throw bad;
    }
    return;
}

//******************************************************************************************************************************
void DividirDosPolinomios(const double P[] ,const int gradoP ,const double F[] ,const int gradoF ,
                            double *&cos ,int &gradoCos ,double *&res ,int &gradoRes )
{
    gradoCos= gradoP-gradoF;
    int gradoAux;
    double *aux=NULL;

    try
    {
        if((!gradoF && !F[0]))
            throw -1;

        if(gradoCos<0)
        {
            cos=CrearArregloD(1);
            cos[0]=0;
            SumaDosPolinomios(P,gradoP,cos,0,res,gradoRes);
            return;
        }

        double vacio[1]={0};
        SumaDosPolinomios(P,gradoP,vacio,0,aux,gradoAux);
        cos=CrearArregloD(gradoCos+1);

        for(int i=0;i<=gradoCos;i++)
        {
            cos[i]=aux[i]/F[0];
            for(int j=0;j<=gradoF && cos[i] ;j++)
            {
                aux[i+j]-=cos[i]*F[j];
            }
        }

        int gradoMultAux;
        double *multAux=NULL;
        MultiplicarDosPolinomios(F,gradoF,cos,gradoCos,multAux,gradoMultAux);
        RestaDosPolinomios(P,gradoP,multAux,gradoMultAux,res,gradoRes);

        BorrarArregloD(multAux);

    }
    catch(std::bad_alloc &ba)
    {
        std::cout<<"No hay espacio en la memoria para el polinomio resultante...";
        throw ba;
    }
    catch(int error)
    {
        std::cout<<"Se intent\242 dividir entre 0...\n";
        throw error;
    }

    BorrarArregloD(aux);

    return;
}

//******************************************************************************************************************************
void DerivarP(const double P[] ,const int gradoP ,double *&res ,int &gradoRes)
{
    try
    {
        gradoRes= gradoP == 0 ? 0 : gradoP-1;
        res=CrearArregloD(gradoRes+1);

        //Do while porque siempre se va a efectuar al menos una vuelta (para que funcione con el polinomio grado 0)
        int i=0;
        do
        {
            res[i]=P[i]*(gradoP-i);
            i++;
        }while(i<gradoP);
    }
    catch(std::bad_alloc &bad)
    {
        std::cout<<"No hay espacio en la memoria para el polinomio resultante...";
        throw bad;
    }
}

//**********************************************************************************************
double EvaluarP(const double P[] ,const int gradoP ,float x)
{
    double res= gradoP > 0 ? P[0]*x : 0;
    for(int i=1;i<gradoP;i++)
    {
        res= x*( res +P[i]);
    }
    res+=P[gradoP];

    return res;
}

//******************************************************************************************************************************
void ImprimirP(const double P[] ,const int gradoP ,const char mensaje[])
{
    std::cout<<mensaje;

    //se imprime el primer elemento por separado porque el primer elemento no lleva símbolo a menos de que sea negativo
    if(P[0]<0) std::cout<<"-";

    if(!gradoP || AbsD(P[0] )!=1) std::cout<<AbsD(P[0]);

    //Puede ser que el primer elemento sea de grado 0
    if(gradoP) std::cout<<'x';

    //puede ser que el primer elemento sea de grado 1
    if(gradoP>1)std::cout<<'^'<<gradoP;


    //Los elementos intermedios se imprimen todos de la misma manera
    for(int i=1;i<gradoP-1;i++)
    {
        if(P[i])
        {
            std::cout<<" ";
            SignoN(P[i]);
            std::cout<<" ";
            if(AbsD(P[i] )!=1) std::cout<<AbsD(P[i]);
            std::cout<<"x^"<<gradoP-i;
        }
    }

    //se imprime el penultimo elemento por separado porque este no lleva el exponente(Sí es el primer elemento entonces ya se imprimió)
    if(gradoP>1 && P[gradoP-1])
    {
        std::cout<<" ";
        SignoN(P[gradoP-1]);
        std::cout<<" ";
        if(AbsD(P[gradoP-1] )!=1) std::cout<<AbsD(P[gradoP-1]);
        std::cout<<"x";
    }

    //se imprime el ultimo elemento por separado porque este no lleva 'x'(Sí es el primer elemento entonces ya se imprimió)
    if(gradoP>0 && P[gradoP])
    {
        std::cout<<" ";
        SignoN(P[gradoP]);
        std::cout<<" "<<AbsD(P[gradoP]);
    }
}

//******************************************************************************************************************************
void CapturarP(double *&P ,const int gradoP ,const char mensaje[])
{
    try
    {
        char solicitud[50];
        P=CrearArregloD(gradoP+1);

        if(gradoP>0)
        {
            do
            {
                sprintf(solicitud , mensaje ,gradoP);
                P[0]=CapturaSegura(solicitud);
                if(!P[0])
                    std::cout<<"El primer elemento no puede ser 0...(chistosito)\n";

            }while(!P[0]);
        }

        for(int i=1;i<gradoP;i++)
        {
            sprintf(solicitud , mensaje ,gradoP-i);
            P[i]=CapturaSegura(solicitud);
        }

        P[gradoP]=CapturaSegura("Coeficiente del t\202rmino independiente: ");
    }
    catch(std::bad_alloc &bad)
    {
        std::cout<<"Error al intentar declarar un arreglo...\n";
        throw bad;
    }
    return;
}

