#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int minV=1, maxV=100;
	int val, opcion, continuar = 1;
	
	printf("Juego de adivinanza\n");
	unsigned int seed = time(0);
	val = rand_r(&seed) % (maxV - minV + 1) + minV; // Genera el número random entre 1 y 100
	printf("El sistema eligió un número entero entre el 1 y el 100, intenta adivinarlo");

	while(continuar != 0){
		printf("\n\n0: Finalizar\n");
		printf("> ");
		scanf("%d", &opcion);

		// Fuera del rango [1;100]
		if(opcion > 100) {
			printf("Fuera de rango");
			continue;
		}

		// Finaliza el juego
		if(opcion == 0){
			continuar = 0;
			continue;
		}

		// Si el número ingresado es igual al número a adivinar
		if(opcion == val) {
			printf("Felicitaciones, encontraste el número\n");
			continuar = 0;
			continue;
		}
		
		// Si el número ingresado es mayor al número a adivinar
		if(opcion < val){
			printf("El número ingresado es más pequeño");
			continue;
		}

		// Si el número ingresado es menor al número a adivinar
		if(opcion > val) {
			printf("El número ingresado es más grande");
			continue;
		}

		// Control de errores
		printf("Error\n");
	}

	return 0;
}

