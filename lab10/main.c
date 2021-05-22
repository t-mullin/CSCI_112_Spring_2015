#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defines the max size for a string
#define MAX_SIZE 100

//node struct
typedef struct node_p{
	//string for the title
	char title[MAX_SIZE];
	//string for the publisher
	char publisher[MAX_SIZE];
	//string for the developer
	char developer[MAX_SIZE];
	//var for the year released
	int year_released;
	//var for the number of platforms
	int num_platforms;
	//char pointer for an array
	char *platforms;
	//pointer to the next node
	struct node_p *next;
} node;

//global variables
//node pointer to the head
node *head = NULL;
//delim used for correct formatting
const char delim[2] = "\n";

//function for hard coding a linked list
void populate_record();
//function for the user menu
void menu();
//function for finding a title
void search_record();
//function to search the linked list
node * search(char []);
//helper function for adding a node
void add_record();
//function to add a node into the linked list
void add(node *);
//helper function for removing a node
void remove_record();
//function to remove a node in the linked list
void remove_node(char []);
//prints the linked list
void print_database();

//main function
int main(int argc, char *argv[]) {
	//function call the populate_record function
	populate_record();
	//function call to the menu function
	menu();
	free(head);
	return 0;
}

//populate_record function
void populate_record() {
	//new node pointers
	node *n1, *n2, *n3, *n4, *n5;
	//allocates memory for the head pointer
	head = (node *) malloc (sizeof(node));
	
	//allocates memory and populates a node
	n1 = (node *) malloc(sizeof(node));
	strcpy(n1->title, "Assassin's Creed");
	strcpy(n1->publisher, "Ubisoft");
	strcpy(n1->developer, "Ubisoft");
	n1->year_released = 2007;
	n1->num_platforms = 3;
	n1->platforms = (char *) malloc(n1->num_platforms * sizeof(char[MAX_SIZE]));
	n1->platforms = "ps3 xbox360 pc";
	
	//sets the head pointer to point to n1
	head->next = n1;
	
	//allocates memory and populates a node
	n2 = (node *) malloc(sizeof(node));
	strcpy(n2->title, "Call of Duty: Modern Warfare");
	strcpy(n2->publisher, "Activison");
	strcpy(n2->developer, "Infinity Ward");
	n2->year_released = 2007;
	n2->num_platforms = 3;
	n2->platforms = (char *) malloc(n2->num_platforms * sizeof(char[MAX_SIZE]));
	n2->platforms = "ps3 xbox360 pc";
	//allocates memory for the next pointer and sets it to the next node
	(n1->next) = (node *) malloc(sizeof(n2));
	n1->next = n2;
	
	//allocates memory and populates a node
	n3 = (node *) malloc(sizeof(node));
	strcpy(n3->title, "Counter Strike: GO");
	strcpy(n3->publisher, "Valve");
	strcpy(n3->developer, "Valve");
	n3->year_released = 2012;
	n3->num_platforms = 3;
	n3->platforms = (char*) malloc(n3->num_platforms * sizeof(char[MAX_SIZE]));
	n3->platforms = "ps3 xbox360 pc";
	//allocates memory for the next pointer and sets it to the next node
	(n2->next) = (node *) malloc(sizeof(node));
	n2->next = n3;
	
	//allocates memory and populates a node
	n4 = (node *) malloc(sizeof(node));	
	strcpy(n4->title, "Destiny");
	strcpy(n4->publisher, "Activision");
	strcpy(n4->developer, "Bungie");
	n4->year_released = 2014;
	n4->num_platforms = 4;
	n4->platforms = (char*) malloc(n4->num_platforms * sizeof(char[MAX_SIZE]));
	n4->platforms = "ps3 ps4 xbox360 xbox1";
	//allocates memory for the next pointer and sets it to the next node
	(n3->next) = (node *) malloc(sizeof(n4));
	n3->next = n4;

	//allocates memory and populates a node
	n5 = (node *) malloc(sizeof(node));
	strcpy(n5->title, "Final Fantasy VII");
	strcpy(n5->publisher, "PlayStation");
	strcpy(n5->developer, "Square");
	n5->year_released = 1997;
	n5->num_platforms = 4;
	n5->platforms = (char*) malloc(n5->num_platforms * sizeof(char[MAX_SIZE]));
	n5->platforms = "ps3 ps4 pc";
	//allocates memory for the next pointer and sets it to the next node
	(n4->next) = (node *) malloc(sizeof(n5));
	n4->next = n5;
	n5->next = NULL;	
}

//menu function
void menu() {
	int choice = 0;
	printf("\nWelcome to the video game database.\n\n");
	//loops until the user enter a 5
	while(choice != 5) {
		//flushes the input buffer
		fflush(stdin);
		//prints the list of options
		printf("Please select and option. (1-5)\n");
		printf("\t1. Search for a videogame\n");
		printf("\t2. Add a videogame to the database.\n");
		printf("\t3. Remove a videogame from the database.\n");
		printf("\t4. Print the database\n");
		printf("\t5. Exit\n");
		printf("Your choice > ");
		scanf("%d", &choice);
		
		//switch statement for calling the right function
		switch(choice) {
			case 1:
				//call the search method
				search_record();
				break;
			case 2:
				//calls the add_record function
				printf("\nAdding a title to the database. (Case matters)\n");
				add_record();
				break;
			case 3:
				//calls the remove_record function
				printf("\nRemoving a title from the database.\n");
				remove_record();
				break;
			case 4:
				//calls the print_database function
				printf("\nPrinting the database.\n");
				print_database();
				break;
			case 5:
				//thanks the user for using the program
				printf("\nThank you for using the videogame database, have a good day.\n");
				break;
			default:
				//makes sure that the user enters the correct value
				printf("\nPlease enter a value between 1 and 5\n"); 	
		}
	}
}

