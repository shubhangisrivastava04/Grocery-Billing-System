#include <stdio.h>

struct Item
{
    char name[100];
    int quantity;
    float price;
};

void generate_bill(char customer_name[], char customer_mob[10], struct Item items[], int num_items)
{
    int i;
    float total = 0;

    printf("Generating bill...\n\n");

    printf("-----------------------------------------\n");
    printf("\t\t  BILL\t\n");

    printf("-----------------------------------------\n");
    printf("Customer Name: %s\nMobile No.: %s\n", customer_name, customer_mob);
    printf("-----------------------------------------\n");

    printf("Item\tQuantity\tPrice\tItem Total\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < num_items; i++)
    {
        total += items[i].quantity * items[i].price;
        float item_total=items[i].quantity * items[i].price;
        printf("%s\t%d\t\t%.2f\t%.2f\n", items[i].name, items[i].quantity, items[i].price, item_total);  
    }

    printf("-----------------------------------------\n");

    printf("Total Price: %.2f\t\tGST: 18%%\n\n", total);

    total=total+(total*0.18);

    printf("Total with GST: %.2f\n",total);
    printf("-----------------------------------------\n\n");

}
