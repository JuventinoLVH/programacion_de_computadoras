/* Nombre: GestionConjuntos.tpp
   Autor: Luis Juventino Velasuez Hidalgo
   Fecha: 13/04/2020
   Descripción: Funciones de gestion para los conjuntos
*/

//*******************************************************************************************************************
template <typename Tipo>
void GestionUnion(Tipo tipoConjuntos)
{
    int tamA,tamB,tamRes;
    char peticion[50];
    Tipo A[DIM_MAX],B[DIM_MAX],res[DIM_MAX_UNION];
    std::cout<<"Uni\242n de un conjunto 'A' y un conjunto 'B' :\n";

    //Aquí se lee el conjunto A
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto A [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamA,peticion);
        if(tamA>DIM_MAX || tamA<0)
           std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamA>DIM_MAX || tamA<0);
    LeerConjuntoA(A,tamA,"Ingrese el elemento %d del conjunto A: ");

    //Aquí se lee el conjunto B
    std::cout<<'\n';
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto B [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamB,peticion);
        if(tamB>DIM_MAX || tamB<0)
            std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamB>DIM_MAX || tamB<0);
    LeerConjuntoA(B,tamB,"Ingrese el elemento %d del conjunto B: ");

    //Aquí se calcula la union y se imprime todo
    UnionAuB(A,tamA,B,tamB,res,tamRes);
    ImprimirConjuntoA(A,tamA,"\nA = ");
    ImprimirConjuntoA(B,tamB,"\nB = ");
    ImprimirConjuntoA(res,tamRes,"\nA U B = ");

    return;
}

//*******************************************************************************************************************
template <typename Tipo>
void GestionInterseccion(Tipo tipoConjuntos)
{
    int tamA,tamB,tamRes;
    char peticion[50];
    Tipo A[DIM_MAX],B[DIM_MAX],res[DIM_MAX];
    std::cout<<"Intersecci\242n de un conjunto 'A' y un conjunto 'B' :\n";

    //Aquí se lee el conjunto A
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto A [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamA,peticion);
        if(tamA>DIM_MAX || tamA<0)
           std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamA>DIM_MAX || tamA<0);
    LeerConjuntoA(A,tamA,"Ingrese el elemento %d del conjunto A: ");

    //Aquí se lee el conjunto B
    std::cout<<'\n';
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto B [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamB,peticion);
        if(tamB>DIM_MAX || tamB<0)
            std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamB>DIM_MAX || tamB<0);
    LeerConjuntoA(B,tamB,"Ingrese el elemento %d del conjunto B: ");

    //Aquí se calcula la intersección y se imprime todo
    OperacionesAyB(A,tamA,B,tamB,res,tamRes,Interseccion);
    ImprimirConjuntoA(A,tamA,"\nA = ");
    ImprimirConjuntoA(B,tamB,"\nB = ");
    ImprimirConjuntoA(res,tamRes,"\nA n B = ");

    return;
}

//*******************************************************************************************************************
template <typename Tipo>
void GestionDiferencia(Tipo tipoConjuntos)
{
    int tamA,tamB,tamRes;
    char peticion[50];
    Tipo A[DIM_MAX],B[DIM_MAX],res[DIM_MAX];
    std::cout<<"Diferencia de un conjunto 'A' y un conjunto 'B' :\n";

    //Aquí se lee el conjunto A
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto A [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamA,peticion);
        if(tamA>DIM_MAX || tamA<0)
           std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamA>DIM_MAX || tamA<0);
    LeerConjuntoA(A,tamA,"Ingrese el elemento %d del conjunto A: ");

    //Aquí se lee el conjunto B
    std::cout<<'\n';
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto B [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamB,peticion);
        if(tamB>DIM_MAX || tamB<0)
            std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamB>DIM_MAX || tamB<0);
    LeerConjuntoA(B,tamB,"Ingrese el elemento %d del conjunto B: ");

    //Aquí se calcula la diferencia y se imprime todo
    OperacionesAyB(A,tamA,B,tamB,res,tamRes,Diferencia);
    ImprimirConjuntoA(A,tamA,"\nA = ");
    ImprimirConjuntoA(B,tamB,"\nB = ");
    ImprimirConjuntoA(res,tamRes,"\nA - B = ");

    return;
}

