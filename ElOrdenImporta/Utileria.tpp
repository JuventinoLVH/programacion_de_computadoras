/*
 Nombre: Utileria.tpp
 Autor: Luis Juventino Velasquez Hidalgo
 Fecha: 3/19/2020
 Descripción: Funciones necesarias para ordenar valores
*/

//*************************************************************************************************************
template<typename Tipo1>
void OrdenarTres(Tipo1 &val1 ,Tipo1 &val2 ,Tipo1 &val3 ,bool (*Criterio)(Tipo1,Tipo1))
{
    if(Criterio(val1,val2)) Intercambiar(val1,val2);
    if(Criterio(val2,val3)) Intercambiar(val2,val3);
    if(Criterio(val1,val2)) Intercambiar(val1,val2);
    return;
}

//*************************************************************************************************************
template<typename Tipo1>
inline void Intercambiar(Tipo1 &a ,Tipo1 &b)
{
    Tipo1 aux=a;
    a=b;
    b=aux;
}

//*************************************************************************************************************
template<typename Tipo1>
bool Ascendente(Tipo1 a ,Tipo1 b)
{
    if(a<b) return false;
    else return true;
}

//*************************************************************************************************************
template<typename Tipo1>
bool Descendente(Tipo1 a ,Tipo1 b)
{
    if(a<b) return true;
    else return false;
}
