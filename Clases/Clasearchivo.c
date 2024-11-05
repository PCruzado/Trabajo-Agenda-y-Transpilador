#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
__FILE__*arch;
char cadena[50];
  arch=fopen("c:\\codigo\\texto.txt");
  if(arch==NULL)
  {
    arch=fopen("c:\\codigo\\texto.txt")
  }
  fgets(cadena,50, arch);
  printf("El texto es: %s", cadena);
  strcpy(cadena,"Vuelve a escribir");
  printf("El texto es %s",cadena);


  fclose(arch);
}
