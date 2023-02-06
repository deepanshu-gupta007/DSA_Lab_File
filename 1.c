#include<stdio.h>
void positive(int[], int);      //Declaration of function
int main()
{
    int i, n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];       //Declaration of an array
    for(i=0; i<n; i++)      //Taking inputs in array
    {
        printf("Enter element %d = ", i+1);
        scanf("%d", &a[i]);
    }
    positive(a, n);     //Calling function
    for(i=0; i<n; i++)      //Printing elements from array
        printf("%d\t",a[i]);
    return 0;
}
void positive(int a[], int n)       //Defination of a  function
{
    int i, j=n, temp;
    for(i=n-1; i>=0; i--)
    {
        if(a[i]>0)
        {
            temp=a[--j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}