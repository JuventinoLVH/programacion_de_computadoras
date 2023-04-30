#include <iostream>
#include <cstdlib>
#include <ctime>

#include <windows.h>

using namespace std;

//*************************************************************************************************************************
/** Colores de texto y fondo de la ventana de despliegue */
enum Color{
    NEGRO, /**< Color negro */
    AZUL, /**< Color azul fuerte */
    VERDE, /**< Color verde oscuro */
    AGUAMARINA, /**< Color azul verde */
    ROJO, /**< Color rojo oscuro */
    PURPURA, /**< Color morado */
    AMARILLO, /**< Color amarillo */
    GRISCLARO, /**< Color gris claro */
    GRIS, /**< Color gris oscuro */
    AZULCLARO, /**< Color azul cielo */
    VERDECLARO, /**< Color verde claro */
    AGUAMARINACLARO, /**< Color azul verde claro */
    ROJOCLARO, /**< Color rojo claro */
    MAGENTA, /**< Color rosa fuerte */
    AMARILLOCLARO, /**< Color amarillo claro */
    BLANCO /**< Color blanco */
};
//*************************************************************************************************************************
/** S&iacute;mbolos para dibujar un rect&aacute;ngulo o marco */
enum {
	BV=179, /**< Barra vertical */
	ESD=191, /**< Esquina superior derecha */
	EII, /**< Esquina inferior izquierda */
	BH=196, /**< Barra horizontal */
	EID=217, /**< Esquina inferior derecha  */
	ESI /**< Esquina superior izquierda */
};
//*************************************************************************************************************************
/** Posibles estados del cursor */
enum EstadoCursor{
	APAGADO, /**< Cursor no visible */
	ENCENDIDO  /**< Cursor visible */
};
//*************************************************************************************************************************
/** Modos o tama&ntilde;os del cursor */
enum ModoCursor{
	MINI = 5, /**< Tama&ntilde;o de cursor peque&ntilde;o */
	NORMAL = 20, /**< Tama&ntilde;o de cursor mediano  */
	SOLIDO = 80 /**< Tama&ntilde;o de cursor grande */
};
//*************************************************************************************************************************
/** \brief Imprime un marco o rect&aacute;ngulo en pantalla con la dimensi&oacute;n dada y en la posici&oacute;n indicada
 *
 * \param ancho Ancho o base del rect&aacute;ngulo
 * \param alto Alto del rect&aacute;ngulo
 * \param x Posici&oacute;n en x donde se imprimir&aacute; el rect&aacute;ngulo
 * \param y Posici&oacute;n en y donde se imprimir&aacute; el rect&aacute;ngulo
 *
 * \pre El ancho y el alto deben ser por lo menos 2. Los valores para la posici&oacute;n (x,y) deben ser no negativos y corresponden
 *      a la posici&oacute;n de la esquina superior izquierda del rect&aacute;ngulo
*/
void ImprimirMarco(int ancho, int alto, int x, int y);
//*************************************************************************************************************************
/** \brief Establece el color de fondo y texto para impresi&oacute;n. Despu&eacute;s de establecer el color, lo que se imprima aparecer&aacute; con esta combinaci&oacute;n de colores.
 *
 * \param colorEst El color a establecer. Es una combinaci&oacute;n del color de fondo y texto
 *
 * \pre El color a establecer debe ser no negativo y una combinaci&oacute;n del color de fondo y texto que se obtiene con la f&oacute;rmula:
 *		(Color de fondo)(16) + (Color de texto). El color del fondo y texto son valores de la enumeraci&oacute;n tipo Color.
 */
void EstablecerColor(WORD colorEst);
//*************************************************************************************************************************
/** \brief Establece el color de fondo y texto para impresi&oacute;n. Despu&eacute;s de establecer el color, lo que se imprima aparecer&aacute; con esta combinaci&oacute;n de colores.
 *
 * \param colorFondo El color de fondo del texto a imprimir
 * \param colorTexto Color del texto a imprimir
 *
 * \pre Tanto el color del fondo y del texto deben ser no negativos. Son valores de la enumeraci&oacute;n tipo Color.
 */
