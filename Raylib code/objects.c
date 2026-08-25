//
//  objects.c
//  C_game_project
//
//  Created by Robs on 2026-07-23.
//
#include "declarations.h"
object* create_object(void){ // the food will be a small circle
    object* obj = malloc(sizeof(object));
    obj->point.x = rand()%50;
    obj->point.y = rand()%30;
    obj->active = 1;
    return obj;
}

void draw_object(object* obj){
    Vector2 center= {
        obj->point.x * CELLSIZE + CELLSIZE/2.0f,
        obj->point.y * CELLSIZE + CELLSIZE/2.0f
    };
    
    DrawPoly(center, 5, CELLSIZE/2.5f, 180.0f, BLACK);
}

_Bool collision_with_object(snake* s , object* obj){
    if(obj==NULL){
        return 0;
    }
    for(int i =0; i<s->size;i++){
        if(s->place[i].x == obj->point.x && s->place[i].y== obj->point.y){
            return 1;
        }
    }
    return 0;
}
