#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "arr.h"
#include "bs.h"
#include "bst.h"
#include "ll.h"
#define datacnt 10000

struct tnode
{
    int num;
    struct tnode *lt;
    struct tnode *rt;
};
typedef struct tnode tnode;

struct node
{
    int num;
    struct node *next;
};
typedef struct node node;

int main(int argc, char **argv)
{
    int *data;
    int num[datacnt] = {0}, bsarr[datacnt] = {0}, array[datacnt] = {0};
    int i, check, rep, n, m, cnt = 0, notfound; //check用來暫存數字; rep用來表示重複狀態; n跟m分別代表插入與查詢的資料數
    int d = 0, q = 0, bst = 0, bs = 0, arr = 0, ll = 0; //以上皆是用來判斷是否有此指令 
    tnode  *troot; //troot為bst的根
    node *llfirst; //llfirst為ll的起始點
    struct timeval start;//起始點
	struct timeval end;//結束點
	unsigned long bdiff;//儲存計算的時間差
    unsigned long qdiff;//儲存計算的時間差
    FILE *xfile;
    FILE *yfile; //紀錄起始點用
    FILE *ifile; //主要移動的指標

    data = malloc(sizeof(int)*datacnt);
    srand(10);
    while(cnt <= datacnt)
    {
        rep = 0;
        check = rand()%100000 + 1;
        for(i = 0; i < cnt; i ++)
        {
            if(check == *(data+i))
            {
                rep = 1;
                break;
            }
        }
        if(rep == 0)
        {
            *(data+cnt) = check;
            cnt ++;
        }
    }
    xfile = fopen("dataset.txt", "w");
    for(i = 0; i < datacnt; i ++)
    {
        fprintf(xfile, "%d\n", *(data+i));
    }
    fclose(xfile);
    free(data);
    for(i = 1; i < argc; i ++)
    {
        if(strcmp(argv[i], "-d") == 0)
        {
            d = 1;
            n = atoi(argv[i+1]);
        }
        else if(strcmp(argv[i], "-q") == 0)
        {
            q = 1;
            m = atoi(argv[i+1]);
        }
        else if(strcmp(argv[i], "-bst") == 0)
        {
            bst = 1;
        }
        else if(strcmp(argv[i], "-bs") == 0)
        {
            bs = 1;
        }
        else if(strcmp(argv[i], "-ll") == 0)
        {
            ll = 1;
        }
        else if(strcmp(argv[i], "-arr") == 0)
        {
            arr = 1;
        }
    }
    if(d == 1 && q == 1)
    {
        if(bst == 1)
        {
            yfile = fopen("dataset.txt", "r");
            ifile = yfile;
            for(i = 0; i < datacnt; i ++)
            {
                fscanf(ifile, "%d", &num[i]);
            }
            gettimeofday(&start, NULL);//開始
            for(i = 0; i < n; i ++)
            {
                troot = inserttree(troot, num[i]);
            }
            gettimeofday(&end, NULL);//結束
            bdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
            gettimeofday(&start, NULL);//開始
            for(i = 0; i < m; i ++)
            {
                findnode(troot, num[i]);
            }
            gettimeofday(&end, NULL);//結束
            qdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
            printf("bst:\n");
	        printf("building time: %f sec\n", bdiff / 1000000.0);//印出生成時間
            printf("query time: %f sec\n", qdiff / 1000000.0);//印出查詢時間
        }
        if(bs == 1)
        {
            ifile = yfile;
            for(i = 0; i < datacnt; i ++)
            {
                fscanf(ifile, "%d", &num[i]);
            }
            gettimeofday(&start, NULL);//開始
            bscreatearr(bsarr, num, n);
            gettimeofday(&end, NULL);//結束
            bdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
            gettimeofday(&start, NULL);//開始
            for(i = 0; i < m; i ++)
            {
                b_search(bsarr, 0, n-1, num[i]);
            }
            gettimeofday(&end, NULL);//結束
            qdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
            printf("bs:\n");
	        printf("building time: %f sec\n", bdiff / 1000000.0);//印出生成時間
            printf("query time: %f sec\n", qdiff / 1000000.0);//印出查詢時間
        }
        if(ll == 1)
        {
            ifile = yfile;
            for(i = 0; i < datacnt; i ++)
            {
                fscanf(ifile, "%d", &num[i]);
            }
            gettimeofday(&start, NULL);//開始
            llfirst = creatlist(num, n);
            gettimeofday(&end, NULL);//結束
            bdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
            gettimeofday(&start, NULL);//開始
            for(i = 0; i < m; i ++)
            {
                searchnode(llfirst, num[i]);
            }
            gettimeofday(&end, NULL);//結束
            qdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
            printf("ll:\n");
	        printf("building time: %f sec\n", bdiff / 1000000.0);//印出生成時間
            printf("query time: %f sec\n", qdiff / 1000000.0);//印出查詢時間
            freelist(llfirst);
        }
        if(arr == 1)
        {
            ifile = yfile;
            for(i = 0; i < datacnt; i ++)
            {
                fscanf(ifile, "%d", &num[i]);
            }
            gettimeofday(&start, NULL);//開始
            createarr(array, num, n);
            gettimeofday(&end, NULL);//結束
            bdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
            gettimeofday(&start, NULL);//開始
            for(i = 0; i < m; i ++)
            {
                arrsearch(array, m, num[i]);
            }
            gettimeofday(&end, NULL);//結束
            qdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
            printf("arr:\n");
	        printf("building time: %f sec\n", bdiff / 1000000.0);//印出生成時間
            printf("query time: %f sec\n", qdiff / 1000000.0);//印出查詢時間
            fclose(yfile);
        }
    }
    return 0;
}