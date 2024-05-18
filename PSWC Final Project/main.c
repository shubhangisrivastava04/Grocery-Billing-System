#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item 
{
    char name[100];
    int quantity;
    float price;
};

int main() 
{
    char name[100];
    char user_name[100];
    char number[10]; 

    printf("Welcome!\n");
    printf("Login:\n");

    login(user_name);
    strcpy(name, user_name); 

    FILE *fp = fopen("inventory.csv", "r");
    char line[500];
    int row = 0; 
    int column = 0;

    mob_no(number);

    int option = 0;
   
    struct Item *items = (struct Item *)malloc(100 * sizeof(struct Item));
    int num_items = 0;

    while (option != 4) 
    {
        printf("-------MAIN MENU-------\n");
        printf("Please select an Option: \n");
        printf("1.Item Details Entry\n2.Bill all Items\n3.View Inventory\n4.Exit\n");
        printf("-----------------------\n");

        printf("Enter your choice: \n");
        scanf("%d", &option);
        printf("\n");

        switch (option) 
        {
            case 1: 
            
                printf("Please Enter Item Details:\n");
                int val=500;
                val=item_entry(items, num_items);
                if(val==0)
                {
                    break;
                }
                else
                {
                    num_items++;
                }
                break;

            case 2: 
                generate_bill(name, number, items, num_items);
                break;

            case 3:
                printf("---------------------------------------\n");
                printf("\t\tINVENTORY\n");
                printf("---------------------------------------\n");
                printf("ID\t\tProduct\t\tPrice\n");
                printf("---------------------------------------\n");
                
                while(fgets(line, 500, fp))
                {
                    column = 0;
                    row++;

                    if (row==1)
                        continue;

                    char* val = strtok(line, ",");
                    
                    while(val)
                    {
                        printf("%s\t\t", val);
                        val = strtok(NULL, ",");
                        column++;
                    }
                    printf("\n");
                }
                printf("---------------------------------------\n\n");

                fseek(fp, 0, SEEK_SET);
                fgets(line, 500, fp);
                break;

            case 4:
                printf("Exiting...\n\nThank You!\n\n");
                break;

            default:
                printf("Invalid option. Please choose a valid option.\n\n");
                break;
        }
        
    }    
   
    free(items);
    return 0;

}
