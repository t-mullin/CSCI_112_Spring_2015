#include <stdio.h>

#define MAX_ARRAY_SIZE 50

int populate_array(int array[]);					// Fill array with values from user
void print_array(int array[], int n);				// Print out the array values
void swap(int array[], int index1, int index2);		// Swap two array elements
void quicksort(int array[], int low, int high);		// Sorting algorithm
int partition(int array[], int low, int high);		// Find the partition point

int main(int argc, char *argv[]) {
	int array[MAX_ARRAY_SIZE];
	int n;
	n = populate_array(array);
	printf("\nThe inital array contains:\n");
	print_array(array, n);
	quicksort(array, 0, n-1);
	printf("\nThe array is now sorted:\n");
	print_array(array, n);
	return 0;
}

//asks the user for input
int populate_array(int array[]) {
	//sets n to one larger than the max for the while loop
	int n = MAX_ARRAY_SIZE + 1;
	//while n is larger than the max array size
	while(n > MAX_ARRAY_SIZE) {
		//asks the user for how many values they want to enter
		printf("Enter the value of n > ");
		//scans in each integer
		scanf("%d", &n);
		//if n that is entered by the user is greater than the max array size
		if(n > MAX_ARRAY_SIZE) {
			//prints an error message
			printf("%d exceeds the maximum array size. Please try again.\n");
		}
	}
	//asks the user to enter values
	printf("Enter %d integers (positive, negative, or zero) >\n", n);
	//for loop for scanning in integers	
	for(int i = 0; i < n; i++) {
		//scans in the integers
		scanf("%d", &array[i]);
	}
	//returns n
	return n;
}

//prints the array
void print_array(int array[], int n) {
	//loops through the array, prints and formats the contents of the array
	for(int i = 0; i < n; i++) {
		//prints and formats the array contents
		printf("%+5d\n", array[i]);
	}
}

//swaps the values in the array
void swap(int array[], int index1, int index2) {
	//temp variable to hold one of the values
	int temp = array[index1];
	//sets the value at index1 to the value at index2
	array[index1] = array[index2];
	//sets the value at index2 to the temp value
	array[index2] = temp;
}

//the quicksort method
void quicksort(int array[], int low, int high) {
	//if low is less than high
	if(low < high) {
		//pivot equals the value returned from the function call
		int pivot = partition(array, low, high);
		//recurse with the high decresing
		quicksort(array, low, pivot - 1);
		//recurse with the low increasing 
		quicksort(array, pivot+1, high);
	}
}

//method to find the pivot and swap numbers
int partition(int array[], int low, int high) {
	//sets the pivot to the value at high
	int pivot = array[high];
	//i is set to low minus 1
	int i = low - 1;
	//loop to go through the array and swaps if need be
	for(int j = low; j < high; j++) {
		//checks if the value is less than or equal to th pivot
		if(array[j] <= pivot) {
			//i is incremented by one
			i = i+1;
			//call to the swap method
			swap(array, i, j);
		}
	}
	//call to the swap method
	swap(array, i+1, high);
	//return i+1
	return i+1;
}
