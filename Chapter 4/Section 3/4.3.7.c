#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
typedef struct chain
{
    int id;
    struct chain* next;
}CHAIN;

typedef struct equipment
{
    char name[100];
    int price;
    int own;
    CHAIN need;
}EQU;

EQU equta[100];
int sum;
int fosum;

void addNum(int n, CHAIN *c)
{
    while(c->next)
    {
        c = c->next;
    }
    c->next = (CHAIN*)malloc(sizeof(CHAIN));
    (c->next)->id = n;
    (c->next)->next = 0;
}

void freeChain(CHAIN* c)
{
    if(c->next)
    {
        freeChain(c->next);
    }
    free(c->next);
    c->next = 0;
}

int findID(char* thename)
{
    int i;
    for(i = 0; i < sum; i++)
    {
        if(strcmp(thename, equta[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int countValue(int id, int need)
{
    int value = 0;
    CHAIN* p;

    if(equta[id].own > need)
    {
        equta[id].own -= need;
    }
    else
    {
        need -= equta[id].own;
        equta[id].own = 0;

        if(equta[id].price > 0)
        {
            value += equta[id].price * need;
        }
        else
        {
            p = equta[id].need.next;
            while(p)
            {
                value += countValue(p->id, need);
                p = p->next;
            }
        }
    }
    return value;
}

int main()
{
    int n1, n2, n3, n4;
    char tempname[100];
    int tempnum;
    int i;
    int id;
    int value;
    CHAIN tempchain;
    char notation;

    while(scanf("%d", &n1) != EOF)
    {
        sum = 0;
        memset(equta, 0, sizeof(equta));
        for(i = 0; i < n1; i++)
        {
            scanf("%s", tempname);
            scanf("%d", &tempnum);
            strcpy(equta[i].name, tempname);
            equta[i].price = tempnum;

            equta[i].need.next = 0;
            sum++;
        }

        scanf("%d", &n2);
        for(i = 0; i < n2; i++)
        {
            scanf("%s", tempname);
            scanf("%d", &tempnum);

            if((id = findID(tempname)) != -1)
            {
                equta[id].own = tempnum;
            }
            else
            {
                strcpy(equta[sum].name, tempname);
                equta[sum].own = tempnum;
                equta[sum].need.next = 0;
                sum++;
            }
        }

        scanf("%d", &n3);

        tempchain.next = 0;

        for(i = 0; i < n3; i++)
        {
            freeChain(&tempchain);
            while(scanf("%s %c", tempname, ¬ation))
            {
                addNum(findID(tempname) ,&tempchain);

                if(notation == '=')
                {
                    scanf("%s", tempname);

                    if((id = findID(tempname)) == -1)
                    {
                        strcpy(equta[sum].name, tempname);
                        equta[sum].own = 0;
                        equta[sum].need.next = tempchain.next;
                        sum++;

                    }
                    else
                    {
                        equta[id].need.next = tempchain.next;
                    }
                    tempchain.next = 0;
                    break;
                }
            }
        }

        value = 0;

        scanf("%d", &n4);
        for(i = 0; i < n4; i++)
        {
            scanf("%s", tempname);
            scanf("%d", &tempnum);

            id = findID(tempname);
            value += countValue(id, tempnum);

        }
        printf("%d\n", value);


    }
    return 0;
}