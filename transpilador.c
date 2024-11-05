#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *archivo = fopen("C:/algoritmos/primero.txt", "r+");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char primertexto[1000];
    char nuevotexto[1000] = "";

    while (fgets(primertexto, sizeof(primertexto), archivo) != NULL)
    {
        if (strstr(primertexto, "#incluir") != NULL)
        {
            strcat(nuevotexto, "#include <stdio.h>\n");
        }
        else if (strstr(primertexto, "entero principal()") != NULL)
        {
            strcat(nuevotexto, "int main()\n");
        }
        else if (strstr(primertexto, "imprimirf") != NULL)
        {
            strcat(nuevotexto, "printf");
            strcat(nuevotexto, strchr(primertexto, '('));
        }
        else if (strstr(primertexto, "escanearf") != NULL)
        {
            strcat(nuevotexto, "scanf");
            strcat(nuevotexto, strchr(primertexto, '('));
        }
        else if (strstr(primertexto, "retornar") != NULL)
        {
            strcat(nuevotexto, "return ");
            strcat(nuevotexto, strchr(primertexto, '0'));
        }
        else
        {
            strcat(nuevotexto, primertexto);
        }
    }

    fclose(archivo);

    archivo = fopen("C:/algoritmos/segundo.txt", "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo para escribir.\n");
        return 1;
    }

    fputs(nuevotexto, archivo);
    fclose(archivo);

    printf("Transpilation completed.\n");

    return 0;
}