#ifndef _appliancelist_H_
#define _appliancelist_H_

struct list
{
    char name[10];
    char brand[10];
    double price;
    int n;
    struct list* next;
};


typedef struct list * LIST;
typedef struct list *position;

LIST MakeNull();
LIST Next(LIST p);
void AppendLast(char name[], char brand[], double price, int n, LIST L);
LIST Find(char name[], char brand[], double price, LIST L);
void Insert(int n, position p);
void PrintList(LIST L);
void Delivery(int n, position p);

#endif // _list_H_
