#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Word.h"
#include "HangingTree.h"
#include <ctime>

enum FailState : int
{
    fail1=1, fail2=2, fail3=3,
    fail4=4, fail5=5, fail6=6
};

class GameManager
{   
    public:
        GameManager();
        ~GameManager();
    private:
        HangingTree hangingTree;
        const int failStateLUT[6]
        {
            FailState::fail1, FailState::fail2, FailState::fail3,
            FailState::fail4, FailState::fail5, FailState::fail6
        };
    
    public:
        void runGame();
    
    private:
        void displayHiddenWord(const Word& word) const;
        void enterUserInput(Word& word);
        bool isAnswerCorrect(Word& word);
        bool isWordRevealed(const Word &word) const;
        void revealHangingTree(const int& failState);
        struct Boundary initBoundray(const size_t yStart, const size_t yEnd, const size_t xStart, const size_t xEnd);
        void displayUsedLetters(const Word& word) const;
        void addUsedLetters(Word& word) const;
};

#endif