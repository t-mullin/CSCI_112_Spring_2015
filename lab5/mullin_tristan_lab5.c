#include <stdio.h>
#include <math.h>

// List of all function declarations ( prototypes )
// Displays user menu , reads input , and validates the input
int user_menu ();
// Equation functions are pass by reference
void equation1 (float *); // Calculate motion equation 1
void equation2 (float *); // Calculate motion equation 2
void equation3 (float *); // Calculate motion equation 3
void equation4 (float *); // Calculate motion equation 4
// User input functions return a value from user
float get_position_initial (void); // Prompts user for x0
float get_position_final (void); // Prompts user for xf
float get_velocity_initial (void); // Prompts user for v0
float get_velocity_final (void); // Prompts user for vf
float get_acceleration (void); // Prompts user for a
float get_time (void); // Prompts user for t

//main function
int main(int argc, char *argv[]) {
	// Print welcome message
	printf ("Welcome to the MOTION EQUATION CALCULATOR\n\n");
	// Variable for the user choice from menu
	int user_choice ;
	
	do{
		user_choice = user_menu (); // Print menu , validate choice is between 1 and 5
		// You will pass the address of this variable to your equation functions
		float result ; // Variable to hold calculated result
		// Handle menu choice selected by user
		switch (user_choice){
			case 1:
				//runs equation 1
				equation1(&result);
				break;
			case 2:
				//runs equation 2
				equation2(&result);
				break;
			case 3:
				//runs equation 3
				equation3(&result);
				break;
			case 4:
				//runs equation 4
				equation4(&result);
				break;
			case 5:
			// Exit program if user selects QUIT
			printf ("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
			return 0;
			break ;
		}
		// Print out the calculated result with four digits after the decimal point
		printf ("Your result is %.4f.\n\n", result);
	} while (user_choice !=5); // Repeat until user chooses QUIT
	return 0; // Return without error
}

//prompts the user for what equation they want to do
int user_menu() {
	//input variable
	int input;
	//displayes the prompt
	printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
	//scans in the input
	scanf("%d", &input);
	//checks to see if the input is in the right range
	if(input < 1 || input > 5) {
		//error message
		printf("Invalid option. Please try again.\n\n");
		//recalls the function
		user_menu();
	} else {
		//if the input is in the range, it is returned
		return input;
	}
}

//function for equation one
void equation1(float * velocity_final) {
	//sets v0 to the result of the function
	float v0 = get_velocity_initial();
	//sets a to the result of the function
	float a = get_acceleration();
	//sets t to the result of the function
	float t = get_time();
	//sets the value to the result of the formula
	*velocity_final = v0 + a * t;
}

//function for equation two
void equation2(float * position_final) {
	//sets x0 to the result of the function
	float x0 = get_position_initial();
	//sets v0 to the result of the function
	float v0 = get_velocity_initial();
	//sets t to the result of the function
	float t = get_time();
	//sets a to the result of the function
	float a = get_acceleration();
	//sets the value to the result of the formula
	*position_final = x0 + v0 * t + (1.0/2.0) * a * (powf(t, 2));
}

//function for equation three
void equation3(float * velocity_final) {
	//sets v0 to the result of the function
	float v0 = get_velocity_initial();
	//sets a to the result of the function
	float a = get_acceleration();
	//sets xf to the result of the function
	float xf = get_position_final();
	//sets x0 to the result of the function
	float x0 = get_position_initial();
	//sets the value to the result of the formula
	*velocity_final = sqrt(powf(v0, 2) + 2 * a * (xf - x0));
}

//function for equation four
void equation4(float * position_final) {
	//sets x0 to the result of the function
	float x0 = get_position_initial();
	//sets vf to the result of the function
	float vf = get_velocity_final();
	//sets v0 to the result of the function
	float v0 = get_velocity_initial();
	//sets t to the result of the function
	float t = get_time();
	//sets the value to the result of the formula
	*position_final = x0 + (1.0/2.0) * (vf + v0) * t;
}

//function for the initial position
float get_position_initial(){
	float x0;
	//promts the user for the value
	printf("\tEnter initial position > ");
	//scans in the value and sets the value
	scanf("%f", &x0);
	//returns the inputed value
	return x0;
}

float get_position_final() {
	float xf;
	//promts the user for the value
	printf("\tEnter final position > ");
	//scans in the value and sets the value
	scanf("%f", &xf);
	//returns the inputed value
	return xf;
}

float get_velocity_initial() {
	float v0;
	//promts the user for the value
	printf("\tEnter initial velocity > ");
	//scans in the value and sets the value
	scanf("%f", &v0);
	//returns the inputed value
	return v0;
}

float get_velocity_final() {
	float vf;
	//promts the user for the value
	printf("\tEnter final velocity > ");
	//scans in the value and sets the value
	scanf("%f", &vf);
	//returns the inputed value
	return vf;
}
float get_acceleration() {
	float a;
	//promts the user for the value
	printf("\tEnter acceleration > ");
	//scans in the value and sets the value
	scanf("%f", &a);
	//returns the inputed value
	return a;
}
float get_time() {
	float t;
	//promts the user for the value
	printf("\tEnter time > ");
	//scans in the value and sets the value
	scanf("%f", &t);
	//returns the inputed value
	return t;
}
