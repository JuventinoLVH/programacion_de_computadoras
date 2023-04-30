/* Nombre: Conjuntos.tpp
   Autor: Luis Juventino Velassquez Hidalgo
   Fecha: 11/04/20
   Descripción: Archivo para las operaciones con conjuntos
*/

#include "Conjuntos.h"

//*******************************************************************************************************************
template <typename Tipo>
void ImprimirConjuntoA(const Tipo A[] ,const int tamA ,const char mensaje[])
{
    std::cout<<mensaje<<'{';

    for(int i=0;i<tamA;i++)
        std::cout<<A[i]<<" ,";

    if(tamA) std::cout<<"\b\b";

    std::cout<<"} ";
    return;
}

//*******************************************************************************************************************
template <typename Tipo>
void LeerConjuntoA(Tipo A[] ,const int tamA ,const char mensaje[])
{
    for(int i=0;i<tamA;)
    {
        char solicitud[100];
        sprintf(solicitud,mensaje,i+1);
        CapturaSegura(A[i],solicitud);

        if(PertenenciaXeA(A,i,A[i]))
            std::cout<<"No se permiten elementos repetidos....\n";
        else i++;
    }
    return;
}

//*******************************************************************************************************************
template <typename Tipo>
bool PertenenciaXeA(const Tipo A[] ,const int tamA ,Tipo X )
{
    for(int i=0;i<tamA;i++)
    {
        if(A[i]==X) return true;
    }
    return false;
}

//*******************************************************************************************************************
template <typename Tipo>
bool ContencionAcB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB )
{

    if(tamB>tamA) return false;

    for(int i=0;i<tamB;i++)
    {
        if(!PertenenciaXeA(A,tamA,B[i])) return false;
    }
    return true;
}

//*******************************************************************************************************************
template <typename Tipo>
void OperacionesAyB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB ,Tipo Res[] ,
                        int &tamRes, bool (*PtroCriterio)(const Tipo[],const int,const Tipo) )
{
    tamRes=0;

    for(int i=0;i<tamA;i++)
    {
        //Sí el elemento i pasa el criterio, lo metemos en el arreglo resultado y aumentamos su tamaño
        if(PtroCriterio(B,tamB,A[i]))
        {
            Res[tamRes]=A[i];
            tamRes++;
        }
    }
    return;
}

//*******************************************************************************************************************
template <typename Tipo>
void UnionAuB(const Tipo A[] ,const int tamA ,const Tipo B[] ,const int tamB ,Tipo Res[] ,int &tamRes)
{
    //Igualamos el arreglo resultado a A(pues la unión de A y B son los elementos de A más los elementos de B)
    tamRes=tamA;
    for(int i=0;i<tamA;i++)
        Res[i]=A[i];

    for(int i=0;i<tamB;i++)
    {
        if(!PertenenciaXeA(A,tamA,B[i]))
        {
            Res[tamRes]=B[i];
            tamRes++;
        }
    }
}

//*******************************************************************************************************************
template <typename Tipo>
bool Interseccion(const Tipo A[] ,const int tamA ,const Tipo B )
{
    //La intersecciín son los elementos que esten en ambos conjuntos
    if(PertenenciaXeA(A,tamA,B)) return true;
    else return false;
}

//*******************************************************************************************************************
template <typename Tipo>
bool Diferencia(const Tipo A[] ,const int tamA ,const Tipo B )
{
    //La diferencia son los elementos de A que no esten en B
    if(!PertenenciaXeA(A,tamA,B)) return true;
    else return false;
}

//*******************************************************************************************************************
