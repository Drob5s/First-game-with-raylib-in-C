#include "declarations.h"


int main(void)
{
    InitWindow(1000, 600, "Snake game");
    SetTargetFPS(30);
    int count = 0;
    snake* s = create_snake(); //creates snake and initialize the position
    food* f = NULL;
    object* obj1 = NULL;
    object* obj2 = NULL;
    int food_timer = 0;
    int obj1_timer= 0;
    int obj2_timer=0;
    int strike= 3;
    _Bool game_over = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        
        if(!game_over){
            count++;
            
            //drawing the snake
            for(int i=0;i<s->size;i++){
                DrawRectangle(s->place[i].x * CELLSIZE, s->place[i].y * CELLSIZE,CELLSIZE,CELLSIZE, ORANGE);
            }
            
            if(IsKeyPressed(KEY_DOWN) && s->direction!=UP){
                s->direction = DOWN;
            }
            if(IsKeyPressed(KEY_UP) && s->direction!=DOWN){
                s->direction= UP;
            }
            if(IsKeyPressed(KEY_RIGHT) && s->direction!=LEFT){
                s->direction = RIGHT;
            }
            if(IsKeyPressed(KEY_LEFT) && s->direction!=RIGHT){
                s->direction = LEFT;
            }
            //snake movement
            if(count%(30/(s->velocity))==0){
                move_snake(s);
            }
            
            //creating and drawing the food every 10 seconds
            if(count%300==0 && f == NULL){
                f= create_food();
                food_timer= count+240;
            }
            if(f!=NULL && f->active){
                draw_food(f);
            }
            if(count>food_timer){
                free(f);
                f=NULL;
            }
            
            //creating and drawing the object
            if(count%600==0 && (obj1==NULL || obj2==NULL)){
                obj1 = create_object();
                obj1_timer = count + 300;
                obj2 = create_object();
                obj2_timer = count + 300;
            }
            if(obj1!=NULL && obj1->active){
                draw_object(obj1);
            }
            if(obj2!=NULL && obj2->active){
                draw_object(obj2);
            }
            if(count>obj1_timer && count>obj2_timer){
                if(obj1!=NULL){
                    free(obj1);
                    obj1 = NULL;
                }
                if(obj2!=NULL){
                    free(obj2);
                    obj2=NULL;
                }
                obj1 = NULL;
                obj2 = NULL;
            }
            
            //increasing the size after collision
            if(collision_with_food(s, f)){
                grid temp_tail_point = s->place[s->size-1];
                grid* temp = realloc(s->place, sizeof(grid)*(s->size+1));
                assert(temp!=NULL);
                s->place = temp;
                s->size++;
                s->velocity++;
                s->place[s->size-1] = temp_tail_point;
                free(f);
                f= NULL;
            }
            
            //reducing the size after collison with an object
            if(collision_with_object(s, obj1) || collision_with_object(s, obj2)){
                if(s->size>1){
                    s->size--;
                }
                strike--;
                if(strike==0){
                    game_over= 1;
                }
            }
            
            //bounds of snake
            if(s->place[0].x < 0 || s->place[0].x > 49){
                game_over =1;
            }
            else if(s->place[0].y <0 || s->place[0].y >29){
                game_over =1;
            }
            
            //self collision
            for(int i =1; i<s->size;i++){
                if(s->place[0].x == s->place[i].x && s->place[0].y == s->place[i].y ){
                    game_over =1;
                }
            }
            DrawText(TextFormat("Velocity:%d",s->velocity), 1, 1, 20, GREEN);
            DrawText(TextFormat("strikes: %d", strike), 150, 1, 20, RED);
            DrawText(TextFormat("size: %d",s->size), 300, 1, 20, BLACK);
        }
        if(game_over==1){
            DrawText("Game over", 300, 250, 50, RED);
        }
        EndDrawing();
    }
    return 0;
}


