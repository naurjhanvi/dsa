#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int stack[MAX], top=-1,c,item;
void push(int x){
    if(top==MAX-1){
        printf("stack overflow");
        return;
    }
    stack[++top] = x;
}

void pop(){
    if(top==-1){
        printf("stack underflow");
        return;
    }
    printf("popped element is %d",stack[top--]);

}

void checkCurrentStackPalindrome() {
    if (top == -1) {
        printf("Stack is empty, cannot check palindrome.\n");
        return;
    }

    int isPalindrome = 1;
    int n = top + 1; // Number of elements currently in stack
    
    // We compare elements from the bottom (0) and the top (top)
    // and move towards the middle.
    for (int i = 0; i < n / 2; i++) {
        if (stack[i] != stack[top - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("The current stack elements form a palindrome!\n");
    else
        printf("The current stack elements do NOT form a palindrome.\n");
}

void display(){
    printf("elements in the stack are:\n");
    for(int i = top;i>=0;i--){
        printf("%d",stack[i]);
    }
}

int main(){
    do{
        printf("MENU\n1.Push\t\t2.Pop\t\t3.Display\t\t4.Palindrome\t\t5.Exit\n");
        printf("enter your choice: ");
        scanf("%d",&c);

        switch(c){
            case 1: printf("enter the element to be pushed: ");
            scanf("%d",&item);
            push(item);
            break;

            case 2: pop();
            break;

            case 3: display();
            break;

            case 4:checkCurrentStackPalindrome();
            break;

            case 5: exit(0);

            default:
            printf("invalid choice");

        }
    }while(c!=5);
    return 0;

}