#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

//TODO: Figure out way to not have to include the cpp file.
#include "../../src/chipeight/chipeight.cpp"

TEST_CASE( "The screen is filled", "[fillscreen]" ) 
{
    //Create our interpreter
    ChipEight ch(true);
    ch.FillEntireScreen();
    CHDisplay display = ch.GetDisplay();
    int failFlag = 0;

    for(int i = 0; i < display.width; i++)
    {
        for(int j = 0; j < display.height; j++)
        {
            //If any part of the screen is 0, it's not fully filled -- failure
            if (display.display[i][j] == 0) 
            {
                failFlag = 1;
                break;
            }
        }

        if (failFlag == 1)
        {
            break;
        }
    }

    //Run our test -- failflag must be 0 to pass.
    REQUIRE (failFlag == 0);
}

TEST_CASE( "The screen is cleared", "[fillscreen]" ) 
{
    //Create our interpreter
    ChipEight ch(true);
    ch.FillEntireScreen();

    //Here we're testing opcode 00E0
    ch.ClearScreen_00E0();
    CHDisplay display = ch.GetDisplay();
    int failFlag = 0;

    for(int i = 0; i < display.width; i++)
    {
        for(int j = 0; j < display.height; j++)
        {
            //If any part of the screen is 1, it's not fully cleared -- failure
            if (display.display[i][j] == 1) 
            {
                failFlag = 1;
                break;
            }
        }

        if (failFlag == 1)
        {
            break;
        }
    }

    //Run our test -- failflag must be 0 to pass.
    REQUIRE (failFlag == 0);
}