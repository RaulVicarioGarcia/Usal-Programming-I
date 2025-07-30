#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // Para usar getch()

void presentarFecha(int opcion, int dia, int mes, int anio, char *cadena);

int main(void) {
    int fecha, opcion, dia, mes, anio;
    char cadena[50]; // Cadena para almacenar la fecha formateada

    // Leer la fecha en formato AAAAMMDD
    printf("Ingrese una fecha en formato AAAAMMDD: ");
    scanf("%d", &fecha);

    // Descomponer la fecha
    anio = fecha / 10000;
    mes = (fecha / 100) % 100;
    dia = fecha % 100;

    // Validar fecha (simplificada)
    if (anio <= 0 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        printf("Fecha invalida.\n");
        return 1;
    }

    do {
        // Presentar el menú
        printf("\nSeleccione el formato de fecha a presentar:\n");
        printf("0 -> 12/04/96\n");
        printf("1 -> 12/04/1996\n");
        printf("2 -> 12/04/1.996\n");
        printf("3 -> 12-04-96\n");
        printf("4 -> 12-04-1996\n");
        printf("5 -> 12-04-1.996\n");
        printf("6 -> 12-Abr-96\n");
        printf("7 -> 12-Abr-1996\n");
        printf("8 -> 12-Abr-1.996\n");
        printf("9 -> 12 de Abril de 1.996\n");
        printf("10 -> 12, Abril 1.996\n");
        printf("99 -> Salir del menu\n");
        printf("Accion: ");
        scanf("%d", &opcion);

        if (opcion >= 0 && opcion <= 10) {
            presentarFecha(opcion, dia, mes, anio, cadena);
            printf("%s\n", cadena);
            printf("Presione una tecla para continuar...\n");
            getch();
        } else if (opcion != 99) {
            printf("Opcion incorrecta: %d\n", opcion);
            printf("Presione una tecla para continuar...\n");
            getch();
        }

    } while (opcion != 99);

    printf("Saliendo del menu...\n");
    return 0;
}

void presentarFecha(int opcion, int dia, int mes, int anio, char *cadena) {
    const char *meses[] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun", 
                           "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};

    switch (opcion) {
        case 0:
            sprintf(cadena, "%02d/%02d/%02d", dia, mes, anio % 100);
            break;
        case 1:
            sprintf(cadena, "%02d/%02d/%04d", dia, mes, anio);
            break;
        case 2:
            sprintf(cadena, "%02d/%02d/%d.%03d", dia, mes, anio / 1000, anio % 1000);
            break;
        case 3:
            sprintf(cadena, "%02d-%02d-%02d", dia, mes, anio % 100);
            break;
        case 4:
            sprintf(cadena, "%02d-%02d-%04d", dia, mes, anio);
            break;
        case 5:
            sprintf(cadena, "%02d-%02d-%d.%03d", dia, mes, anio / 1000, anio % 1000);
            break;
        case 6:
            sprintf(cadena, "%02d-%s-%02d", dia, meses[mes - 1], anio % 100);
            break;
        case 7:
            sprintf(cadena, "%02d-%s-%04d", dia, meses[mes - 1], anio);
            break;
        case 8:
            sprintf(cadena, "%02d-%s-%d.%03d", dia, meses[mes - 1], anio / 1000, anio % 1000);
            break;
        case 9:
            sprintf(cadena, "%02d de %s de %d.%03d", dia, meses[mes - 1], anio / 1000, anio % 1000);
            break;
        case 10:
            sprintf(cadena, "%02d, %s %d.%03d", dia, meses[mes - 1], anio / 1000, anio % 1000);
            break;
        default:
            strcpy(cadena, "Formato no valido");
    }
}
