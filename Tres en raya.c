

#include <stdio.h>
#include <stdlib.h>//nos permite en este caso tener los comandos "rand"
#include <string.h> 
#include <windows.h>//nos permite cambiar el nombre de la consola y ademas cambiarle el color
#include <locale.h>//nos permite traducir la consola, logrando colocar acentos o simbolos en nuestro lenguaje


int main(int argc, char *argv[]) {
    SetConsoleTitle("Tres en raya");
    setlocale(LC_ALL, "spanish");
    system("color F0");
    int k, l, mod, dificultad, fila, colu,opcionMenu;
    int ganar, empate,mover;
    char tablero[3][3], jugadorx = 'X' , jugadoro = 'O', jugadoractual = jugadorx, nueva[5], jug1[12],jug2[12],menu [5];
    
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|       Bienvenido a Tres en Raya         |\n");
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\t|1. Comenzar Juego                        |\n"); 						
    printf("\t\t\t\t\t|2. Salir                                 |\n");
    printf("\t\t\t\t\t|=========================================|\n\n");
    printf("\t\t\t\t\tSeleccione una opción: ");
    scanf("%d",&opcionMenu);
    if (opcionMenu == 1) {
	
	system ("cls");
    printf("\n");
    printf("=========================== Reglas del Juego: Tres en Raya ===========================\n");
    printf("\n");
    printf("1. Objetivo del Juego:\n");
    printf("   - El objetivo del juego es alinear 3 fichas (X /O )en una fila,\n");
    printf("     columna o diagonal.\n");
    printf("\n");
    printf("2. Configuración del Juego:\n");
    printf("   - Se juega en un tablero de 3 filas y 3 columnas.\n");
    printf("\n");
    printf("3. Modos de Juego:\n");
    printf("   - Jugador vs Jugador: Dos jugadores se turnan para colocar fichas (X / O).\n");
    printf("   - Jugador vs Máquina: Un jugador juega contra la máquina.\n");
    printf("\n");
    printf("4. Turnos:\n");
    printf("   - Los jugadores se turnan para colocar una ficha en una de las columnas del tablero.\n");
    printf("   - La ficha se colocara justo en la fila y  columna elegida.\n");
    printf("\n");
    printf("5. Ganar el Juego:\n");
    printf("   - Un jugador gana si logra alinear Tres fichas del mismo Simbolo en una fila,\n");
    printf("     columna o diagonal.\n");
    printf("\n");
    printf("6. Empate:\n");
    printf("   - El juego termina en empate si todas las casillas del tablero están llenas\n");
    printf("     y ningún jugador ha logrado alinear Tres  fichas.\n");
    printf("\n");
    printf("7. Lo mas importante: \n");
    printf("   - Divertirse!!!!!");
    printf("\n");
    printf("==========================================================================================\n\n\n");
    printf("\t");
    system("pause");
    system("cls");

   
    do {
    	
		do{//este ciclo es para volver al menu para cuando sea requerido por el jugador
			 system("cls");
		    printf("\n\n\n\n\n");
		    printf("\t\t\t\t\t|=========================================|\n");
		    printf("\t\t\t\t\t|           Modalidad del juego           |\n");
		    printf("\t\t\t\t\t|=========================================|\n");
		    printf("\t\t\t\t\t|1. Jugador vs Jugador                    |\n"); 						
		    printf("\t\t\t\t\t|2. Jugador vs máquina                    |\n");
		    printf("\t\t\t\t\t|3. Cerrar el Juego                       |\n");
		    printf("\t\t\t\t\t|=========================================|\n\n");
		    printf("\t\t\t\t\tSeleccione una opción: ");
	        scanf("%d", &mod);
	        if (mod != 1 && mod != 2 && mod !=3)
			{printf("\n\n\t\t\t\t\t-Opcion no valida!, por favor intentelo de nuevo!\n\n");
			system("pause");
			system("cls");
		}
	}while (mod != 1 && mod != 2 && mod !=3); // esto hace que se devuelva al menu principal inmediatamente si no se coloca una opcion valida
		if(mod==1){
			system("cls");
			printf("\n\t\t\t\t\t-[Por favor registre su nombre Jugador 1]: ");
			scanf("%s",&jug1);
			printf("\n\t\t\t\t\t-[Por favor registre su nombre Jugador 2]:  ");
			scanf("%s",&jug2); 
			system("cls");
		}
	
        if (mod == 2) {
        	do {
			system("cls");
        	printf("\n\n\n\n\n");
		    printf("\t\t\t\t\t|=========================================|\n");
		    printf("\t\t\t\t\t|         Dificultad  del juego           |\n");
		    printf("\t\t\t\t\t|=========================================|\n");
		    printf("\t\t\t\t\t|1. -Dificultad Normal     (^_^)          |\n"); 						
		    printf("\t\t\t\t\t|2. -Dificultad Difícil    (¬_¬)          |\n");
		    printf("\t\t\t\t\t|3. -Dificultad Definitiva (x_x)          |\n");
		    printf("\t\t\t\t\t|=========================================|\n\n");
    
            printf("\t\t\t\t\t-Elija la dificultad: ");
            scanf("%d", &dificultad);
          	if (dificultad != 1 && dificultad != 2 && dificultad !=3){
          		{printf("\n\n\t\t\t\t\t-Opcion no valida!, por favor intentelo de nuevo!\n\n");
				system("pause");
				system("cls");
				}
			  }
            
            }while (dificultad != 1 && dificultad != 2 && dificultad !=3);//igual que el while anteior este hace volver al menu de dificultad inmediatamente al no ingresar una opcion correcta 
            system("cls");
            printf("\t\t\t\t\t-[Por favor ingrese su nombre jugador]: ");
        	scanf("%s",&jug1);
           }
        system("cls");
		do{//este bucle permite reiniciar la partida inmediatamente con los mismos ajustes anteriores
		system("cls");
     	// se utiliza para generar el tablero de juego vacio
        for (k = 0; k < 3; k++) {
            for (l = 0; l < 3; l++) {
                tablero[k][l] = ' ';
            }
        }

        while (1) {// este while hace que el cilo se repita hasta que se cumpla alguna condicion, ya sea victoria o empate,esto debido a que al tener 1 como condicional hace que siempre sea verdadero
		
            printf("\t\t\t\t\t\t-*[%s (X)] VS [%s (O)]*-\n\n\n\n", jug1, mod == 1 ? jug2 : "Máquina");/*esto hace que los jugadores se muestren en pantalla, el operador ternario
            																				    revisa si la condicion se cumple (mod==1) y si no automaticamente se colocara el nombre "maquina"   			*/
            for (k = 0; k < 3; k++) {//con este recorrido de for y prints se logra conseguir un tablero muy parecido al tres en raya
                printf("\t\t\t\t\t\t\t");
                for (l = 0; l < 3; l++) {
                	 
                    printf(" %c ", tablero[k][l]);
                
                    if (l < 2) printf("|");
                }
                printf("\n");
                if (k < 2) printf("\t\t\t\t\t\t\t---|---|---\n");
            } 

            switch (mod) {
                case 1: // aqui se le pide al jugador elegir una celda dentro del tablero y se repite hasta que todas las celdas esten llenas o si se consigue al ganador
                    do {
                    	
                        printf("\n\t\t\t\t\t-Jugador  (%c), ingrese la fila (1-3): ", jugadoractual);
                        scanf("%d", &fila);
                        printf("\n\t\t\t\t\t-Jugador  (%c), ingrese la columna (1-3): ", jugadoractual);
                        scanf("%d", &colu);
                        
                        fila--;//esto es para restale 1 a la variable, ya que cuando ingreso los respectivos numeros el programa no lo lee correctamente, esto creo que sucede ya que en lenguaje c el sistema empieza contar desde 0 
                        colu--;// y al por ejemplo colocar el numero 1 lo coloca en la posicion 2 de la matriz 
                        if (fila < 0 || fila >= 3 || colu < 0 || colu >= 3) {
                            printf("\n\n\t\t\t\t\t\t-Posicion no válida. Por favor Inténtalo de nuevo.\n");
                        } else if (tablero[fila][colu] != ' ') {
                            printf("\n\n\t\t\t\t\t\t-Celda ya ocupada. Por favor Inténtalo de nuevo.\n");
                        }
                    } while (fila < 0 || fila >= 3 || colu < 0 || colu >= 3 || tablero[fila][colu] != ' ');/*esto verifica si la celda colocada por el jugador se encuentra dentro de los limites de la matriz o si la celda ya esta ocupada
                    																						 de estarlo se ejecutara el while, dandole la opcion al jugador de arreglar su error*/
                    tablero[fila][colu] = jugadoractual;
                    //esto es para que se guarde el movimiento del jugador actual dentro de la matriz, en el jugador vs Jugador
					system("cls");
                    break;

                case 2:
       													 
                    if (jugadoractual == jugadorx) {//esto se hace para que jugador actual siempre sea jugador x y no cambie a jugador O
                        do {
                        	
							
                            printf("\n\n\t\t\t\t\t\t-Jugador(%c), ingrese la fila (1-3): ", jugadoractual);
                            scanf("%d", &fila);
                            printf("\n\t\t\t\t\t\t-Jugador (%c), ingrese la columna (1-3): ", jugadoractual);
                            scanf("%d", &colu);
                            fila--;
                            colu--;
                            if (fila < 0 || fila >= 3 || colu < 0 || colu >= 3) {
                                printf("\n\n\t\t\t\t\t\t-Posicion no válida. Por favor Inténtalo de nuevo.\n");
                            } else if (tablero[fila][colu] != ' ') {
                                printf("\n\t\t\t\t\t-Celda ya ocupada. Por favor Inténtalo de nuevo.\n");
                            }
                        } while (fila < 0 || fila >= 3 || colu < 0 || colu >= 3 || tablero[fila][colu] != ' ');
                    } else {
                        switch (dificultad) {
                            case 1:  // funciona  parecido al caso jugador vs jugador, solo que aqui el programa buscara un espacio vacio dentro de la matriz y lo rellenara de manera aleatoria
                 
                                do {
                                    fila = rand() % 3;//este es el operador modulo,funciona dando el resto de una division como resultado
                                    colu = rand() % 3;//en este caso al colocar% 3 los resultados vrian solamente entre 0 y 2 ya que son los unicos restos posibles en divisiones entre 3
                                } while (tablero[fila][colu] != ' ');
                                break;
                                
                            case 2://aqui el programa analiza si el usario "X" tiene dos celdas donde puede conseguir la victoria, si las tiene el programa pondra un 0 para evitar la derrota
                                {
                                    mover = 0;
                                    
                                    for (k = 0; k < 3; k++) {//aqui analiza todas las posibles jugadas en horizontal y vertical y si encuentra dos x seguidas o separadas que podrian generar una victoria el programa colocoa un 0 para evitar la derrota
                                        if (tablero[k][0] == jugadorx && tablero[k][1] == jugadorx && tablero[k][2] == ' ') {fila = k; colu = 2; mover = 1; break;}
                                        if (tablero[k][1] == jugadorx && tablero[k][2] == jugadorx && tablero[k][0] == ' ') {fila = k; colu = 0; mover = 1; break;}
                                        if (tablero[k][0] == jugadorx && tablero[k][2] == jugadorx && tablero[k][1] == ' ') {fila = k; colu = 1; mover = 1; break;}
                                        if (tablero[0][k] == jugadorx && tablero[1][k] == jugadorx && tablero[2][k] == ' ') {fila = 2; colu = k; mover = 1; break;}
                                        if (tablero[1][k] == jugadorx && tablero[2][k] == jugadorx && tablero[0][k] == ' ') {fila = 0; colu = k; mover = 1; break;}
                                        if (tablero[0][k] == jugadorx && tablero[2][k] == jugadorx && tablero[1][k] == ' ') {fila = 1; colu = k; mover = 1; break;}
                                    }
                                    if (!mover) {//esto hace que si no se encunetran celdas seguidas en horizontal o vertical, el sistema analizara los diagonales
                                    	//aqui analiza todas las posibles jugadas en diagonal y si se encuentran dos x seguidas en diagonal o dos separadas que puedan generar la victoria el programa coloca un 0 para evitar la derrota
                                        if (tablero[0][0] == jugadorx && tablero[1][1] == jugadorx && tablero[2][2] == ' ') {fila = 2; colu = 2;}
                                        else if (tablero[1][1] == jugadorx && tablero[2][2] == jugadorx && tablero[0][0] == ' ') {fila = 0; colu = 0;}
                                        else if (tablero[0][0] == jugadorx && tablero[2][2] == jugadorx && tablero[1][1] == ' ') {fila = 1; colu = 1;}
                                        else if (tablero[0][2] == jugadorx && tablero[1][1] == jugadorx && tablero[2][0] == ' ') {fila = 2; colu = 0;}
                                        else if (tablero[1][1] == jugadorx && tablero[2][0] == jugadorx && tablero[0][2] == ' ') {fila = 0; colu = 2;}
                                        else if (tablero[0][2] == jugadorx && tablero[2][0] == jugadorx && tablero[1][1] == ' ') {fila = 1; colu = 1;}
                                        else {
                                            do {
                                                fila = rand() % 3;
                                                colu = rand() % 3;
                                            } while (tablero[fila][colu] != ' ');/*esto hace que al programa no ver dos celdas seguidas puestas por el jugador
                                        										 simplemente eliga una casilla al azar como en la difcultad normal*/
                                    }
                                    }
                                }
                                break;
                            case 3://aqui el programa hara todo lo posible por ganar y defenderse , es un modo tal como lo llame, definitivo
							{
							mover = 0;
						        for (k = 0; k < 3; k++) {//este funciona a la inversa del dificil, ya que la maquina detecta que tiene dos 0 que puedan darle la victoria y sin dudarlo buscara obtenerla
						            if (tablero[k][0] == jugadoractual && tablero[k][1] == jugadoractual && tablero[k][2] == ' ') {fila = k; colu = 2; mover = 1; break;}
						            if (tablero[k][1] == jugadoractual && tablero[k][2] == jugadoractual && tablero[k][0] == ' ') {fila = k; colu = 0; mover = 1; break;}
						            if (tablero[k][0] == jugadoractual && tablero[k][2] == jugadoractual && tablero[k][1] == ' ') {fila = k; colu = 1; mover = 1; break;}
						            if (tablero[0][k] == jugadoractual && tablero[1][k] == jugadoractual && tablero[2][k] == ' ') {fila = 2; colu = k; mover = 1; break;}
						            if (tablero[1][k] == jugadoractual && tablero[2][k] == jugadoractual && tablero[0][k] == ' ') {fila = 0; colu = k; mover = 1; break;}
						            if (tablero[0][k] == jugadoractual && tablero[2][k] == jugadoractual && tablero[1][k] == ' ') {fila = 1; colu = k; mover = 1; break;}
						        }
						        if (!mover) {//aqui buscara dos celdas con 0 las cuales puedan darle la victoria en diagonal
						            if (tablero[0][0] == jugadoractual && tablero[1][1] == jugadoractual && tablero[2][2] == ' ') {fila = 2; colu = 2;}
						            else if (tablero[1][1] == jugadoractual && tablero[2][2] == jugadoractual && tablero[0][0] == ' ') {fila = 0; colu = 0;}
						            else if (tablero[0][0] == jugadoractual && tablero[2][2] == jugadoractual && tablero[1][1] == ' ') {fila = 1; colu = 1;}
						            else if (tablero[0][2] == jugadoractual && tablero[1][1] == jugadoractual && tablero[2][0] == ' ') {fila = 2; colu = 0;}
						            else if (tablero[1][1] == jugadoractual && tablero[2][0] == jugadoractual && tablero[0][2] == ' ') {fila = 0; colu = 2;}
						            else if (tablero[0][2] == jugadoractual && tablero[2][0] == jugadoractual && tablero[1][1] == ' ') {fila = 1; colu = 1;}
						            else {
						            	mover = 0;
						            	for (k = 0; k < 3; k++) {// aqui utilice el mismo algoritmo que use para la dificultad dificil, el programa busca bloquear al usario si este esta cerca de ganar
					                    if (tablero[k][0] == jugadorx && tablero[k][1] == jugadorx && tablero[k][2] == ' ') {fila = k; colu = 2; mover = 1; break;}
					                    if (tablero[k][1] == jugadorx && tablero[k][2] == jugadorx && tablero[k][0] == ' ') {fila = k; colu = 0; mover = 1; break;}
					                    if (tablero[k][0] == jugadorx && tablero[k][2] == jugadorx && tablero[k][1] == ' ') {fila = k; colu = 1; mover = 1; break;}
					                    if (tablero[0][k] == jugadorx && tablero[1][k] == jugadorx && tablero[2][k] == ' ') {fila = 2; colu = k; mover = 1; break;}
					                    if (tablero[1][k] == jugadorx && tablero[2][k] == jugadorx && tablero[0][k] == ' ') {fila = 0; colu = k; mover = 1; break;}
					                    if (tablero[0][k] == jugadorx && tablero[2][k] == jugadorx && tablero[1][k] == ' ') {fila = 1; colu = k; mover = 1; break;}
					                    
					                }
					                if (!mover) {//aqui busca bloquear al jugador si tiene posibilidades de ganar diagonalmente
										
                                      if (tablero[0][0] == jugadorx && tablero[1][1] == jugadorx && tablero[2][2] == ' ') {fila = 2; colu = 2;}
                                      else if (tablero[1][1] == jugadorx && tablero[2][2] == jugadorx && tablero[0][0] == ' ') {fila = 0; colu = 0;}
                                      else if (tablero[0][0] == jugadorx && tablero[2][2] == jugadorx && tablero[1][1] == ' ') {fila = 1; colu = 1;}
                                      else if (tablero[0][2] == jugadorx && tablero[1][1] == jugadorx && tablero[2][0] == ' ') {fila = 2; colu = 0;}
                                      else if (tablero[1][1] == jugadorx && tablero[2][0] == jugadorx && tablero[0][2] == ' ') {fila = 0; colu = 2;}
                                      else if (tablero[0][2] == jugadorx && tablero[2][0] == jugadorx && tablero[1][1] == ' ') {fila = 1; colu = 1;}
                                      else {
                                      	if (!mover) {
						                    
						                    if (tablero[1][1] == ' ') {fila = 1; colu = 1;} // esto es para que en caso de que el jugador no empiece en el centro, el programa lo haga
						                    
						                    else {
						                        do {//esto es por si el programa no encuentra ninguna alternativa y simplemente se mueva al azar
						                              fila = rand() % 3;
						                              colu = rand() % 3;
						                        } while (tablero[fila][colu] != ' ');
						    }
					}	
			}	
		}	
	}
       	}
		   	}               
  }
   }tablero[fila][colu] = jugadoractual;//esto es para que se guarde el movimiento del jugador actual dentro de la matriz, en el jugador vs maquina
     system("cls");
     break;
case 3:
	{
		system("cls");
		printf("\n\n\t\t-----Cerrando programa de Juego-----\n");
		printf("\n\n\t\t-Hecho y elaborado por  -[Ivan Blanco]-\n");
		printf("\n\n\t\t-Muchas gracias por jugar!!!\n");
		return 0;
	}

}
ganar = 0;// verificar si alguno de los jugadores consiguio una victoria
for (k = 0; k < 3; k++) {
    if (tablero[k][0] == jugadoractual && tablero[k][1] == jugadoractual && tablero[k][2] == jugadoractual) ganar = 1;// el programa revisa si el usario tiene tres celdas seguidas sea en horizontal o vertical y de ser asi concede la victoria
    if (tablero[0][k] == jugadoractual && tablero[1][k] == jugadoractual && tablero[2][k] == jugadoractual) ganar = 1;
}
if (tablero[0][0] == jugadoractual && tablero[1][1] == jugadoractual && tablero[2][2] == jugadoractual) ganar = 1;// el programa aqui revisa si el usario tiene 3 celdas seguidas en diagonal y si es asi concede la victoria
if (tablero[0][2] == jugadoractual && tablero[1][1] == jugadoractual && tablero[2][0] == jugadoractual) ganar = 1;

if (ganar) {

 	printf("\t\t\t\t\t\t-*[%s (X)] VS [%s (O)]*-\n\n\n\n", jug1, mod == 1 ? jug2 : "Máquina");
    for (k = 0; k < 3; k++) {
       	 printf("\t\t\t\t\t\t\t");//esto es para mostrar el tablero  luego de conseguir la condicion de victoria
        for (l = 0; l < 3; l++) {
            printf(" %c ", tablero[k][l]);
            if (l < 2) printf("|");
        }
        printf("\n");
        if (k < 2) printf("\t\t\t\t\t\t\t---|---|---\n");
    }
    printf("\n\n\t\t\t\t\t\t¡Jugador %c gana!. Felicidades!!!\n", jugadoractual);
    break;
}

// verificar si los usuarios consiguieron un empate
empate = 1;
for (k = 0; k < 3; k++) {
    for (l = 0; l < 3; l++) {
        if (tablero[k][l] == ' ') empate = 0;//se recorre la matriz en busca de espacios en blanco, de no encontrar el empate pasa a ser verdadero
    }
}
if (empate) {
	printf("\t\t\t\t\t\t-*[%s (X)] VS [%s (O)]*-\n\n\n\n", jug1, mod == 1 ? jug2 : "Máquina");
    for (k = 0; k < 3; k++) {//esto es para mostrar el tablero cuando se san las condiciones del empate
        printf("\t\t\t\t\t\t\t");
        for (l = 0; l < 3; l++) {
            printf(" %c ", tablero[k][l]);
            if (l < 2) printf("|");
        }
        printf("\n");
        if (k < 2) printf("\t\t\t\t\t\t\t---|---|---\n");
    }
    printf("\n\n\t\t\t\t\t\t¡¡¡Es un empate!!!\n");
    break;
}

jugadoractual = (jugadoractual == jugadorx) ? jugadoro : jugadorx;

 /* esto se llama operador ternario ,es un tipo de condicional donde se utilizael signo "?" 
 es una forma que encontre de hacer facilmente el cambio de jugador, primeramente se coloca una condicion, lcual es si jugador actual es igual a jugadorX
es verdadero , entonces para la siguiente ronda jugador actual pasara a ser jugadorO,si es falso entonces ja ugadoractual pasare a ser jugadorX en la siguiente ronda y asi sucecivamente*/	
}

printf("\n\n\t\t\t\t\t\tDesea jugar otra partida? Si/No: ");
scanf("%s",&nueva);
}while(strcmpi(nueva,"si")==0);
printf("\n\n\t\t\t\t\t\tDesea Volver al Menu?  Si/No: ");
scanf("%s",&menu);

}while(strcmpi(menu,"si")==0);
}
		system("cls");
		
		printf("\n\n\t\t-----Cerrando programa de Juego-----\n");
		
		printf("\n\n\t\t-Muchas gracias por jugar!!!\n");

return 0;
}