void EstablecerColor(Color colorFondo, Color colorTexto);
//*************************************************************************************************************************
/** \brief Obtiene el color de fondo y texto actual de la ventana de despliegue.
 *
 * \return Valor que combina el color de fondo y texto establecidos actualmente en la ventana de despliegue. Est&aacute; compuesto por: (Color de fondo)(16) + (Color de texto)
 *		   Para obtener los colores separados se divide en m&oacute;dulo el valor devuelto entre 16, este es el color de texto.
 * 		   Se divide entre 16 (divisi&oacute;n entera), este es el color de fondo.
 */
WORD ObtenerColorOriginal();
//*************************************************************************************************************************
/** \brief Mueve el cursor a la posici&oacute;n indicada
 *
 * \param x Posici&oacute;n en x a la que se mueve el cursor
 * \param y Posici&oacute;n en y a la que se mueve el cursor
 *
 * \pre Las posiciones (x,y) deben ser no negativas. La posici&oacute;n m&iacute;nima es cero.
 */
void gotoxy(SHORT x,SHORT y);
//*************************************************************************************************************************
/**
 * \brief Establece el tama&ntilde;o de la ventana de ejecuci&oacute;n.
 *
 * \param ancho Valor entero para el ancho de la ventana.
 * \param alto Valor entero para el alto de la ventana.
 **/
void EstablecerTamVentana(SHORT ancho, SHORT alto);
//*************************************************************************************************************************
/**
 * \brief Modifica el estado del cursor.
 *
 * \param estado Estado del cursor a establecer. Puede ser un valor de la enumeraci&oacute;n EstadoCursor
 * \param modo Tama&ntilde;o del indicador del cursor. Puede ser un valor de la enumeraci&oacute;n ModoCursor. Si se omite, tomar&aacute; el valor NORMAL.
 **/
void CambiarCursor(EstadoCursor estado, ModoCursor modo = NORMAL);
//*************************************************************************************************************************

//  PROGRAMA PRINCIPAL

//*************************************************************************************************************************

int main()
{
    EstablecerTamVentana(41,17);
    WORD original = ObtenerColorOriginal();
    EstablecerColor(AGUAMARINA, AZUL);
    CambiarCursor(APAGADO);

    srand(time(NULL));

    for(int colorFondo = NEGRO, colorTexto = BLANCO ; colorFondo <= BLANCO ; ++colorFondo, --colorTexto){
        EstablecerColor((Color)colorFondo,(Color)colorTexto);
        cout << "Hola mundo" << endl;
        Sleep(500);
    }
    EstablecerColor(original);
    CambiarCursor(ENCENDIDO);

    system("pause");
    return 0;
}



//*************************************************************************************************************************

// IMPLEMENTACIÓN DE FUNCIONES

//*************************************************************************************************************************
void EstablecerColor(WORD colorEst)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorEst);
}
//*************************************************************************************************************************
void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo*16 + colorTexto);
}
//*************************************************************************************************************************
WORD ObtenerColorOriginal()
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsoleHandle, ConsoleInfo);
    WORD original = ConsoleInfo->wAttributes;
    delete ConsoleInfo;
    return original;
}
//*************************************************************************************************************************
void gotoxy(SHORT x,SHORT y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos={x,y};
    SetConsoleCursorPosition(hcon,dwPos);
}
//*************************************************************************************************************************
void ImprimirMarco(int ancho, int alto, int x, int y)
{
    // Parte superior
    gotoxy(x,y);
    std::cout << (char)ESI;
    for(int i = 2 ; i < ancho ; ++i) std::cout << (char)BH;
    std::cout << (char)ESD;
    // Parte media
    for(int i = 2; i < alto; ++i){
        gotoxy(x, ++y);
        std::cout << (char)BV;
        for (int i=2; i< ancho; ++i) std::cout << " ";
        std::cout << (char)BV;
    }
    // Parte inferior
    gotoxy(x,++y);
    std::cout << (char)EII;
    for(int i = 2 ; i < ancho ; ++i) std::cout << (char)BH;
    std::cout << (char)EID;
}
//*************************************************************************************************************************
void CambiarCursor(EstadoCursor estado, ModoCursor modo /* = NORMAL*/)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info = {modo,estado};
	SetConsoleCursorInfo(consoleHandle, &info);
}
//*************************************************************************************************************************
void EstablecerTamVentana(SHORT ancho, SHORT alto)
{
	_COORD coord = {--ancho, --alto};
	_SMALL_RECT rect = {0,0,ancho,alto};
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsola, coord);
	SetConsoleWindowInfo(hConsola, true, &rect);
}
//*************************************************************************************************************************
