#include<stdio.h>

int m,i,h[20],n,index,key;
void init(int m){
    for(i=0;i<m;i++){
        h[i]=-1;
    }
}

void insert(int key, int m){
    index= key %m;

    while(h[index]!=-1){
        index=(index+1)%m;
    }
    h[index]=key;
}

void display(){
    printf("the details are:\n");
    for(i=0;i<m;i++){
        printf("Address %d: %d",i,h[i]);
    }
}

int main(){
    printf("enter the hash table size:");
    scanf("%d",&m);

    init(m);

    printf("enter the number of employees:");
    scanf("%d",&n);

    printf("enter the details:\n");
    for(i=0;i<n;i++){
        scanf("%d",&key);
        insert(key,m);
    }
    
    display();
    return 0;
}