//
//  objects.c
//  C_game_project
//
//  Created by Robs on 2026-06-23.
//

#include "declarations.h"

food* create_food(void){ // the food will be a small circle
    food* f = malloc(sizeof(food));
    f->point.x = rand()%50;
    f->point.y = rand()%30;
    f->active = 1;
    return f;
}

void draw_food(food* f){
    DrawCircle(f->point.x * CELLSIZE + CELLSIZE/2, f->point.y * CELLSIZE + CELLSIZE/2 , CELLSIZE/2 , BLACK);
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
