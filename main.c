#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    float marks[3];
    float total;
    float average;
    char grade;
};

void calculateResults(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 3; i++) {
        s->total += s->marks[i];
    }
    s->average = s->total / 3;
    if (s->average >= 90) s->grade = 'A';
    else if (s->average >= 75) s->grade = 'B';
    else if (s->average >= 50) s->grade = 'C';
    else s->grade = 'F';
}

void displayStudent(struct Student s) {
    printf("\n-----------------------------\n");
    printf(" Name: %s\n", s.name);
    printf(" Roll No: %d\n", s.rollNo);
    printf(" Total: %.2f, Avg: %.2f, Grade: %c\n", s.total, s.average, s.grade);
    printf("-----------------------------\n");
}

int main() {
    struct Student students[2];

    for (int i = 0; i < 2; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Enter name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);
        for (int j = 0; j < 3; j++) {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
        getchar();
        calculateResults(&students[i]);
    }

    for (int i = 0; i < 2; i++) {
        displayStudent(students[i]);
    }

    return 0;
}