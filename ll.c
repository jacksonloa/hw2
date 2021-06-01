#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};
typedef struct node node;

node *creatlist(int *arr, int len)
{
    int i;
    node *first, *current, *previous;

    for(i = 0; i < len; i ++)
    {
        current = malloc(sizeof(node));
        current->num = arr[i];
        if(i == 0)
        {
            first = current;
        }
        else
        {
            previous->next = current;
        }
        current->next = NULL;
        previous = current;
    }
    return first;
}

void freelist(node *first)
{
    node *current, *tmp;
    current =first;
    while(current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
} 

node *searchnode(node * first, int key)
{
    node *tmp = first;
    while(tmp != NULL)
    {
        if(tmp->num == key)
        {
            return tmp;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return NULL;
}