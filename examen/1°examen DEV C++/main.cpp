#include <stdio.h>
#include <string.h>

// definir las estructuras para usuarios y materiales
typedef struct {
    char nombre[50];
    int puntos;
} Usuario;

typedef struct {
    char tipo[20];
    double cantidad;
} Material;

// declarar variables
Usuario usuarios[100]; // almacenar hasta 100 usuarios
int totalUsuarios = 0; // contador de usuarios registrados
Material materiales[4] = {
    {"papel", 0.0},
    {"plastico", 0.0},
    {"vidrio", 0.0},
    {"metal", 0.0}
};

// funcion para registrar un usuario
void registrarUsuario() {
    printf("ingrese el nombre del usuario: ");
    scanf("%s", usuarios[totalUsuarios].nombre); // leer el nombre del usuario
    usuarios[totalUsuarios].puntos = 0; // inicializar los puntos del usuario a 0
    totalUsuarios++; // incrementar el contador de usuarios
    printf("usuario registrado exitosamente.\n");
}

// funcion para registrar actividades de reciclaje
void registrarReciclaje() {
    char nombre[50];
    char tipoMaterial[20];
    double cantidad;
    int usuarioEncontrado = 0;

    printf("ingrese el nombre del usuario: ");
    scanf("%s", nombre); // leer el nombre del usuario
    printf("ingrese el tipo de material (papel, plastico, vidrio, metal): ");
    scanf("%s", tipoMaterial); // leer el tipo de material reciclado
    printf("ingrese la cantidad reciclada: ");
    scanf("%lf", &cantidad); // leer la cantidad reciclada

    for (int i = 0; i < totalUsuarios; i++) { // buscar al usuario en el arreglo
        if (strcmp(usuarios[i].nombre, nombre) == 0) {
            usuarioEncontrado = 1;
            for (int j = 0; j < 4; j++) { // buscar el tipo de material
                if (strcmp(materiales[j].tipo, tipoMaterial) == 0) {
                    materiales[j].cantidad += cantidad; // actualizar la cantidad reciclada
                    usuarios[i].puntos += (int)(cantidad * 10); // asignar puntos al usuario
                    printf("reciclaje registrado y puntos asignados.\n");
                    break;
                }
            }
            break;
        }
    }
    if (!usuarioEncontrado) {
        printf("usuario no encontrado.\n");
    }
}

// funcion para generar estadisticas de reciclaje
void generarEstadisticas() {
    printf("estadisticas de reciclaje:\n");
    for (int i = 0; i < 4; i++) { // imprimir las cantidades recicladas por tipo de material
        printf("%s: %.2f kg\n", materiales[i].tipo, materiales[i].cantidad);
    }
}

// funcion para mostrar los puntos acumulados por un usuario
void mostrarPuntos() {
    char nombre[50];
    printf("ingrese el nombre del usuario: ");
    scanf("%s", nombre); // leer el nombre del usuario

    for (int i = 0; i < totalUsuarios; i++) { // buscar al usuario en el arreglo
        if (strcmp(usuarios[i].nombre, nombre) == 0) {
            printf("puntos acumulados por %s: %d puntos\n", nombre, usuarios[i].puntos);
            return;
        }
    }
    printf("usuario no encontrado.\n");
}

// funcion principal para mostrar el menu y manejar la entrada del usuario
int main() {
    int opcion;
    while (1) { // bucle infinito para mostrar el menu hasta que el usuario decida salir
        printf("\n");
        printf("----------- BIEVENIDO ----------\n");
		printf("--------------------------------\n");
		printf(" SISTEMA DE GESTION DE RESICLAJE \n");
        printf("--------------------------------\n");
        printf("1. registrar usuario\n");
        printf("2. registrar reciclaje\n");
        printf("3. generar estadisticas\n");
        printf("4. mostrar puntos\n");
        printf("5. salir\n");
        printf("--------------------------------\n");
        printf("seleccione una opcion por favor: ");
        scanf("%d", &opcion); // leer la opcion seleccionada por el usuario

        switch (opcion) { // ejecutar la funcion correspondiente a la opcion seleccionada
            case 1:
                registrarUsuario();
                break;
            case 2:
                registrarReciclaje();
                break;
            case 3:
                generarEstadisticas();
                break;
            case 4:
                mostrarPuntos();
                break;
            case 5:
                return 0; // salir del programa
            default:
                printf("opcion no valida.\n");
        }
    }
}

