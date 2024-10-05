#include<stdio.h>

#define MAXSIZE 100

typedef int ElemType;
/*定义线性表*/
typedef struct
{
    ElemType list[MAXSIZE];
    int last;
}SeqList;

/*创建空表*/
void InitList(SeqList *L)
{
    L->last=-1;
}

/*输入递增有序顺序表*/
void PutSeqList(SeqList *L,int n)
{
    for(int i=0; i<n; i++)
    {
        scanf("%d", &L->list[i]);
    }
    L->last=L->last + n;
}

/*输出元素*/
void OutputSeqList(SeqList *L)
{
    int i;
    printf("输出的结果为：");
    for(i=0; i<=L->last; i++)
        printf("%d ", L->list[i]);
    printf("\n");
}

/*将两个递增有序的顺序表A,B进行合并，合并后仍然有序，并求中位数。*/
SeqList MergeList(SeqList *A, SeqList *B)
{
    int i=0, j=0, k=0;
    SeqList C;
    InitList(&C);
    while(i<=A->last && j<=B->last)
    {
        if(A->list[i] <= B->list[j])
            C.list[k++] = A->list[i++];
        else
            C.list[k++] = B->list[j++];
    }
    while(i<=A->last)
        C.list[k++] = A->list[i++];
    while(j<=B->last)
        C.list[k++] = B->list[j++];
    C.last = k-1;
    return C;
}

/*请删除重复出现的元素，使每个元素只出现一次*/
void DeleteRepeat(SeqList *L)
{
    int i, j;
    for(i=0;i<L->last;i++)
    {
        for(j=i+1;j<=L->last;j++)
        {
            if(L->list[i] == L->list[j])
            {
                for(int k=j; k<L->last; k++)
                    L->list[k] = L->list[k+1];
                L->last--;
                j--;
            }
        }
    }
    OutputSeqList(L);
}

int main()
{
    SeqList L, M, N;
    int n,m;
    InitList(&L);
    printf("请输入递增有序表的长度：");
    scanf("%d", &n);
    printf("请输入递增有序表的元素：");
    PutSeqList(&L, n);
    OutputSeqList(&L);

    InitList(&M);
    printf("请输入递增有序表的长度：");
    scanf("%d", &m);
    printf("请输入递增有序表的元素：");
    PutseqList(&M, m);
    OutputSeqList(&M);
    N = MergeList(&L, &M);
    printf("合并后的递增有序表为：");
    OutputSeqList(&N);
    printf("中位数为：%d\n", N.list[N.last/2]);
    DeleteRepeat(&N);
    return 0;
}
