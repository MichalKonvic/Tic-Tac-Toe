#include <iostream>
#include <fstream>
#include <Windows.h>
#define clear system("cls");
#define NL '\n'

char Game_Area[8];
int player = 1;

void Initiailize_Array()
{
    for (int i = 0; i < 8; i++)
    {
        Game_Area[i] = 'N';
    }
}

bool END_GAME()
{
}

int main()
{
    std::cout << "Welcome to My Game" << NL;
    Sleep(100);
    clear;
    do
    {
        Initiailize_Array();
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                std::cout << row++;
                std::cout << '[';
                if (Game_Area[row * column] != 'N')
                {
                    std::cout << column++;
                    std::cout << Game_Area[row * column];
                }
                else
                {
                    std::cout << ' ';
                }

                std::cout << ']';
            }
            std::cout << NL;
        }
        //Loop that prints Game area
        
    } while (END_GAME() == false);
}