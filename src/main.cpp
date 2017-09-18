#include "renderer.h"
#include "chipeight.h"

int main(void)
{

    //Instantiate our ChipEight object on the stack, with true verbosity.
    ChipEight interpreter(true);

    //Instantiate our emuRenderer on the stack, and open a window.
    Renderer emuRenderer;
    emuRenderer.InitContext();
    emuRenderer.GameLoop();

    return 0;
}