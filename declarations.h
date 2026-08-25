//
//  declarations.h
//  C_game_project
//
//  Created by Robs on 2026-06-23.
//

#ifndef declarations_h
#define declarations_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <LiquidCrystal.h>
extern LiquidCrystal lcd;
#define FPS 1


typedef struct grid{
    int x;
    int y;
}grid;

typedef enum{
    UP,
    DOWN,
    LEFT,
    RIGHT,
}direction;

typedef struct snake{
    grid* place;
    int size;
    int velocity; // max velocity will be 4, this is how many grids the snake covers per frame
    direction direction;
}snake;

typedef struct food{
    grid point;
    _Bool active;
}food;

typedef struct object{
    grid point;
    _Bool active;
} object;

snake* create_snake(void);

food* create_food(void);

void draw_food(food* f);

_Bool collision_with_food(snake* s, food* f);

void move_snake(snake* s);

object* create_object(void);

void draw_object(object* obj);

_Bool collision_with_object(snake* s, object* obj);
#endif declarations_h
