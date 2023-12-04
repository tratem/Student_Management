#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Subject
{
    int Lab_Exercises;
    int Test;
};


struct Student
{
    char FirstName[10];
    char LastName[20];
    int DoB;
    int ID;

    struct Subject Math, Physics, Geography;
};

void student_data(int total_students, struct Student s[])
{
    printf("ENTER STUDENT DATA: \n");
    for (int i=0; i<total_students; i++)
    {  
        printf ("[%d]: Enter First Name: ", i);
        scanf ("%9s", &s[i].FirstName);
        printf ("[%d]: Enter Last Name: ", i);
        scanf ("%19s", &s[i].LastName);
        printf ("[%d]: Enter DoB: ", i);
        scanf ("%d", &s[i].DoB);
        printf ("[%d]: Enter StudentID: ", i);
        scanf ("%d", &s[i].ID);
    }  
}

void print_student(int total_students, struct Student s[])
{
    printf("STUDENT DATA: \n");
    for (int i=0; i<total_students; i++)
    {  
        printf ("[%d]: First Name: %s \n", i, s[i].FirstName);
        printf ("[%d]: Last Name: %s \n", i,s[i].LastName);
        printf ("[%d]: DoB: %d \n", i, s[i].DoB);
        printf ("[%d]: StudentID: %d \n", i, s[i].ID);
    }
}

void grades(int total_students, struct Student s[])
{
    int id;
    char c;
    do
        {
            printf ("Please enter studentID: ");
            scanf ("%d", &id);
            for (int i=0; i<total_students; i++)
            {
                if (s[i].ID == id)
                {
                    printf("Enter data for geography: first Lab_Exercises then Test \n");
                    scanf (" %d %d", &s[i].Geography.Lab_Exercises, &s[i].Geography.Test);
                    printf("Enter data for math: first Lab_Exercises then Test \n");
                    scanf (" %d %d", &s[i].Math.Lab_Exercises, &s[i].Math.Test);
                    printf("Enter data for physics: first Lab_Exercises then Test \n");
                    scanf (" %d %d", &s[i].Physics.Lab_Exercises, &s[i].Physics.Test);
                    break;
                }
                else if(i == total_students - 1)
                {
                    printf("That studentID doesn't exist, please enter valid student ID: ");
                    scanf ("%d", &id);
                    i=-1;
                }
            }

            //check if data is going to be entered for another student
            printf("Do you want to enter grades for a another student?: [Y]es/[N]o \n");
            scanf (" %c", &c);

            while ((toupper(c)!='Y') && (toupper(c)!='N'))
            {
                printf("Invalid input! Please choose [Y]es/[N]o \n");
                scanf (" %c", &c);
            }

        } while (toupper(c)!='N');
}

int main()
{
    int total_students;
    char c;

    printf ("Enter total number of students: \n");
    scanf (" %d", &total_students);

    struct Student s[total_students];

    student_data(total_students, s);

    printf("Do you want to enter grades for a specific student?: [Y]es/[N]o \n");
    scanf (" %c", &c);

    while ((toupper(c)!='Y') && (toupper(c)!='N'))
    {
        printf("Invalid input! Please choose [Y]es/[N]o \n");
        scanf (" %c", &c);
    }

    if (toupper(c)=='Y')
    {
        grades(total_students, s);
    }

    printf("Do you want to print the data?: [Y]es/[N]o \n");
    scanf (" %c", &c);

    while ((toupper(c)!='Y') && (toupper(c)!='N'))
    {
        printf("Invalid input! Please choose [Y]es or [N]o \n");
        scanf (" %c", &c);
    }

    if (toupper(c)=='Y')
    {
        print_student(total_students, s);
    }
    
    return 0;
}