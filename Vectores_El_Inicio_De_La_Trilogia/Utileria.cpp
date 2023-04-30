/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include"Utileria.h"

//*******************************************************************************************************************
float CapturaSegura(const char mensaje[])
{
    float auxiliar;
    while(true)
    {
        std::cout<<mensaje;
        std::cin>>auxiliar;
        if(std::cin.bad()){
            std::cout << "Ocurri\242 un error irrecuperable en el flujo de entrada\n";
            system("pause");
            exit(1);
        }
        if(std::cin.fail()){
            std::cout << "Eso no es un numero..." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        return auxiliar;
    }
}
//*******************************************************************************************************************
