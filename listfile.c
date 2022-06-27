#include<stdio.h>
#include<stdlib.h>
#include"listfile.h"

void ReadfromFile(LIST L)
{
    FILE* fp;
    if ((fp = fopen("list.txt", "r")) == NULL)
    {
        printf("Failure to open list.txt!\n");
        system("pause");
        exit(0);
    }
    for (int i = 0; !feof(fp); i++)
    {
        struct list temp;
        fread(&temp, sizeof(struct list), 1, fp);
        if (i > 0)
        {
            AppendLast(temp.name, temp.brand, temp.price, temp.n, L);
        }
    }
    fclose(fp);
    printf("文件读取完成！\n");
}

void WritetoFire(LIST L)
{
    FILE* fp;
    if ((fp = fopen("list.txt", "w")) == NULL)
    {
        printf("Failure to open list.txt!\n");
        exit(0);
    }
    while (L->next != NULL)
    {
        fwrite(L->next, sizeof(struct list), 1, fp);
        L = Next(L);
    }
    fclose(fp);
    printf("文件写入完成！\n");
}
