//11662
#include<stdio.h>
void find_seq(int *A, int cur, int n);
int B[2050] = {0};
int k = 1;
int main(){
    int A[2050] = {0};
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d" ,&A[i]);
    find_seq(A, 1, n);
    for(int i = 1; i <= n; ++i) printf("%d%c", B[i], ' '*(i != n)+'\n'*(i == n));
    return 0;
}

void find_seq(int *A, int cur, int n){
    if(A[cur] == 0) return; //means the index is empty
    find_seq(A, 2*cur, n);
    B[k] = A[cur];
    k++;
    if(A[2*cur+1] != 0) find_seq(A, 2*cur+1, n);  
}