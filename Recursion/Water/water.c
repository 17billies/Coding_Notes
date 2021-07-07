
#include <stdio.h>
#include <stdlib.h>
#define MAXNV 10
int DONE = 0;
int liters[MAXNV]={0};
int numbers[MAXNV];
int count[MAXNV]={0};
void show(int nv);
void filling(int amount, int cur, int nv);
int j=0;
int water;
int min=100;
int temp=0;
int min_numbers[MAXNV]={0};
int main(void){
    int nv, i;

    scanf("%d", &nv);
    for (i=0; i<nv; i++) {
        scanf("%d", &liters[i]);
    }
    scanf("%d", &water);
    min=water;
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

void filling(int amount, int cur, int nv){//where we have to write
    int times=0;
    
    if(amount==0){
        DONE++;
        if(temp<min){
            min=temp;
            //printf("%d\n",min);
            for(int i=0;i<nv;++i){
                min_numbers[i]=count[i];
                //printf("==%d\n",min_numbers[i]);
            }
            count[cur]=0;
        }
        return;
    }
    for(int i=cur;i<nv;++i){
        //printf("i==%d, temp==%d ,amount==%d\n",i,temp,amount);
        while(amount>=liters[i]){
            temp++;
            count[i]++;
            amount-=liters[i];
        }
        //printf("amount==%d\n",amount);
        filling(amount,i+1,nv);
        amount+=count[i]*liters[i];
        temp-=count[i];
        count[i]=0;
        
    }
    return;
}
   


    
    
        


