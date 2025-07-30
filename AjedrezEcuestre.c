#include <stdio.h>

#define FILAS 80
#define COLUMNAS 80
#define CABALLO_BLANCO 'B'
#define CABALLO_NEGRO 'N'

// Prototipos de funciones
int getMovimientos(char (*m)[COLUMNAS], int fil, int col, int coordX, int coordY, char (*nuevaMatriz)[COLUMNAS], int *movimientosTotales);
void imprimirTablero(char (*m)[COLUMNAS], int fil, int col);

// Vector de componente X de movimientos del caballo
char movimientosX[] = {2, 1, -1, -2, -2, -1, 1, 2};

// Vector de componente Y de movimientos del caballo
char movimientosY[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Cantidad de movimientos posibles
int nMovimientos = sizeof(movimientosX) / sizeof(movimientosX[0]);

int main() {
    // Tablero inicial
    char tablero[FILAS][COLUMNAS] = {
        { 'N', '.', '.', '.', '.', '.', '.', '.' },
        { '.', 'N', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', 'B', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', 'B', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' }
    };
    int fil = 8;  // Número de filas
    int col = 8;  // Número de columnas

    char nuevaMatriz[FILAS][COLUMNAS]; // Matriz para representar los movimientos
    int movimientosTotales = 0;        // Contador de movimientos
    int resultado;                     // Resultado de la función

    // Coordenadas del caballo a mover (ejemplo: el caballo blanco en la posición [2][3])
    int coordX = 2;
    int coordY = 3;

    // Imprimir el tablero inicial
    printf("Tablero inicial:\n");
    imprimirTablero(tablero, fil, col);

    // Llamada a la función
    resultado = getMovimientos(tablero, fil, col, coordX, coordY, nuevaMatriz, &movimientosTotales);

    // Imprimir el resultado de la función
    if (resultado == 0) {
        printf("\nTablero con movimientos del caballo:\n");
        imprimirTablero(nuevaMatriz, fil, col);
        printf("\nMovimientos totales posibles: %d\n", movimientosTotales);
    } else if (resultado == -1) {
        printf("\nError: Coordenadas fuera del tablero.\n");
    } else if (resultado == -2) {
        printf("\nError: No hay un caballo en las coordenadas especificadas.\n");
    }

    return 0;
}

// Implementación de la función imprimirTablero
void imprimirTablero(char (*m)[COLUMNAS], int fil, int col) {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

// Implementación de la función getMovimientos
int getMovimientos(char (*m)[COLUMNAS], int fil, int col, int coordX, int coordY, char (*nuevaMatriz)[COLUMNAS], int *movimientosTotales) {
    int i, nuevaX, nuevaY;

    // Validar si las coordenadas están fuera del tablero
    if (coordX < 0 || coordY < 0 || coordX >= fil || coordY >= col) {
        return -1;
    }

    // Validar si hay un caballo en las coordenadas especificadas
    if (m[coordX][coordY] != CABALLO_NEGRO && m[coordX][coordY] != CABALLO_BLANCO) {
        return -2;
    }

    // Copiar el tablero original a la nueva matriz
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            nuevaMatriz[i][j] = m[i][j];
        }
    }

    // Inicializar el contador de movimientos posibles
    *movimientosTotales = 0;

    // Procesar los movimientos del caballo
    for (i = 0; i < nMovimientos; i++) {
        nuevaX = coordX + movimientosX[i];
        nuevaY = coordY + movimientosY[i];

        // Verificar si la nueva posición está dentro del tablero
        if (nuevaX >= 0 && nuevaX < fil && nuevaY >= 0 && nuevaY < col) {
            if (m[nuevaX][nuevaY] == '.') {
                // Casilla vacía
                nuevaMatriz[nuevaX][nuevaY] = 'x';
                (*movimientosTotales)++;
            } else if ((m[coordX][coordY] == CABALLO_BLANCO && m[nuevaX][nuevaY] == CABALLO_NEGRO) ||
                       (m[coordX][coordY] == CABALLO_NEGRO && m[nuevaX][nuevaY] == CABALLO_BLANCO)) {
                // Captura posible
                nuevaMatriz[nuevaX][nuevaY] = '!';
                (*movimientosTotales)++;
            }
        }
    }

    // Marcar la posición del caballo como 'O'
    nuevaMatriz[coordX][coordY] = 'O';

    return 0; // Éxito
}
