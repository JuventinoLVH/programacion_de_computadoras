/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include "OperacionesConMatrices.h"

//*************************************************************************************************************************
/** \brief Función que calcula los digitos
 *
 * \param num un numero
 *
 * \return la cantidad de digitos del numero
 */
int tamanoNumero(double num);

//*************************************************************************************************************************
/** \brief Función que intercambia 2 renglones de una funcion
 *
 * \param double la matriz
 * \param renglon1 el numero del renglon a intercambiar
 * \param renglon2 el segundo renglon a intercambiar
 * \param m el numero de columnas de la matriz
 *
 */
void IntercambiarReng(double ** matriz ,int renglon1 ,int renglon2 ,int m);

//*************************************************************************************************************************
/** \brief Función que multiplica un renglon por un escalar
 *
 * \param double la matriz
 * \param renglon1 el numero del renglon a multiplicar
 * \param k el escalar
 * \param m el numero de columnas de la matriz
 *
 */
void MultiplicarRenglon(double ** matriz ,int renglon1 ,double k ,int m);

//*************************************************************************************************************************
/** \brief Función que le suma a un renglon, otro renglon multiplicado por un escalar
 *
 * \param matriz la matriz
 * \param renglonSuma renglon a modificar
 * \param renglonMultiplo renglon que va a ser multiplicado
 * \param k el escalar por el cual se va a multiplicar renglonMultiplo
 * \param m numero de columnas de la matriz
 *
 */
void SumarMultiplosRenglones(double ** matriz ,int renglonSuma ,int renglonMultiplo ,double k ,int m);

//*************************************************************************************************************************
/** \brief Función calcula el valor absoluto de un numero
 *
 * \param n un numero
 *
 * \return el valor absoluto de n
 *
 */
double absoluto(double n);

//*************************************************************************************************************************
void EscribirMatrizEnArchivo(const char *cadena ,double * const * matriz ,int n ,int m)
{
    char extencion[100];
    sprintf(extencion,"Matrices\\%s.txt",cadena);
    std::ofstream archivo(extencion);

    archivo<<n<<' '<<m<<'\n';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            archivo<<matriz[i][j]<<' ';
        }
        archivo<<'\n';
    }

    archivo.close();
    return;
}

//*************************************************************************************************************************
void CapturarMatriz(double **matriz ,int n ,int m)
{
    char solicitud[100];
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {

            sprintf(solicitud,"Elemento [%d][%d] de la matriz: ",i+1,j+1);
            matriz[i][j]=CapturaSegura(solicitud);
        }
    }
}

//*************************************************************************************************************************
bool CapturarMatrizDeUnArchivo(const char *cadena ,double **&matriz ,int &n ,int &m)
{
    char extencion[100];
    sprintf(extencion,"Matrices\\%s.txt",cadena);

    std::ifstream archivo(extencion);
    if(!archivo)
    {
        std::cout<<"Archivo no encontrado...\n";
        archivo.close();
        return false;
    }

    archivo>>n>>m;
    matriz=CrearMatriz(n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            archivo>>matriz[i][j];
        }
    }

    archivo.close();
    return true;
}

//*************************************************************************************************************************
void ImprimirMatriz(double * const * matriz ,int n, int m ,const char *nombre)
{
    std::cout<<nombre<<'\n';
    std::cout<<(char)ESI;
    std::cout<<" ";
    for(int i=1,fin=(m-1)*SEPARACION;i<fin;i++)
        std::cout<<" ";
    std::cout<<(char)ESD<<'\n';


    for(int i=0;i<n;i++)
    {
        std::cout<<(char)BV;
        std::cout <<matriz[i][0];
        if(m>1)
            std::cout << std::setw(SEPARACION-tamanoNumero(matriz[i][0])-1)<<matriz[i][1];

        for(int j=2;j<m;j++)
        {
            std::cout << std::setw(SEPARACION) <<matriz[i][j];
        }
        std::cout<<(char)BV<<'\n';
    }

    std::cout<<(char)EII;
    std::cout<<" ";
    for(int i=1,fin=(m-1)*SEPARACION;i<fin;i++)
        std::cout<<" ";
    std::cout<<(char)EID<<'\n';
}

//*************************************************************************************************************************
int tamanoNumero(double num)
{
    int r=0,dec=0,numtrunc;
    double aux=num;

    if(aux<0)
        r++;

    while(aux>=10||aux<=-10)
    {
        r++;
        aux/=10;
    }

    do
    {
        numtrunc=num;
        num*=10;
        numtrunc*=10;
        if(numtrunc!=num)
        {
            dec++;
        }
    }
    while(numtrunc!=num && dec<4);
    if(dec)
    {
        r+=dec+1;
    }
    return r;
}

