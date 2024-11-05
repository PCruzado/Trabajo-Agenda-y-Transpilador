#include<stdio.h>
// Este include es para usar sqrt() que saca la raiz cuadrada de lo que esta en ()
#include<math.h>

int main(){
    int a, b, media;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &a, &b);

    media = sqrt(a*b);

    printf("La media geometrica de ambos numeros es: %d", media);

    return 0;
}