#include <stdio.h>
#include <stdlib.h>
typedef struct node     //Declaration of structure of node
{
    struct node *next;
    int info;
    int sno;
} NODE;
NODE* insert(NODE*,int);       //Declaration of function for insertion
void traverse(NODE*);       //Declaration of function to display
void delete(NODE**);        //Declaration of deletion of node
void taskprocess(NODE**, int);      //Declaration of CPU processing
int main()
{
    NODE *top=NULL;
    int choice, x, ch=1;
    printf("OPERATION YOU NEED TO PERFORM:\n1. INSERT\n2. PROCESS SCHEDULING\n3. DISPLAY\n4. EXIT\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:     //For insertion
                printf("Enter time: ");
                scanf("%d", &x);
                top=insert(top, x);       //Calling insertion function
                break;
            case 2:     //CPU processing
                taskprocess(&top, 10);      //Calling CPU processing 
                break;
            case 3:     //To display
                traverse(top);      //Calling display function
                break;
            case 4:     //To exit the code
                ch=0;
                break;
            default:        //Invalid entry from the menu
                printf("Invalid choice hence exit\n");
                break;
        }
    } while(ch==1);
}
NODE* insert(NODE *start,int n)      //Defination of insertion function
{
    static int sno=0;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));      //Creating new node
    ptr->sno=++sno;
    ptr->info=n;
    if(start==NULL)
        ptr->next=ptr;  
    else
    {
        ptr->next=start->next;
        start->next=ptr;
    }
    return ptr;
}
void traverse(NODE* start)      //Defination of display function
{
    if (start==NULL)
        printf("No data available\n");
    else
    {
        NODE *t=start;
        printf("Time Taken\n");
        while(t->next!=start)        //Printing elements of list
        {
            printf("%d\t", t->info);
            t=t->next;
        }
        printf("%d\n", t->info);
    }
}
void delete(NODE **p)       //Defination of deleting a node
{
    NODE *q=*p, *r=NULL;
    if(q->next==q)
    {
        free(q);
        *p=NULL;
    }
    else
    {
        r=q->next;
        q->next=r->next;
        free(r);
        *p=q;
    }
}
void taskprocess(NODE **p, int timee)       //Defination of CPU processing
{
    int c=0, y;
    NODE *q=*p;
    while(q)
    {
        y=(++c)*timee;
        NODE *f=q->next;
        f->info-=timee;
        if((f->info)<=0)
        {
            printf("Process-%d is completed in %d turn within %d unit time\n", f->sno, c, y);
            delete(&q);
        }
        else q=q->next;
    }
}