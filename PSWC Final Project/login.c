#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

void password(char pass[50], char *user_name)
{
    printf("Enter Password: ");
    scanf("%s", pass);
    strcat(pass, "\n");

    FILE *fp = fopen("users.csv", "r");
    char line[500];

    int row = 0;
    int column = 0;

    int comp1 = 1;
    int comp2 = 1;
    int found = 0;


    while(fgets(line, 500, fp))
    {
        column = 0;
        row++;
        
        int check1 = 0;
        int check2 = 0;

        if(row==1)
        {
            continue;
        }
        char *val = strtok(line, ",");

        while(val)
        {
            switch (column)
            {
                case 0:
                comp1 = strcmp(user_name, val);
                if(comp1==0)
                {
                    check1 = 1;
                }
                
                case 1:
                comp2 = strcmp(pass, val);
                if(comp2==0)
                {
                    check2 = 1;
                }

            }   
            val = strtok(NULL, ",");
            column++;
        }
        if(check1==1 && check2==1)
            {
                found = 1;
            }
    }

    if(found==1)
    {
        printf("You have successfully been logged in.\n");
    }
    else
    {
        printf("You have entered the incorrect password. Please try again.\n\n");
        return password(pass, user_name);
    }

    fseek(fp, 0, SEEK_SET);
    fgets(line, 500, fp);
    
    fclose(fp);
    
}

void addUser(char user_name[100])
{
    FILE *fp = fopen("users.csv", "a+");
    char line[500];

    char pin[50];
    printf("Enter New Password: ");
    scanf("%s", pin);

    char new_user[100], new_pin[50];
    strcpy(new_user, user_name);
    strcpy(new_pin, pin);

    fprintf(fp, "%s,%s\n", new_user, new_pin);
    fclose(fp);
    printf("New User successfully added to database.\n\n");
    
}


void login(char user_name[100])
{
    FILE *fp = fopen("users.csv", "r");
    char line[500];

    int row = 0;
    int column = 0;

    char pin[50];
    int comp = 1;

    int add_user;

    printf("Enter Username: ");
    scanf("%[^\n]s", user_name);
    int check = 0;

    while(fgets(line, 500, fp))
    {
        column = 0;
        row++;
        char *val = strtok(line, ",");

        while(val)
        {
            switch(column)
            {
                case 0:
                comp = strcmp(user_name, val);
                if(comp==0)
                {
                    check = 1;
                    fclose(fp);
                }
                break;

            }
            val = strtok(NULL, ",");
            column++;
        }
    }

    if(check==0)
    {
        printf("User does not exist in database.\n");
        printf("Add NEW user?\n0: No, continue without logging in.\n1: Yes\n");
        scanf("%d",&add_user);

        switch(add_user)
        {
            case 0:
            return;
            break;

            case 1:
            addUser(user_name);
            break;

            default:
            printf("Invalid option. Please choose a valid option.\n\n");
            break;
        }
    }
    
    else if(check==1)
    {
        password(pin, user_name);
    }

}
