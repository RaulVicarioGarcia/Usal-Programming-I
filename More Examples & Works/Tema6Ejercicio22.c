#include <stdio.h>
#include <stdlib.h>
#define FILMAX 20
#define COLMAX 50
#define VALMIN 1
#define VALMAX 99
#define COLMIN 5
#define FILMIN 2

int main(void) {
    int dimfil, dimcol;
    int fila, columnna;
    int i, j;
    int suma = 0, contador = 0; // Para el cálculo del valor medio
    int eje;
    int minimo; // Para el cálculo del valor mínimo
    int matriz[FILMAX][COLMAX];

    // Leer dimensiones de la matriz
    do {
        printf("\nIntroduce el numero de filas (min 2, max 20): ");
        scanf("%d", &dimfil);

        printf("Introduce el numero de columnas (min 5, max 50): ");
        scanf("%d", &dimcol);
    } while (dimfil < FILMIN || dimfil > FILMAX || dimcol < COLMIN || dimcol > COLMAX);

    // Leer coordenadas del eje
    do {
        printf("\nIntroduce las coordenadas del eje.");
        printf("\nFila (1 a %d): ", dimfil);
        scanf("%d", &fila);
        printf("Columna (1 a %d): ", dimcol);
        scanf("%d", &columnna);
        printf("\n");
    } while (fila < 1 || fila > dimfil || columnna < 1 || columnna > dimcol);

    // Leer los elementos de la matriz
    for (i = 0; i < dimfil; i++) {
        for (j = 0; j < dimcol; j++) {
            do {
                printf("Introduzca el elemento |%d, %d|: ", i + 1, j + 1);
                scanf("%d", &matriz[i][j]);
            } while (matriz[i][j] < VALMIN || matriz[i][j] > VALMAX);
        }
    }

    // Cálculo del valor medio desde el primer elemento hasta el elemento eje
    int ejeFila = fila - 1;    // Convertir a índice 0
    int ejeColumna = columnna - 1; // Convertir a índice 0

    for (i = 0; i <= ejeFila; i++) {
        for (j = 0; j < dimcol; j++) {
            suma += matriz[i][j];
            contador++;
            if (i == ejeFila && j == ejeColumna) {
                break; // Detenerse en el elemento eje
            }
        }
    }

    float media = (float)suma / contador;

    // Cálculo del valor mínimo desde el elemento eje hasta el último
    minimo = matriz[ejeFila][ejeColumna]; // Inicializar con el elemento eje

    for (i = ejeFila; i < dimfil; i++) {
        for (j = (i == ejeFila ? ejeColumna : 0); j < dimcol; j++) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
            }
        }
    }

    // Mostrar resultados
    printf("\nValor medio desde el primero hasta el elemento eje: %.2f\n", media);
    printf("Valor mínimo desde el elemento eje hasta el último: %d\n", minimo);

    return 0;
}
