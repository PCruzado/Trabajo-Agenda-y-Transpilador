#include <stdio.h>

int main() {
    int a, b, promedio;
    
    printf("Ingrese dos numeros: ");
    scanf("%d %d", &a, &b);
    
    promedio = (a+b)/2;
    
    printf("El promedio de estos es: %d", promedio);
    return 0;
}