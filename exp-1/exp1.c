#include <stdio.h>
#include <stdlib.h>

int array[100], size;

void create();
void insert();
void delete ();
void display();

void main()
{
    int i, choice;
    while (1)
    {
        printf("Enter 1: To create an Array \n");
        printf("Enter 2: To Insert New Element\n");
        printf("Enter 3: To Delete An Element\n");
        printf("Enter 4: To Display Array Elements\n");
        printf("Enter 5: To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice Entered");
            break;
        }
    }
}

void create()
{
    int i;
    printf("Enter the size of the array \n");
    scanf("%d", &size);
    printf("Enter the array elements\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}
void insert()
{
    int elem, pos, i;
    printf("Enter the Element\n");
    scanf("%d", &elem);
    printf("Enter the position\n");
    scanf("%d", &pos);
    if (pos < 0 || pos > size)
    {
        printf("Invalid Position \n");
        return;
    }
    size++;
    for (i = size - 1; i > pos; i--)
    {
        array[i] = array[i - 1];
    }
    array[pos] = elem;
    return;
}

void delete ()
{
    int pos, i;
    printf("Enter the position\n");
    scanf("%d", &pos);
    if (pos < 0 || pos > size - 1)
    {
        printf("Invalid Position \n");
        return;
    }
    for (i = pos; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
}

void display()
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d \t", array[i]);
    }
    printf("\n");
}