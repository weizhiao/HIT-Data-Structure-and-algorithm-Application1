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
                printf("��������ɣ�\n");
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
            printf("����������������룡\n");
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
    printf("## ����������1   ##\n");
    printf("## ���������2   ##\n");
    printf("## ��ѯ�������3 ##\n");
    printf("## �˳�������0   ##\n");
    printf("##               ##\n");
    printf("###################\n");
}

void Input(char name[], char brand[], double* price, int* n, int a)
{
    fflush(stdin);
    printf("������ҵ����ƣ�\n");
    while (*gets(name) == '\0');
    printf("������ҵ�Ʒ�ƣ�\n");
    while (*gets(brand) == '\0');
    printf("������ҵ絥�ۣ�\n");
    while (scanf("%lf", price) != 1 || *price < 0)
    {
        printf("����������������룡\n");
        fflush(stdin);
    }
    if (a == 0)
    {
        printf("���������������\n");
        while (scanf("%d", n) != 1 || *n <= 0)
        {
            printf("����������������룡\n");
            fflush(stdin);
        }
    }
    else
    {
        printf("���������������\n");
        while (scanf("%d", n) != 1 || *n <= 0)
        {
            printf("����������������룡\n");
            fflush(stdin);
        }
    }
}