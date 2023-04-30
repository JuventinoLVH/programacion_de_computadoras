/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/


template <typename Tipo>
void ImprimirVector(const Tipo arreglo[], int dimension)
{
	std::cout << '(';
	for(int i = 0; i < dimension; ++i)
		std::cout << arreglo[i] << ", ";

    if(dimension != 0)
        std::cout << "\b\b)";
    else
        std::cout<<")";

	return;
}

//*******************************************************************************************************************
template <typename Tipo>
void CapturarVector(Tipo arreglo[], int dimension)
{
	for(int i = 0; i < dimension; ++i)
    {
		char mensaje[50];
		sprintf(mensaje ,"Ingrese el elemento %d del vector: " ,i+1);
		arreglo[i]=CapturaSegura(mensaje);
	}
	std::cout << '\n';

	return;
}

//*******************************************************************************************************************
void SumarVectores(const float primerVector[], const float segundoVector[],float vectorResultante[], int dimension)
{
	for(int i = 0; i < dimension; ++i)
		vectorResultante[i] = primerVector[i] + segundoVector[i];

	return;
}

//*******************************************************************************************************************
template <typename Tipo>
void RestaVectores(const Tipo primerVector[], const Tipo segundoVector[],Tipo vectorResultante[], int dimension)
{
	for(int i = 0; i < dimension; ++i)
		vectorResultante[i] = primerVector[i] - segundoVector[i];

	return;
}

//*******************************************************************************************************************
template <typename Tipo>
float ProductoPunto(const Tipo primerVector[], const Tipo segundoVector[], int dimension)
{
    float resultado=0;

	for(int i = 0; i < dimension; ++i)
		resultado+= primerVector[i] * segundoVector[i];

	return resultado;
}

//*******************************************************************************************************************
template <typename Tipo>
void ProductoVectorEscalar(const Tipo Vector[] ,Tipo vectorResultante[] ,float escalar ,int dimension)
{
    for(int i = 0; i < dimension; ++i)
		vectorResultante[i] = Vector[i]*escalar;
}

//*******************************************************************************************************************
template <typename Tipo>
float NormaVector(const Tipo Vector[], int dimension)
{
    float resultado=0;

    for(int i = 0; i < dimension; ++i)
		resultado = Vector[i]*Vector[i];

    resultado=sqrt(resultado);
    return resultado;
}
