#include <stdio.h>

int calculo(int val1, int operador, int val2) {
	int res;
	char operadorChar;
	switch (operador) {
		case 1: 
			res = val1 + val2;
			operadorChar = '+';
			break;
		case 2: 
			res = val1 - val2;
			operadorChar = '-';
			break;
		case 3: 
			res = val1 * val2;
			operadorChar = '*';
			break;
		case 4: 
			res = val1 / val2;
			operadorChar = '/';
			break;
		default:
			printf("error\n");
			return -1;
	}

	printf("%d %c %d ", val1, operadorChar, val2);
	printf("= %d\n", res);
	return res;
}

int main () {
	int val1, val2, operador, res;

	printf("valor 1: ");
	scanf("%d", &val1);

	printf("1: suma | 2: resta | 3: multiplicación | 4: división\n");
	printf("Selecciona operador: ");
	scanf("%d", &operador);


	printf("valor 2: ");
	scanf("%d", &val2);

	res = calculo(val1, operador, val2);

	return 0;
}

