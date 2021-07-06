//11209
#include <stdio.h>

int col[50]={0},cnt1[50]={0},cnt2[50]={0};
int n,ans=0;
void queen(int row);
int qtest(int x, int y);
int main(){
    scanf("%d",&n);
    queen(0);
    printf("%d",ans);
    return 0;
}
int qtest(int x, int y){
    if(col[y]!=1 && cnt1[y-x+10]!=1 && cnt2[x+y]!=1) return 0;
    else return 1;
}



void queen(int row){//start from the first(0) row
    if(row==n){//when row equals to n, means that 0~n-1 row has been tested
        ans++;
        return;
    }
    for(int y=0;y<n;++y){//controlling the column coordinate
        if(qtest(row,y)==0){
            col[y]=1;
            cnt1[y-row+10]=1;
            cnt2[row+y]=1;
            queen(row+1);
            col[y]=0;
            cnt1[y-row+10]=0;
            cnt2[row+y]=0;

        }

    }

}
