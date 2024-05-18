#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

struct Item 
{
    char name[100];
    int quantity;
    float price;
};

void product_Name(int product_id, char product_name[50])
{
    FILE *fp = fopen("inventory.csv", "r");
    char line[500];

    int row = 0;
    int column = 0;

    int id = 0;

    while(fgets(line, 500, fp))
    {
        column = 0; 
        row++;
        char *val = strtok(line, ",");
        int check = 0;

        while(val)
        {
            switch (column)
            {
                case 0:
                id = atoi(val);
                if(id==product_id)
                {
                    check = 1;
                }
                break;

                case 1:
                strcpy(product_name, val);
                break;
            }
            val = strtok(NULL, ",");
            column++;

        }
        if(check==1)
            {
                return product_name;
            }
    }

    fseek(fp, 0, SEEK_SET);
    fgets(line, 500, fp);
}

int product_Price(int product_id)
{
    FILE *fp = fopen("inventory.csv", "r");
    char line[500];

    int row = 0;
    int column = 0;

    int id = 0;
    int product_price;

    while(fgets(line, 500, fp))
    {
        column = 0; 
        row++;
        char *val = strtok(line, ",");
        int check = 0;

        while(val)
        {
            switch (column)
            {
                case 0:
                id = atoi(val);
                if(id==product_id)
                {
                    check = 1;
                }
                break;

                case 2:
                product_price = atoi(val);
                break;
            }
            val = strtok(NULL, ",");
            column++;
        }

        if(check==1)
            {
                return product_price;
            }
    }

    fseek(fp, 0, SEEK_SET);
    fgets(line, 500, fp);
}

int item_entry(struct Item items[],int num_items)
{
    int product_id;
    printf("Enter Product ID: ");
    scanf("%d", &product_id);

    if(product_id<=20)
    {
        product_Name(product_id,items[num_items].name);

        printf("Enter Quantity: ");
        scanf("%d", &items[num_items].quantity);
        
        items[num_items].price=product_Price(product_id);

        printf("\n");

        return 1;
    }
    
    else
    {
        printf("Invalid Product ID.\n\n");

        return 0;
    }

}
