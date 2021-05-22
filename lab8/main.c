#include <stdio.h>
#include <stdlib.h>

/**
* Tristan Mullin
* CSCI112, Lab8
* 4/17/15
*/

//the max size for a char array
#define NAME_SIZE 25

//a student structure
typedef struct{
	//the students id number
	int sid;
	//the char array for the last name
	char last_name[NAME_SIZE];
	//the char array for the first name
	char first_name[NAME_SIZE];
	//pointer for the array of student grades
	float *grades;
	//the students gpa
	float gpa;
} student;

//function to calculate the students gpa
float calc_gpa(student s_record, int num_grades) {
	//the sum of the grades added
	float sum = 0.0;
	//loops through and adds the students grades together
	for(int i = 0; i < num_grades; i++) {
		//adds the students grades into the sum
		sum += *(s_record.grades + i);
	}
	//averages the grades by the number of grades entered
	sum = sum/num_grades;
	//returns the calculated gpa
	return sum;
}

//function for inputting the students info
student input_student_info(int num_grades) {
	//a new student struct
	student s_record;
	//informs the user to input information about a student
	printf("\nEnter information for student:\n");
	//asks for the SID
	printf("\tEnter SID:> ");
	scanf("%d", &s_record.sid);
	//asks for the last name
	printf("\tEnter last name:> ");
	scanf("%s", &s_record.last_name);
	//asks for the first name
	printf("\tEnter first name:> ");
	scanf("%s", &s_record.first_name);
	//asks for the grades
	printf("\tEnter grades (separated by space):> ");
	//allocates the memory to hold the grades array
	s_record.grades = (float *) malloc(num_grades * sizeof(float));
	//loops through each float and adds it to the grades array in the struct
	for(int i = 0; i < num_grades; i++) {
		scanf("%f", s_record.grades+i);
	}
	//calculates the students gpa
	s_record.gpa = calc_gpa(s_record, num_grades);
	//returns the student struct
	return s_record;
}

//prints the students info
void print_student(student *s_record, int num_student, int num_grades) {
	//loops through each student
	for(int i = 0; i < num_student; i++) {
		//prints the students SID
		printf("\nStudent ID #%d:", (*(s_record + i)).sid);
		//prints the students name
		printf("\n\tName: %s %s", (*(s_record + i)).first_name, (*(s_record + i)).last_name);
		//prints their grades
		printf("\n\tGrades: ");
		//loops the grades array for each of the grades
		for(int j = 0; j < num_grades; j++) {
			printf("%.1f ", *((*(s_record + i)).grades + j));
		}
		//prints the students gpa
		printf("\n\tGPA: %.2f", (*(s_record + i)).gpa);
	}	
}

//main function
int main(int argc, char *argv[]) {
	//var for the number of students
	int num_students = 0;
	//var for the number of grades
	int num_grades = 0;
	//asks for the number of students
	printf("Enter the number of students:> ");
	//scans in the user input and assigns it to a var
	scanf("%d", &num_students);
	//asks for the number of grades
	printf("Enter the number of grades to track:> ");
	//scans in the user input and assigns it to a var
	scanf("%d", &num_grades);
	//prints out the users input
	printf("\nThere are %d students.\n", num_students);
	printf("There are %d grades", num_grades);
	//allocates the memory for an array of student structures
	student *student_record = (student *) malloc(num_students * sizeof(student));
	//loops through the number of students and adds them to the student record
	for(int i = 0; i < num_students; i++) {
		*(student_record + i) = input_student_info(num_grades);
	}
	//prints the students info
	print_student(student_record, num_students, num_grades);
	//frees up the memory taken by the array of student structs
	free(student_record);
	//returns 0
	return 0;
}
