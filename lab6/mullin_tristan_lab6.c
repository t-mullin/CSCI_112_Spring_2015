#include <stdio.h>

//Tristan Mullin
//CSCI 112, Lab6
//3/19/15

//defines the length of a upc code
#define MAX_UPC_LENGTH 12

void prompt(int * upc) {
	//prompts the user to enter a code
	printf("Enter a bar code to check. Separate digits with a space >\n");
	//loop variable
	int i;
	//loops through each digit, except for the last one, and places it into the array
	for(i = 0; i < MAX_UPC_LENGTH - 1; i++) {
		scanf("%d ", &upc[i]);
	}
	//places the last digit in the array
	scanf("%d", &upc[MAX_UPC_LENGTH]);
	printf("\n");
}

int calc_odd(int upc[MAX_UPC_LENGTH]) {
	//return vairable
	int odd = 0;
	//loop variable
	int i;
	//loops through the odd contents of the array
	for(i = 0; i < MAX_UPC_LENGTH - 1; i += 2) {
		//adds the odd values into the return vairable
		odd += upc[i];	
	}
	//prints out the information of this step
	printf("STEP 1: Sum of odds times 3 is %d\n", (odd * 3));
	//returns odd * 3
	return odd * 3;
}

int calc_even(int upc[MAX_UPC_LENGTH]) {
	//return variable
	int even = 0;
	//loop vairable
	int i;
	//loops through the even contents of the array 
	for(i = 1; i < MAX_UPC_LENGTH - 1; i += 2) {
		//adds the even values into the return variable
		even += upc[i];
	}
	//prints the information for this step
	printf("STEP 2: Sum of the even digets is %d\n", even);
	//returns even
	return even;
}

int total_sum(int odd, int even) {
	//prints the information for this step 
	printf("STEP 3: Total sum is %d\n", (odd + even));
	//returns the sum of the odd and even values
	return (odd + even);
}

void check(int check, int upc) {
	//checks if the check value is the same at the last upc value
	if(check == upc) {
		//prints the information for this step
		printf("STEP 5: Check digit and last digit match\n");
		//prints that the code is valid
		printf("Barcode is VALID.\n");
	} else {
		//if the check variable is not the same as the last upc value
		//prints the information for this step
		printf("STEP 5: Check digit and last digit do not match\n");
		//prints that the code is not valid
		printf("Barcode is INVALID.\n");	
	}
}

int extract(int total, int upc) {
	//sets the check variable to the total mod 10
	int extracted_value = (total % 10);
	//if the check value is not equal to the last upc value
	if (extracted_value != upc) {
		//take 10 minus the check value 
		extracted_value = 10 - extracted_value;
		//prints the information for this step
		printf("STEP 4: Calculated check digit is %d\n", extracted_value);
		//calls the check method
		check(extracted_value, upc);
		//returns 0
		return 0;
	}	
	//prints the information for this step
	printf("STEP 4: Calculated check digit is %d\n", extracted_value);
	//calls the check method
	check(extracted_value, upc);
	//returns 0
	return 0;
}

int main(int argc, char *argv[]) {
	//array variable
	int upc[MAX_UPC_LENGTH];
	//even variable
	int even = 0;
	//odd variable
	int odd = 0;
	//total variable
	int total = 0;
	//int check_num = 0;
	prompt(upc);
	//sets odd to the result of the method call
	odd = calc_odd(upc);
	//sets even to the result of the method call
	even = calc_even(upc);
	//sets total to the result of the method call
	total = total_sum(odd, even);
	//calls the extract method
	extract(total, upc[MAX_UPC_LENGTH]);
	//returns 0
	return 0;
}
