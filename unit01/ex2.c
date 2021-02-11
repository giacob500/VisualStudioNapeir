#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    // while loop
    while (1)
    {
        // Character array to read number into
        char name[50];
        // Prompt for value
        printf("Enter student's name (0 to quit ): ");
        // Read in value
        fgets(name, 50, stdin);
        // Gets the length of the string. Finds the null terminator
        int len = strlen(name);
        // Check if last character is a newline
        if (len > 0 && name[len - 1] == '\n')
            // If so set newline character to null terminator
            name[len - 1] = '\0';
        // If number equals 0 then set flag and continue
        if (strcmp(name, "0") == 0)
        {
            break;
        }

        int total = 0;
        int count = 0;
        while (1)
        {
            // Character array to read number into
            char grade[5];
            // Prompt for value
            printf("Enter grade (-1 to quit ): ");
            // Read in value
            fgets(grade, 50, stdin);
            // Convert string to number
            int number = atoi(grade);
            // If number equals 0 then set flag and continue
            if (number == -1)
            {
                double average = total / count;
                printf("The grades average is %.1f\n", average);
                break;
            }
            else
            {
                total += number;
                ++count;
            }
        }
    }

    return 0;
}