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
    printf("Menu:-\n1. Insert in original\n2. Traverse positive and negative linked list\n3. Exit\n");
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
    NODE *pos=NULL,*p=NULL,*neg=NULL,*n=NULL, *t=NULL;
    for(t=start; t!=NULL; t=t->next)
    {
        if(t->data>0)
        {
            if(pos==NULL)
                pos=t;
            else
                p->next=t;
            p=t;
        }
        else
        {
            if(neg==NULL)
                neg=t;
            else
                n->next=t;
            n=t;
        }
    }
    p->next=NULL;
    n->next=NULL;
    printf("Positive Linked List:-\n");
    traverse(pos);      //Calling display function
    printf("Negative Linked List:-\n");
    traverse(neg);      //Calling display function
}