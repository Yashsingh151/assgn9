#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Student {
    char name[50];
    int rollNumber;
    float percentage;
};

struct Student database[100];
int numRecords = 0; 

void insert(struct Student record) {
    int i = numRecords - 1;
    while (i >= 0 && database[i].rollNumber > record.rollNumber) {
        database[i + 1] = database[i];
        i--;
    }
    database[i + 1] = record;
    numRecords++;
}

void sortName() {
    struct Student temp;
    for (int i = 0; i < numRecords - 1; i++) {
        for (int j = 0; j < numRecords - i - 1; j++) {
            if (strcmp(database[j].name, database[j + 1].name) > 0) {
                temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
}

char* findOne(const char* prefix) {
    for (int i = 0; i < numRecords; i++) {
        if (strncmp(database[i].name, prefix, strlen(prefix)) == 0) {
            return database[i].name;
        }
    }
    return NULL;
}

void specs(float* result) {
    result[0] = numRecords; 

    if (numRecords == 0) {
        result[1] = 0; 
        result[2] = 0; 
        result[3] = 0; 
        result[4] = 0;
        return;
    }

    float highest = database[0].percentage;
    float lowest = database[0].percentage;
    float sum = database[0].percentage;
    for (int i = 1; i < numRecords; i++) {
        sum += database[i].percentage;
        if (database[i].percentage > highest) {
            highest = database[i].percentage;
        }
        if (database[i].percentage < lowest) {
            lowest = database[i].percentage;
        }
    }
    result[1] = highest;
    result[2] = lowest;

    result[3] = sum / numRecords;

    float variance = 0;
    for (int i = 0; i < numRecords; i++) {
        variance += pow(database[i].percentage - result[3], 2);
    }
    result[4] = sqrt(variance / numRecords - 1);
}

void deleteRecord(int rollNumber) {
    int i, j;
    for (i = 0; i < numRecords; i++) {
        if (database[i].rollNumber == rollNumber) {
            for (j = i; j < numRecords - 1; j++) {
                database[j] = database[j + 1];
            }
            numRecords--;
            printf("Record with roll number %d deleted.\n", rollNumber);
            return;
        }
    }
    printf("Record with roll number %d not found.\n", rollNumber);
}

void printDatabase() {
    printf("Student Database:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, Roll Number: %d, Percentage: %.2f\n", database[i].name, database[i].rollNumber, database[i].percentage);
    }
}

int main() {
    struct Student record1 = {"John", 101, 80.5};
    struct Student record2 = {"Alice", 102, 75.0};
    struct Student record3 = {"Bob", 103, 85.5};

    insert(record1);
    insert(record2);
    insert(record3);

    sortName();
    printf("Sorted by name:\n");
    printDatabase();

    char* foundName = findOne("Al");
    if (foundName != NULL) {
        printf("Found name starting with 'Al': %s\n", foundName);
    } else {
        printf("No name found starting with 'Al'\n");
    }

    float stats[5];
    specs(stats);
    printf("Count of records: %d\n", stats[0]);
    printf("Highest percentage: %.2f\n", stats[1]);
    printf("Lowest percentage: %.2f\n", stats[2]);
    printf("Mean: %.2f\n", stats[3]);
    printf("Standard deviation: %.2f\n", stats[4]);

    deleteRecord(102);
    printf("After deleting record with roll number 102:\n");
    printDatabase();

    return 0;
}