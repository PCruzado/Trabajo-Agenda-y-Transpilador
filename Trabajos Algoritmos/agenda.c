#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO_CONTACTOS "agenda.bin"
#define MAX_NOMBRE 50
#define MAX_TELEFONO 15
#define MAX_CORREO 50

// Definimos la estructura Contacto
typedef struct {
    char nombre[MAX_NOMBRE];
    char telefono[MAX_TELEFONO];
    char correo[MAX_CORREO];
} Contacto;

// Función para agregar un contacto
void agregarContacto() {
    FILE *archivo = fopen(ARCHIVO_CONTACTOS, "ab");
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        return;
    }

    Contacto nuevoContacto;
    printf("Ingrese el nombre: ");
    scanf(" %[^\n]", nuevoContacto.nombre);
    printf("Ingrese el teléfono: ");
    scanf(" %[^\n]", nuevoContacto.telefono);
    printf("Ingrese el correo: ");
    scanf(" %[^\n]", nuevoContacto.correo);

    if (fwrite(&nuevoContacto, sizeof(Contacto), 1, archivo) != 1) {
        perror("Error al escribir en el archivo");
    } else {
        printf("Contacto agregado exitosamente.\n");
    }

    fclose(archivo);
}

// Función para mostrar los contactos guardados
void mostrarContactos() {
    FILE *archivo = fopen(ARCHIVO_CONTACTOS, "rb");
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        return;
    }

    Contacto contacto;
    printf("\n--- Lista de Contactos ---\n");
    while (fread(&contacto, sizeof(Contacto), 1, archivo) == 1) {
        printf("Nombre: %s\n", contacto.nombre);
        printf("Teléfono: %s\n", contacto.telefono);
        printf("Correo: %s\n\n", contacto.correo);
    }

    fclose(archivo);
}

// Función para modificar un contacto existente
void modificarContacto() {
    FILE *archivo = fopen(ARCHIVO_CONTACTOS, "rb+");
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        return;
    }

    Contacto contacto;
    char nombreBuscado[MAX_NOMBRE];
    int encontrado = 0;

    printf("Ingrese el nombre del contacto a modificar: ");
    scanf(" %[^\n]", nombreBuscado);

    while (fread(&contacto, sizeof(Contacto), 1, archivo) == 1) {
        if (strcmp(contacto.nombre, nombreBuscado) == 0) {
            encontrado = 1;
            printf("Ingrese el nuevo teléfono: ");
            scanf(" %[^\n]", contacto.telefono);
            printf("Ingrese el nuevo correo: ");
            scanf(" %[^\n]", contacto.correo);

            fseek(archivo, -sizeof(Contacto), SEEK_CUR);
            fwrite(&contacto, sizeof(Contacto), 1, archivo);
            printf("Contacto modificado exitosamente.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Contacto no encontrado.\n");
    }

    fclose(archivo);
}

// Función para eliminar un contacto
void eliminarContacto() {
    FILE *archivo = fopen(ARCHIVO_CONTACTOS, "rb");
    FILE *tempArchivo = fopen("temp.bin", "wb");

    if (!archivo || !tempArchivo) {
        perror("No se pudo abrir el archivo");
        if (archivo) fclose(archivo);
        if (tempArchivo) fclose(tempArchivo);
        return;
    }

    Contacto contacto;
    char nombreBuscado[MAX_NOMBRE];
    int encontrado = 0;

    printf("Ingrese el nombre del contacto a eliminar: ");
    scanf(" %[^\n]", nombreBuscado);

    while (fread(&contacto, sizeof(Contacto), 1, archivo) == 1) {
        if (strcmp(contacto.nombre, nombreBuscado) != 0) {
            fwrite(&contacto, sizeof(Contacto), 1, tempArchivo);
        } else {
            encontrado = 1;
            printf("Contacto eliminado exitosamente.\n");
        }
    }

    if (!encontrado) {
        printf("Contacto no encontrado.\n");
    }

    fclose(archivo);
    fclose(tempArchivo);

    remove(ARCHIVO_CONTACTOS);
    rename("temp.bin", ARCHIVO_CONTACTOS);
}

// Menú principal para probar las funciones
int main() {
    int opcion;

    do {
        printf("\n--- Agenda ---\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar contactos\n");
        printf("3. Modificar contacto\n");
        printf("4. Eliminar contacto\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarContacto();
                break;
            case 2:
                mostrarContactos();
                break;
            case 3:
                modificarContacto();
                break;
            case 4:
                eliminarContacto();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
 