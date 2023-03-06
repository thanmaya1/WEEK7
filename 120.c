#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct Customer {
    char name[50];
    int ticket_num;
};

struct Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer(char* name, int ticket_num) {
    if (num_customers < MAX_CUSTOMERS) {
        strcpy(customers[num_customers].name, name);
        customers[num_customers].ticket_num = ticket_num;
        num_customers++;
        printf("Added customer\n");
    } else {
        printf("Error: maximum number of customers reached\n");
    }
}

void check_ticket(char* name, int ticket_num) {
    int i;
    for (i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].name, name) == 0 && customers[i].ticket_num == ticket_num) {
            printf("Data found, Enjoy the movie\n");
            return;
        }
    }
    printf("Ticket ID not found, re-register\n");
}

int main() {
    int option;
    char name[50];
    int ticket_num;

    do {
        scanf("%d", &option);

        switch(option) {
            case 1:
                scanf("%s %d", name, &ticket_num);
                add_customer(name, ticket_num);
                break;

            case 2:
                scanf("%s %d", name, &ticket_num);
                check_ticket(name, ticket_num);
                break;

            case 3:
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 3);

    return 0;
}
