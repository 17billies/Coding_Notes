
#include <stdio.h>
#include <stdlib.h>
#define MAXNV 5
int DONE = 0;//record how many times to pour water into the bottle
int liters[MAXNV]={0};
int numbers[MAXNV];
void show(int nv);
void filling(int amount, int cur, int nv);
int j=0;//set in global to avoid j turn into 0 when recursion call
int water;
int min=100;//to record the minimum of the method since there would be several ways
int min_numbers[MAXNV]={0};//to record the minimum amount of each liter
int main(void){
    int nv, i;

    scanf("%d", &nv);
    for (i=0; i<nv; i++) {
        scanf("%d", &liters[i]);
    }
    scanf("%d", &water);
    filling(water, 0, nv);

    for(i=0;i<nv;i++)
        numbers[i]=min_numbers[i];
    show(nv);
    return 0;
}

void show(int nv){
    int i;
    printf("(%d", numbers[0]);
    for (i=1; i<nv; i++) {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}

void filling(int amount, int cur, int nv){//cur to record how many water has been pour into the bottle
    if( amount == cur && DONE < min ){ //determine if the method is smaller than the current min amount
        min = DONE;
        for(int i = 0; i < nv; ++i) min_numbers[i] = numbers[i];
        return;
     }
    for(int i = j; i < nv; i++){ //to let the recursion start at the former liter index
        j = i;
        if(liters[i] > amount - cur) continue; // next: liters[i+1]
        else{
            DONE++;
            numbers[i]++;
            filling(amount, cur + liters[i], nv); //change the amount in the bottle and run the recursion again
            DONE--;
            numbers[i]--;
        }
    }
}

/*
<1>
4
39 38 37 1
183
<2>
1
1
19
*/