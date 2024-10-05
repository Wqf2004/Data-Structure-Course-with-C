#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> // 导入库

#define LEN sizeof(struct Student) // 宏定义：替换结构体的大小

typedef struct Student
{
    int num;
    float score;
    struct Student *next; //结构体的next指针又指向了结构体本身,开始构建链表
}Node; //结构体->定义出一个结点

typedef struct LinkList
{
    Node *head; //头结点
    int length;
}Link; //我们要的类型->链表

