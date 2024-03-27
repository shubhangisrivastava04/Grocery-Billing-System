#include <stdio.h>

void item_name(char item[100])
{
    printf("Enter Item Name: ");
    scanf("%s", item);  
}

int item_quantity(int *quantity)
{
    printf("Enter Quantity: ");
    scanf("%d",quantity); 
    return *quantity;
}

int item_price(float *price)
{
    printf("Enter Item Price: ");
    scanf("%f",price); 
    return *price;
}
