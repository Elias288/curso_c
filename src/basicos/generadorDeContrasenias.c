#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHARS 10

char generarCaracterAleatorio() {
	int tipo = rand() % 3;

	if(tipo == 0) {
		return 'A' + (rand() % 26);
	} else if (tipo == 1) {
		return 'a' + (rand() % 26);
	} else {
		return '0' + (rand() % 10);
	}
}

int main() {
	int largoContraseña;
	char input[20];
	int valorPorDefecto = 12;

	printf("Ingrese la cantidad de caracteres a ingresar (por defecto %d)\n> ", valorPorDefecto);
	fgets(input, sizeof(input), stdin);

	/* --- Largo de contraseña --- */
	// Detecta si se ingresó un valor, sino carga el valor por defecto
	if (input[0] == '\n') {
		largoContraseña = valorPorDefecto;
	} else {
		largoContraseña = atoi(input);
	}

	// Se definen la cadena de la contraseña y la de caracteres personalizados con el tamaño deseado
	char contraseña[largoContraseña], caracteresSeleccionados[largoContraseña];

	/* --- Caracteres --- */
	char ingresarCaracter, caracter;
	int contadorDeCaracteres = 0;
	printf("Desea ingresar caracteres que aparezcan en su contraseña? (s/n) ");
	// el espacio antes del %c evita que el scanf lea saltos de lineas o espacios por error, especialmente en el bucle while
	scanf(" %c", &ingresarCaracter);
	while(ingresarCaracter == 's' && contadorDeCaracteres < MAX_CHARS) {
		printf("Ingrese un caracter\n> ");
		scanf(" %c", &caracter);
		caracteresSeleccionados[contadorDeCaracteres++] = caracter;

		printf("Desea agregar otro cáracter? (s/n) ");
		scanf(" %c", &ingresarCaracter);
	}

	/* --- Generar contraseña --- */
	int i;
	int *posicionesUsadas = malloc(largoContraseña * sizeof(int));
	srand(time(NULL)); // inicializa la semilla
	// Carga la cadena con valores aleatorios
	for(i = 0; i < largoContraseña; i++) {
		contraseña[i] = generarCaracterAleatorio();
	}

	for(i = 0; i < contadorDeCaracteres; i++) {
		int posicionAleatoria;

		do {
			posicionAleatoria = rand() % largoContraseña; // genera una posición aleatoria en el rango de la contraseña
		} while (posicionesUsadas[posicionAleatoria] != 0); // verifica que la posición no esté ocupada

		contraseña[posicionAleatoria] = caracteresSeleccionados[i];
		posicionesUsadas[posicionAleatoria] = 1; // marca la posición como usada
	}

	/* --- Imprimir resultado --- */
	printf("\nLa contraseña generada con %d caracteres ", largoContraseña);
	// si tiene caracteres especiales los imprime
	if(contadorDeCaracteres > 0) {
		printf("incluyendo [");
		for(i = 0; i < contadorDeCaracteres; i++) {
			printf("%c", caracteresSeleccionados[i]);
		}
		printf("] ");
	}
	printf("es: \n");
	for(i = 0; i < largoContraseña; i++) {
		printf("%c", contraseña[i]);
	}
	printf("\n\n");

	return 0;
}
