#include <stdio.h>

void generate_bill(char customer_name[], int customer_mob, char item_names[][100], int item_quantities[], float item_prices[], int num_items)
 {
    int i;
    float total = 0;

    printf("Generating bill...\n\n");

    printf("-----------------------------------------\n");
    printf("\t\t  BILL\t\n");

    printf("-----------------------------------------\n");
    printf("Customer Name: %s\nMobile No.: %d\n", customer_name, customer_mob);
    printf("-----------------------------------------\n");

    printf("Item\tQuantity\tPrice\tItem Total\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < num_items; i++)
    {
        total += item_quantities[i] * item_prices[i];
        float item_total=item_quantities[i] * item_prices[i];
        printf("%s\t%d\t\t%.2f\t%.2f\n", item_names[i], item_quantities[i], item_prices[i],item_total);  
    }

    printf("-----------------------------------------\n");

    printf("Total Price: %.2f\t\tGST: 18%%\n\n", total);

    total=total+(total*0.18);

    printf("Total with GST: %.2f\n",total);
    printf("-----------------------------------------\n");

}

