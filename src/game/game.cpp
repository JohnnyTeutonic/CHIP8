/**
game.cpp
@author: Kevin Mallinson
@version: 0.1
@license: GNU/GPL 2.0
*/

#include <stdexcept>
#include "game.h"

Game::Game(ChipEight * interpreter)
{
    this->interpreter = interpreter;

    if (!glfwInit())
    {
        throw std::runtime_error("glfw could not initialize."); //TODO: Custom Exception
    }

    if (!(window = glfwCreateWindow(640, 480, "ChipEight Interpreter", NULL, NULL)))
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
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        this->DrawSquare();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

void Game::DrawSquare()
{
    //This method merely calls LoadIdentity, otherwise the rotate won't work correctly.
    //Then, we build a quad (square) using four points, and in between change its colour.
    //The result, is a rotating square. This is merely to test that our program hasn't hanged,
    //and to assist in creating our Chip8 'sprites' later.

    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 25.f, 0.f, 0.f, 1.f);
    glBegin(GL_QUADS);
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(-0.5f, 0.5f);
    glColor3f(1.f, 1.f, 0.f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.f, 1.f, 1.f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex2f(0.5f, 0.5f);
    glEnd();
}