/**
 * @file chipeight.cpp
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