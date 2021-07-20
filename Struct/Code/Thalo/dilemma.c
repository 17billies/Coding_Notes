#include<stdio.h>
#include<stdlib.h>
#define Mod 1000000007

typedef struct Mat{
    long long int a[3][3];
} Mat;
Mat matmul (Mat A, Mat B){
    Mat res;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            res.a[i][j] = 0;
        }
    }//make sure the array is empty
    for(int i =0; i < 3; ++i){
        for(int j =0; j < 3; ++j){
            for(int k =0; k < 3; ++k){
                res.a[j][i] +=(A.a[k][i] * B.a[j][k]) % Mod;
            }
            res.a[j][i] %= Mod;
        }
    }
    return res;
}
Mat fpw(Mat A, long long int k){
    Mat res;
    if(k == 1)return A;//no need to fpw
    res = fpw(A, k/2);//recursion
    if(k % 2 == 0){
        return matmul(res, res);
    }
    else{
        return matmul(A, matmul(res, res));
    }
}
int main(){
    Mat A, B;
    int t;
    long long int k;
    //to assure the array is empty
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            A.a[i][j] = 0;
            B.a[i][j] = 0;
        }
    }
    //setup the A and B array
    A.a[0][0] = 1;
    A.a[0][1] = 1; 
    A.a[1][0] = 2; 
    A.a[1][2] = 1;
    A.a[2][0] = 1;
    B.a[0][0] = 13;
    B.a[0][1] = 12;
    B.a[0][2] = 1;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        scanf("%lld", &k);
        if(k <= 3){
            printf("%lld\n", B.a[0][3-k]);
        }
        else{
            printf("%lld\n", matmul(fpw(A, k-3), B).a[0][0]);
        }
    }
    return 0;
}