/* Ivan Blanco  					-La contraseña es el nombre de la mejor universidad del tachira y su año de fundacion-
  V31341450 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <ctype.h> 

#define FILAS 15
#define COLS 15
#define MAX_PALABRAS 10
#define MIN_PALABRAS 5
#define MIN_largo 4
#define MAX_largo 15

char sopa[FILAS][COLS]; // Matriz de la sopa de letras
char palabras[MAX_PALABRAS][MAX_largo + 1]; // Arreglo para almacenar las palabras
int num_palabras = 0; // Contador de palabras ingresadas
char letras() {
    return 'A' + rand() % 26; // Generar letras aleatorias de A-Z
}

void menuPrincipal() {// esta funcion es la que inicia el programa
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|     Bienvenido a La Sopa de Letras      |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|1. Comenzar Juego                        |\n"); 						
    printf("\t\t\t\t\t|2. Salir                                 |\n");
    printf("\t\t\t\t\t|=========================================|\n\n");
    printf("\t\t\t\t\tSeleccione una opción: ");
}

void menuRol() {
	system ("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|          Elija su Rol de juego          |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|1. Administrador (debe ingresar primero) |\n"); 						
    printf("\t\t\t\t\t|2. Jugador                               |\n");
    printf("\t\t\t\t\t|=========================================|\n\n");
    printf("\t\t\t\t\tSeleccione una opción: ");
}

void Reglas() {//esto son las reglas del juego las cuales, luego de que el usuario eliga la opcion de jugador, apareceran
	system ("cls");
    printf("\n");
    printf("=========================== Reglas del Juego: Sopa de Letras ===========================\n");
    printf("\n");
    printf("1. Objetivo del Juego:\n");
    printf("   - El objetivo del juego es encontrar las palabras indicadas en un tablero 15x15,\n");
    printf("   - Dichas palabras seras colocadas por un administrador y seran vistas abajo del tablero\n");
    printf("   - El tablero tendra letras aleatorias para confundir y retrasar al jugador\n");
    printf("\n");
    printf("2. Configuración del Juego:\n");
    printf("   - Se juega en un tablero de 15 filas y 15 columnas.\n");
    printf("   - Debajo del tablero se mostraran las palabras a buscar.\n");
    printf("   - Las palabras cuentan de 4 a 15 letras.\n");
    printf("\n");
    printf("3. Modo de Juego:\n");
    printf("   - Se contaran con dos roles, Jugador y Administrador.\n");
    printf("   - El administrador seleccionará las palabras deseadas.\n");
    printf("   - El jugador las buscara en el tablero, al encontrarlas colocara la fila y columna,.\n");
     printf("     de la primera y ultima letra de cada palabra para determinar su posicion.\n");
    printf("\n");
    printf("4. Condiciones:\n");
    printf("   - Las palabras pueden ubicarse verticalmente, horizontalmente y diagonalmente.\n");
    printf("\n");
    printf("5. Ganar el Juego:\n");
    printf("   - El jugador encuentra todas las palabras solicitadas\n");
    printf("\n");
    printf("6. Derrota:\n");
    printf("   - Salirse del programa antes de terminar la partida.\n");
    printf("\n");
    printf("7. Lo mas importante: \n");
    printf("   - Divertirse!!!!!");
    printf("\n");
    printf("==========================================================================================\n\n\n");
    printf("\t");
    system("pause");
    system("cls");
    
}

void Menuadmin (){
	
	
	
	
		
	system ("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t               Administrador\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|            Que Desea Hacer?             |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|1. Incluir Palabras                      |\n"); 						
    printf("\t\t\t\t\t|2. Corregir Palabra                      |\n");
    printf("\t\t\t\t\t|3. Eliminar Palabra                      |\n");
    printf("\t\t\t\t\t|4. Lista de Palabras                     |\n");
    printf("\t\t\t\t\t|5. Regresar al Menú Principal            |\n");
    printf("\t\t\t\t\t|=========================================|\n\n");
    printf("\t\t\t\t\tSeleccione una opción: ");



}






void colocarpala() {
    int i, j;
    char palabra[MAX_largo + 1];

    if (num_palabras >= MAX_PALABRAS) {
        printf("Ya ha ingresado el máximo de palabras permitidas (%d).\n", MAX_PALABRAS);
        return;
    }

    printf("\t\t [Ingrese la cantidad de palabras a incluir] (Entre %d a %d Palabras): ", MIN_PALABRAS, MAX_PALABRAS);
    int cantidad;
    scanf("%d", &cantidad);

    if (cantidad < MIN_PALABRAS || cantidad > MAX_PALABRAS) {
        printf("La cantidad de palabras debe estar entre %d y %d .\n", MIN_PALABRAS, MAX_PALABRAS);
        return;
    }

    for (i = 0; i < cantidad; i++) {
        printf("\t [Ingrese la palabra %d ]: ", num_palabras + 1);
        scanf("%s", palabra);

        // Validar longitud
        int longitud = strlen(palabra);
        if (longitud < MIN_largo || longitud > MAX_largo) {
            printf("\t\t [La palabra debe tener entre %d y %d caracteres]\n", MIN_largo, MAX_largo);
            i--; 
            continue;
        }

        // Convertir a mayúsculas
        for (j = 0; j < longitud; j++) {
            if (palabra[j] >= 'a' && palabra[j] <= 'z') {
                palabra[j] = palabra[j] - 'a' + 'A';
            }
        }

        // Verificar que la palabra no esté ya ingresada
        int repetida = 0;
        for (j = 0; j < num_palabras; j++) {
            if (strcmp(palabras[j], palabra) == 0) {
                repetida = 1;
                break;
            }
        }

        if (repetida) {
            printf("La palabra ya ha sido ingresada previamente.\n");
            i--; // Repetir esta iteración
            continue;
        }

        // Almacenar la palabra
        strcpy(palabras[num_palabras], palabra);
        num_palabras++;
        printf("\t\t -Palabra agregada exitosamente.\n");
    }
}
void modifpala() {
    int indicePalabra, j;
    char nueva_palabra[MAX_largo + 1];

    if (num_palabras == 0) {
        printf("\t\t No hay palabras para corregir.\n");
        return;
    }

    printf("\t\t Lista de palabras ingresadas:\n");
    for (indicePalabra = 0; indicePalabra < num_palabras; indicePalabra++) {
        printf("\t\t -%d. [ %s ]\n", indicePalabra + 1, palabras[indicePalabra]);
    }

    printf("\t\tIngrese el número de la palabra que desea corregir: ");
    scanf("%d", &indicePalabra);
    indicePalabra--; // Ajustar índice de la palabra

    if (indicePalabra < 0 || indicePalabra >= num_palabras) {
        printf("Número inválido.\n");
        return;
    }

    printf("\t[Ingrese la nueva palabra] : ");
    scanf("%s", nueva_palabra);

    // Validar longitud
    int longitud = strlen(nueva_palabra);
    if (longitud < MIN_largo || longitud > MAX_largo) {
        printf("La palabra debe tener entre %d y %d caracteres.\n", MIN_largo, MAX_largo);
        return;
    }

    // Convertir a mayúsculas
    for (j = 0; j < longitud; j++) {
        if (nueva_palabra[j] >= 'a' && nueva_palabra[j] <= 'z') {
            nueva_palabra[j] = nueva_palabra[j] - 'a' + 'A';
        }
    }

    // Verificar que la nueva palabra no esté ya ingresada
    for (j = 0; j < num_palabras; j++) {
        if (strcmp(palabras[j], nueva_palabra) == 0) {
            printf("\t\tLa nueva palabra ya ha sido ingresada previamente.\n");
            return;
        }
    }

    // Corregir la palabra
    strcpy(palabras[indicePalabra], nueva_palabra);
    printf("\tPalabra corregida exitosamente.\n");
}
void quitarpala() {
    int indicePalabra, i;

    if (num_palabras == 0) {
        printf("\t\tNo hay palabras para eliminar.\n");
        return;
    }

    printf("\t\t Lista de palabras ingresadas:\n");
    for (indicePalabra = 0; indicePalabra < num_palabras; indicePalabra++) {
        printf("\t\t -%d. [ %s ]\n", indicePalabra + 1, palabras[indicePalabra]);
    }

    printf("\tIngrese el número de la palabra que desea eliminar: ");
    scanf("%d", &indicePalabra);
    indicePalabra--; // Ajustar índice

    if (indicePalabra < 0 || indicePalabra >= num_palabras) {
        printf("\tNúmero inválido.\n");
        return;
    }

    // Desplazar las palabras
    for (i = indicePalabra; i < num_palabras - 1; i++) {
        strcpy(palabras[i], palabras[i + 1]);
    }
    num_palabras--;//eliminar la palabra del vector de palabras
    printf("\tPalabra eliminada exitosamente.\n");
}

void listaPalabras() {
	int i;
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t                  Administrador\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|            Lista de Palabras            |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    for ( i = 0; i < num_palabras; i++) {
        printf("\t\t\t\t\t|- %-39s|\n", palabras[i]);
    }
    printf("\t\t\t\t\t|=========================================|\n\n");
}

void inicializarYUbicarPalabras() {
    int fila, columna,i;

    // Inicializar el tablero con espacios en blanco
    for (fila = 0; fila < FILAS; fila++) {
        for (columna = 0; columna < COLS; columna++) {
            sopa[fila][columna] = ' ';
        }
    }

    // Insertar palabras en el tablero
    for ( i = 0; i < num_palabras; i++) {
        int direccion, filaInicial, columnaInicial;
        do {
            direccion = rand() % 3; // 0 = horizontal, 1 = vertical, 2 = diagonal
            filaInicial = rand() % FILAS;
            columnaInicial = rand() % COLS;
        } while (!insertarYVerificarPalabra(sopa, palabras[i], direccion, filaInicial, columnaInicial));
    }

    // Rellenar el tablero con letras aleatorias
    for (fila = 0; fila < FILAS; fila++) {
        for (columna = 0; columna < COLS; columna++) {
            if (sopa[fila][columna] == ' ') {
                sopa[fila][columna] = letras();
            }
        }
    }
}


void mostrarTablero() {
    int i, j;

	
    // Imprimir los números de las columnas
    printf("   ");
    printf("\t\t\t\t");
    printf("   ");
    for (j = 0; j < COLS; j++) {
        printf("%3d ", j + 1);
    }
    printf("\n");

    // Imprimir una línea de separación superior
    printf("\t\t\t\t");
    printf("   +");
    for (j = 0; j < COLS; j++) {
        printf("---+");
    }
    printf("\t\t\t\t");
    printf("\n");

    // Imprimir las filas de la sopa de letras
    for (i = 0; i < FILAS; i++) {
        // Imprimir el número de la fila
        printf("\t\t\t\t%2d |", i + 1);

        // Imprimir las letras de la sopa
        for (j = 0; j < COLS; j++) {
            printf(" %c |", sopa[i][j]);
        }
        printf("\n");

        printf("\t\t\t\t");
        printf("   +");
        for (j = 0; j < COLS; j++) {
            printf("---+");
        }
        printf("\n");
    }

   // Mostrar las palabras restantes 
    printf("\n\n\n");
    printf("\t\t\t\t\t                  Jugador\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|            Lista de Palabras            |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    for (i = 0; i < num_palabras; i++) {
        printf("\t\t\t\t\t|- %-39s|\n", palabras[i]);
    }
    printf("\t\t\t\t\t|=========================================|\n\n");

}

int insertarYVerificarPalabra(char sopa[FILAS][COLS], char palabra[], int direccion, int filaInicial, int columnaInicial) {
    int longitud = strlen(palabra);
    int i;

    if (direccion == 0) { // Horizontal
        if (columnaInicial + longitud > COLS) return 0; // Verificar si cabe horizontalmente
        for (i = 0; i < longitud; i++) {
            if (sopa[filaInicial][columnaInicial + i] != ' ' && sopa[filaInicial][columnaInicial + i] != palabra[i]) return 0;
        }
        for (i = 0; i < longitud; i++) {
            sopa[filaInicial][columnaInicial + i] = palabra[i]; // Insertar palabra en caso de que si
        }
    } else if (direccion == 1) { // Vertical
        if (filaInicial + longitud > FILAS) return 0; // Verificar si cabe verticalmente
        for (i = 0; i < longitud; i++) {
            if (sopa[filaInicial + i][columnaInicial] != ' ' && sopa[filaInicial + i][columnaInicial] != palabra[i]) return 0;
        }
        for (i = 0; i < longitud; i++) {
            sopa[filaInicial + i][columnaInicial] = palabra[i]; // Insertar palabra en caso de que si
        }
    } else if (direccion == 2) { // Diagonal
        if (filaInicial + longitud > FILAS || columnaInicial + longitud > COLS) return 0; // Verificar si cabe diagonalmente
        for (i = 0; i < longitud; i++) {
            if (sopa[filaInicial + i][columnaInicial + i] != ' ' && sopa[filaInicial + i][columnaInicial + i] != palabra[i]) return 0;
        }
        for (i = 0; i < longitud; i++) {
            sopa[filaInicial + i][columnaInicial + i] = palabra[i]; // Insertar palabra en caso de que si
        }
    }

    return 1;
}



int verificar_palabra(char sopa[FILAS][COLS], char palabra[], int filaInicio, int colInicio, int filaFin, int colFin) {
    int longitud = strlen(palabra);
    int i;

    if (filaInicio == filaFin) { // en Horizontal
        for (i = 0; i < longitud; i++) {
            if (tolower(sopa[filaInicio][colInicio + i]) != tolower(palabra[i])) return 0;
        }
    } else if (colInicio == colFin) { //en  Vertical
        for (i = 0; i < longitud; i++) {
            if (tolower(sopa[filaInicio + i][colInicio]) != tolower(palabra[i])) return 0;
        }
    } else { //en Diagonal
        for (i = 0; i < longitud; i++) {
            if (tolower(sopa[filaInicio + i][colInicio + i]) != tolower(palabra[i])) return 0;
        }
    }
    return 1;
}


void eliminar_palabra(char sopa[FILAS][COLS], int filaInicio, int colInicio, int filaFin, int colFin) {
    int longitud = (filaInicio == filaFin) ? colFin - colInicio + 1 : filaFin - filaInicio + 1;
    int i;

    if (filaInicio == filaFin) { // en Horizontal
        for (i = 0; i < longitud; i++) {
            sopa[filaInicio][colInicio + i] = ' ';
        }
    } else if (colInicio == colFin) { //en  Vertical
        for (i = 0; i < longitud; i++) {
            sopa[filaInicio + i][colInicio] = ' ';
        }
    } else { //en  Diagonal
        for (i = 0; i < longitud; i++) {
            sopa[filaInicio + i][colInicio + i] = ' ';
        }
    }
}

void Jugador() {
    while (1) {
    	
        int fila_inicio, col_inicio, fila_fin, col_fin,i,j;
        char palabra[16], seguir [5];
        printf("\n\t\t[Ingrese la fila y columna del inicio de la palabra] (ejemplo: 1 4): ");
        scanf("%d %d",&fila_inicio, &col_inicio);
        getchar();
        printf("\n\t\t[Ingrese la fila y columna del Final de la palabra] (ejemplo: 1 9): ");
        scanf("%d %d",&fila_fin, &col_fin);
		
        printf("\n\n\t\tIngrese la palabra que encontraste: ");
        scanf("%15s", palabra);
        getchar();

        if (verificar_palabra(sopa, palabra, fila_inicio - 1, col_inicio - 1, fila_fin - 1, col_fin - 1)) {
            printf("Palabra correcta!\n");
            eliminar_palabra(sopa, fila_inicio - 1, col_inicio - 1, fila_fin - 1, col_fin - 1);
            
            // Eliminar palabra de la lista de palabras
            for ( i = 0; i < num_palabras; i++) {
                if (strcasecmp(palabras[i], palabra) == 0) {
                    for ( j = i; j < num_palabras - 1; j++) {
                        strcpy(palabras[j], palabras[j + 1]);
                    }
                    num_palabras--;
                    break;
                }
            }

            // Mostrar el tablero actualizado
            mostrarTablero();
        } else {
            printf("Palabra incorrecta...\n");
        }

        if (num_palabras == 0) {
            printf("\t\t ¡Felicidades! Has encontrado todas las palabras!!\n");
            printf("\t¿Quieres volver a jugar? Si / No: ");
            
            scanf(" %s", &seguir);
            
            if (strcmpi(seguir,"si")==0) {
                return; // Volver al menú principal
            } else {
            system ("cls");
            printf("\n\n\t-Gracias por jugar Mi Sopa de Letras!!!\n\n\n");
	        
	        printf("\tCerrando programa en: \n\n");
	        printf("\t3...\n\n");
	        printf("\t2...\n\n");
	        printf("\t1...\n\n\n");
	       
               exit(0);  // Salir del juego
            }
        }
    }
}


int main() {
    SetConsoleTitle("Sopa de Letras");
    setlocale(LC_ALL, "spanish");
    system("color F0");
    int opcionMenu, opcionRol, opcionAdmin;
    char contra [15], Pista [20];
    do {
    	system("cls");
        menuPrincipal();
        scanf("%d", &opcionMenu);
        if (opcionMenu == 1) {
            int regresar = 0;
            do {
            	system("cls");
                menuRol();
                scanf("%d", &opcionRol);
                if (opcionRol == 1) {
                	do{
					system("cls");
                	printf("\n\n\t\t\t\t-[Por favor Ingrese La contraseña de Administrador]: ");
                	scanf("%s", contra);
            
                	if (strcmp(contra, "unet1974") == 0){
				
                    do {
                        Menuadmin();
                        scanf("%d", &opcionAdmin);
                        switch (opcionAdmin) {
                            case 1: 
                                colocarpala();
                                printf("\n\n");
                                system("pause");
                                break;
                            case 2:
                                modifpala();
                                printf("\n\n");
                                system("pause");
                                break;
                            case 3:
                                quitarpala();
                                printf("\n\n");
                                system("pause");
                                break;
                            case 4:
                            	listaPalabras();
                            	printf("\n\n");
                                system("pause");
                                break;
                            case 5:
                            	
                            	
                				system ("cls");
                                printf("\n\n\n\n\t\t\t\t\t---Volviendo al Menu Principal---\n\n");
                                system("pause");
                                system("cls");
                                regresar = 1;
                                break;
                            default:
                                printf("\n\t\t-Opción inválida. Por favor Intente nuevamente.\n\n");
			                    printf("\t\t");
			                    system("pause");
                        }
                    } while (opcionAdmin != 5);
                }else {
                	printf("\n\n\t\t\t\tContraseña no Valida Por favor Ingresela de nuevo\n\n");
                	system ("pause");
				}
          		  }while (strcmp(contra, "unet1974") != 0);
                } else if (opcionRol == 2) {
                	if (num_palabras >= MIN_PALABRAS) {
                		Reglas();
                		system ("cls");
                		
                   inicializarYUbicarPalabras();
                   
                    mostrarTablero();
                    Jugador();
                    system("pause");
                   
                }else {
                	printf("\n\n\tNo se puede ingresar como jugador.El administrador Debe ingresar al menos %d palabras primero.\n\n", MIN_PALABRAS);
       				 system("pause");
                	
				}
                } else {
                	
                    printf("\n\t\t-Opción inválida. Por favor Intente nuevamente.\n\n");
                    printf("\t\t");
                    system("pause");
                }
            } while (!regresar);
        } else if (opcionMenu == 2) {
            system ("cls");
            printf("\n\n\t-Gracias por jugar Mi Sopa de Letras!!!\n\n\n");
	       
	        printf("\tCerrando programa en: \n\n");
	        printf("\t3...\n\n");
	        printf("\t2...\n\n");
	        printf("\t1...\n\n\n");
        } else {
        	printf("\n\t\t-Opción inválida. Por favor Intente nuevamente.\n\n");
                    printf("\t\t");
                    system("pause");
        }
    } while (opcionMenu != 2);
    return 0;
}




	


