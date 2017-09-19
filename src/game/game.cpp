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
    //Assign our chipeight variable to one that has already been created.
    this->interpreter = interpreter;

    /* Initialize the library */
    if (!glfwInit())
        throw std::runtime_error("glfw could not initialize."); //TODO: Custom Exception

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("glfw could not create a window."); //TODO: Custom Exception
    }

    glfwSetWindowTitle(window, "ChipEight Interpreter");
}

void Game::InitContext()
{
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
}

//EVERYTHING IN THIS METHOD WILL BE REMOVED. ITS FOR DEBUG ONLY.
void Game::DrawRandom()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //Slightly randomize a certain variable to show it's not frozen.
    float random = -1+2*((float)rand())/RAND_MAX;

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(random, random);
    glVertex2f( 0.1f, random);
    glVertex2f( 0.1f,  0.1f);
    glVertex2f(random,  0.1f);
    glEnd();
  
    glFlush();  // Render now
}

void Game::GameLoop()
{
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //Just draw a shape in random locations for testing.
        this->DrawRandom();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}