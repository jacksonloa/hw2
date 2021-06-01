#include <stdio.h>

int *createarr(int *sarr, int *rarr, int len)
{
    int i;
    for(i = 0; i < len; i ++)
    {
        sarr[i] = rarr[i];
    }
    return sarr;
}

int arrsearch(int *sarr, int len, int key)
{
    int i;
    for(i = 0; i < len; i ++)
    {
        if(sarr[i] == key)
        {
            return i;
        }
    }
    return -1;
}