/**
 * @file game.cpp
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

#include <stdexcept>
#include <cstdlib>
#include "game.h"

Game::Game(ChipEight * interpreter)
{
    this->interpreter = interpreter;

    if (!glfwInit())
    {
        throw std::runtime_error("glfw could not initialize."); //TODO: Custom Exception
    }

    this->width = 1344; // 64 * 21
    this->height = 672; // 32 * 21

    if (!(window = glfwCreateWindow(width, height, "ChipEight Interpreter", NULL, NULL)))
    {
        glfwTerminate();
        throw std::runtime_error("glfw could not create a window."); //TODO: Custom Exception
    }

    //We use a reference because we're setting width and height.
    glfwGetFramebufferSize(window, &this->width, &this->height);
    this->ratio = this->width / (float) this->height;
    glViewport(0, 0, width, height);
}

void Game::InitContext()
{
    //We need to specify that our context is current - that is to say,
    //all drawing, setting, etc, will happen on the 'window' context.
    glfwMakeContextCurrent(window);
}

void Game::GameLoop()
{
    //For testing only
    srand (time(NULL));

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        //For testing only
        this->DrawSprite(rand() % 64 + 1, rand() % 32 + 1);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

    void Game::DrawSprite(int x, int y)
    {
        //ASSUMPTION: We want it ONE indexed, not ZERO indexed
        //TODO: Verify this assumption
        if (x != 0)
            x--;
        if (y != 0)
            y--;

        //Divide the width by 64, so whatever our width, 64 squares should fit.
        int sWidth = this->width / 64;

        //Same with height, but 32.
        int sHeight = this->height / 32;

        x = x * sWidth;
        y = y * sHeight;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,width,height,0,-1,1);
        glMatrixMode(GL_MODELVIEW);

        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x+sWidth, y);
        glVertex2f(x+sWidth, y+sHeight);
        glVertex2f(x, y+sHeight);
        glEnd();
    }