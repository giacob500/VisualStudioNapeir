#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	// Declare character arrays to store name
	char first_name[50];
	char last_name[50];
	char full_name[50];

	// Prompt for first name
	printf("Please enter your first name: ");
	// Read name into array from stdin ( standard input )
	fgets(first_name, 50, stdin);

	// Remove the newline character
	// Gets the length of the string . Finds the null terminator
	int len = strlen(first_name);
	// Check if last character is a newline
	if (len > 0 && first_name[len - 1] == '\n')
		// If so set newline character to null terminator
		first_name[len - 1] = '\0';

	// Check if your name is Brian
	if (strcmp(first_name, "Brian") == 0)
		printf("Hey! Another Brian \n");
	else
		printf("Oh well \n");
	printf("You entered %d characters \n", strlen(first_name));
	// ***** DO THE SAME FOR LAST NAME *****
	// Prompt for first name
	printf("Please enter your first name: ");
	// Read name into array from stdin ( standard input )
	fgets(last_name, 50, stdin);

	// Remove the newline character
	// Gets the length of the string . Finds the null terminator
	int lenn = strlen(last_name);
	// Check if last character is a newline
	if (lenn > 0 && last_name[lenn - 1] == '\n')
		// If so set newline character to null terminator
		last_name[lenn - 1] = '\0';

	// Check if your name is Brian
	if (strcmp(last_name, "Esposito") == 0)
		printf("Hey! Another Esposito \n");
	else
		printf("Oh well \n");
	printf("You entered %d characters \n", strlen(last_name));
	// Join the strings
	// strcat looks for null terminator . Set first character of full name
	full_name[0] = '\0';
	strcat(full_name, first_name);
	strcat(full_name, " ");
	strcat(full_name, last_name);
	printf("Your full name is %s which is %d characters long \n", full_name, strlen(full_name));
	return 0;
}