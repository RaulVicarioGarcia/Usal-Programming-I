#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cartesianasAPolares (float x, float y, float *r, float *ang);

int main (void) {

    char p;
    float x, y;
    float r, ang;

    do {

    printf ("Convertidor coordenadas polares <-> cartesianas en C\n");
    printf ("A) Polares -> Cartesianas\n");
    printf ("B) Cartesianas -> Polares\n");
    printf ("S) Salir\n");

    printf ("Introduzca una opcion: ");
    scanf ("%c",&p);


    switch (p) {

    case 'A':

        printf ("\nIntroduzca la coordenada x: ");

        scanf ("%f",&x);

        printf ("\nIntroduzca la coordenada y: ");

        scanf ("%f",&y);
        
        cartesianasAPolares(x, y, &r, &ang);

        printf("Las coordenadas polares son:\n");
                
        printf("Radio (r): %.2f\n", r);
                
        printf("Ángulo (theta) en radianes: %.2f\n", ang);
                
        break;
    
    case 'B':


        break;

    case 'S':

    printf ("Gracias por usar este programa.");

        break;

        
    default:

    printf ("No contemplado.\n");

    } 
    
    } while (x != 'S');

}

void cartesianasAPolares (float x, float y, float *r, float *ang) {

    *r = sqrt(pow(x,2)+pow(y,2));
    *ang = atan(y/x);

}