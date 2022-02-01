#include "GameManager.h"

int main()
{
    system("clear");
    srand(time(nullptr));
    std::setlocale(LC_ALL, "");
    GameManager gameManager;
    gameManager.runGame();
    return 0;
}