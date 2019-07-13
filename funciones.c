/*
 * El archivo contiene las funciones
 *
 */
#include "funciones.h"


void posicion_bola (int *ptrX, int *ptrY) {
  printf("DIGITE LA POSICION X DE LA BOLA:");
  scanf("%i", ptrX);
  printf("\n" );

  if (*ptrX > 65) {
    *ptrX = 65;
  }
  if (*ptrX < 4) {
    *ptrX = 4;
  }

  if (*ptrY > 17) {
    *ptrY = 17;
  }
  if (*ptrY < 4) {
    *ptrY = 4;
  }

  printf("DIGITE LA POSICION Y DE LA BOLA:");
  scanf("%i", ptrY);
  printf("\n" );
};

void nivel(int *ptrCantidadPuntos) {
    printf("DIGITE EL NIVEL:");
    scanf("%i", ptrCantidadPuntos);
    printf("\n" );
  };

void inicio(char campo [V][H], int bolaX, int bolaY, int iniciojugador, int finjugador, int inicioraqueta, int finraqueta){
      //funcion bordes del campo
      borde (campo);
      raqjug (campo, iniciojugador, finjugador);
      raqjuego (campo, inicioraqueta, finraqueta);
      bola (campo, bolaX, bolaY);
    };

void borde (char campo [V][H]){
      int a,b; //para escribir dentro de una matriz se necesita dos bucles y por tanto dos enteros
      for (a = 0; a < V; a++){
         for (b = 0; b < H; b++){
             if(a == 0 || a == V-1){ //para demarcar el cuadro de campo o la matriz, se "pintarA" solo la poscion cero tanto de V como de H
                 campo[a][b] = '-' ;
               }
             else if (b == 0 || b == H-1){
               campo [a][b] = '|';
           }
             else{
               campo [a][b] = ' ' ;
                 }
         }
       }
    };

void raqjug (char campo [V][H], int iniciojugador, int finjugador){
      int a,b;
      for (a = iniciojugador; a <= finjugador; a++){
        for(b = 2; b <= 3; b++){
          campo [a][b] = 'N';

        }
      }
    }


void raqjuego (char campo [V][H], int inicioraqueta, int finraqueta){
       int a,b;
      for (a = inicioraqueta; a <= finraqueta; a++){
         for (b = H - 4; b <= H - 3; b++){
           campo [a][b] = 'N';
         }
       }

     };

void bola (char campo [V][H], int bolaX, int bolaY){
       campo [bolaY][bolaX] = 'O';
     }
 void leermatrizcampo (char campo[V][H]) {
       int a,b;
       for(a = 0; a < V; a++){
         for(b = 0; b < H; b++){
           printf ("%c", campo[a][b]);

         }
         printf ("\n");
       }
     }
  void loopjuego  (char campo [V][H], int bolaX, int bolaY, int iniciojugador, int finjugador, int inicioraqueta, int finraqueta, int trayeX, int trayeY, int trayeinijug, int cantidad_puntos){
     int punto,max_sleep,disminuye_por_punto;
     punto = 0;
     max_sleep = ((cantidad_puntos * 0,8) / 4) * 100000;
     disminuye_por_punto = max_sleep / cantidad_puntos;
     do{
       update(campo,bolaX,bolaY,iniciojugador,finjugador,inicioraqueta,finraqueta);

       drew(campo);

       input(campo, &bolaX, &bolaY, &iniciojugador, &finjugador, &inicioraqueta, &finraqueta, &trayeX, &trayeY, &trayeinijug, &punto, cantidad_puntos);



       usleep (max_sleep - ((punto + 1) * disminuye_por_punto));
     }while (punto < cantidad_puntos);


     };
void drew (char campo [V][H]){

     leermatrizcampo (campo);

   };
void input (char campo [V][H], int *bolaX, int *bolaY, int *iniciojugador, int *finjugador, int *inicioraqueta, int *finraqueta, int *trayeX, int *trayeY, int *trayeinijug, int *punto, int cantidad_puntos){

     int a,b;


     if (*bolaY == 1 || *bolaY == V-2){
       *trayeY *= -1;

       }
       //******Revise esto deben ser dos condiciones distintas una donde pierde el usuario y otra donde gana****///
     if (*bolaX == 1 || *bolaX == H-2){
         *punto += 1;
         if (cantidad_puntos == *punto) {
           printf("Terminó el juego. 'Enter' para continuar: ... \n");
           return;
         }
         printf("PUNTO No. %i\n Presione'Enter' para continuar: ... \n", *punto);
         posicion_bola(bolaX, bolaY);
        while (getchar() != '\n');

       }
     if (*bolaX == 4){
       for (a = (*iniciojugador); a <= (*finjugador); a++) {
         if (a == (*bolaY)){
           *trayeX *= -1;
           }

       }
     }

     if (*bolaX == H - 5){
       for (a = (*inicioraqueta); a <= (*finraqueta); a++){
         if (a == (*bolaY)){
           *trayeX *= -1;
         }
       }
     }
     if (*inicioraqueta == 1 || *finraqueta == V-1){
       *trayeinijug *= -1;
      }
       //modificacion

     if (*punto < cantidad_puntos){
         //Pelota:
        *bolaX += (*trayeX);
         *bolaY += (*trayeY);

         *inicioraqueta += (*trayeinijug);
         *finraqueta += (*trayeinijug);
         *iniciojugador += (*trayeinijug);
         *finjugador += (*trayeinijug);
       }
     };

 void update (char campo [V][H], int bolaX, int bolaY, int iniciojugador, int finjugador, int inicioraqueta, int finraqueta){
       borde (campo);
       raqjug (campo, iniciojugador, finjugador);
       raqjuego (campo, inicioraqueta, finraqueta);
       bola (campo, bolaX, bolaY);
     };
