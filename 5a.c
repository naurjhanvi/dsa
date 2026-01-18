#include<stdio.h>
#include<math.h>
#include<ctype.h>

int stack[20],top=-1;

void push(int x){
    stack[++top]=x;
    return;
}

int pop(){
    return stack[top--];
}

int main(){
    char postfix[20],ch;
    int i=0,op1,op2;
    printf("enter the postfix expression: ");
    scanf("%s",postfix);
    while((ch=postfix[i++])!= '\0'){
        if(isdigit(ch)){
            push(ch-'0');
        }
        else{
            op2=pop();
            op1=pop();

            switch(ch){
                case '+':push(op1+op2);break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 % op2); break;
                case '^':push(pow(op1,op2));break;
            }
        }
    }
    printf("result=%d",pop());
    return 0;
}