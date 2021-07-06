#include <stdio.h>
#include <stdlib.h>
#define MAXNV 5
int DONE = 0;
int liters[MAXNV];
int numbers[MAXNV];
void show(int nv);
int cmp(const void *a, const void *b);
void filling(int amount, int cur, int nv);
int j=0;
int water;
int min=100;
int min_numbers[MAXNV]={0};
int main(void){
    int nv, i;

    scanf("%d", &nv);
    for (i=0; i<nv; i++) {
        scanf("%d", &liters[i]);
    }
    qsort(liters,nv,sizeof(liters[0]),cmp);
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

void filling(int amount, int cur, int nv){
    
    if(amount<=DONE){
        return;
    }
    
    if(liters[cur]<=amount){
        min_numbers[cur]++;
        amount-=liters[cur];
        filling(amount,cur,nv);
    }
    else if(cur==nv-1){
        amount-=liters[cur];
        min_numbers[cur]++;
        filling(amount,cur,nv);
    }
    else{
        filling(amount,cur+1,nv);
    }
        
}

int cmp(const void *a, const void *b)//reminder:a pointer in the input
{
      int c = *(int*)a;
    int d = *(int*)b;

      if(c > d) {return -1;}
      else if (c == d) {return 0;}
      else return 1;
}