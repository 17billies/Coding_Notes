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

## 遞迴(Recursion)

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

## 結構(Struct)

結構又可稱為自訂資料型別，可以把不同型別的變數、陣列、指標集合在一個自訂的資料型別中統一宣告。

為了寫起來比較順暢，一般會搭配typedef使用

### Without typedef
如果沒有typedef，每一次設一次struct的變數就要在自訂型別前面加一個struct。

```C=
//struct without typedef

#include <stdio.h>
struct student{
    char name[20];
    int ID;
};

int main(){
    struct student//結構體名稱  boy//結構體變數名稱;
    struct student girl;
    scanf("%s %d", girl.name, &girl.ID);
    scanf("%s %d", boy.name, &boy.ID);
    
    printf("boy name:%s boy ID:%d\n", boy.name, boy.ID);
    printf("girl name:%s girl ID:%d\n", girl.name, girl.ID);
}

```
另外一種寫法就是在宣告結構體的時候就把結構體變數設好(那她就會是一個全域的變數)：
```C=
//struct without typedef

#include <stdio.h>
struct student//結構體名稱{
    char name[20];
    int ID;
}Mary;//結構體變數名稱

int main(){
    scanf("%s %d", Mary.name, &Mary.ID);
    printf("Mary name:%s Mary ID:%d\n", Mary.name, Mary.ID);
    return 0;
}
```
### typedef
程設課教授是直接教我們用typedef，阿學得不明不白就會每次加分號都加得不明不白，現在把它搞懂。
```C=
#include <stdio.h>
typedef unsigned long long int LLD;
int main(){
    LLD huge;
    scanf("%lld", &huge);
    printf("%lld\n", huge);
    return 0;
}
```
這樣看起來typedef 和 #define 有點像，但其實還是有差別。主要是因為執行時間的不同造成他們在code裡面的效果也不同：
| | typedef |#define|
|:------ |:------- |:---------|
|執行|編譯器|預處理器(編譯前被置換掉之後，編譯器是沒辦法再判讀define的東西)|
|可替換東西|型態|型態、數值|
|連續定義變量|能確保所有變量都是同一個類型|不能保證|
|封裝後擴增|(封裝性)定義後就不能增加別的東西|定義後能增加|

上面提到，當連續定義變量時，#define不能確保都是同一個類型，來舉個例子
```C=
#include<stdio.h>
#define INT int*
typedef int* Int;


int main(){
    INT a, b;//a是指標(int*)，但是b還是int
    Int c, d;
    b = 20;
    printf("%p %d\n", a, b);
    printf("%p %p\n", c, d);
    return 0;
}
/*
Output
00000035 20
00000000 00401620
*/
```

>順帶一提，#define沒有辦法直接拿來定義struct，需要先定義完struct再用#define去置換

回到struct，當struct加上typedef
```C=
#include <stdio.h>
typedef struct student//這個命名可寫可不寫{
    char name[20];
    int ID;
} student;
//將 struct student{...} 用 student 替代

int main(){
    student boy;
    student girl;
    scanf("%s %d", girl.name, &girl.ID);
    scanf("%s %d", boy.name, &boy.ID);
    
    printf("boy name:%s boy ID:%d\n", boy.name, boy.ID);
    printf("girl name:%s girl ID:%d\n", girl.name, girl.ID);
    return 0;
}
```
### struct 指標表示和非指標表示
一個struct 裡面可能回包括很多個int變數以及char變數(目前學到的)，所以如果要指定struct裡面的某個變數時，就會表示成「結構體變數.變數」，但struct是以指標型式存在在function中，表示法則為「結構體變數->變數」。
```C=
#include <stdio.h>
typedef struct student{
    char name[20];
    int num;
} student;
void exchange_id(student *boy, student *girl);
void add_id(student girl);

int main(){
    student boy;
    student girl;
    scanf("%s %d", girl.name, &girl.num);
    scanf("%s %d", boy.name, &boy.num);
    exchange_id(&boy, &girl);//傳入指標
    add_id(girl);//傳入變數值
    printf("boy name:%s boy ID:%d\n", boy.name, boy.num);
    printf("girl name:%s girl ID:%d\n", girl.name, girl.num);
}

void exchange_id(student *boy, student *girl){
    int temp;
    temp = boy->num;
    boy->num = girl->num;
    girl->num = temp;
}

void add_id(struct student girl){
    girl.num += 10;
}

/* 
Input: 
Kelly 110
John 510

Output:
boy name:John    boy ID:110
girl name:Kelly  girl ID:510
*/
```
當function add_id傳入的只有變數值，即使執行完function，girl.name本身的值並不會有改變。相對的，function exchange_id傳入的是指標，所以執行之後，boy.num 和 girl.num 就會交換。

## Linked List









