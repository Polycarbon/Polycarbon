#include"stdio.h"
#include"conio.h"
#include"windows.h"
void walk(int x,int y){
COORD walk;
walk.X =x;
walk.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),walk);
}
