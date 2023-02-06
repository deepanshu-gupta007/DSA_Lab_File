#include <stdio.h>
#include<stdlib.h>
typedef struct node     //Declaration of structure of node
{
    int data, ex;
    struct Node *next;
}NODE;
NODE* insert(NODE*, int, int);       //Declaration of function for insertion
NODE *add(NODE*, NODE*);        //Declaration of function to add two polynomials
void traverse(NODE*);       //Declaration of function to display
int main()
{
    NODE *list1=NULL, *list2=NULL,*list3=NULL;
    int ch, ele, n, i, e;
    char x='Y';
    printf("Menu:-\n1. Insert in List 1\n2. Insert in List 2\n3. Add both lists\n4. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:     //For insertion in list 1
                printf("Enter number of terms in list 1: ");
                scanf("%d", &n);
                for(i=1; i<=n; i++)
                {
                    printf("Enter number & exponent:\n");
                    scanf("%d%d", &ele, &e);
                    list1=insert(list1, ele, e);        //Calling insertion function
                }
                traverse(list1);        //Calling display function
                break;
            case 2:     //For insertion in list 2
                printf("Enter number of terms in list 2: ");
                scanf("%d", &n);
                for(i=1; i<=n; i++)
                {
                    printf("Enter number & exponent:\n");
                    scanf("%d%d", &ele, &e);
                    list2=insert(list2, ele, e);        //Calling insertion function
                }
                traverse(list2);        //Calling display function
                break;
            case 3:     //To add polynomials
                list3=add(list1,list2);     //Calling function to adding
                traverse(list3);        //Calling display function
                break;
            case 4:     //To exit the code
                x='N';
                break;
            default:        //Invalid entry from the menu
                printf("Invalid choice\n");
                break;
        }
    } while (x=='Y');
    return 0;
}
NODE* insert(NODE *start, int ele, int e)      //Defination of insertion function
{
    NODE* ptr=(NODE*)malloc(sizeof(NODE));      //Creating new node
    ptr->data=ele;
    ptr->ex=e;
    ptr->next=NULL;
    if (start==NULL)
        return ptr;
    NODE *t=start, *p=NULL;
    while (t!=NULL && t->ex<e)
    {
        p=t;
        t=t->next;
    }
    if (p==NULL)
    {
        ptr->next=start;
        return ptr;
    }
    else
    {
        p->next=ptr;
        ptr->next=t;
        return start;
    }
}
NODE *add(NODE *l1, NODE *l2)       //Defination of adding polynomials
{
    NODE *l3=NULL;
    while(l1!=NULL && l2!=NULL)
    {
        NODE *ptr=(NODE*)malloc(sizeof(NODE));
        if(l1->ex==l2->ex)
        {
            ptr->data=l1->data+l2->data;
            ptr->ex=l1->ex;
            l1=l1->next;
            l2=l2->next;
        }
        else if(l1->ex<l2->ex)
        {
            ptr->data=l1->data;
            ptr->ex=l1->ex;
            l1=l1->next;   
        }
        else 
        {
            ptr->data=l2->data;
            ptr->ex=l2->ex;
            l2=l2->next;   
        }
        ptr->next=NULL;
        if(l3==NULL)
            l3=ptr;
        else
        {
            ptr->next=l3;
            l3=ptr;
        }
    }
    while(l1!=NULL)     //If list 1 having more elements than list 2
    {
        NODE *ptr=(NODE*)malloc(sizeof(NODE));
        ptr->data=l1->data;
        ptr->ex=l1->ex;
        ptr->next=NULL;
        if(l3==NULL)
            l3=ptr;
        else
        { 
            ptr->next=l3; 
            l3=ptr;
        }
        l1=l1->next;       
    }
    while(l2!=NULL)     //If list 2 having more elements than list 1
    {
        NODE *ptr=(NODE*)malloc(sizeof(NODE));
        ptr->data=l2->data;
        ptr->ex=l2->ex;
        ptr->next=NULL;
        if(l3==NULL)
            l3=ptr;
        else
        {
            ptr->next=l3; 
            l3=ptr;
        }
        l2=l2->next;       
    }
    return l3;
}
void traverse(NODE *start)      //Defination of display function
{
    NODE *t=start;
    printf("Display:-\n");
    while(t!=NULL)        //Printing elements of list
    {
        printf("%dx%d\t",t->data,t->ex);
        t=t->next;
    }
    printf("\n");
}