#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define LOOP_LIMIT 90

typedef enum MENU {
	Sine,
	Cosine,
	Tangent,
	QUIT
} menu_t;

void get_sin() {
	int i = 0;
	double r;
	while (i <= LOOP_LIMIT) {
		r = sin((PI * i)/180);
		printf("\tsin(%d) = %lf\n", i, r);
		i += 15;
	}
	printf("\n");
}

void get_cos() {
	int i = 0;
	double r;
	while (i <= LOOP_LIMIT) {
		r = cos((PI * i)/180);
		printf("\tcos(%d) = %.4lf\n", i, r);
		i += 15;
	}
	printf("\n");
}

void get_tan() {
	int i = 0;
	double r;
	while (i <= LOOP_LIMIT) {
		if(i == 90) {
			printf("\ttan(%d) = UNDEFINED\n", i);
		} else {
			r = tan((PI * i)/180);
			printf("\ttan(%d) = %lf\n", i, r);
		}
		i += 15;
	}
	printf("\n");
}

void get_input() {
	
	menu_t input;
	while(input != QUIT) {
		printf("Please choose an option:  (0) Sine (1) Cosine (2) Tangent (3)QUIT\n");
		printf("Enter your choice > ");
		scanf("%d", &input);
	
		switch (input) {
			case Sine:
				get_sin();
				break;
			case Cosine:
				get_cos();
				break;
			case Tangent:
				get_tan();
				break;
			case QUIT:
				printf("You chose QUIT. Thank you, come again!");
				break;
			default:
				printf("%d is an invalid option. Please try again.\n\n", input);
				break;
		}
	}
}

int main(int argc, char *argv[]) {
	get_input();
	return 0;
}
