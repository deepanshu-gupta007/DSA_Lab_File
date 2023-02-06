#include<stdio.h>
#include<stdlib.h>
typedef struct node     //Declaration of structure of node
{
    struct node *left;
    int info;
    struct node *right;
} NODE;
NODE *insert(NODE*, int);       //Declaration of function to inserting an element in tree
void search(NODE*, int);        //Declaraton of function to searching an element
NODE* delete(NODE*, int);       //Declaration of function to deleting an element from a tree
int count_leaf_nodes(NODE*);        //Declaration of function to count leaf nodes
int count_height(NODE*);        //Declaration of function to count height of tree
int count_nodes(NODE*);        //Declaration of function to count nodes
int main()
{
    NODE *tree=NULL;
    int x, ch, total_leaf_nodes, total_right_nodes, height;
    char y='Y';
    printf("0. Insert\n1. Search key\n2. Delete\n3. Count leaf nodes\n4. Height\n5. Nodes from right hand\n6. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 0:     //For insert
                printf("Enter an element: ");
                scanf("%d", &x);
                tree=insert(tree, x);       //Calling insertion function
                break;
            case 1:     //For searching
                printf("Enter an element: ");
                scanf("%d", &x);
                search(tree, x);        //Calling search function
                break;
            case 2:     //To delete a node
                printf("Enter an element: ");
                scanf("%d", &x);
                tree=delete(tree, x);       //Calling delete function
                break;
            case 3:     //To count leaf nodes
                total_leaf_nodes=count_leaf_nodes(tree);        //Calling function to count leaf nodes
                printf("Total number of leaf nodes: %d\n", total_leaf_nodes);
                break;
            case 4:     //To count height
                height=count_height(tree);        //Calling function to count height
                printf("Height of tree: %d\n", height);
                break;
            case 5:     //To count total nodes
                total_right_nodes=count_nodes(tree->right);        //Calling function to count nodes
                printf("Total number of nodes: %d\n", total_right_nodes);
                break;
            case 6:     //To exit the code
                y='n';
                break;
            default:        //Invalid entry from the menu
                printf("Invalid entry\n");
                break;
        }
    } while (y=='Y');
    return 0;
}
NODE *insert(NODE *tree, int ele)      //Defination of insertion function
{
    if (tree==NULL)
    {
        tree=(NODE*)malloc(sizeof(NODE));
        tree->left=NULL;
        tree->info=ele;
        tree->right=NULL;
    }
    else if (ele>(tree->info))
        tree->right=insert(tree->right, ele);
    else
        tree->left=insert(tree->left, ele);
    return tree;
}
void search(NODE *tree, int ele)      //Defination of search function
{
    if (tree==NULL)
        printf("Not found\n");
    else if (tree->info==ele)
        printf("Element found\n");
    else if (ele>tree->info)
        search(tree->right, ele);
    else
        search(tree->left, ele);
}
NODE* delete(NODE* tree, int ele)             //Defination of delete function
{
    if (tree==NULL)
        return NULL;
    if (ele<tree->info)
        tree->left=delete(tree->left, ele);
    else if (ele>tree->info)
        tree->right=delete(tree->right, ele);
    else 
    {
        if (tree->left==NULL && tree->right==NULL)
            return NULL;
        else if (tree->left==NULL)
            return tree->right;
        else if (tree->right==NULL)
            return tree->left;
        else
        {
            NODE* p=NULL;
            for(p=tree; p->left!=NULL; p=p->right);
            tree->info=p->info;
            tree->right=delete(tree->right, tree->info);
        }   
    }
}
int count_leaf_nodes(NODE *tree)      //Defination of count leaf node function
{
    if(tree==NULL)
        return 0;
    else if ((tree->left)==NULL && (tree->right)==NULL)
        return 1;
    else
        return count_leaf_nodes(tree->left)+count_leaf_nodes(tree->right);
}
int count_height(NODE *tree)      //Defination of count height function
{
    if(tree==NULL)
        return 0;
    else
    {
        int l, r;
        l=count_height(tree->left);
        r=count_height(tree->right);
        return (l>r)?(l+1):(r+1);
    }
}
int count_nodes(NODE *tree)      //Defination of count nodes function
{
    if(tree==NULL)
        return 0;
    else
        return 1+count_nodes(tree->left)+count_nodes(tree->right);
}