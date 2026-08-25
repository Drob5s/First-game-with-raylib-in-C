# First-game-with-raylib-in-C
My first embedded systems project - a snake game written in C and optimized to run on 2kb SRAM of the arduino uno r3 smd.

#overview
Allocates memory to store positions of the snake on the LCD then updates every frame updating the position moving it one step forward depending on the direction variable in the structure of the snake, eating food increases the size and speed of the snake., there is a raylib version i also created as the prototype.

#features
-snake movement.
-snake size increase.
-snake speed increase.
-collision detection(in the raylib version).

#hardware
-Arduino uno r3 smd.
-4 buttons.
-LCD 16x4 display.
-10Kohm potentiometer.

#software
-C.
-Arduino.
-raylib(prototype, file is provided)

#what I learned
-Memory optimization.
-Implementing frame rate for a hardware driven game.
-interfacing software with an LCD.
-Reading digital IO inputs.
-Basic arduino functions such as serial() or millis(), even if it wasn't used in this coe.
