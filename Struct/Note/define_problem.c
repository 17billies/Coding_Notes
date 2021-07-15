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
