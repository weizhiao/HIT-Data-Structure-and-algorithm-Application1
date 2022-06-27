#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "appliancelist.h"
#include"listfile.h"

void ShowMenu();
void Input(char name[], char brand[], double* price, int* n, int a);

int main()
{
    LIST L = MakeNull();
    char name[10];
    char brand[10];
    int n;
    double price;
    ReadfromFile(L);
    while (1)
    {
        ShowMenu();
        switch (getchar())
        {
        case '0':
            WritetoFire(L);
            system("pause");
            return 0;
        case '1':
            Input(name, brand, &price, &n, 0);
            position p = Find(name, brand, price, L);
            if (p == NULL)
            {
                AppendLast(name, brand, price, n, L);
                printf("库存添加完成！\n");
            }
            else
            {
                Insert(n, p);
            }
            system("pause");
            system("cls");
            fflush(stdin);
            break;
        case '2':
            Input(name, brand, &price, &n, 1);
            p = Find(name, brand, price, L);
            Delivery(n, p);
            system("pause");
            system("cls");
            fflush(stdin);
            break;
        case '3':
            PrintList(L);
            system("pause");
            system("cls");
            fflush(stdin);
            break;
        default:
            printf("输入错误，请重新输入！\n");
            system("pause");
            system("cls");
            fflush(stdin);
        }
    }
}

void ShowMenu()
{
    printf("###################\n");
    printf("##               ##\n");
    printf("## 进货请输入1   ##\n");
    printf("## 提货请输入2   ##\n");
    printf("## 查询库存输入3 ##\n");
    printf("## 退出请输入0   ##\n");
    printf("##               ##\n");
    printf("###################\n");
}

void Input(char name[], char brand[], double* price, int* n, int a)
{
    fflush(stdin);
    printf("请输入家电名称：\n");
    while (*gets(name) == '\0');
    printf("请输入家电品牌：\n");
    while (*gets(brand) == '\0');
    printf("请输入家电单价：\n");
    while (scanf("%lf", price) != 1 || *price < 0)
    {
        printf("输入错误，请重新输入！\n");
        fflush(stdin);
    }
    if (a == 0)
    {
        printf("请输入进货数量：\n");
        while (scanf("%d", n) != 1 || *n <= 0)
        {
            printf("输入错误，请重新输入！\n");
            fflush(stdin);
        }
    }
    else
    {
        printf("请输入提货数量：\n");
        while (scanf("%d", n) != 1 || *n <= 0)
        {
            printf("输入错误，请重新输入！\n");
            fflush(stdin);
        }
    }
}