#include <stdio.h>
#include <stdlib.h>

struct student
{
    char usn[20], name[20], prog[20], phno[15];
    int sem;
    struct student *next;
};

struct student *head = NULL;

void insert_front()
{
    struct student *n = malloc(sizeof(struct student));
    scanf("%s %s %s %d %s",
          n->usn, n->name, n->prog, &n->sem, n->phno);
    n->next = head;
    head = n;
}

void insert_end()
{
    struct student *n = malloc(sizeof(struct student));
    struct student *t = head;

    scanf("%s %s %s %d %s",
          n->usn, n->name, n->prog, &n->sem, n->phno);
    n->next = NULL;

    if (head == NULL) { head = n; return; }

    while (t->next) t = t->next;
    t->next = n;
}

void delete_front()
{
    head = head->next;
}

void delete_end()
{
    struct student *t = head;
    while (t->next->next) t = t->next;
    t->next = NULL;
}

void display()
{
    struct student *t = head;
    int c = 0;

    while (t)
    {
        printf("%s %s %s %d %s\n",
               t->usn, t->name, t->prog, t->sem, t->phno);
        t = t->next;
        c++;
    }
    printf("Nodes = %d\n", c);
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1.IF 2.IE 3.DF 4.DE 5.DIS 6.EXIT\n");
        scanf("%d", &ch);

        if (ch == 1) insert_front();
        else if (ch == 2) insert_end();
        else if (ch == 3) delete_front();
        else if (ch == 4) delete_end();
        else if (ch == 5) display();
        else break;
    }
}
