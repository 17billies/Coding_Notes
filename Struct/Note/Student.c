#include <stdio.h>
typedef struct student{
    char name[20];
    int ID;
} student;
void exchange_id(student *boy, student *girl);
void add_id(student girl);

int main(){
    student boy;
    student girl;
    scanf("%s %d", girl.name, &girl.ID);
    scanf("%s %d", boy.name, &boy.ID);
    exchange_id(&boy, &girl);
    add_id(girl);
    printf("boy name:%s boy ID:%d\n", boy.name, boy.ID);
    printf("girl name:%s girl ID:%d\n", girl.name, girl.ID);
}

void exchange_id(student *boy, student *girl){
    int temp;
    temp = boy->ID;
    boy->ID = girl->ID;
    girl->ID = temp;
}

void add_id(struct student girl){
    girl.ID += 10;
}