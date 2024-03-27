#include <stdio.h>

int main()
{
    printf("Welcome!\n");
    printf("Please enter Customer Details:\n");

    char name[100];
    int number;
    
    customer_entry(name); 
    number=mob_no();
    

    int option=0;
    printf("Please Enter Item Details:\n");
    
    char itname[100][100];
    int itqty[100];
    float itprice[100];
    int num_items=0;

    while(option!=3)
    {
        printf("1.Item Details Entry\n2.Bill all Items\n3.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&option);

        switch (option)
        {
            case 1: 
            
            item_name(itname[num_items]);
            itqty[num_items]=item_quantity(&itqty[num_items]);
            itprice[num_items]=item_price(&itprice[num_items]);
            num_items++; 
            break;

            case 2: 
            
            generate_bill(name,number,itname,itqty,itprice,num_items);
            break;

            case 3:

            printf("Exiting...\n");
            break;

            default:

            printf("Invalid option. Please choose a valid option.\n");
            break;

        }

    }    

    return 0;
}