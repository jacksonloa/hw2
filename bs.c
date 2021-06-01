#include <stdio.h>

int *bscreatearr(int *sarr, int *rarr, int len) //sarr陣列是儲存用,rarr是資料來源
{
    int i, j, key;

    for(i = 0; i < len; i ++)
    {
        sarr[i] = rarr[i];
    }
    for(i = 1; i < len; i++)
    {
        key = sarr[i];
        j = i - 1;
        while(j >= 0 && sarr[j] > key)
        {
            sarr[j + 1] = sarr[j];
            j --;
        }
        sarr[j + 1] = key;
    }
    return sarr;
}

int b_search(int *arr, int start, int end, int key)
{
    if(start > end) return -1;
    int mid = start + (end - start) / 2;
    if(arr[mid] > key) return b_search(arr, start, mid-1, key);
    else if(arr[mid] < key) return b_search(arr, mid+1, end, key);
    else return mid;
}
 

