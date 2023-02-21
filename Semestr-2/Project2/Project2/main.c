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

int main()
{
    int n, field1, field2;
    printf("Enter the number of flats: ");
    scanf_s("%d", &n);
    int* pn = &n;
    //Flat flats[100];
    Flat* flats = malloc(n * sizeof(Flat));
    input(flats, pn);
    output(flats, pn);
    while (1)
    {
        switch (menu())
        {
        case 1:
            deleteStruct(flats, pn);
            output(flats, pn);
            break;
        case 2:
            printf("\nEnter the field numbers (1-4) to sort on (first and second): ");
            scanf_s("%d %d", &field1, &field2);
            shellSort(flats, n, field1, field2);
            printf("\nSorted Flats:\n");
            output(flats, pn);
            break;
        case 3:
            return 0;
        }
    }
    return 0;
}