#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int num;
    struct tnode *lt;
    struct tnode *rt;
};
typedef struct tnode tnode;

tnode *inserttree(tnode *t, int input)
{
    if(t == NULL)
    {
        t = malloc(sizeof(tnode));
        t->lt = NULL;
        t->rt = NULL;
        t->num = input;
        return t;
    }
    else if(t->num > input)
    {
        t->lt = inserttree(t->lt, input);
    }
    else if(t->num < input)
    {
        t->rt = inserttree(t->rt, input); 
    }
    return t;
}

int findnode(tnode *t, int key)
{
    if(t == NULL)
    {
        return 0;
    }
    else if(t->num == key) return 1;
    else if(t->num > key) return findnode(t->lt, key);
    else if(t->num < key) return findnode(t->rt, key);
}

void printTree(tnode *t)
{
    if(t == NULL)return;
    printf("%d ",t->num);
    printTree(t->lt);
    printTree(t->rt);
}