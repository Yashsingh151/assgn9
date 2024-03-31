#include<stdio.h>

struct data1 {
    int day: 5;
    int month: 4;
    int year;
};

struct data2 {
    int day: 5;
    int month: 4;
    int year;
};

int compare (struct data1 d1, struct data2 d2) {

    if((d1.year == d2.year) && (d1.month == d2.month) && (d1.day == d2.day)) {
        return 0;
    }

    if((d1.year > d2.year) || ((d1.year == d2.year) && (d1.month > d2.month)) || (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)) {
        return 1;
    }

    return -1;
}


int main() {
    struct data1 d1 = {17, 7, 2004};
    struct data2 d2 = {16, 7, 2004};

    int result = compare(d1, d2);

    printf("%d", result);
    return 0;
}