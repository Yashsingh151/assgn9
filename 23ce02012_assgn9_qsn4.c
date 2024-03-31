#include<stdio.h>
#include<string.h>

struct Address {
    char street[100];
    char city[50];
    int zipcode;
};

struct Person {
    char name[20];
    struct Address address;
};

int main() {
    struct Person person;

    printf("Enter name: ");
    fgets(person.name, sizeof(person.name), stdin);
    person.name[strcspn(person.name, "\n")] = '\0';

    printf("Enter street: ");
    fgets(person.address.street, sizeof(person.address.street), stdin);
    person.address.street[strcspn(person.address.street, "\n")] = '\0';

    printf("Enter city: ");
    fgets(person.address.city, sizeof(person.address.city), stdin);
    person.address.city[strcspn(person.address.city, "\n")] = '\0';

    printf("Enter zipcode: ");
    scanf("%d", &person.address.zipcode);

    printf("\nPerson Details: \n");
    printf("Name: %s\n", person.name);
    printf("Street: %s\n", person.address.street);
    printf("City: %s\n", person.address.city);
    printf("Zipcode: %d\n", person.address.zipcode);

    return 0;

}