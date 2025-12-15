#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    Person person;
    int numSubjects;
    int *creditHours;    
    float perCreditFee;   
} Student;

float computeSemesterFee(Student *s, int currentSubject) {
    if (currentSubject == s->numSubjects)  // base case: all subjects processed
        return 0;

    return s->creditHours[currentSubject] * s->perCreditFee +
           computeSemesterFee(s, currentSubject + 1);
}

int main() {
    Student s;

    printf("Enter student name: ");
    scanf(" %[^\n]", s.person.name);

    printf("Enter student age: ");
    scanf("%d", &s.person.age);

    printf("Enter number of subjects: ");
    scanf("%d", &s.numSubjects);

    s.creditHours = malloc(s.numSubjects * sizeof(int));
    if (!s.creditHours) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < s.numSubjects; i++) {
        printf("Enter credit hours for subject %d: ", i + 1);
        scanf("%d", &s.creditHours[i]);
    }

    printf("Enter fee per credit hour: ");
    scanf("%f", &s.perCreditFee);

    float totalFee = computeSemesterFee(&s, 0);

    printf("\nStudent: %s\nAge: %d\nTotal Semester Fee: $%.2f\n",
           s.person.name, s.person.age, totalFee);

    free(s.creditHours);

    return 0;
}









