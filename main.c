#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 5
typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;

}eVacuna;

float aplicarAumento(float precio);
int ordenarArrayVacuna(eVacuna lista[],int tam);
void mostrarVacuna(eVacuna unaVacuna);
int mostrarVacunas(eVacuna lista[],int tam);

int main()
{
    float precio;
    float precioFinal;
    eVacuna lista[TAM] = {
    {2000,"Sputnik",'c',50},
    {2001,"Pfizer",'c',60},
    {2003,"Modena",'h',70},
    {2004,"Larry",'l',80},
    {2005,"Klour",'t',90}};

    printf("ingrese Precio: ");
    scanf("%f",&precio);

    precioFinal = aplicarAumento(precio);

    printf("precio con aumento: %.2f\n",precioFinal);


    // Ejer3

    ordenarArrayVacuna(lista,TAM);
    mostrarVacunas(lista,TAM);



    return 0;
}


float aplicarAumento(float precio)
{
    float aumento = 0.5;
    float precioAumento;

    precioAumento = precio * aumento / 100;

    precioAumento = precio + aumento;

    return precioAumento;
}

int ordenarArrayVacuna(eVacuna lista[],int tam)
{
    int todoOk = 0;
    eVacuna auxVacuna;
    if(lista != NULL && tam > 0)
    {

        todoOk = 1;
        for(int i = 0;i < tam-1;i++)
        {
            for(int j = i + 1;j <tam;j++)
            {
                if(lista[i].tipo > lista[j].tipo)  || (lista[i].tipo == lista[j].tipo && lista[i].efectividad > lista[j].efectividad)
                {
                    auxVacuna = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxVacuna;
                }
            }
        }
    }

    return todoOk;
}

void mostrarVacuna(eVacuna unaVacuna)
{
    printf("%d  %s      %c      %.2f \n",
           unaVacuna.id,
           unaVacuna.nombre,
           unaVacuna.tipo,
           unaVacuna.efectividad);
}

int mostrarVacunas(eVacuna lista[],int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        todoOk = 1;

        printf("\n---------------------------\n");
        printf("            Lista de Vacuna    \n");
        printf("ID    Nombre         Tipo      Efectividad    \n");

        for(int i = 0; i<tam;i++)
        {
            mostrarVacuna(lista[i]);
        }


    }

    return todoOk;
}


