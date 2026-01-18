#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
    char usn[20], name[20], prog[20], phno[15];
    int sem;
    struct student *next;
}; 

struct student *head = NULL;

void insert_front() {
    struct student *new = malloc(sizeof(struct student));

    printf("Enter USN Name Programme Sem PhNo:\n");
    scanf("%s %s %s %d %s", new->usn, new->name, new->prog, &new->sem, new->phno);

    new->next = head;
    head = new;
}

void insert_end() {
    struct student *new = malloc(sizeof(struct student));
    struct student *temp = head;

    printf("Enter USN Name Programme Sem PhNo:\n");
    scanf("%s %s %s %d %s", new->usn, new->name, new->prog, &new->sem, new->phno);

    new->next = NULL;

    if (head == NULL) {
        head = new;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new;
}


void delete_front() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    struct student *temp = head;
    head = head->next;
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    struct student *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void display() {
    struct student *temp = head;
    int count = 0;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%s %s %s %d %s\n",
               temp->usn, temp->name, temp->prog, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Total nodes: %d\n", count);
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert Front\n2.Insert End\n3.Delete Front\n4.Delete End\n5.Display\n6.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_front(); break;
            case 2: insert_end(); break;
            case 3: delete_front(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
