#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    oneroom = 1,
    tworoom,
    threeroom,
    fourroom,
    multiroom
} Flattype; 

typedef struct
{
    char address[100];
    float price;
    int floor;
    Flattype type;
}Flat;

void input(Flat* flats, int* n)
{
    char temp;
    for (int i = 0; i < *n; i++)
    {
        printf("Enter adress %d flat: ", i + 1);
        temp = getchar();
        gets(flats[i].address);

        printf("Enter price %d flat: ", i + 1);
        scanf_s("%f", &flats[i].price);

        printf("Enter floor %d flat: ", i + 1);
        scanf_s("%d", &flats[i].floor);

        printf("Enter type:(1 - oneroom; 2 - tworoom; 3 - threeroom; 4 - fourroom; 5 - multiroom): ");
        scanf_s("%d", &flats[i].type);
    }
}

void output(Flat* flats, int* n)
{
    for (int i = 0; i < *n; i++)
    {
        printf("Address:%s\n Price:%f\n Floor:%d\n Type:%d\n", flats[i].address, flats[i].price, flats[i].floor, flats[i].type);
    }
}

void deleteStruct(Flat* flats, int* n)
{
    int x;
    printf("Enter the number of structure to delete: ");
    scanf_s("%d", &x);
    for (int i = x - 1; i < *n - 1; i++)
    {
        flats[i] = flats[i + 1];
    }
    *n = *n - 1;
    flats = (Flat*)realloc(flats, (*n) * sizeof(Flat));
}

int compare(Flat* f1, Flat* f2, int field1, int field2)
{
    if (field1 == 1)
    {
        if (strcmp(f1->address, f2->address) < 0)
        {
            return -1;
        }
        else if (strcmp(f1->address, f2->address) > 0)
        {
            return 1;
        }
    }
    else if (field1 == 2)
    {
        if (f1->price < f2->price)
        {
            return -1;
        }
        else if (f1->price > f2->price)
        {
            return 1;
        }
    }
    else if (field1 == 3)
    {
        if (f1->floor < f2->floor)
        {
            return -1;
        }
        else if (f1->floor > f2->floor)
        {
            return 1;
        }
    }
    else if (field1 == 4)
    {
        if (f1->type < f2->type)
        {
            return -1;
        }
        else if (f1->type > f2->type)
        {
            return 1;
        }
    }

    // If field1 values are equal, compare field2
    if (field2 == 1)
    {
        if (strcmp(f1->address, f2->address) < 0)
        {
            return -1;
        }
        else if (strcmp(f1->address, f2->address) > 0)
        {
            return 1;
        }
    }
    else if (field2 == 2)
    {
        if (f1->price < f2->price)
        {
            return -1;
        }
        else if (f1->price > f2->price)
        {
            return 1;
        }
    }
    else if (field2 == 3)
    {
        if (f1->floor < f2->floor)
        {
            return -1;
        }
        else if (f1->floor > f2->floor)
        {
            return 1;
        }
    }
    else if (field2 == 4)
    {
        if (f1->type < f2->type)
        {
            return -1;
        }
        else if (f1->type > f2->type)
        {
            return 1;
        }
    }

    return 0;
}

void shellSort(Flat* flats, int n, int field1, int field2)
{
    int gap, i, j;
    Flat temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = flats[i];
            for (j = i; j >= gap && compare(&flats[j - gap], &temp, field1, field2) > 0; j -= gap)
            {
                flats[j] = flats[j - gap];
            }
            flats[j] = temp;
        }
    }
}

int menu()
{
    int x;
    printf("Enter:\n");
    printf("1 - To delete a structure\n");
    printf("2 - To sort by 2 fields\n");
    printf("3 - To exit the program\n");
    scanf_s("%d", &x);
    return x;
}