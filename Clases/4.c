#include <stdio.h>

int main(){
    int precio;
    float iva, iibb, tem;

    printf("Ingrese el precio del producto: ");
    scanf("%d", &precio);

    iva = precio*0.21;
    iibb = precio*0.025;
    tem = precio*0.015;

    printf("El iva del producto es %f, iibb es %f y tem es %f", iva, iibb, tem);

    return 0;
}
