#include <stdio.h>

struct stu
{
    int number;
    char name[10];
    int consum;
    struct stu *next;
};

void creat(struct stu *l);
void load(struct stu *l);
void search(struct stu *l);
void delete (struct stu *l);
void add(struct stu *l);
void show(struct stu *l);
void save(struct stu *l);

void creat(struct stu *l)
{
    if (NULL == l)
        return;
    struct stu *p = l->next;
    struct stu *q = NULL;
    while (p)
    {
        p = p->next;
    }
    while (1)
    {

        printf("please input student's information,input 0 to exit!\n");
        if (getchar() == '0')
        {
            break;
        }
        q = (struct stu*)malloc(sizeof(struct stu));
        if(NULL == q)
        {
            printf("malloc failed\n");
            return;;
        }
        printf("please input student's number >");
        scanf("%d", q->number);
        printf("please input student's name >");
        scanf("%s", q->name);
        printf("please input student's consum money >");
        scanf("%d", q->consum);
        q->next = p->next;
        p->next = q;
        p = q;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
