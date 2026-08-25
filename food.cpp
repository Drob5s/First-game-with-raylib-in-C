//
//  objects.c
//  C_game_project
//
//  Created by Robs on 2026-06-23.
//

#include "declarations.h"

food* create_food(void){ // the food will be a small circle
    food* f = malloc(sizeof(food));
    f->point.x = rand()%15;
    f->point.y = rand()%3;
    f->active = 1;
    return f;
}

void draw_food(food* f){
    lcd.setCursor(f->point.x,f->point.y);
    lcd.print('0');
}

_Bool collision_with_food(snake* s, food* f){
    if(f==NULL || s==NULL){
        return 0;
    }
    if(s->place[0].x==f->point.x && s->place[0].y==f->point.y){
        return 1;
    }
    else{
        return 0;
    }
}
