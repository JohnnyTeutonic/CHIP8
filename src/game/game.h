/**
 * @file game.h
 * @author Kevin Mallinson
 * @version 0.1
 * @section LICENSE
 * 
 * Copyright (C) 2017 Kevin Mallinson
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include "chipeight.h"


class Game
{
    
private:
    GLFWwindow * window;
    ChipEight * interpreter; 
    int width, height;
    float ratio;

    //Private unused constructor
    Game();

public:
    Game(ChipEight * interpreter);
    void InitContext();
    void GameLoop();
    void DrawSprite(int x, int y);
    void ClearSprite(int x, int y);
    void ClearScreen();

};

#endif