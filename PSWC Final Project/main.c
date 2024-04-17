#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Item {
    char name[100];
    int quantity;
    float price;
};

int main() {

    char name[100];
    char user_name[100];
    int number; 

    printf("Welcome!\n");
    printf("Login:\n");

    username(user_name);
    strcpy(name, user_name); 
    
    char pin[50];
    password(pin);

    number = mob_no();

    int option = 0;
    printf("Please select an Option: \n");


    struct Item *items = (struct Item *)malloc(100 * sizeof(struct Item));
    int num_items = 0;

    while (option != 3) {
        printf("1.Item Details Entry\n2.Bill all Items\n3.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &option);

        switch (option) {
            case 1: 
                printf("Please Enter Item Details:\n");
                item_name(items[num_items].name);
                items[num_items].quantity = item_quantity(&items[num_items].quantity);
                items[num_items].price = item_price(&items[num_items].price);
                num_items++; 
                break;

            case 2: 
                generate_bill(name, number, items, num_items);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Please choose a valid option.\n");
                break;
        }
    }    

    free(items);
    return 0;
}
