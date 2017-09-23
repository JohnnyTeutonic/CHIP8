/**
 * @file main.cpp
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

#include "game.h"
#include "chipeight.h"

int main(void)
{

    //Instantiate our ChipEight object on the heap via a pointer, with true (verbosity).
    ChipEight * interpreter = new ChipEight(true);

    //Instantiate our emuRenderer on the stack, and open a window.
    Game emuRenderer(interpreter);
    emuRenderer.InitContext();
    emuRenderer.GameLoop();

    //Since we're now instantiating interpreter on the heap, remember to delete it.
    delete interpreter;

    return 0;
}