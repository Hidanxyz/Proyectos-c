/* Ivan Blanco 
    V.31341450
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

#define FILAS 8 //esto es para definir el valor de las variables, es decir, cada vez que se declaren estas variables siempre tendran un valor determinado
#define COLS 9

int victoriasJugador1 = 0;//las utilice de esta manera para que puedan ser usadas por la funcion de estadisticas mas adelante
int victoriasJugador2 = 0;
int victoriasMaquina = 0;
int empates = 0;
// hay bugs a la hora de colocar un caracter tipo char cuando se solicita un valor tipo int, haciendo que el programa se corrompa
void menuPrincipal() {// esta funcion es la que inicia el programa
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|      Bienvenido a Cuatro en Línea       |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|1. Comenzar Juego                        |\n"); 						
    printf("\t\t\t\t\t|2. Salir                                 |\n");
    printf("\t\t\t\t\t|=========================================|\n\n");
    printf("\t\t\t\t\tSeleccione una opción: ");
}





void Reglas() {//esto son las reglas del juego las cuales, luego de darle comenzar el juego se mostraran al usuario
	system ("cls");
    printf("\n");
    printf("=========================== Reglas del Juego: Cuatro en Línea ===========================\n");
    printf("\n");
    printf("1. Objetivo del Juego:\n");
    printf("   - El objetivo del juego es alinear cuatro fichas del mismo color en una fila,\n");
    printf("     columna o diagonal.\n");
    printf("\n");
    printf("2. Configuración del Juego:\n");
    printf("   - El juego se juega en un tablero de 6 filas y 7 columnas por defecto.\n");
    printf("   - Los jugadores pueden elegir otros tamaños de tablero: 7x8 o 8x9.\n");
    printf("\n");
    printf("3. Modos de Juego:\n");
    printf("   - Jugador vs Jugador: Dos jugadores se turnan para colocar fichas.\n");
    printf("   - Jugador vs Máquina: Un jugador juega contra la máquina.\n");
    printf("   - Máquina vs Máquina: Dos máquinas juegan entre sí.\n");
    printf("\n");
    printf("4. Turnos:\n");
    printf("   - Los jugadores se turnan para colocar una ficha en una de las columnas del tablero.\n");
    printf("   - La ficha caerá hasta la posición disponible más baja en la columna elegida.\n");
    printf("\n");
    printf("5. Ganar el Juego:\n");
    printf("   - Un jugador gana si logra alinear cuatro fichas del mismo color en una fila,\n");
    printf("     columna o diagonal.\n");
    printf("\n");
    printf("6. Empate:\n");
    printf("   - El juego termina en empate si todas las casillas del tablero están llenas\n");
    printf("     y ningún jugador ha logrado alinear cuatro fichas.\n");
    printf("\n");
    printf("7. Lo mas importante: \n");
    printf("   - Divertirse!!!!!");
    printf("\n");
    printf("==========================================================================================\n\n\n");
    printf("\t");
    system("pause");
    system("cls");
    
}


void iniciarTab(int tab[FILAS][COLS], int filas, int cols) {//esto es para iniciar el tablero cuando sea requerido
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            tab[i][j] = 0; // 0 indica una casilla vacía
        }
    }
}

void imprimirTab(int tab[FILAS][COLS], int filas, int cols, char jugador1[], char jugador2[], char color1[], char color2[]) {//esto es para imprimir el tablero cuando sea requerido
	int i,j;
    printf("\n\t\t\t-[%s]- vs -[%s]-\n\n", jugador1, jugador2);

    // Imprimir números de columnas
    printf("\t   ");
    for ( j = 0; j < cols; j++) {
        printf("  %d   ", j + 1);
    }
    printf("\n");

    // Imprimir la parte superior del tablero
    printf("\t  +");
    for (j = 0; j < cols; j++) {
        printf("-----+");
    }
    printf("\n");

    for ( i = 0; i < filas; i++) {
        printf("\t%d |", i + 1); // Número de fila
        for ( j = 0; j < cols; j++) {
            if (tab[i][j] == 1) {
                printf(" %s O %s |", color1, "\033[0m"); // Ficha del jugador 1
            } else if (tab[i][j] == 2) {
                             printf(" %s O %s |", color2, "\033[0m"); // Ficha del jugador 2
            } else {
                printf("     |"); // Casilla vacía
            }
        }
        printf("\n");

        // Imprimir la parte inferior de cada fila
        printf("\t  +");
        for ( j = 0; j < cols; j++) {
            printf("-----+");
        }
        printf("\n");
    }
}
                
                
                
                
int verificarGanador(int tab[FILAS][COLS], int filas, int cols, int turno) {//aqui el programa analiza si hay 4 seguidas de las diferentes maneras de ganar
    int i, j, contar;
    
    // Verificar si hay 4 celdas seguidas en horizontal
    for (i = 0; i < filas; i++) {
        contar = 0;
        for (j = 0; j < cols; j++) {
            if (tab[i][j] == turno) {
                contar++;
                if (contar == 4) return 1;
            } else {
                contar = 0;
            }
        }
    }
    
    //  Verificar si hay 4 celdas seguidas en vertical
    for (j = 0; j < cols; j++) {
        contar = 0;
        for (i = 0; i < filas; i++) {
            if (tab[i][j] == turno) {
                contar++;
                if (contar == 4) return 1;
            } else {
                contar = 0;
            }
        }
    }
    
    //  Verificar si hay 4 celdas seguidas en diagonal (de izquierda a derecha)
    for (i = 0; i < filas - 3; i++) {
        for (j = 0; j < cols - 3; j++) {
            if (tab[i][j] == turno && tab[i+1][j+1] == turno && tab[i+2][j+2] == turno && tab[i+3][j+3] == turno) {
                return 1;
            }
        }
    }
    
    // Verificar si hay 4 celdas seguidas en diagonal (de derecha a izquierda)
    for (i = 0; i < filas - 3; i++) {
        for (j = 3; j < cols; j++) {
            if (tab[i][j] == turno && tab[i+1][j-1] == turno && tab[i+2][j-2] == turno && tab[i+3][j-3] == turno) {
                return 1;
            }
        }
    }

    return 0;
}
int verificarEmpate(int tab[FILAS][COLS], int filas, int cols) {// aqui el prgrama seguira hasta que no hayan espacios vacios
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            if (tab[i][j] == 0) {
                return 0; // Aún hay casillas vacías, no hay empate
            }
        }
    }
    return 1; // No hay casillas vacías, es un empate
}

void seleccionarColor(char color[]) {//aqui utilice codigo ansii para poder ejecutar los colores en el programa
    int opcion;
      printf("\n\n\n\n\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|     Seleccione el color de su ficha     |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|1.- Rojo                      6.- Celeste|\n"); 						
    printf("\t\t\t\t\t|2.- Verde                     7.- Blanco |\n");
    printf("\t\t\t\t\t|3.- Amarillo                  8.- Gris   |\n");
    printf("\t\t\t\t\t|4.- Azul                      9.- Naranja|\n");
    printf("\t\t\t\t\t|5.- Magenta                   10.- Rosado|\n");
    printf("\t\t\t\t\t|=========================================|\n\n");
    printf("\t\t\t\t\t -Seleccione un Color para su ficha: ");
    scanf("%d", &opcion);
    system("cls");
    switch (opcion) {//aqui cada color tiene su respectivo codigo para que se muestre en el compilador
        case 1:
            strcpy(color, "\033[31m"); // codigo ansi para el color Rojo
            break;
        case 2:
            strcpy(color, "\033[32m"); // Verde
            break;
        case 3:
            strcpy(color, "\033[33m"); // Amarillo
            break;
        case 4:
            strcpy(color, "\033[34m"); // Azul
            break;
        case 5:
            strcpy(color, "\033[35m"); // Magenta
            break;
        case 6:
            strcpy(color, "\033[36m"); // Celeste
            break;
        case 7:
            strcpy(color, "\033[37m"); // Blanco
            break;
        case 8:
            strcpy(color, "\033[90m"); // Gris
            break;
        case 9:
            strcpy(color, "\033[91m"); // Naranja
            break;
        case 10:
            strcpy(color, "\033[95m"); // Rosa
            break;
        default:
            strcpy(color, "\033[0m"); // Default (sin color)
            break;
    }
}




void mostrarEstadisticas(char jugador1[], char jugador2[]) {
    printf("\n\t\t===== Estadísticas de Victorias =====\n");
    printf("\t\t|%s: %d victorias\n", jugador1, victoriasJugador1);
    printf("\t\t|%s: %d victorias\n", jugador2, victoriasJugador2);
    printf("\t\t|Empates: %d\n", empates);
    printf("\t\t=====================================\n");
}


void jugadorVsJugador(int tab[FILAS][COLS], int filas, int cols, char jugador1[], char jugador2[], char color1[], char color2[]) {
    int turno = 1;
    int col;

    while (1) {
        imprimirTab(tab, filas, cols, jugador1, jugador2, color1, color2);
        if (turno == 1) {
            printf("\nTurno de %s (1): ", jugador1);
        } else {
            printf("\nTurno de %s (2): ", jugador2);
        }

        do {
            printf("Elija una columna (1-%d): ", cols);
            scanf("%d", &col);
            col--; // Ajustar para índice del array
            if (col < 0 || col >= cols || tab[0][col] != 0) {
                printf("Columna no válida, Por favor, Inténtalo de nuevo.\n");
            }
        } while (col < 0 || col >= cols || tab[0][col] != 0);

        // Colocar ficha en la primera posición vacía de la columna
        int fila = filas - 1;
        while (fila >= 0 && tab[fila][col] != 0) {
            fila--;
        }
        tab[fila][col] = turno;

        // Verificar si un jugador ha conseguido la victoria
        if (verificarGanador(tab, filas, cols, turno)) {
            imprimirTab(tab, filas, cols, jugador1, jugador2, color1, color2);
            printf("\n\t¡%s ha ganado!\n", turno == 1 ? jugador1 : jugador2);
            if (turno == 1) {
                victoriasJugador1++;
            } else {
                victoriasJugador2++;
            }
            mostrarEstadisticas(jugador1, jugador2);
            break;
        }

        // Verificar si los jugadores han conseguido un empate
        if (verificarEmpate(tab, filas, cols)) {
            imprimirTab(tab, filas, cols, jugador1, jugador2, color1, color2);
            printf("\n\t¡Es un empate!\n");
            empates++;
            mostrarEstadisticas(jugador1, jugador2);
            break;
        }

        // Cambiar de turno
        turno = (turno == 1) ? 2 : 1;

        system("cls");
    }
}


void jugadorVsMaquina(int tab[FILAS][COLS], int filas, int cols, char jugador1[], char color1[], char color2[]) {
    int turno = 1;
    int col;

    while (1) {
        imprimirTab(tab, filas, cols, jugador1, "Máquina", color1, color2);
        if (turno == 1) {
            printf("\nTurno de %s (1): ", jugador1);
            do {
                printf("Elija una columna (1-%d): ", cols);
                scanf("%d", &col);
                col--; 
                if (col < 0 || col >= cols || tab[0][col] != 0) {
                    printf("Columna no válida, Por favor, Inténtalo de nuevo.\n");
                }
            } while (col < 0 || col >= cols || tab[0][col] != 0);
        } else {
            col = rand() % cols;//esto es para que se mueva dentro del limite de columnas
            while (tab[0][col] != 0) {
                col = rand() % cols;
            }
            printf("\nTurno de la Máquina (2): Columna %d\n", col + 1);
        }

        // Colocar ficha en la primera posición vacía de la columna
        int fila = filas - 1;
        while (fila >= 0 && tab[fila][col] != 0) {
            fila--;
        }
        tab[fila][col] = turno;

        // Verificar si un jugador ha conseguido la victoria
        if (verificarGanador(tab, filas, cols, turno)) {
            imprimirTab(tab, filas, cols, jugador1, "Máquina", color1, color2);
            printf("\n\t¡%s ha ganado!\n", turno == 1 ? jugador1 : "Máquina");
            if (turno == 1) {
                victoriasJugador1++;
            } else {
                victoriasMaquina++;
            }
            mostrarEstadisticas(jugador1, "Máquina");
            break;
        }

        // // Verificar si los jugadores han conseguido un empate
        if (verificarEmpate(tab, filas, cols)) {
            imprimirTab(tab, filas, cols, jugador1, "Máquina", color1, color2);
            printf("\n\t¡Es un empate!\n");
            empates++;
            mostrarEstadisticas(jugador1, "Máquina");
            break;
        }

        // Cambiar de turno con un operador ternario
        turno = (turno == 1) ? 2 : 1;

        system("cls");
    }
}

void maquinaVsMaquina(int tab[FILAS][COLS], int filas, int cols, char color1[], char color2[]) {
    int turno = 1;
    int col;

    while (1) {
        imprimirTab(tab, filas, cols, "Peter (Máquina 1)", "Rodolfo (Máquina 2)", color1, color2);
        col = rand() % cols;
        while (tab[0][col] != 0) {
            col = rand() % cols;
        }
        printf("\nTurno de la Máquina %d: Columna %d\n", turno, col + 1);

        // Colocar ficha en la primera posición vacía de la columna
        int fila = filas - 1;
        while (fila >= 0 && tab[fila][col] != 0) {
            fila--;
        }
        tab[fila][col] = turno;

        // Verificar si un jugador ha conseguido la victoria
        if (verificarGanador(tab, filas, cols, turno)) {
            imprimirTab(tab, filas, cols, "Peter (Máquina 1)", "Rodolfo (Máquina 2)", color1, color2);
            printf("\n\t¡Máquina %d ha ganado!\n", turno);
            if (turno == 1) {
                victoriasJugador1++; // Incrementa victorias para Máquina 1
            } else {
                victoriasJugador2++; // Incrementa victorias para Máquina 2
            }
            mostrarEstadisticas("Peter (Máquina 1)", "Rodolfo (Máquina 2)");
            break;
        }

        // Verificar si los jugadores han conseguido un empate
        if (verificarEmpate(tab, filas, cols)) {
            imprimirTab(tab, filas, cols, "Peter (Máquina 1)", "Rodolfo (Máquina 2)", color1, color2);
            printf("\n\t¡Es un empate!\n");
            empates++;
            mostrarEstadisticas("Peter (Máquina 1)", "Rodolfo (Máquina 2)");
            break;
        }

        // Cambiar de turno
        turno = (turno == 1) ? 2 : 1;
		system("pause");
        system("cls");
    }
}




int main() {
    SetConsoleTitle("Cuatro en Raya");
    setlocale(LC_ALL, "spanish");
    int opcionMenu;
    menuPrincipal();
    scanf("%d", &opcionMenu);
    if (opcionMenu == 1) {
   	Reglas();
	
    char jugador1[50], jugador2[50];
    char color1[10], color2[10];
    char continuar[5],volmenu[5];
    int filas, cols;
    int tab[FILAS][COLS];
    int opcion, modo;
	do {
	 victoriasJugador1 = 0;
	 victoriasJugador2 = 0;
	 victoriasMaquina = 0;
	 empates = 0;
	system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|      Seleccione el tamaño del tablero   |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|1. 6 filas, 7 columnas (Tradicional)     |\n"); 						
    printf("\t\t\t\t\t|2. 7 filas, 8 columnas                   |\n");
    printf("\t\t\t\t\t|3. 8 filas, 9 columnas                   |\n");
    printf("\t\t\t\t\t|=========================================|\n\n");
    printf("\t\t\t\t\t -Seleccione una opción: ");
    scanf("%d", &opcion);
   
    system("cls");

    switch (opcion) {
        case 1:
            filas = 6;
            cols = 7;
            break;
        case 2:
            filas = 7;
            cols = 8;
            break;
        case 3:
            filas = 8;
            cols = 9;
            break;
        default:
            printf("\t\t\t*-Opción no válida. Se seleccionará el tamaño predeterminado.\n");
            filas = 6;
            cols = 7;
            break;
    }
	
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|        Seleccione el modo de juego      |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|1. Jugador vs Jugador                    |\n"); 						
    printf("\t\t\t\t\t|2. Jugador vs Máquina                    |\n");
    printf("\t\t\t\t\t|3. Máquina vs Máquina                    |\n");
    printf("\t\t\t\t\t|=========================================|\n\n");
    printf("\t\t\t\t\t -Seleccione una opción: ");
    scanf("%d", &modo);
    system("cls");

    if (modo == 1 || modo == 2) {
        printf("\n\n\t\t\t-[Ingrese el nombre del Jugador 1]:  ");
        scanf("%s", jugador1);
        system("cls");
        seleccionarColor(color1);

        if (modo == 1) {
            printf("\n\n\t\t\t-[Ingrese el nombre del Jugador 2]: ");
            scanf("%s", jugador2);
            system("cls");
            seleccionarColor(color2);
        } else {
            strcpy(jugador2, "Máquina");
            seleccionarColor(color2);
        }
    }
    
    if (modo == 3){
    	seleccionarColor(color1);
    	seleccionarColor(color2);
    	
	}
	do {
	
    iniciarTab(tab, filas, cols);

    switch (modo) {
        case 1:
            jugadorVsJugador(tab, filas, cols, jugador1, jugador2, color1, color2);
            break;
        case 2:
            jugadorVsMaquina(tab, filas, cols, jugador1, color1, color2);
            break;
        case 3:
            maquinaVsMaquina(tab, filas, cols, color1, color2);
            break;
        default:-
            printf("\t\t\t*-Modo no válido.\n");
            break;
    }
	
    // Opción para reiniciar el juego
    printf("\t\t*-Desean continuar la Partida? (Si/No): ");
    scanf("%s",&continuar);
	}while (strcmpi(continuar,"si")==0);
    printf("\t\t*-¿Desean Volver al menu?  (Si/No): ");
    scanf("%s", &volmenu);
	}while (strcmpi(volmenu,"si")==0);

	
	

}
        printf("\n\n\t-Gracias por jugar Mi Cuatro en LInea!!\n\n\n");
        printf("\tBY: -[Ivan Blanco]-\n\n");
        printf("\tCerrando programa en: \n\n");
        printf("\t3...\n\n");
        printf("\t2...\n\n");
        printf("\t1...\n\n\n");
          return 0;
    }

   


