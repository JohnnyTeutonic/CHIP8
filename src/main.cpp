#include "game.h"
#include "chipeight.h"

int main(void)
{

    //Instantiate our ChipEight object on the stack, with true verbosity.
    ChipEight * interpreter = new ChipEight(true);

    //Instantiate our emuRenderer on the stack, and open a window.
    Game emuRenderer(interpreter);
    emuRenderer.InitContext();
    emuRenderer.GameLoop();

    //Since we're now instantiating interpreter on the heap, remember to delete it.
    delete interpreter;

    return 0;
}