#include<stdio.h>

struct CourseRecord {
    char name[20];
    char rollno[10];
    char department[10];
    char coursecode[10];
    int marks[3];
};

float printAvg (struct CourseRecord record) {
    int sum = 0;
    for(int i=0; i<3; i++) {
        sum += record.marks[i];
    }

    return (float)sum / 3;
}

void result (float avg) {
    if(avg > 35) {
        printf("True");
    }
    else {
        printf("False");
    }
}

int main() {
    struct CourseRecord record;

    printf("Enter the marks of student: \n");
    for(int i=0; i<3; i++) {
        scanf("%d", &record.marks[i]);
    }

    float avg = printAvg(record);

    printf("Avg marks: %.2f\n",avg);

    result(avg);

    return 0;
}