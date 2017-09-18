#ifndef CHIPEIGHT_H
#define CHIPEIGHT_H

class ChipEight
{
public:
    ChipEight(bool verbose);

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
    uint8_t display[64][32];

    //Since we only have 35 opcodes, we're going to 'fudge' it by wrapping the parsing in a switch statement.
    //If we were working on e.g. the Intel 8080, this would be pretty messy and we might want to consider something like function pointers instead.
    //We don't pass the opcode to the function, since the opcode will be determined in realtime by reading the memory & program counter.
    void ParseOpcode();

    //Private default constructor, might change in the future but we at least want to start the interpreter with some verbosity (true or false).
    ChipEight();
};

#endif