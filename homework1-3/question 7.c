#include <stdio.h>
#include <stdlib.h>
// NAT0056

struct node 
{
    int num;
    struct node *nextptr;
}*stnode;

void createNodeList(int n);
void NodeInsertatEnd(int num);
void displayList();

int main()
{
    int n, num;
    printf("\n\n Linked List : Insert a new node at the end of a Singly Linked List :\n");
    printf("-------------------------------------------------------------------------\n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list are : \n");
    displayList();
    printf("\n Input data to insert at the end of the list : ");
    scanf("%d", &num);
    NodeInsertatEnd(num);
    printf("\n Data after inserted in the list are : \n");
    displayList();

    return 0;
}

void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        printf(" Input data for node 1 : ");
        scanf("%d", &num);

        stnode-> num = num;      
        stnode-> nextptr = NULL;
        tmp = stnode;
        for(i = 2; i <= n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;
                fnNode->nextptr = NULL;
                tmp->nextptr = fnNode;
                tmp = tmp->nextptr;
            }
        }
    }
} 

void NodeInsertatEnd(int num)
{
    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num;
        fnNode->nextptr = NULL; 
        tmp = stnode;
        while(tmp->nextptr != NULL)
            tmp = tmp->nextptr;
        tmp->nextptr = fnNode;
    }
}

void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the empty list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);
            tmp = tmp->nextptr;
        }
    }
}