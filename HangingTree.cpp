#include "HangingTree.h"

wchar_t HangingTree::asciiArtArray[ArraySize::height][ArraySize::width] {' '};

HangingTree::HangingTree()
{
    HangingTree::readCharactersFromFile();
}

void HangingTree::readCharactersFromFile()
{
    std::fstream inFile {filename, std::ios::in};
    if(!inFile.is_open())
    {
        std::wcout << L"Error opening file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    char byte {};
    for(size_t i {0}; i < ArraySize::height; i++)
    {
        for(size_t j {0}; j < ArraySize::width; j++)
        {
            if(!inFile.eof())
            {
                inFile >> std::noskipws >> byte;
            }
            asciiArtArray[i][j] = Word::widenChar(byte);
        }
    }

    inFile.close();
}

void HangingTree::displayHangingTree(const struct Boundary& boundary)
{
    for(size_t i {boundary.yStart}; i < boundary.yEnd; i++)
    {
        for(size_t j {boundary.xStart}; j < boundary.xEnd; j++)
        {
            std::wcout << asciiArtArray[i][j];
        }
        if(boundary.xEnd < ArraySize::width)
            std::wcout << std::endl;
    }
}