#include <iostream>
#include <fstream>
#include <Windows.h>
#define clear system("cls");
#define NL '\n'

//             x  y
char Game_Area[2][2];
int player = 1;
int x = 0;
int y = 0;
bool Valid_Input = false;

void Initiailize_Array()
{
    for (int i = 0; i < 2; i++)
    {
        for (int n = 0; n < 2; n++)
        {
            Game_Area[i][n] = 'N';
        }
    }
}

bool END_GAME()
{
    for (int Checks_1 = 0; Checks_1 < 3; Checks_1++)
    {
        for (int Checks_2 = 0; Checks_2 < 3; Checks_2++)
        {
                }
    }
}

int main()
{
    std::cout << "Welcome to My Game" << NL;
    Sleep(1000);
    clear;
    do
    {
        Initiailize_Array();
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                std::cout << '[';
                if (Game_Area[x][y] != 'N')
                {
                    std::cout << Game_Area[x][y];
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
        if (END_GAME == false)
        {
            do
            {
                if (player == 1)
                {
                    std::cout << "Player 1:";
                    std::cin >> x >> y;
                    if (x * y <= 9 || x * y > 0) //input validation
                    {
                        Valid_Input == true;
                    }
                    player = 2;
                }
                if (player == 2)
                {
                    std::cout << "Player 2:";
                    std::cin >> x >> y;
                    if (x * y <= 9 || x * y > 0) //input validation
                    {
                        Valid_Input == true;
                    }
                    player = 1;
                }
            } while (Valid_Input == false);
            x = 0;
            y = 0;
            Valid_Input = false;
        }
    } while (END_GAME() == false);
    system("pause");
    return 0;
}