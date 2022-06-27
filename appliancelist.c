#include<stdio.h>
#include<stdlib.h>
#include "appliancelist.h"

LIST MakeNull()
{
    LIST L = malloc(sizeof(struct list));
    L->next = NULL;
    return L;
}

LIST Next(LIST p)
{
    p=p->next;
    return p;
}

void AppendLast(char name[], char brand[], double price, int n, LIST L)
{
    while (L->next != NULL && L->next->price <= price)
    {
        L = Next(L);
    }
    position temp = malloc(sizeof(struct list));
    strcpy(temp->name, name);
    strcpy(temp->brand, brand);
    temp->price = price;
    temp->n = n;
    temp->next = L->next;
    L->next = temp;
}

LIST Find(char name[], char brand[], double price, LIST L)
{
    int flag = 0;
    while (L->next != NULL)
    {
        if ((strcmp(L->next->name, name) == 0) && (strcmp(L->next->brand, brand) == 0) && ((L->next->price - price) < 1e-6))
        {
            flag = 1;
            break;
        }
        L = Next(L);
    }
    if (flag == 0)
    {
        return NULL;
    }
    else
    {
        return L;
    }
}

void Insert(int n, position p)
{
    p->next->n = p->next->n + n;
    printf("库存已更新！目前库存为：%d\n", p->next->n);
}

void PrintList(LIST L)
{
    int count = 1;
    while (L->next != NULL)
    {
        printf("商品%d:\n", count);
        printf("家电名称：%s\n", L->next->name);
        printf("家电品牌：%s\n", L->next->brand);
        printf("家电单价：%.1f\n", L->next->price);
        printf("剩余库存：%d\n", L->next->n);
        L = Next(L);
        count++;
    }
}

void Delivery(int n, position p)
{
    if (p == NULL)
    {
        printf("库存不够，请进货！\n");
    }
    else if (n <= p->next->n)
    {
        printf("提货成功！\n");
        p->next->n = p->next->n - n;
        printf("剩余库存为：%d\n", p->next->n);
        if (p->next->n == 0)
        {
            position temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    else
    {
        printf("库存不够，请进货！\n");
    }
}
