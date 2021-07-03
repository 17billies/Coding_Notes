# 程式設計一筆記整理
## 目錄
[TOC]

## 時間複雜度($O(f(n)$)
Def: 當輸入n筆資料時，此function所需要花費的時間。通常指最差情況複雜度(就是在最衰的情況，同一種輸入所需要花最長的時間)

| 執行時間 | 白話文 |例子|
|:------ |:------- |:---------|
| $$O(1)$$   | 不管輸入多少東西，都不影響求出答案的時間範圍。其中$1$可被替換成任意常數。 |printf("%d",book[237])
| $$O(n)$$  | 假設要從$n$個人當中找出拿著筆的人，從第一個人問到第$n$個人，時間複雜度會隨$n$的數目增大而線性增加。 |簡易搜尋|
| $$O(n^2)$$  | 呈上例，在問第一個人時同時叫他也去依序問其他$n-1$個人，這樣執行$n$次。此時時間複雜度會依照$n$增加，以$n^2$圖形增加|**[泡沫排序法](https://hackmd.io/@VSCwqJYJSXeRPkfDpYnbnQ/Sy79MIyju#%E6%B0%A3%E6%B3%A1%E6%8E%92%E5%BA%8F%E6%B3%95Bubble-Sort)**|
| $$O(\log n)$$  |以二分搜尋法為例，在執行當中一次過濾掉資料的一半 ，所以當資料數目增加，時間複雜度會以$\log_2n$圖形增加|二分搜尋法

>寫完發現真的不能不放圖

![time complexity](https://ithelp.ithome.com.tw/upload/images/20181020/20112011LzUSOSLEC0.png)



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




