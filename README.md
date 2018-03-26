# Introduction
This project serves as a CHIP-8 emulator/interpreter.
The aim of this project is to introduce myself, and anyone following, to systems emulation.
This project will (aim to) use best practices in C++, and best practices in git (good commit messages.)

# Building the project
Please use an out of source build method, for example:
```
mkdir build
cd ./build
cmake ../
make
```

and to run the project (relative to the new build folder we made):
```
./bin/CHIP8
```

# Dependencies
Make sure you have installed:
* libx11-dev
* xorg-dev
* libglu1-mesa-dev

# Unit Testing
...



# Coding Style

To maintain a consistent codebase, use the following style when formatting your code:

* __Classes:__ `UpperCase`
* __Methods:__ `UpperCase`
* __Instance Variables:__ `lowerCase`
* __Class(static) Variables:__ `lowerCase`
* __Constants:__ `UNDER_SCORE_CAPS`

# Commenting style:
* __File Comments:__  Block Comments `/** ... */` , detailing:
    * file name (e.g. main.cpp),
    * `@author` 
    * `@version`
    * license
    * optional description
* __Function Comments:__ Block Comments `/** ... */` , detailing:
    * purpose, 
    * `@param`
    * `@return`
* __Code Comments:__ Use the double slash style `//` for all other comments. 
    * Try not to over-comment, only comment when the code can't describe itself.
