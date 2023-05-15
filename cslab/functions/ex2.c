#include <stdio.h>
#include <string.h>

struct Student 
{
    int id;
    char name[20];
    float average;
};

float getAverageByID(struct Student students[], int id) 
{
    for (int i = 0; i < 5; i++)
        if (students[i].id == id) return students[i].average;
    return -1;
}

int main() 
{
    struct Student students[5];

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter information for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Average: ");
        scanf("%f", &students[i].average);
    }

    int searchID;
    printf("Enter ID to search for average: ");
    scanf("%d", &searchID);

    float average = getAverageByID(students, searchID);

    average != -1 ?
        printf("Average for student with ID %d: %f\n", searchID, average):
        printf("Student with ID %d not found.\n", searchID);

    return 0;
}
