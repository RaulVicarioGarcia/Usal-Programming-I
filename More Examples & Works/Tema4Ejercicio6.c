#include <stdio.h>
#include <stdlib.h>

char transformar (int cifra) {

char letras;

switch (cifra) {

case 0:

    letras = 'O';
    return letras;
    break;

case 1:

    letras = 'G';
    return letras;
    break;

case 2:

    letras = 'A';
    return letras;
    break;

case 3:

    letras = 'L';
    return letras;
    break;

case 4:

    letras = 'E';
    return letras;
    break;

case 5:

    letras = 'I';
    return letras;
    break;

case 6:

    letras = 'C';
    return letras;
    break;

case 7:

    letras = 'R';
    return letras;
    break;

case 8:

    letras = 'U';
    return letras;
    break;

case 9:

    letras = 'M';
    return letras;
    break;
}}

int main (void) {

    int n_req, unidades, decenas, centenas, u_millar;

    printf ("Introduzca un numero positivo de hasta 4 cifras: ");
    scanf ("%d",&n_req);

    if (n_req < 0 || n_req > 9999) {

        printf ("No has cumplido los requisitos. Error.");
        return -1;

    }

    unidades = n_req % 10;
    decenas = ( n_req / 10 ) % 10;
    centenas = ( n_req / 100 ) % 10;
    u_millar = n_req / 1000;

    printf ("La transformacion es: %c%c%c%c", transformar(u_millar), transformar(centenas), transformar(decenas), transformar(unidades));

    return 0;
}