//*************************************************************************************************************************
bool SumaMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes ,int &rn ,int &rm)
{
    if(n1!=n2 || m1!=m2)
    {
        std::cout<<"Para sumar dos matrices se necesita que ambas tengan las mismas dimenciones...\n";
        return false;
    }
    rn=n1;
    rm=m1;
    matrizRes=CrearMatriz(rn,rm);
    for(int i=0;i<rn;i++)
        for(int j=0;j<rm;j++)
            matrizRes[i][j]=matriz1[i][j]+matriz2[i][j];

    return true;
}

//*************************************************************************************************************************
bool SumaMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes)
{
    if(n1!=n2 || m1!=m2)
    {
        std::cout<<"Para sumar dos matrices se necesita que ambas tengan las mismas dimenciones...\n";
        return false;
    }
    matrizRes=CrearMatriz(n1,m1);
    for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            matrizRes[i][j]=matriz1[i][j]+matriz2[i][j];

    return true;
}

//*************************************************************************************************************************
bool RestarMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes ,int &rn ,int &rm)
{
    if(n1!=n2 || m1!=m2)
    {
        std::cout<<"Para sumar dos matrices se necesita que ambas tengan las mismas dimenciones...\n";
        return false;
    }
    rn=n1;
    rm=m1;
    matrizRes=CrearMatriz(rn,rm);
    for(int i=0;i<rn;i++)
        for(int j=0;j<rm;j++)
            matrizRes[i][j]=matriz1[i][j]-matriz2[i][j];

    return true;
}

//*************************************************************************************************************************
bool RestarMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes)
{
    if(n1!=n2 || m1!=m2)
    {
        std::cout<<"Para sumar dos matrices se necesita que ambas tengan las mismas dimenciones...\n";
        return false;
    }
    matrizRes=CrearMatriz(n1,m1);
    for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            matrizRes[i][j]=matriz1[i][j]-matriz2[i][j];

    return true;
}

//*************************************************************************************************************************
void MultiplicarPorEscalar(double * const *  matriz1 ,int n1 ,int m1 ,double k ,double **&matrizRes ,int &rn ,int &rm)
{
    rn=n1;
    rm=m1;
    matrizRes=CrearMatriz(n1,m1);
    for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            matrizRes[i][j]=matriz1[i][j]*k;
}

//*************************************************************************************************************************
void MultiplicarPorEscalar(double * const * matriz1 ,int n1 ,int m1 ,double k ,double **&matrizRes)
{
    matrizRes=CrearMatriz(n1,m1);
    for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            matrizRes[i][j]=matriz1[i][j]*k;
}

//*************************************************************************************************************************
bool MultiplicarMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes ,int &rn ,int &rm)
{
    if(m1!=n2)
    {
        std::cout<<"Las columnas de la primera matriz deben de ser iguales a los renglones de la segunda matriz...\n";
        return false;
    }
    rn=n1;
    rm=m2;
    matrizRes=CrearMatriz(n1,m2);
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m2;j++)
        {
            matrizRes[i][j]=0;
            for(int k=0;k<n2;k++)
            {
                matrizRes[i][j]+=matriz1[i][k]*matriz2[k][j];
            }
        }
    }
    return true;
}

//*************************************************************************************************************************
bool MultiplicarMat(double * const * matriz1 ,int n1 ,int m1 ,double * const * matriz2 ,int n2 ,int m2 ,double **&matrizRes)
{
    if(m1!=n2)
    {
        std::cout<<"Las columnas de la primera matriz deben de ser iguales a los renglones de la segunda matriz...\n";
        return false;
    }
    matrizRes=CrearMatriz(n1,m2);
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m2;j++)
        {
            matrizRes[i][j]=0;
            for(int k=0;k<n2;k++)
            {
                matrizRes[i][j]+=matriz1[i][k]*matriz2[k][j];
            }
        }
    }
    return true;
}

//*************************************************************************************************************************
void Transpuesta(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes ,int &rn ,int &rm)
{
    rn=n1;
    rm=m1;
    matrizRes=CrearMatriz(n1,m1);
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
        {
            matrizRes[i][j]=matriz1[j][i];
        }
    }
    return;
}

//*************************************************************************************************************************
void Transpuesta(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes)
{
    matrizRes=CrearMatriz(n1,m1);
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
        {
            matrizRes[i][j]=matriz1[j][i];
        }
    }
    return;
}

