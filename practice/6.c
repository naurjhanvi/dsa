int isempty(){
    if(top == -1 || front == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(){
    if(top == max-1){
        return 1;
    }
    else{
        return 0;
    }
}
int insert(char x){
    //full //overflow

    if(front == -1)
        front = 0;
    printf("enter the element to be inserted")
    scanf
    cq[rear] = ch;
    rear = (rear+1)%max;
}

int delete(){
    //empty //underflow

    if(front == rear){
        front = rear = -1;
    }
    printf("elements del is %s", cq[front]);
    front = (front+1)%max;
}

int display(){
    
}