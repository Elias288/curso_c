#include <stdio.h>
#include <math.h>

// Para compilar es necesario agregar al comando gcc el flag -lm

void calcArea(int option) {
	int lado, largo, alto, radio;
	float res;

	switch(option) {
		case 1:
			printf("Ingrese el radio del circulo (cm)\n> ");
			scanf("%d", &radio);
			// π * r²
			res = M_PI * pow(radio, 2);
			printf("El área del circulo de radio %dcm es de: ", radio);
			break;
		case 2:
			printf("Ingrese la base del triangulo (cm)\n> ");
			scanf("%d", &largo);
			printf("Ingrese el alto del triangulo (cm)\n> ");
			scanf("%d", &alto);
			// (b * a) / 2
			res = (largo * alto) / 2;
			printf("El área del triangulo de base %dcm y alto %dcm es de: ", largo, alto);
			break;
		case 3:
			printf("Ingrese el lado del rectangulo (cm)\n> ");
			scanf("%d", &lado);
			printf("Ingrese el largo del rectangulo (cm)\n> ");
			scanf("%d", &largo);
			// l * a
			res = lado * largo;
			printf("El área del rectangulo de lado %dcm y largo %dcm es de: ", lado, largo);
			break;
		case 4:
			printf("Ingrese el lado del cuadrado (cm)\n> ");
			scanf("%d", &lado);
			// l * l
			res = lado * lado;
			printf("El área del cuadrado de lado %dcm es de: ", lado);
			break;
		default:
			printf("Error, la figura seleccionada no existe.\n");
	}

	// Resultado
	printf("%.2fcm²\n", res);

	return;
}

void calcPerimetro(int option){
	int lado, largo, alto, radio;
	float res;

	switch(option) {
		case 1:
			printf("Ingrese el radio del circulo (cm)\n> ");
			scanf("%d", &radio);
			// 2 * π * r
			res = 2 * M_PI * radio;
			printf("El perímetro del circulo de radio %dcm es de: ", radio);
			break;
		case 2:
			printf("Ingrese el primer lado del triangulo (cm)\n> ");
			scanf("%d", &lado);
			printf("Ingrese el segundo lado del triangulo (cm)\n> ");
			scanf("%d", &largo);
			printf("Ingrese el tercer lado del triangulo (cm)\n> ");
			scanf("%d", &alto);
			// l + a + t
			res = lado + largo + alto;
			printf("El perímetro del triangulo de lados %dcm %dcm %dcm es de: ", lado, largo, alto);
			break;
		case 3:
			printf("Ingrse el largo del rectangulo (cm)\n> ");
			scanf("%dd", &largo);
			printf("Ingrse el alto del rectangulo (cm)\n> ");
			scanf("%dd", &alto);
			// 2 * (l + a)
			res = 2 * (largo + alto);
			printf("El perímetro del rectangulo de largo %dcm y alto %dcm es de: ", largo, alto);
			break;
		case 4:
			printf("Ingrese el lado del cuadrado (cm)\n> ");
			scanf("%d", &lado);
			// 4 * l
			res = 4 * lado;
			printf("El perímetro del cuadrado de lado %dcm es de: ", lado);
			break;
		default:
			printf("Error, la figura seleccionada no existe.\n");
			return;
	}

	// Resultado
	printf("%.2fcm²\n", res);
	return;
}

int main() {
	int option, option2;

	printf("Seleccione la figura a calcular:\n");
	printf("1: Circulo | 2: Triángulo | 3: Rectángulo | 4: Cuadrado\n");
	printf("> ");
	scanf("%d", &option);

	printf("1: Area | 2: Perímetro\n");
	printf("> ");
	scanf("%d", &option2);

	if(option2 == 1){
		calcArea(option);
	} else if(option2 == 2){
		calcPerimetro(option);
	} else {
		printf("Error, opción de calculo erronea.\n");
		return -1;
	}

	return 0;
}
