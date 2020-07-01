#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN sizeof(struct stu)

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
//void add(struct stu *l);
void show(struct stu *l);
void save(struct stu *l);
void stringoutput(struct stu *l);
void menu();

void menu()
{
    printf("\n\t**********************************************************\n");
    printf("\t|*                       0.exit                            |\n ");
    printf("\t|*                       1.create                          |\n ");
    printf("\t|*                       2.load                            |\n ");
    printf("\t|*                       3.search                          |\n ");
    printf("\t|*                       4.delete                          |\n ");
    printf("\t|*                       5.add                             |\n ");
    printf("\t|*                       6.save                            |\n ");
    printf("\t|*                       7.show                            |\n ");
    printf("\t**********************************************************\n");
}

void stringoutput(struct stu *l)
{
    if (NULL == l)
        return;
    printf("|%d\t|%s|\t|%d\t|\n", l->number, l->name, l->consum);
}

void creat(struct stu *l)
{
    if (NULL == l)
        return;
    struct stu *p = l;
    int x = -1;
    struct stu *q = NULL;
    while (1)
    {

        printf("please input student's information,input 0 to exit!\n");
        if(getchar()=='0'){
            getchar();
            break;
        }
        q = (struct stu *)malloc(sizeof(struct stu));
        if (NULL == q)
        {
            printf("malloc failed\n");
            return;
            ;
        }
        printf("please input student's number >");
        scanf("%d", &q->number);
        printf("please input student's name >");
        scanf("%s", q->name);
        printf("please input student's consum money >");
        scanf("%d", &q->consum);
        getchar();
        q->next = p->next;
        p->next = q;
        p = q;
    }
}

void load(struct stu *p)
{
    if (NULL == p)
        return;
    struct stu *p1;
    int m = 0;
    char filepn[10];
    FILE *fp;

    printf("please input file's postion and its name:");
    scanf("%s", filepn);
    if ((fp = fopen(filepn, "r+")) == NULL)
    {
        printf("can't open this file!\n");
        getchar();
        return;
    }
    else
    {
        while (feof(fp))
        {
            p1 = (struct stu *)malloc(LEN);
            fscanf(fp, "%d%s%d", &p1->number, p1->name, &p1->consum);
            printf("|%d\t|%s\t|%d\t|\n",p1->number, p1->name, p1->consum);
            p1->next = p->next;
            p->next = p1;
        }
    }
    fclose(fp);
}

void search(struct stu *l)
{
    //判断合法性
    //定义一个容器存放学生的号码
    if (NULL == l)
        return;
    struct stu *p = l->next;
    int temp;
    //需要遍历链表
    printf("Input the number of student you want to search:");
    scanf("%d", &temp);
    getchar();

    while (p)
    {
        if (p->number == temp)
        {
            stringoutput(p);
            break;
        }
    }
    printf("Not found the student\n");
}

void delete (struct stu *l)
{
    if (NULL == l)
        return;
    struct stu *p = l->next;
    struct stu *q = l;
    int x;

    printf("Input the number you want to delete:");
    scanf("%d", &x);

    while (p)
    {
        if (p->number == x)
        {
            q->next = p->next;
            free(p);
            break;
        }
        p = p->next;
        q = q->next;
    }

    printf("Not found the student\n");
}

void show(struct stu *l)
{
    if (NULL == l)
        return;
    struct stu *p = l->next;
    while (p)
    {
        stringoutput(p);
        p = p->next;
    }
}

void save(struct stu *l)
{
    char buf[10];
    FILE *fp;
    struct stu *q;
    q = l->next;

    printf("please input the file you want to save:");
    scanf("%s", buf);
    if ((fp = fopen(buf, "w+")) == 0)
    {
        printf("create failed");
    }
    else
    {
        while (q)
        {
            fprintf(fp, "%d %s %d\n", q->number, q->name, q->consum);
            q = q->next;
        }
    }
    fclose(fp);
}

int main(int argc, char const *argv[])
{
    struct stu *p = NULL;
    p = (struct stu *)malloc(LEN);
    int x;
    while (1)
    {
        menu();
        printf("                please input your choose:");
        scanf("%d", &x);
        getchar();
        switch (x)
        {
        case 0:
            exit(1);
            break;
        case 1:
            creat(p);
            break;
        case 2:
            load(p);
            break;
        case 3:
            search(p);
            break;
        case 4:
            delete(p);
            break;
        case 6:
            save(p);
            break;
        case 7: 
            show(p);
            break;
        default:
            break;
        }
    }
    
    return 0;
}
