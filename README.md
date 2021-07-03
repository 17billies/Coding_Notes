


>遞迴的設計：
>
>1.找出遞迴的終止條件
>
>2.找出問題本身的遞迴關係



```C=
//Factorial
#include <stdio.h>
int main(){
    int n = 4, fact;
    fact = factorial(n);
    printf("%d",fact);

    return 0;
}

int factorial(int n){ //n為參數值
    int temp_fact; //區域變數

    if(n == 1) temp_fact = 1; //終止條件
    else temp_fact = n * factorial(n-1);//遞迴關係

    return temp_fact;
}
```
當程式遇到遞迴呼叫，須保存當時的執行狀態
>push 資料到 stack memory
>
>資料:
>1. 參數值 ( int n )
>2. 區域變數值( int temp_fact )
>3. 回傳位址

而Stack (堆疊) 是一種 FILO (先進後出) 的資料結構

![recursion](https://1.bp.blogspot.com/-xFvScD_zgm4/U730S6ZXgmI/AAAAAAAAAEk/kt9sN4Cx59U/s1600/38_Factorial_Recursion_detailed.png)




