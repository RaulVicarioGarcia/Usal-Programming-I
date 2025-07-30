#include <stdio.h>
#include <stdlib.h>

int sumaDeParametros(int numero);
int sumaDeParesComprendidos(int n, int m);

int main(void) {
    int numero, n, m, resultado, resultado2;

    // Solicitar y calcular la suma de los primeros "numero" enteros
    printf("Introduzca un numero para calcular la suma de los primeros n numeros: ");
    scanf("%d", &numero);

    resultado = sumaDeParametros(numero);

    printf("La suma de los primeros %d numeros enteros es: %d\n", numero, resultado);

    // Solicitar los valores de n y m para calcular la suma de los pares
    printf("Ingrese el primer numero (n): ");
    scanf("%d", &n);

    printf("Ingrese el segundo numero (m): ");
    scanf("%d", &m);

    resultado2 = sumaDeParesComprendidos(n, m);

    printf("La suma de los numeros pares comprendidos entre %d y %d es: %d\n", n, m, resultado2);

    return 0;
}

int sumaDeParametros(int numero) {
    if (numero <= 0) {
        return 0; // Si el número es no positivo, la suma es 0
    }

    // Fórmula matemática para la suma de los primeros n números
    return (numero * (numero + 1)) / 2;
}

int sumaDeParesComprendidos(int n, int m) {
    int suma = 0;

    // Determinar los límites inferiores y superiores
    int menor = (n < m) ? n : m;
    int mayor = (n > m) ? n : m;

    // Recorrer los números comprendidos entre menor y mayor
    for (int i = menor; i <= mayor; i++) {
        if (i % 2 == 0) { // Verificar si es par
            suma += i; // Sumarlo si es par
        }
    }

    return suma;
}
