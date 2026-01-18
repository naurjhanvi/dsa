#include<stdio.h>

struct day{
    char *dayName;
    int date;
    char *activity;
};

void create(struct day *cal){
    for(int i =0; i<7; i++){
        cal[i].dayName = (char*)malloc(20* sizeof(char));
        cal[i].activity = (char*)malloc(30* sizeof(char));
    }
}

void read(struct day *cal){
    printf("enter the details:\n");
    for(int i =0; i<7; i++){
        printf("DAY\t\tDATE\t\tACTIVITY\n");
        scanf("%s %d %s",cal[i].dayName, &cal[i].date, cal[i].activity);
    }
}

void display(){
    printf("details ar");
}

int main(){
    struct day *calendar;
    calendar = (struct day*)malloc(7 * sizeof(struct day));
    create(calendar);
}