#include<stdio.h>
#include<string.h>

struct Student {
    char rollno[10];
    char name[50];
    char address[100];
    int age;
    float averageMarks;
};

int main() {
    struct Student student[1];

    printf("Enter details for 6 students: \n");
    for(int i=0; i<6; i++) {
        printf("\nDetails for student %d: \n", i+1);

        printf("Enter Roll No: ");
        scanf("%s", &student[i].rollno);

        printf("Enter Name: ");
        getchar();
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        printf("Enter Address: ");
        fgets(student[i].address, sizeof(student[i].address), stdin);
        student[i].address[strcspn(student[i].address, "\n")] = '\0';

        printf("Enter Age: ");
        scanf("%d", &student[i].age);

        printf("Enter Average Marks: ");
        scanf("%f", &student[i].averageMarks);
    }


    printf("Details of all 6 students: \n");
    for(int i=0; i<6; i++) {
        printf("\nDetails for student %d: \n", i+1);

        printf("Roll No: %s\n", student[i].rollno);
        printf("Name: %s\n", student[i].name);
        printf("Address: %s\n", student[i].address);
        printf("Age: %d\n", student[i].age);
        printf("Average Marks: %.2f\n", student[i].averageMarks);
    }

    return 0;

}