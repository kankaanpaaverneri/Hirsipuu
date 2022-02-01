#include "Word.h"

Word::Word()
    : m_realWord{readWordFromFile()}{
    this->generateHiddenWord(this->getRealWord().length());
}

const std::wstring Word::readWordFromFile() const
{
    //Getting the maxLineCount from the file
    const int maxLineCount {getFileLineCount()};
    if(maxLineCount == -1)
    {
        return L"";
    }

    //Generate a random value for randomLineNumber
    const int randomLineNumber {rand() % (1 + maxLineCount)};
    std::fstream inFile {filename, std::ios::in};
    std::string utf8Line;
    if(!inFile.is_open())
    {
        std::cerr << "readWordFromFile() Error opening file" << std::endl;
        return L"";
    }
    //Reading the file line by line until we hit the randomLineNumber
    int i {0};
    while(!inFile.eof())
    {
        std::getline(inFile, utf8Line);
        if(i >= randomLineNumber)
            break;
        i++; 
    }
    inFile.close();
    return widenString(utf8Line); //Converting normal std::string to a std::wstring
}

const int Word::getFileLineCount() const
{
    std::fstream inFile {filename, std::ios::in};
    if(!inFile.is_open())
    {
        std::cerr << "getFileLineCount() Error opening file" << std::endl;
        return -1;
    }
    std::string line {};
    int lineCount {0};
    //Reading file line by line to find out how many lines there are in the file
    while(!inFile.eof())
    {
        std::getline(inFile, line);
        lineCount++;
    }
    inFile.close();
    return lineCount;
}

const std::wstring Word::widenString(const std::string& utf8)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
    return convert.from_bytes(utf8);
}

const wchar_t Word::widenChar(const char& character)
{
    return (const wchar_t)character;
}

void Word::generateHiddenWord(const size_t& length)
{
    for(size_t i {0}; i < length; i++)
    {
        m_hiddenWord.push_back('_');
    }
}

void Word::revealCharacters(const wchar_t& character)
{
    for(size_t i {0}; i < getRealWord().length(); i++)
    {
        if(m_realWord.at(i) == character)
        {
            m_hiddenWord.at(i) = character;
        }
    }
}

//Getters and setters
void Word::setRealWord(const std::wstring& word)
{
    m_realWord = word;
}

const std::wstring& Word::getRealWord() const
{
    return m_realWord;
}

const std::wstring& Word::getHiddenWord() const
{
    return m_hiddenWord;
}

void Word::setUserInput(const std::wstring& userInput)
{
    m_userInput = userInput;
}

const std::wstring& Word::getUserInput() const
{
    return m_userInput;
}

void Word::setUsedLetters(const wchar_t& usedLetter)
{
    m_usedLetters.push_back(usedLetter);
}

const std::wstring& Word::getUsedLetters() const
{
    return m_usedLetters;
}