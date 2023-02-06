#include<stdio.h>
#include<stdlib.h>
typedef struct node     //Declaration of structure of node
{
    int data;
    struct node *next;
    struct node *pre;
} NODE;
NODE* insert(NODE*, int);       //Declaration of function for insertion
void traverse(NODE*);       //Declaration of function to display
int main()
{
    int ch, ele, n;
    char x='Y';
    printf("Menu:-\n1. Insert\n2. Traverse\n3. Exit\n");
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
            case 2:     //To display
                traverse(start);      //Calling display function
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
    ptr->pre=NULL;
    ptr->next=NULL;
    if (start==NULL)
        return ptr;
    else if(start->data>ele)
    {
        ptr->next=start;
        return ptr;
    }
    else
    {
        NODE *t=start;
        while(t->next!=NULL && t->next->data<ele)
            t=t->next;
        ptr->next=t->next;
        if (t->next!=NULL)
            t->next->pre=ptr;
        t->next=ptr;
        ptr->pre=t;
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