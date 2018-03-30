/**
 * @file chipeight.h
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
#ifndef CHIPEIGHT_H
#define CHIPEIGHT_H

#include <stdint.h>

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32


//The chip8 supports a 64x32 pixel display - and from what I've read a single byte is used to represent a sprite.
//(A single sprite is 8 pixels wide)
struct CHDisplay
{
    int width = DISPLAY_WIDTH;
    int height = DISPLAY_HEIGHT;
    uint8_t display[DISPLAY_WIDTH][DISPLAY_HEIGHT];
};

class ChipEight
{
public:
    ChipEight(bool verbose);

    void ClearScreen_00E0();
    void Unused_0NNN(); //Only implementing in case we need it eventually

    CHDisplay GetDisplay();

    //This inline function is just for testing. Remove later.
    //It merely fills the entire screen with white pixels.
    void FillEntireScreen() 
    {
        for(int i = 0; i < this->display.width; i++)
        {
            for(int j = 0; j < this->display.height; j++)
            {
                this->display.display[i][j] = 1;
            }
        }
    }


private:
    //This bool will be used to verbosely document what's going on - that is, it will explain each opcode as it reads it.
    //In addition, it will give some basic messages such as "Instantiating..."
    bool verbose;

    //The Chip8 has 4096 bytes of memory (4KB), so we'll just use a uint8_t array of length 4096 for simplicity.
    uint8_t memory[4096];

    //The Chip8 has 16 8-bit registers - thus we can represent it as above, with len 16.
    //The Chip8 registers are V0 to VF - therefore, they can be referred to directly by their array location.
    uint8_t registers[16];

    //The address register is 16 bits wide, - it's a special register referred to as I. Used for some memory operations.
    uint16_t addressRegister;

    //The Chip8 has two timers, which count down at 60hz.
    //When non-zero, the soundTimer will make a beep.
    //Both timers can be set to the value of a register, therefore it's width is 8 bits.
    uint8_t delayTimer, soundTimer;

    //The keyboard simply has 16 keys, 0x0 to 0xF, we'll use a 16 bit number for implementation, and set high any bit
    //when that key is being pressed, and set it low when that key isn't being pressed.
    //(i.e. if 0xC is being pressed, then the 12th bit will be set high.)
    uint16_t keyboard;

    //The stack stores 16 bit numbers, and has a maximum nesting of 16 - i.e. the stack will overflow past 16.
    uint16_t stack[16]; 

    //The chip8 supports a 64x32 pixel display - and from what I've read a single byte is used to represent a sprite.
    //(A single sprite is 8 pixels wide)
    CHDisplay display;

    //The program counter (PC) should be 16-bit, and is used to store the currently executing address. 
    uint16_t programCounter;

    //The stack pointer (SP) can be 8-bit, it is used to point to the topmost level of the stack.
    uint8_t stackPointer;

    //Since we only have 35 opcodes, we're going to 'fudge' it by wrapping the parsing in a switch statement.
    //If we were working on e.g. the Intel 8080, this would be pretty messy and we might want to consider something like function pointers instead.
    //We don't pass the opcode to the function, since the opcode will be determined in realtime by reading the memory & program counter.
    void ParseOpcode();

    //Private default constructor, might change in the future but we at least want to start the interpreter with some verbosity (true or false).
    ChipEight();
};

#endif
