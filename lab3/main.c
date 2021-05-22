#include <stdio.h>

#define TRUE 0
#define FALSE 1

int get_input() {
	int num;
	printf("Enter an odd number less than or equal to 9 > ");
	scanf("%d", &num);
	if(is_valid(num) == FALSE) {
		get_input();
	} else {
		return num;
	}
}

int is_valid(int input) {
	if (input < 1) {
		printf("You have entered a number less than 1. Please try again.\n");
		return FALSE;
	} else if(input % 2 == 0) {
		printf("You have entered an even number. please try again.\n");
		return FALSE;
	} else if (input > 9) {
		printf("You have entered a number greater than 9. Please try again.\n");
		return FALSE;
	} else {
		return TRUE;
	}	
}

void print_pattern(int num) {
	int i;
	for(i = 0; i < num; i += 2) {
		printf("%*s", num - i, "");
		int j = 0;
		
		while (j < i+1) {
			printf("%d ", j+1);
			j++;
		}
		printf("\n");
	}
	for(i = num-2; i > 0; i -= 2) {
		int j = 0;
		printf("%*s", num - i + 1, "");
		while(j < i) {
			printf("%d ", j+1);
			j++;
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int num;
	num = get_input();
	print_pattern(num);
	return 0;
}
