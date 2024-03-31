#include<stdio.h>
#include<string.h>

struct company {
    char name[20];
    char address[100];
    double phone;
    int noOfEmployee;
};

int main() {
    struct company comp;

    printf("Enter the name of company: ");
    fgets(comp.name, sizeof(comp.name), stdin);
    comp.name[strcspn(comp.name, "\n")] = '\0';

    printf("Enter the address: ");
    fgets(comp.address, sizeof(comp.address), stdin);
    comp.address[strcspn(comp.address, "\n")] = '\0';

    printf("Enter the phone number: ");
    scanf("%lf", &comp.phone);

    printf("Enter the no of employees: ");
    scanf("%d", &comp.noOfEmployee);

    printf("\nName: %s \nAddress: %s \nPhone number: +91 %0.0lf \nNo of Employees: %d", comp.name, comp.address, comp.phone, comp.noOfEmployee);

    return 0;
}