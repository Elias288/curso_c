#include <stdio.h>
#include <string.h>

#define CELCIUS 273.15
#define KELVIN 459.67
#define FAHRENHEIT 32

// IMPRIME EL CONTENIDO DE LA LISTA
void printList(char *arr[], int size, int ignoreIndex){
	for(int i = 0; i < size; i++){
		if(i != ignoreIndex-1) {
			printf("%d: %s | ", i+1, arr[i]);
		}
	}
}

// CONVERSOR DE TEMPERATURAS
float temperatura() {
	char *arr[] = {
		"Celsius",		// C
		"Fahrenheit",	// F
		"Kelvin"			// K
	}; // 1: Celsius | 2: Fahrenheit | 3: Kelvin
	int unidad1, unidad2,
			arrSize = sizeof(arr) / sizeof(arr[0]);
	float value, res;
	char letraUnidad1, letraUnidad2; // se usan para determinar la unidad que se va a imprimir del valor 1 y el valor 2

	printList(arr, arrSize, -1); 
	printf("\nIngresa la unidad del valor a convertir: ");
	scanf("%d", &unidad1);

	printf("Ingresa el valor a convertir:\n> ");
	scanf("%f", &value);

	printList(arr, arrSize, unidad1);
	printf("\nIngresa la unidad a la que se desea convertir: ");
	scanf("%d", &unidad2);

	/*
	 * 1 Celsius			-> 2 Fahrenheit 	= x * 9/5 + 32
	 * 1 Celsius 			-> 3 Kelvin 			= x + 273,15
	 * 2 Fahrenheit 	-> 1 Celsius 			= (x - 32) * 5 / 9
	 * 2 Fahrenheit 	-> 3 Kelvin 			= (x + 459,67) * 5/9
	 * 3 Kelvin				-> 1 Celsius			= x - 273,15
	 * 3 Kelvin				-> 2 Fahrenheit		= x * 9/5 - 459,67
	 */
	if(unidad1 == 1 && unidad2 == 2) {
		letraUnidad1 = 'C';
		letraUnidad2 = 'F';
		printf("Celsius a Fahrenheit\n");
		res = value * 9/5 + FAHRENHEIT;
	} else if(unidad1 == 1 && unidad2 == 3) {
		letraUnidad1 = 'C';
		letraUnidad2 = 'K';
		printf("Celsius a Kelvin\n");
		res = value + CELCIUS;
	} else if(unidad1 == 2 && unidad2 == 1) {
		letraUnidad1 = 'F';
		letraUnidad2 = 'C';
		printf("Fahrenheit a Celsius\n");
		res = (value - FAHRENHEIT) * 5/9;
	} else if(unidad1 == 2 && unidad2 == 3) {
		letraUnidad1 = 'F';
		letraUnidad2 = 'K';
		printf("Fahrenheit a Kelvin\n");
		res = (value - KELVIN) * 5/9;
	} else if(unidad1 == 3 && unidad2 == 1) {
		letraUnidad1 = 'K';
		letraUnidad2 = 'C';
		printf("Kelvin a Celsius\n");
		res = value-CELCIUS;
	} else if(unidad1 == 3 && unidad2 == 2) {
		letraUnidad1 = 'K';
		letraUnidad2 = 'F';
		printf("Kelvin a Fahrenheit\n");
		res = value * 9/5 - KELVIN;
	} else {
		printf("error\n\n");
		return -1;
	}

	printf("%.2f°%c --> %.2f°%c\n\n", value, letraUnidad1, res, letraUnidad2);
	return res;
}

// CONVERSOR DE DISTANCIAS
float distancia() {
	char *arr[] = {
		"centimetros", 	// cm
		"metros",				// m
		"kilometros"		// km
	}; // 1: centimetros | 2: metros | 3: kilometros 
	int unidad1, unidad2,
			arrSize = sizeof(arr) / sizeof(arr[0]);
	float value, res;
	char letraUnidad1[3], letraUnidad2[3]; // se usan para determinar la unidad que se va a imprimir del valor 1 y el valor 2

	printList(arr, arrSize, -1); 
	printf("\nIngresa la unidad del valor a convertir: ");
	scanf("%d", &unidad1);

	printf("Ingresa el valor a convertir:\n> ");
	scanf("%f", &value);

	printList(arr, arrSize, unidad1);
	printf("\nIngresa la unidad a la que se desea convertir: ");
	scanf("%d", &unidad2);

	/*
	 * 1 centimetros	-> 2 metros				= x/100 
	 * 1 centimetros	-> 3 kilometros		= x/100000
	 * 2 metros				-> 1 centimetros	= x*100
	 * 2 metros				-> 3 kilometros		= x/1000
	 * 3 kilometros		-> 1 centimetros	= x*100000
	 * 3 kilometros		-> 2 metros				=	x*1000
	 */
	if(unidad1 == 1 && unidad2 == 2){
		strcpy(letraUnidad1, "cm");
		strcpy(letraUnidad2, "m");
		printf("Centimetros a Metros\n");
		res = value / 100;
	}else if(unidad1 == 1 && unidad2 == 3){
		strcpy(letraUnidad1, "cm");
		strcpy(letraUnidad2, "km");
		printf("Centimetros a Kilometros\n");
		res = value / 100000;
	}else if(unidad1 == 2 && unidad2 == 1){
		strcpy(letraUnidad1, "m");
		strcpy(letraUnidad2, "cm");
		printf("Metros a Centimetros\n");
		res = value * 100;
	}else if(unidad1 == 2 && unidad2 == 3){
		strcpy(letraUnidad1, "m");
		strcpy(letraUnidad2, "km");
		printf("Metros a Kilometros\n");
		res = value / 1000;
	}else if(unidad1 == 3 && unidad2 == 1){
		strcpy(letraUnidad1, "km");
		strcpy(letraUnidad2, "cm");
		printf("Kilometros a Centimetros\n");
		res = value * 100000;
	}else if(unidad1 == 3 && unidad2 == 2){
		strcpy(letraUnidad1, "km");
		strcpy(letraUnidad2, "m");
		printf("Kilometros a Metros\n");
		res = value * 1000;
	}else{
		printf("error\n\n");
		return -1;
	}

	printf("%.2f%s --> %.2f%s\n\n", value, letraUnidad1, res, letraUnidad2);

	return 0;
}

// MAIN
int main() {
	int menu, continuar=1;
	float res;

	while(continuar != 0){
		printf("Elegir la unidad a la que se quiere convertir:\n1: Temperatura\n2: Distancia\n0: Salir\n> ");
		scanf("%d", &menu);
		switch(menu) {
			case 0:
				continuar = 0;
				break;
			case 1:
				res = temperatura();
				break;
			case 2:
				res = distancia();
				break;
			default:
				printf("error\n\n");
				return -1;
		}
	}

	return 0;
}
