#include <stdio.h> 
#include <stdlib.h>
#define MAXFILAS 30
#define MAXCOLUMNAS 50

int main (void) {

    int matrizConsumos[MAXFILAS][MAXCOLUMNAS];
    int dimFil, dimCol;
    int i,j;

    do {

    printf ("Introduce los meses a realizar el estudio (max 30.): ");

        scanf("%d",&dimFil);

    printf ("Introduce las viviendas a realizar el estudio (max 50.): ");

        scanf("%d",&dimCol);
        
    

    } while (dimFil > 30 || dimFil <= 1 || dimCol > 50 || dimCol <= 1 );

    for (i = 0; )

    return 0;

}