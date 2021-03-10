#pragma once
#define NAME_SIZE 100

struct student 
{
    char name [NAME_SIZE];
    int matric;
};

//function prototypes
void readname(struct student*);
void remove_new_line(char []);