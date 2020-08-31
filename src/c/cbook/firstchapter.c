#include <stdio.h>

int main()
{
	/* Fahreneit to Celcius Converter */
	float fahr, celc;
	int lower, upper, step;
	/* celc = 5 / 9 * (fahr - 32) */
	lower = 0;
	upper = 300;
	step = 20;
	while(fahr <= upper) {
		celc = 5.0 / 9.0 * (fahr - 32.0);
		printf("Celcius: %f -- Fahreneit: %f \n", celc, fahr);
		fahr = fahr + step;
	}
}