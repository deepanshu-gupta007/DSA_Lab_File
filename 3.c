#include<stdio.h>
#include<stdlib.h>
typedef struct node     //Declaration of structure of node
{
    int data;
    struct node *next;
}NODE;
NODE* insert(NODE*, int);       //Declaration of function for insertion
void traverse(NODE*);       //Declaration of function to display
void divide(NODE*);     //Declaration of function to separate the original list
int main()
{
    int ch, ele;
    char x='Y';
    printf("Menu:-\n1. Insert in original\n2. Traverse even and odd linked list\n3. Exit\n");
    NODE *start=NULL;
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:     //For insertion
                printf("Enter number: ");
                scanf("%d", &ele);
                start=insert(start, ele);       //Calling insertion function
                break;
            case 2:     //To separate the list
                divide(start);      //Calling separation function
                break;
            case 3:     //To exit the code
                x='N';
                break;
            default:        //Invalid entry from the menu
                printf("Invalid choice\n");
                break;
        }
    } while (x=='Y');
    return 0;
}
NODE* insert(NODE* start, int ele)      //Defination of insertion function
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));      //Creating new node
    ptr->data=ele;
    if (start==NULL)
    {
        ptr->next=NULL;
        return ptr;
    }
    else
    {
        NODE *t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=ptr;
        ptr->next=NULL;
        return start;
    }
}
void traverse(NODE* start)      //Defination of display function
{
    if (start==NULL)
        printf("No data available\n");
    else
    {
        NODE *t=start;
        while(t->next!=NULL)        //Printing elements of list
        {
            printf("%d\t", t->data);
            t=t->next;
        }
        printf("%d\n", t->data);
    }
}
void divide(NODE *start)        //Defination to separate the list
{
    NODE *even=NULL,*e=NULL,*odd=NULL,*o=NULL, *t=NULL;
    int i=1;
    for(t=start; t!=NULL; t=t->next)
    {
        if(i%2==0)
        {
            if(even==NULL)
                even=t;
            else
                e->next=t;
            e=t;
        }
        else
        {
            if(odd==NULL)
                odd=t;
            else
                o->next=t;
            o=t;
        }
        i++;
    }
    e->next=NULL;
    o->next=NULL;
    printf("Even Position Linked List:-\n");
    traverse(even);      //Calling display function
    printf("Odd Position Linked List:-\n");
    traverse(odd);      //Calling display function
}