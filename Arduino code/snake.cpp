//
//  definitions.c
//  C_game_project
//
//  Created by Robs on 2026-06-23.
//

#include "declarations.h"
snake* create_snake(void){
    snake* s = malloc(sizeof(snake));
    assert(s!=NULL);
    s->size =3;
    s->place=malloc(sizeof(grid)*s->size);
    for(int i=0;i<s->size;i++){
        s->place[i].x=s->size-1-i;
        s->place[i].y=0;
        s->velocity =2;
    }
    s->direction = RIGHT;
    return s;
}


//movement of snake
void move_snake(snake* s){
    assert(s!=NULL);

     if (s->size > 1) {
        if (s->direction == RIGHT && s->place[1].x == s->place[0].x + 1) s->direction = LEFT;
        if (s->direction == LEFT  && s->place[1].x == s->place[0].x - 1) s->direction = RIGHT;
        if (s->direction == DOWN  && s->place[1].y == s->place[0].y + 1) s->direction = UP;
        if (s->direction == UP    && s->place[1].y == s->place[0].y - 1) s->direction = DOWN;
    }

    grid prev = s->place[0];

    switch (s->direction) {
        case RIGHT:
            s->place[0].x++;
            break;
        case DOWN:
            s->place[0].y++;
            break;
        case LEFT:
            s->place[0].x--; 
            break;
        case UP:
            s->place[0].y--;
            break;
    }
        
    for(int i =1; i<s->size;i++){
        grid curr = s->place[i];
        s->place[i]=prev;
        prev = curr;
            }
}

