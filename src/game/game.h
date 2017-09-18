#include <GLFW/glfw3.h>


class Renderer
{
    
private:
    GLFWwindow* window;

public:
    Renderer();
    void InitContext();
    void GameLoop();

};