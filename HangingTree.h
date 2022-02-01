#ifndef HANGING_TREE_H
#define HANGING_TREE_H

#include <fstream>
#include <iostream>

#include "Word.h"

struct Boundary
{
    size_t yStart, yEnd;
    size_t xStart, xEnd;
};

enum ArraySize
{
    height = 13, width = 40
};

class HangingTree
{
    private:
        static constexpr const char* filename {"ascii_art.txt"};
    private:
        static wchar_t asciiArtArray[ArraySize::height][ArraySize::width];
    private:
        static void readCharactersFromFile();
    public:
        HangingTree();
    public:
        static void displayHangingTree(const struct Boundary& boundary);
};

#endif