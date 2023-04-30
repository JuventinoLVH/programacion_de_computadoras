/* Nombre: Utileria.tpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 10/04/2020
   Descripción: Archivo para las funciones de utilería
*/

//*******************************************************************************************************************
template< typename Tipo>
void CapturaSegura(Tipo &n ,const char mensaje[])
{
    while(true)
    {
        std::cout<<mensaje;
        std::cin>>n;
        if(std::cin.bad())
        {
            std::cout << "Ocurri\242 un error irrecuperable en el flujo de entrada\n";
            system("pause");
            exit(1);
        }
        if(std::cin.fail())
        {
            std::cout << "Eso no es un numero..." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        return;
    }
}
//*******************************************************************************************************************
