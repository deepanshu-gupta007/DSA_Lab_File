#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(char[][50], int, int, int);        //Declaration of merging function
void mergeSort(char [][50], int, int);        //Declaration of merge sort function
void display(char [][50], int);        //Declaration of display function
int main()
{
    int n,i;
    printf("Enter number of string: ");
    scanf("%d", &n);
    char arr[n][50];
    for(i=0; i<n; i++)          //Taking inputs of array
    {
        printf("Enter string: ");
        scanf("%s", arr[i]);
    }
    printf("Given array: \n");
    display(arr, n);        //Calling display function
    mergeSort(arr, 0, n-1);         //Calling merge sort function
    printf("Sorted array: \n");
    display(arr, n);        //Calling display function
    return 0;
}
void merge(char arr[][50], int l, int m, int r)     //Defination of merge function
{
    int i, j, k, n1=m-l+1, n2=r-m;
    char L[n1][50], R[n2][50];
    for (i=0; i<n1; i++)
        strcpy(L[i], arr[l+i]);
    for (j=0; j<n2; j++)
        strcpy(R[j], arr[m+1+j]);
    i=0, j=0, k=l; 
    while (i<n1 && j<n2) 
    {
        if (strcmp(L[i], R[j])<=0) 
            strcpy(arr[k++] ,L[i++]);
        else 
            strcpy(arr[k++], R[j++]);
    }
    while (i<n1) 
        strcpy(arr[k++], L[i++]);
    while (j<n2) 
        strcpy(arr[k++], R[j++]);
}
void mergeSort(char arr[][50], int l, int r)     //Defination of merge sort function
{
    if (l<r) 
    {
        int m=l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
void display(char A[][50], int size)     //Defination of display function
{
    int i;
    for (i=0; i<size; i++)      //Printing strings from array
        printf("%s\t", A[i]);
    printf("\n");
}