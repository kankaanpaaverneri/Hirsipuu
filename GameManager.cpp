#include "GameManager.h"

GameManager::GameManager()
{}

GameManager::~GameManager()
{}

void GameManager::runGame()
{
    Word word;

    while(!isWordRevealed(word))
    {
        displayHiddenWord(word);
        std::wcout << std::endl;
        std::wcout << L"Käytetyt kirjaimet: ";
        displayUsedLetters(word);
        std::wcout << L"Arvaa merkki: ";
        enterUserInput(word);
        addUsedLetters(word);
        system("clear");
        std::wcout << std::endl;
        static int failCounter {0};
        if(!isAnswerCorrect(word))
        {
            failCounter++;
        }
        revealHangingTree(failStateLUT[failCounter]);
        if(failCounter == FailState::fail6)
        {
            std::wcout << L"HÄVISIT PELIN" << std::endl;
            break;
        }
    }
    std::wcout << L"Piilotettu sana: " << word.getRealWord() << std::endl;
}

void GameManager::displayHiddenWord(const Word& word) const
{
    for(const wchar_t& ch: word.getHiddenWord())
    {
        std::wcout << ch << L" ";
    }
    std::wcout << std::endl;
}

void GameManager::enterUserInput(Word& word)
{
    std::wstring userInputBuffer;
    std::getline(std::wcin, userInputBuffer);
    word.setUserInput(userInputBuffer);
}

bool GameManager::isAnswerCorrect(Word& word)
{
    bool isCharacterMatch {false};
    for(size_t i {0}; i < word.getUserInput().length(); i++)
    {
        for(const wchar_t& realCh : word.getRealWord())
        {
            if(word.getUserInput().at(i) == realCh)
            {
                isCharacterMatch = true;
                word.revealCharacters(realCh);
            }
        }
    }
    return isCharacterMatch;
}

bool GameManager::isWordRevealed(const Word &word) const
{
    for(const wchar_t& ch : word.getHiddenWord())
    {
        if(ch == L'_')
            return false;
    }
    displayHiddenWord(word);
    std::wcout << "OLET VIINERI" << std::endl;
    return true;
}

void GameManager::revealHangingTree(const int& failState)
{
    struct Boundary boundary;
    switch(failState)
    {
        case FailState::fail1:
            for(size_t i {0}; i < 9; i++)
                std::wcout << std::endl;
            boundary = initBoundray(9, ArraySize::height-1, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            break;
        case FailState::fail2:
            boundary = initBoundray(0, 9, 0, 21);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(9, ArraySize::height-1, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            break;
        case FailState::fail3:
            boundary = initBoundray(0, 2, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(2, 9, 0, 21);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(9, ArraySize::height-1, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            break;
        case FailState::fail4:
            boundary = initBoundray(0, 2, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(2, 5, 0, 25);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(5, 9, 0, 21);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(9, ArraySize::height-1, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            break;
        case FailState::fail5:
            boundary = initBoundray(0, 2, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(2, 5, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(5, 9, 0, 21);
            HangingTree::displayHangingTree(boundary);
            boundary = initBoundray(9, ArraySize::height-1, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            break;
        case FailState::fail6:
            boundary = initBoundray(0, ArraySize::height-1, 0, ArraySize::width);
            HangingTree::displayHangingTree(boundary);
            break;
        default:
            break; 
    }
}

struct Boundary GameManager::initBoundray(const size_t yStart, const size_t yEnd, const size_t xStart, const size_t xEnd)
{
    struct Boundary boundary {yStart, yEnd, xStart, xEnd};
    return boundary;
}

void GameManager::displayUsedLetters(const Word& word) const
{
    for(const wchar_t& ch : word.getUsedLetters())
    {
        std::wcout << ch << " ";
    }
    std::wcout << std::endl;
}

void GameManager::addUsedLetters(Word& word) const
{
    if(word.getUsedLetters().empty())
    {
        for(const wchar_t& ch : word.getUserInput())
        {
            word.setUsedLetters(ch);
        }
    }
    else
    {
        bool isCharacterFound {false};
        //Compares userInput string to usedLetters string and if there isn´t occurance
        //Character will be pushed in to the usedLetters string
        for(size_t i {0}; i < word.getUserInput().length(); i++)
        {
            for(const wchar_t& ch : word.getUsedLetters())
            {
                if(word.getUserInput().at(i) == ch)
                    isCharacterFound = true;
            }
            if(!isCharacterFound)
                word.setUsedLetters(word.getUserInput().at(i));
        }
    }
}