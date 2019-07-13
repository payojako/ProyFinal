
/**
* @hederfile funciones.h
*<ruta/funciones.h>
*/

/**
@defgroup funciones contiene las estructuras para el programa del proyecto Atari en consola
*
*Las siguiente son DEFINICIONES Y FUNCIONES DE PONG
*/

//D E F I N I C I O N E S Pong

/*Definie la magnitud del campo de juego dentro de la consola*/
#define V 21
#define H 75


#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/select.h>
#include <termios.h>
#include <fcntl.h>


// F U N C I O N E S
/**
 * Se encarga de adquirir los datos que el usuario desea para posicionar la pelota.
 * @details Esta funcion debe encargarse
 *@param [*] ptrX : Puntero de la bolaX
 *@param [*] ptrY: Puntero de la bolaY
 *
 * @returns
 */
void posicion_bola (int *ptrX, int *ptrY);
/**
 * Se encarga de adquirir el nivel que el usuario desea para el pong.
 * @details El nivel define la rapidez del juego.
 *@param [*] ptrCantidadPuntos: Apunta la cantidad que digita el usuario
* @returns
*/
void nivel(int *ptrCantidadPuntos);
/**
 * Se encarga de adjuntar todos los elementos que invlocra la matriz de campo.
 * @details Esta funcion debe encargarse de, a la hora de imprimir la matriz, presentar los elementos que corresponden,  que son las raquetas y la pelota.
 *
 *@param [char] campo : Matriz [V][H], bolaX, bolaY, iniciojugador, finjugador, inicioraqueta, finraqueta
 *@param [int] bolaX, bolaY:  la Pelota en el campo
 *@param [int] iniciojugador, finjugador: raqueta izquierda
 *@param [int]  inicioraqueta, finraqueta:  raqueta derecha
 * @returns No retorna
 */

void inicio(char campo [V][H], int bolaX, int bolaY, int iniciojugador, int finjugador, int inicioraqueta, int finraqueta);

/**
 * Se encarga de delimitar los bordes del campo.
 * @details Esta funcion debe encargarse de delimitar los bordes de la matriz campo.
 *
 * @param [char] campo : Matriz [V][H]
 *
 * @returns No retorna
 */
void borde (char campo [V][H]);

/**
 * Se encarga de contener los elementos del campo y la raqueta izquierda.
 * @details Esta funcion debe encargarse de crear los bucles para crear y delimitar la raqueta en el campo.
 *
 *@param [char] campo : Matriz [V][H].
 *@param [int] iniciojugador, finjugador: raqueta izquierda.
 *
 * @returns No retorna
 */

void raqjug (char campo [V][H], int iniciojugador, int finjugador);
/**
 * Se encarga de contener los elementos del campo y la raqueta derecha.
 * @details Esta funcion debe encargarse de crear los bucles para crear y delimitar la raqueta en el campo.
 *
 *@param [char] campo : Matriz [V][H].
 *@param [int]  inicioraqueta, finraqueta:  raqueta derecha
 *
 * @returns No retorna
 */


void raqjuego (char campo [V][H], int inicioraqueta, int finraqueta);
/**
 * Se encarga de adjuntar todos los elementos que invlocra la pelota.
 * @details Esta funcion debe encargarse crear la pelota en el campo.
 *
 *@param [char] campo : Matriz [V][H].
 *@param [int] bolaX, bolaY:  la Pelota en el campo.
 *
 * @returns No retorna
 */
void bola (char campo [V][H], int bolaX, int bolaY);
/**
 * Se encarga de imprimir la matriz campo.
 * @details Esta funcion debe encargarse imprimir la matriz campo en la consola.
 *
 *@param [char] campo : Matriz [V][H].
 *
 * @returns No retorna
 */

void leermatrizcampo (char campo[V][H]);

/**
 * Se encarga de llamar las funciones input, drew, update.
 * @details Esta funcion debe encargarse de imprimir la veces necesarias en consola con la verificacion y modificacion correcta.
 *
 *@param [char] campo : Matriz [V][H], bolaX, bolaY, iniciojugador, finjugador, inicioraqueta, finraqueta
 *@param [int] bolaX, bolaY:  la Pelota en el campo
 *@param [int] iniciojugador, finjugador: raqueta izquierda
 *@param [int]  inicioraqueta, finraqueta:  raqueta derecha
 *@param [int]  cantidad_puntos.
 *
 * @returns No retorna
 */
void loopjuego  (char campo [V][H], int bolaX, int bolaY, int iniciojugador, int finjugador, int inicioraqueta, int finraqueta, int trayeX, int trayeY, int trayeinijug, int cantidad_puntos);
/**
 * Se encarga de llamar a la funcion leermatrizcampo.
 * @details Esta funcion debe encargarse llamar para imprimir la matriz campo en la consola.
 *
 *@param [char] campo : Matriz [V][H].
 *
 * @returns No retorna
 */
void drew (char campo [V][H]);
/**
 * Se encarga de verificar los datos.
 * @details Esta funcion debe encargarse modificar los datos del loop.
 *@param [char] campo : Matriz [V][H], bolaX, bolaY, iniciojugador, finjugador, inicioraqueta, finraqueta
 *@param [*] bolaX, bolaY:  la Pelota en el campo
 *@param [*] iniciojugador, finjugador: raqueta izquierda
 *@param [*]  inicioraqueta, finraqueta:  raqueta derecha
 *@param [*]  cantidad_puntos: nivel del juego
 * @returns No retorna
 *
 */
void input (char campo [V][H], int *bolaX, int *bolaY, int *iniciojugador, int *finjugador, int *inicioraqueta, int *finraqueta, int *trayeX, int *trayeY, int *trayeinijug, int *punto, int cantidad_puntos);
/**
 * Se encarga de modificar los datos del loop..
 * @details Esta funcion debe encargar modificar los requerimientos del loop.
 *
*@param [char] campo : Matriz [V][H], bolaX, bolaY, iniciojugador, finjugador, inicioraqueta, finraqueta  *@param [int] bolaX, bolaY:  la Pelota en el campo
*@param [int] iniciojugador, finjugador: raqueta izquierda
*@param [int]  inicioraqueta, finraqueta:  raqueta derecha
* @returns No retorna
*/
void update (char campo [V][H], int bolaX, int bolaY, int iniciojugador, int finjugador, int inicioraqueta, int finraqueta);
