/**
chipeight.cpp
@author: Kevin Mallinson
@version: 0.1
@license: GNU/GPL 2.0
*/

#include <iostream>
#include "chipeight.h"

ChipEight::ChipEight(bool verbose)
{
    this->verbose = verbose;

    if (this->verbose)
    {
        std::cout << "Instantiating the Chip8 Interpreter." << std::endl;
    }
}

void ChipEight::ParseOpcode()
{
    //TODO: Check opcode, actually.
    uint16_t opcode = 0xFFFF;

    //Only consider the first half-byte (nibble), so AND the opcode with F000 to disregard the remaining 12 bits.
    uint16_t opNibble = opcode & 0x0FFF;

    //TODO: Implement the switch.
    switch(opNibble)
    {

    }
}