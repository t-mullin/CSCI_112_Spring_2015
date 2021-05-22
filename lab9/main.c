#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defines a max size for char arrays
#define LINE_SIZE 100

//the delim for sectioning the strings
const char delim[2] = ",";


void merge_files(FILE *, FILE *, FILE *);	//function prototype for the merge files function
void find_elements(char[]);		//function prototype for the find elements function
void verify_files(FILE *);	//function prototype for the verify file function 

//main function
int main(int argc, char *argv[]) {
	//pointers to a file, initially null
	FILE *inp1;
	FILE *inp2;
	FILE *outp;
	
	//opens the files that will be worked with
	inp1 = fopen("elements_file1.csv", "r");
	inp2 = fopen("elements_file2.csv", "r"); 
	outp = fopen("elements.csv", "w");
	
	//checks if there is a problem opening the files
	verify_files(inp1);
	verify_files(inp2);
	verify_files(outp);
	
	//function call to the merge_files function
	merge_files(inp1, inp2, outp);
	
	//closes the files 
	fclose(inp1);
	fclose(inp2);
	fclose(outp);
	
	//loops through the commandline aruguments 
	for(int i = 1; i < argc; i++) {
		//function call to the find_elements function with a value from the commmand line
		find_elements(argv[i]);
		//prints a new line
		printf("\n");
	}
	//returns 0
	return 0;
}

//merge files function
void merge_files(FILE *inp1, FILE *inp2, FILE *outp) {
	//new char arrays
	char curr_line_f1[LINE_SIZE];
	char curr_line_f2[LINE_SIZE];
	char cpy_f1[LINE_SIZE];
	char cpy_f2[LINE_SIZE];
	
	//gets the first lines from the two files that are being merged
	fgets(curr_line_f1, LINE_SIZE, inp1); 
	fgets(curr_line_f2, LINE_SIZE, inp2); 
	
	//makes a copy of the lines 
	strcpy(cpy_f1, curr_line_f1);
	strcpy(cpy_f2, curr_line_f2);
	
	//loops until one of the files is "empty"
	while(!feof(inp1) && !feof(inp2)) {
		//new tolken that is set to the first string before the delim
		char *tolkf1 = strtok(curr_line_f1, delim);
		char *tolkf2 = strtok(curr_line_f2, delim);
		//converts the tolken into a int value
		int atn1 = atoi(tolkf1);
		int atn2 = atoi(tolkf2);
		//checks if atn1 is less than atn2
		if(atn1 < atn2) {
			//output to file
			fprintf(outp, "%s", cpy_f1);
			//sets the current line to the null terminator
			*curr_line_f1 = '\0';
			//gets the next line
			fgets(curr_line_f1, LINE_SIZE, inp1);
			//makes a copy of the line
			strcpy(cpy_f1, curr_line_f1);
		} else {
			//output to file
			fprintf(outp, "%s", cpy_f2);
			//sets the current line to the null terminator
			*curr_line_f2 = '\0';
			//gets the next line
			fgets(curr_line_f2, LINE_SIZE, inp2);
			//makes a copy of the line
			strcpy(cpy_f2, curr_line_f2);
		}
	}
	//checks if file 2 reached the end of file
	if(feof(inp2)) {
		//loops until file 1 is at the end of file
		while(!feof(inp1)) {
			//output to file
			fprintf(outp, "%s", cpy_f1);
			//sets the current line to the null terminator
			*curr_line_f1 = '\0';
			//gets the next line
			fgets(curr_line_f1, LINE_SIZE, inp1);
			//makes a copy of the line
			strcpy(cpy_f1, curr_line_f1);		
		}
	} else {
		//loops until file 2 is at the end of file
		while(!feof(inp2)) {
			//output to file
			fprintf(outp, "%s", cpy_f2);
			//sets the current line to the null terminator
			*curr_line_f2 = '\0';
			//gets the next line
			fgets(curr_line_f2, LINE_SIZE, inp2);
			//makes a copy of the line
			strcpy(cpy_f2, curr_line_f2);
		}
	}
	//prints that the merge was successful
	printf("File merging complete.\n\n");
} 

//find elements function
void find_elements(char arg[]) {
	//new file pointer
	FILE *inp;
	//new char arrays
	char curr_line[LINE_SIZE];
	char cpy[LINE_SIZE];
	
	//opens the file
	inp = fopen("elements.csv", "r");
	//verifys the file
	verify_files(inp);
	
	//gets the files first line
	fgets(curr_line, LINE_SIZE, inp);
	
	//loops until the file reached end of file
	while(!feof(inp)) {
		//checks if the current line is null
		if(curr_line == NULL) {
			//skips the current itteration of the loop
			continue;
		} else {
			//makes a copy of the current line
			strcpy(cpy, curr_line);
			//string to hold the atomic number
			char *atomic_number = strtok(curr_line, delim);
			//string to hold the atomic weight
			char *atomic_weight = strtok(NULL, delim);
			//string to hold the element name
			char *element_name = strtok(NULL, delim);
			//string to hold the element symbol
			char *element_symbol = strtok(NULL, delim);
			//string to hold the year discovered
			char *year_discovered = strtok(NULL, delim);
			//string to hold the elements category
			char *element_category = strtok(NULL, delim);
			
			//checks if the arg matchs the elements symbol
			if(strcmp(arg, element_symbol) == 0) {
				//prints the elements name
				printf("Element: %s\n", element_name);
				//prints the elements symbol
				printf(" Symbol: %s\n", element_symbol);
				//prints the elements number
				printf(" Atomic Number: %s\n", atomic_number);
				//prints the elements weight
				printf(" Atomic Weight: %s\n", atomic_weight);
				//checks if the year discovered is not ancient
				if(strcmp(year_discovered, "ancient") != 0) {
					//prints the year discovered
					printf(" Discovered in: %s\n", year_discovered);
				}
			}
		}
		//gets the next line
		fgets(curr_line, LINE_SIZE, inp);
	}
	//closes the file
	fclose(inp);
}

//verify the files function
void verify_files(FILE *fptr) {
	//checks if the pointer is null
	if(fptr == NULL) {
		//prints that an error occured
		printf("Error loading file.");
		//exits the program
		exit(1);
	}
}
