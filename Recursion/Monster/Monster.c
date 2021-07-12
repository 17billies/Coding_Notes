#include <stdio.h>
int k;
int stand;
int cox[]={0, 1};
int coy[]={1, 0};
int visited[5][5]={0};
typedef struct Char{
    int hp;
    int attack;
    int x;
    int y;
}Char;

typedef struct Mon{
    Char mon[26];
}Mon;
int encounter(int x, int y, Mon *m);
int battle(Char *hero, Mon *mon);
int can_go(int x, int y);
int dfs( int x, int y, Char *hero, Mon *m);
int main(){
    Char ash;
    Mon m;
    scanf("%d %d %d",&ash.hp, &ash.attack, &k);
    for(int i = 0; i < k; ++i){
        scanf("%d %d %d %d", &m.mon[i].hp, &m.mon[i].attack, &m.mon[i].x, &m.mon[i].y);
    }
    if(dfs(1, 1, &ash, &m))printf("HEIR OF FIRE DESTROYED\n");
    else printf("YOU DIED\n");
    return 0;
}

int encounter(int x, int y, Mon *m){
    for(int i = 0; i < k; ++i){
        if(m->mon[i].x == x && m->mon[i].y == y){
            stand = i;//save the monster's index for the battle function
            return 1;
        } 
    }
    return 0;
}

int battle(Char *hero, Mon *mon){
    Char h =*(Char*)hero;
    Mon m =*(Mon*)mon;
    int j = 0;
    while( h.hp > 0 && m.mon[stand].hp > 0){
        if(j % 2 == 0){
            m.mon[stand].hp -= h.attack;
            if(m.mon[stand].hp <= 0) return 1;
        }
        else{
            h.hp -= m.mon[stand].attack;
            if(h.hp <= 0) return 0;
        }
        ++j;
    }
}

int can_go(int x, int y){
    if(x > 5 | y > 5) return 0;
    else return 1;
}



int dfs( int x, int y, Char *hero, Mon *m){
    Char h = *(Char*)hero;
    h.x = x;
    h.y = y;//initial where the hero stand
    if(encounter(h.x, h.y, m)){//to determine if the hero encounter the monster
        if(!battle(hero, m)){
            return 0;//to determine if the hero can fight over the monster
        }
    }
    if(h.x == 5 && h.y == 5){//if the hero has fought over the monster and reach the end
        return 1;
    }
    for(int i = 0; i < 2; i++){//to move in two directions
        if(can_go(x + cox[i], y + coy[i])){//to make sure the hero is in the 5*5 array
            visited[x + cox[i]][y + coy[i]] = 1;//mark it as visited
            if(dfs( x + cox[i], y + coy[i], hero, m)){
                return 1;
            }
            visited[x + cox[i]][y + coy[i]] = 0;
        }
    }
    return 0;
}
