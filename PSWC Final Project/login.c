#include <stdio.h>
#include <string.h>

void username(char user_name[100])
{
    printf("Enter Username: ");
    scanf("%[^\n]s", user_name);
}

void password(char pass[50])
{
    printf("Enter Password: ");
    scanf("%s", pass);

    char* correct_password = "abc@123";
    int x;
    x=strcmp(correct_password, pass);

    if(x==0)
    {
        printf("You have successfully been logged in.\n");
    }
    else
    {
        printf("You have entered the incorrect password. Please try again.\n");
        return password(pass);
    }

}
