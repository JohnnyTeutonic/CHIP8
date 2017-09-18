#include <stdexcept>
#include "renderer.h"

Renderer::Renderer()
{
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
}

void Renderer::InitContext()
{
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
}

void Renderer::GameLoop()
{
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}