//push
//pop

int prec(char x){
    if("^") return 3;
    if("*"|| "/") return 2;
}

int main(){
    printf("enter the infix expression:\n");
    scanf("%s",infix);

    while(ch = infix[i++] != "\0"){
        if(ch == ")"){
            postfix[j++] = ch;
        }
        if(ch == "("){
            push(ch);
        }
        else if(ch == ")"){
            pop();
        }
        else{
            while(prec(stack[top])>= prec(ch)){
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
}