#include <stdio.h>
#include <stdlib.h>

int calcular_dig_control_entidad(int cod_dharma)
{

    int prim_dig, seg_dig, ter_dig, cuart_dig, total, resultado;

    prim_dig = cod_dharma / 10000;
    seg_dig = (cod_dharma / 1000) % 10;
    ter_dig = (cod_dharma / 100) % 10;
    cuart_dig = (cod_dharma / 10) % 10;

    if (prim_dig % 2 == 0)
    {

        prim_dig = prim_dig * 4;
        seg_dig = seg_dig * 8;
        ter_dig = ter_dig * 5;
        cuart_dig = cuart_dig * 10;
    }
    else
    {

        prim_dig = prim_dig * 9;
        seg_dig = seg_dig * 7;
        ter_dig = ter_dig * 3;
        cuart_dig = cuart_dig * 6;
    }

    total = prim_dig + seg_dig + ter_dig + cuart_dig;
    total = total % 11;
    resultado = 11 - total;

    if (resultado > 9)
    {

        resultado = 1;
    }

    return resultado;
}

int main(void)
{

    int cod_dharma;
    int unidades;
    int calculado_por_entidad;

    printf("Introduzca el codigo Dharma por teclado (5 cifras): ");
    scanf("%d", &cod_dharma);

    unidades = cod_dharma % 10;

    if (cod_dharma > 99999 || cod_dharma < 10000 || unidades == 0)
    {

        printf("\nCodigo Dharma no tiene 5 digitos. Ni el valor de unidades puede equivaler a 0");
        return -1;
    }

    calculado_por_entidad = calcular_dig_control_entidad(cod_dharma);

    printf("\nDigito de control del codigo Dharma: %d", unidades);
    printf("\nDigito de control del codigo Dharma: %d", calculado_por_entidad);

    if (unidades == calculado_por_entidad)
    {

        printf("\nEl codigo Dharma SI es correcto");
    }
    else
    {

        printf("\nEl codigo Dharma NO es correcto");
    }

    system("pause");
    return 0;
}