//*******************************************************************************************************************
template <typename Tipo>
void GestionComplemento(Tipo tipoConjunto)
{
    int tamUn,tamA,tamRes;
    bool contencionUcA;
    char peticion[50];
    Tipo Universo[DIM_MAX],A[DIM_MAX],res[DIM_MAX];
    std::cout<<"Complemento de un universo y un conjunto 'A' :\n";

    //Aquí se lee el Universo
    sprintf(peticion,"Ingrese la dimensi\242n del universo [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamUn,peticion);
        if(tamUn>DIM_MAX || tamUn<0)
           std::cout<<"El rango del universo es [0,"<<DIM_MAX<<"]...";

    }while(tamUn>DIM_MAX || tamUn<0);
    LeerConjuntoA(Universo,tamUn,"Ingrese el elemento %d del universo: ");

    //Aquí se lee el conjunto A
    std::cout<<'\n';
    do
    {
        sprintf(peticion,"Ingrese la dimensi\242n del conjunto A [0,%d] : ",DIM_MAX);
        do
        {
            CapturaSegura(tamA,peticion);
            if(tamA>DIM_MAX || tamA<0)
                std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

        }while(tamA>DIM_MAX || tamA<0);
        LeerConjuntoA(A,tamA,"Ingrese el elemento %d del conjunto A: ");

        //Se verifica que A sea parte del universo
        contencionUcA=ContencionAcB(Universo,tamUn,A,tamA);
        if(!contencionUcA)
            std::cout<<"El conjunto A no es parte del universo....\n";

    }while(!contencionUcA);

    //El complemento es la diferencia del universo con el conjunto A
    OperacionesAyB(Universo,tamUn,A,tamA,res,tamRes,Diferencia);
    ImprimirConjuntoA(Universo,tamUn,"Universo: ");
    ImprimirConjuntoA(A,tamA,"\nA = ");
    ImprimirConjuntoA(res,tamRes,"\nAc = ");

    return;
}

//*******************************************************************************************************************
template <typename Tipo>
void GestionPertenencia(Tipo tipoConjunto)
{
    int tamA;
    char peticion[50];
    Tipo A[DIM_MAX],X;
    std::cout<<"Pertenencia de un elemento 'x' en un conjunto 'A' :\n";

    //Aquí se lee el conjunto A
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto A [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamA,peticion);
        if(tamA>DIM_MAX || tamA<0)
           std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamA>DIM_MAX || tamA<0);
    LeerConjuntoA(A,tamA,"Ingrese el elemento %d del conjunto A: ");

    //Aquí se lee el elemento X
    CapturaSegura(X,"Elemento a buscar: ");

    //Se imprime el resultado
    if(PertenenciaXeA(A,tamA,X))
        std::cout<<"El elemento "<<X<<" SI est\240 en el conjunto";
    else
        std::cout<<"Sorry, el elemento "<<X<<" NO existe en el conjunto :'(";

    return;
}

//*******************************************************************************************************************
template <typename Tipo>
void GestionContencion(Tipo tipoConjuntos)
{
    int tamA,tamB;
    char peticion[50];
    bool respuesta;
    Tipo A[DIM_MAX],B[DIM_MAX];
    std::cout<<"Contencion de un conjunto 'B' en otro conjunto 'A' :\n";

    //Aquí se lee el conjunto A
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto A [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamA,peticion);
        if(tamA>DIM_MAX || tamA<0)
           std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamA>DIM_MAX || tamA<0);
    LeerConjuntoA(A,tamA,"Ingrese el elemento %d del conjunto A: ");

    //Aquí se lee el conjunto B
    std::cout<<'\n';
    sprintf(peticion,"Ingrese la dimensi\242n del conjunto B [0,%d] : ",DIM_MAX);
    do
    {
        CapturaSegura(tamB,peticion);
        if(tamB>DIM_MAX || tamB<0)
            std::cout<<"El rango de la dimensi\242n es [0,"<<DIM_MAX<<"]...";

    }while(tamB>DIM_MAX || tamB<0);
    LeerConjuntoA(B,tamB,"Ingrese el elemento %d del conjunto B: ");

    //Aquí se calcula la respuesta
    respuesta=ContencionAcB(A,tamA,B,tamB);

    //Se imprime el resultado
    if(respuesta)
        std::cout<<"En efecto, A contiene a B";
    else
        std::cout<<"Te mintieron, B no est\240 esn A";

    return;
}