//*************************************************************************************************************************
bool Inversa(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes ,int &rn ,int &rm)
{
    if(n1!=m1)
    {
        std::cout<<"No existe la matriz inversa...\n";
        return false;
    }

    double tol=1.0E-10;
    double ** matrizAuxiliar=CrearMatriz(n1,m1*2);

    for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            matrizAuxiliar[i][j]=matriz1[i][j];

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
            matrizAuxiliar[i][j+m1]=0;
        matrizAuxiliar[i][i+m1]=1;
    }

    bool esInvertible;
    for(int i=0;i<n1;i++)
    {
        if(absoluto(matrizAuxiliar[i][i])<tol)
        {
            esInvertible=false;
            for(int j=i+1;j<n1;j++)
            {
                if(absoluto(matrizAuxiliar[j][i])>tol)
                {
                    esInvertible=true;
                    IntercambiarReng(matrizAuxiliar,i,j,n1*2);
                    break;
                }
            }
            if(!esInvertible)
            {
                std::cout<<"No existe la matriz inversa...\n";
                BorraraMatriz(matrizAuxiliar,n1);
                return false;
            }
        }

        MultiplicarRenglon(matrizAuxiliar,i,1/matrizAuxiliar[i][i],2*n1);

        for(int j=0;j<i;j++)
            SumarMultiplosRenglones(matrizAuxiliar,j,i,-matrizAuxiliar[j][i],n1*2);
        for(int j=i+1;j<n1;j++)
            SumarMultiplosRenglones(matrizAuxiliar,j,i,-matrizAuxiliar[j][i],n1*2);
    }


    rn=n1;
    rm=m1;
    matrizRes=CrearMatriz(n1,m1);
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
            matrizRes[i][j]= matrizAuxiliar[i][j+m1];
    }

    BorraraMatriz(matrizAuxiliar,n1);
    return true;
}


//*************************************************************************************************************************
bool Inversa(double * const *  matriz1 ,int n1 ,int m1 ,double **&matrizRes)
{
    if(n1!=m1)
    {
        std::cout<<"No existe la matriz inversa...\n";
        return false;
    }

    double tol=1.0E-10;
    double ** matrizAuxiliar=CrearMatriz(n1,m1*2);

    for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            matrizAuxiliar[i][j]=matriz1[i][j];

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
            matrizAuxiliar[i][j+m1]=0;
        matrizAuxiliar[i][i+m1]=1;
    }

    bool esInvertible;
    for(int i=0;i<n1;i++)
    {
        if(absoluto(matrizAuxiliar[i][i])<tol)
        {
            esInvertible=false;
            for(int j=i+1;j<n1;j++)
            {
                if(absoluto(matrizAuxiliar[j][i])>tol)
                {
                    esInvertible=true;
                    IntercambiarReng(matrizAuxiliar,i,j,n1*2);
                    break;
                }
            }
            if(!esInvertible)
            {
                std::cout<<"No existe la matriz inversa...\n";
                BorraraMatriz(matrizAuxiliar,n1);
                return false;
            }
        }
        MultiplicarRenglon(matrizAuxiliar,i,1/matrizAuxiliar[i][i],2*n1);

        for(int j=0;j<i;j++)
            SumarMultiplosRenglones(matrizAuxiliar,j,i,-matrizAuxiliar[j][i],n1*2);
        for(int j=i+1;j<n1;j++)
            SumarMultiplosRenglones(matrizAuxiliar,j,i,-matrizAuxiliar[j][i],n1*2);
    }

    matrizRes=CrearMatriz(n1,n1);
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
            matrizRes[i][j]= matrizAuxiliar[i][j+m1];
    }

    BorraraMatriz(matrizAuxiliar,n1);
    return true;
}

//*************************************************************************************************************************
void IntercambiarReng(double ** matriz ,int renglon1 ,int renglon2 ,int m)
{
    double aux;
    for(int j=0;j<m;j++)
    {
        aux=matriz[renglon1][j];
        matriz[renglon1][j]=matriz[renglon2][j];
        matriz[renglon2][j]=aux;
    }
}

//*************************************************************************************************************************
void MultiplicarRenglon(double ** matriz ,int renglon1 ,double k ,int m)
{
    for(int i=0;i<m;i++)
        matriz[renglon1][i]*=k;
}

//*************************************************************************************************************************
void SumarMultiplosRenglones(double ** matriz ,int renglonSuma ,int renglonMultiplo ,double k ,int m)
{
    for(int i=0;i<m;i++)
        matriz[renglonSuma][i]+=matriz[renglonMultiplo][i]*k;
}

//*************************************************************************************************************************
double absoluto(double n)
{
    if(n<0)
    {
        return -n;
    }
    return n;
}
