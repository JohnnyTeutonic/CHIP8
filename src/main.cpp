#include "renderer.h"

int main(void)
{
    //Create a renderer on the stack - no need for pointer here.
    Renderer emuRenderer;
    emuRenderer.InitContext();

    return 0;
}