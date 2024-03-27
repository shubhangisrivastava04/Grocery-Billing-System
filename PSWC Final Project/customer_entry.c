#include <stdio.h>

char customer_entry(char name[100])
{
    printf("Enter Customer Name: ");
    gets(name);
    return *name;
}

int mob_no(int num)
{
    printf("Enter Customer Mobile No.: ");
    scanf("%d",&num);
    return num;
}