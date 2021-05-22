#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double fahrenheit;
	double celsius;
	
	printf("Please enter a fahrenheit temp> ");
	scanf("%lf", &fahrenheit);
	
	celsius = (5*(fahrenheit - 32))/9;
	
	printf("\n %f degree F is %f in C", fahrenheit, celsius );
	
	return 0;
}
