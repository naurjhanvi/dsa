#include<stdio.h>
#include<stdlib.h>

struct day{
    char *dayName;
    int date;
    char *activity;
};

void create(struct day *cal){
    for(int i = 0; i < 7; i++) {
        cal[i].dayName = (char*)malloc(20 * sizeof(char));
        cal[i].activity = (char*)malloc(30 * sizeof(char));
    }
}

void read(struct day *cal){
    for(int i=0;i<7;i++)
    {
        printf("enter the day and date:");
        scanf("%s %d",cal[i].dayName,&cal[i].date);
        printf("enter the activity for day%d:",i+1);
        scanf("%s",cal[i].activity);

    }
    
}

void display(struct day *cal){
    printf("\nDAY\t\tDATE\tACTIVITY\n");
    for(int i = 0; i < 7; i++) {
        printf("%s\t\t%d\t%s\n", cal[i].dayName, cal[i].date, cal[i].activity);
    }
}

int main(){
    struct day *calendar;
    calendar = (struct day*)malloc(7 * sizeof(struct day));
    create(calendar);
    read(calendar);
    display(calendar);
    return 0;
}
