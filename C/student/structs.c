#include <stdio.h>
#include "student.h"

int main()
{
    struct student s;
    readname(&s);
    printf("The student's name is: %s\n", s.name);
    return 0;
}