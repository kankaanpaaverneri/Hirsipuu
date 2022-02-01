#include "GameManager.h"

int main()
{
    srand(time(nullptr));
    std::setlocale(LC_ALL, "");
    GameManager gameManager;
    gameManager.runGame();
    return 0;
}