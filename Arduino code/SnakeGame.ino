#include "declarations.h"
#include <LiquidCrystal.h>
#define BUTTON_R 14 //right button
#define BUTTON_L 15 //left button
#define BUTTON_U 16//up button
#define BUTTON_D 17 //down button
LiquidCrystal lcd(12,11,5,6,7,8);

int count = 0;
snake* s = create_snake(); //creates snake and initialize the position
food* f = NULL;
int food_timer = 0;
_Bool game_over = 0;
unsigned long last_move_time = 0; 

void setup() {
    lcd.begin(16,4);
    pinMode(BUTTON_R,INPUT_PULLUP);
    pinMode(BUTTON_L,INPUT_PULLUP);
    pinMode(BUTTON_U,INPUT_PULLUP);
    pinMode(BUTTON_D,INPUT_PULLUP);
}

void loop() {
    int frame_time = (FPS * 1000) / s->velocity;
    for (int time_passed = 0; time_passed < frame_time; time_passed += 10) {
        if(digitalRead(BUTTON_R)==LOW){
        s->direction = RIGHT;
        }
        else if(digitalRead(BUTTON_L)==LOW){
        s->direction = LEFT;
        }
        else if(digitalRead(BUTTON_U)==LOW){
        s->direction = UP;
        }
        else if(digitalRead(BUTTON_D)==LOW){
        s->direction = DOWN;
    }
      if (millis() - last_move_time >= frame_time) {
        last_move_time = millis();
        
        if(game_over==0){
            count++;
            lcd.clear();
            //drawing the snake
            for(int i=0;i<s->size;i++){
                lcd.setCursor(s->place[i].x, s->place[i].y);
                lcd.print('.');
            }

            
        //snake movement
            move_snake(s);
            
            //creating and drawing the food every 10 seconds
            if(count%10==0 && f == NULL){
                f= create_food();
                food_timer= count+20;
            }
            if(f!=NULL && f->active){
                draw_food(f);
            }
            if(count>food_timer){
                free(f);
                f=NULL;
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
            
            //bounds of snake
            if(s->place[0].x < 0 || s->place[0].x > 15){
                game_over =1;
            }
            else if(s->place[0].y <0 || s->place[0].y >3){
                game_over =1;
            }
            
            //self collision
            for(int i =1; i<s->size;i++){
                if(s->place[0].x == s->place[i].x && s->place[0].y == s->place[i].y ){
                    game_over =1;
                }
            }
        }
    
    if(game_over==1){
            lcd.clear();
            lcd.print("Game over");
            lcd.setCursor(0, 3);
            lcd.print("Press a button");
            }

    if (digitalRead(BUTTON_R) == LOW || digitalRead(BUTTON_L) == LOW || 
    digitalRead(BUTTON_U) == LOW || digitalRead(BUTTON_D) == LOW) {
    free(s->place);
    free(s);
    if(f != NULL) { 
        free(f); f = NULL; 
        }
    count = 0;
    s = create_snake(); 
    game_over = 0; 
    }
            }
      }
    }

    

