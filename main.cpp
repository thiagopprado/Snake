#include <iostream>
#include <cstdlib>
#include "snake.h"
#include <windows.h>
using namespace std;

int main (){
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor); // Desliga o Cursor
    Snake game(50,20);
    game.Inicia();
    return 0;
}
