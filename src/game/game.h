#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include "chipeight.h"


class Game
{
    
private:
    GLFWwindow * window;
    ChipEight * interpreter; 

    //Private unused constructor
    Game();

public:
    Game(ChipEight * interpreter);
    void InitContext();
    void GameLoop();

};

#endif