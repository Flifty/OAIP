#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

void input(Flat* flats, int* n);
void output(Flat* flats, int* n);
void deleteStruct(Flat* flats, int* n);
int compare(Flat* f1, Flat* f2, int field1, int field2);
void shellSort(Flat* flats, int n, int field1, int field2);
int menu();
#endif