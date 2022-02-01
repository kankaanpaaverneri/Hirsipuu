#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <codecvt>
#include <locale>

class Word
{
    private:
        const char* filename = "sanasto.txt";
    private:
        std::wstring m_realWord;
        std::wstring m_hiddenWord;
        std::wstring m_userInput;
        std::wstring m_usedLetters;
    public:
        //Constructors and destructors
        Word();
        ~Word() = default;
    private:
        //Member methods
        const std::wstring readWordFromFile() const;
        const int getFileLineCount() const;
        void generateHiddenWord(const size_t& length);
    public:
        void revealCharacters(const wchar_t& character);
        static const std::wstring widenString(const std::string& utf8Line);
        static const wchar_t widenChar(const char& character);
    public:
        //Getters and setters
        void setRealWord(const std::wstring& realWord);
        const std::wstring& getRealWord() const;
        const std::wstring& getHiddenWord() const;
        void setUserInput(const std::wstring& userInput);
        const std::wstring& getUserInput() const;
        void setUsedLetters(const wchar_t& usedLetter);
        const std::wstring& getUsedLetters() const;
};

#endif