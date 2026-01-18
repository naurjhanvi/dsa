#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int prec(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char infix[20], postfix[20];
    int i = 0, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    while ((ch = infix[i++]) != '\0') {

        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            push(ch);

        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }

        else {
            while (prec(stack[top]) >= prec(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
        return 0;
}