//search_record function
void search_record() {
	//flushes the input buffer
	fflush(stdin);
	//string to contain the user input
	char title[MAX_SIZE];
	//new node
	node *result;
	printf("\nPlease enter the title of the game you're looking for. (Case matters)> ");
	fgets(title, MAX_SIZE, stdin);
	//sets the node to the value from the search method
	result = search(title);

	//checks if the next title matches the users input
	if(strcmp(result->next->title, strtok(title, delim)) == 0) {
		//prints the structs contents
		printf("\n\tGame's title: %s\n", result->next->title);
		printf("\tGame's publisher: %s\n", result->next->publisher);
		printf("\tGame's developer: %s\n", result->next->developer);
		printf("\tYear of release: %d\n", result->next->year_released);
		printf("\tPlatforms available on: %s\n\n", result->next->platforms);
	} else {
		//prints that the title was not found
		printf("%d was not found.\n", strtok(title, delim));
	}
}

//search function
node * search(char title[]) {
	//this will iterate through the list and find the title
	//sets the pointers for itterating through the list
	node *prev = head;
	node *current = prev->next;
	
	//checks if current is null and if current title is less than the title inputed from the users
	while((current != NULL) && (strcmp(current->title, strtok(title, delim )) < 0)) {	
		//moves the pointers over by one node
		prev = current;
		current = current->next;
	}
	return prev;
}

void add_record() {
	//flushes the input buffer
	fflush(stdin);
	//new node
	node *n_record;
	//allocates memory for the new node then asks the user to input each field
	n_record = (node *) malloc(sizeof(node));
	printf("\tPlease enter the game's title. > ");
	fgets(n_record->title, MAX_SIZE, stdin);
	printf("\tPlease enter the publisher. > ");
	fgets(n_record->publisher, MAX_SIZE, stdin);
	printf("\tPlease enter the developer. > ");
	fgets(n_record->developer, MAX_SIZE, stdin);
	printf("\tPlease enter the year that the game was released. > ");
	scanf("%d", &n_record->year_released);
	printf("\tHow many platforms was the game released on? > ");
	scanf("%d", &n_record->num_platforms);
	printf("\tPlease enter the platforms (seperated by a space). > ");
	//flushes the input buffer
	fflush(stdin);
	n_record->platforms = (char *) malloc(n_record->num_platforms * sizeof(char[MAX_SIZE]));
	fgets(n_record->platforms, MAX_SIZE, stdin);
	add(n_record);
	printf("\n");
}

void add(node *new_node) {
	//pointers for itterating through the list
	node *current = search(new_node->title);
	node *next_node = current->next;
	
	//checks if current is null or if the titles are not the same
	if((next_node == NULL) || (strcmp(next_node->title, strtok(new_node->title, delim)) != 0)) {
		//places the new node into the linked list
		current->next = new_node;
		new_node->next = next_node;
		//prints that the node was added
		printf("\t%s was added to the database.\n", strtok(new_node->title, delim));	
	} else {
		//prints that the title exists in the list
		printf("\t%s already exists in the database.\n", strtok(new_node->title, delim));
		//frees the memory
		free(new_node);
	}
}

//remove_record function
void remove_record() {
	//flushes the input buffer
	fflush(stdin);
	char title[MAX_SIZE];
	printf("\tPlease enter the title that you want to remove. (Case matters)> ");
	fgets(title, MAX_SIZE, stdin);
	//calls the remove node function
	remove_node(title);
}

//remove_node function
void remove_node(char title[]) {
	//pointers for itterating through the list
	node *current = search(title);
	node *next_node = current->next;
	
	//checks if the next node is null and if the next nodes title matches the users input
	if((next_node != NULL) && (strcmp(next_node->title, strtok(title, delim)) == 0)) {
		//moves the current nodes pointer to the next nodes pointer
		current->next = next_node->next;
		//prints that the node was removed
		printf("\t%s was removed.\n\n", next_node->title);
		//frees the memory
		free(next_node);
	} else {
		//prints that the title was not found
		printf("\t%s was not found.\n\n", strtok(title, delim));
	}
}

void print_database() {
	//pointer for itterating through the list
	node *current = head->next;
	
	//while current is not null prints the contents of the list
	while(current != NULL) {
		printf("\tGame's title: %s\n", strtok(current->title, delim));
		printf("\tGame's publisher: %s\n", strtok(current->publisher, delim));
		printf("\tGame's developer: %s\n", strtok(current->developer, delim));
		printf("\tYear of release: %d\n", current->year_released);
		printf("\tPlatforms available on: %s\n\n", strtok(current->platforms, delim));
		current = current->next;
	}
}
