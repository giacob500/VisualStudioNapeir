#include "student.h"
#include <stdio.h>
#include <string.h>
//function definitions

void readname(struct student *s)
{
    printf("Please enter the name of the student\n");
    fgets((*s).name, NAME_SIZE, stdin);
    remove_new_line((*s).name);
}

void remove_new_line(char line [])
{
    int len = strlen(line);
    if(len > 0 && line[len-1] == '\n')
    {
        line[len-1] = '\0';
    }
}