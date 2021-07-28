/*OXOX (2)
OXXO
OOOO
OOXX
XXOO
XXXX
XOOX*/
//recursion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXBITS 16

char bits[3];
char input [MAXBITS+1];
char answer [MAXBITS+1];
int NBITS;
void check_bits(int cur_bit, int num_hits);
char flip(char ch);

int main(void){
    int nhits;
    scanf("%2s", bits);
    scanf("%s", input);
    NBITS = strlen(input);
    answer[NBITS] = '\0';
    scanf("%d", &nhits);
    check_bits(0, nhits);
    return 0;
}

void check_bits(int cur_bit, int num_hits){
    if(cur_bit == NBITS){
        if(num_hits == 0){
            printf("%s\n", answer);
        }
    }
    else{
        if(num_hits > 0){
            answer[cur_bit] = input[cur_bit];
            check_bits(cur_bit + 1, num_hits - 1);
        }
        answer[cur_bit] = flip(input[cur_bit]);
        check_bits(cur_bit + 1, num_hits);//when return, switch the correct one to the next index
    }
}

char flip(char ch){
    return ( (ch == bits[0]) ? bits[1] : bits[0] );
    //if(ch == bits[0]) return bits[1]
    //else return bits[0]
}
