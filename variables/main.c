#include <stdio.h>

/*
 * Tipos de variables:
 * int numero = 10;
 * float decimal = 3.14;
 * char letra = 'A';
 */

int main() {
	int edad;
	printf("Introduce tu edad: ");
	scanf("%d", &edad);
	printf("Tu edad es %d\n", edad);

	int mitad = edad / 2;
	printf("La mitad de tu edad es %d\n", mitad);


	return 0;
}

