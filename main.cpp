#include <iostream>
#include <fstream>
#include <Windows.h>
#define clear system("cls");
#define NL '\n'

//             x  y
char Game_Area[3][3];
int player = 1;
int x = 0;
int y = 0;
bool Valid_Input = false;

void Print_Values()
{
    std::cout << NL << NL;
    for (int i = 0; i < 3; i++)
    {
        for (int n = 0; n < 3; n++)
        {
            std::cout << Game_Area[i][n];
        }
        std::cout << NL;
    }
}



void Initiailize_Array()
{
    for (int i = 0; i < 3; i++)
    {
        for (int n = 0; n < 3; n++)
        {
            Game_Area[i][n] = 'N';
        }
    }
}

bool Array_Full()
{
    for (int x_loop = 0; x_loop < 3; x_loop++)
    {
        for (int y_loop = 0; y_loop < 3; y_loop++)
        {
            if(Game_Area[x_loop][y_loop] == 'N')
            {
                return false;
            }
            
        }
    }
    return true;
}

int END_GAME()
{
    for (int x_loop = 0; x_loop < 3; x_loop++)
    {
        for (int y_loop = 0; y_loop < 3; y_loop++)
        {
            if (Game_Area[x_loop][y_loop] == 'X')
            {
                                                                                                //podmínka aby x_loop nebo y_loop nebyl mimo pole
                if (Game_Area[x_loop-1][y_loop] == 'X' && Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop+1][y_loop] == 'X'){return 1;}if (Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop+1][y_loop] == 'X' && Game_Area[x_loop+2][y_loop] == 'X'){return 1;}if (Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop-1][y_loop] == 'X' && Game_Area[x_loop-2][y_loop] == 'X'){return 1;}if (Game_Area[x_loop][y_loop-1] == 'X' && Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop][y_loop+1] == 'X'){return 1;}if (Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop][y_loop+1] == 'X' && Game_Area[x_loop][y_loop+2] == 'X'){return 1;}if (Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop][y_loop-1] == 'X' && Game_Area[x_loop][y_loop-2] == 'X'){return 1;}if (Game_Area[x_loop-1][y_loop-1] == 'X' && Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop+1][y_loop+1] == 'X'){return 1;}if (Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop+1][y_loop+1] == 'X' && Game_Area[x_loop+2][y_loop+2] == 'X'){return 1;}if (Game_Area[x_loop][y_loop] == 'X' && Game_Area[x_loop-1][y_loop-1] == 'X' && Game_Area[x_loop-2][y_loop-2] == 'X'){return 1;}
            }
            if (Game_Area[x_loop][y_loop] == 'O')
            {
                if (Game_Area[x_loop-1][y_loop] == 'O' && Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop+1][y_loop] == 'O'){return 2;}if (Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop+1][y_loop] == 'O' && Game_Area[x_loop+2][y_loop] == 'O'){return 2;}if (Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop-1][y_loop] == 'O' && Game_Area[x_loop-2][y_loop] == 'O'){return 2;}if (Game_Area[x_loop][y_loop-1] == 'O' && Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop][y_loop+1] == 'O'){return 2;}if (Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop][y_loop+1] == 'O' && Game_Area[x_loop][y_loop+2] == 'O'){return 2;}if (Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop][y_loop-1] == 'O' && Game_Area[x_loop][y_loop-2] == 'O'){return 2;}if (Game_Area[x_loop-1][y_loop-1] == 'O' && Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop+1][y_loop+1] == 'O'){return 2;}if (Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop+1][y_loop+1] == 'O' && Game_Area[x_loop+2][y_loop+2] == 'O'){return 2;}if (Game_Area[x_loop][y_loop] == 'O' && Game_Area[x_loop-1][y_loop-1] == 'O' && Game_Area[x_loop-2][y_loop-2] == 'O'){return 2;}
            }
            else if (Array_Full() == true){return 4;}
        }
    }
        return 0;
}

int main()
{
    Initiailize_Array();
    std::cout << "Welcome to My Game" << NL;
    Sleep(1000);
    clear;
    do
    {
        for (int x = 0; x < 3; ++x)
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
                    std::cout << " ";
                }

                std::cout << ']';
            }
            std::cout << NL;
        }
        //Loop that prints Game area
        if (END_GAME() == 0)
        {
            do
            {
                if (player == 1)
                {
                    std::cout << "Player 1:";
                    std::cin >> x >> y;
                    if (x * y <= 9 || x * y > 0) //input validation                                 // podminka aby neslo napsat misto ,ktere uz je zabrane
                    {
                        Valid_Input == true;
                        Game_Area[--x][--y] = 'X';
                        player = 2;
                    }
                }
                else if (player == 2)
                {
                    std::cout << "Player 2:";
                    std::cin >> x >> y;
                    if (x * y <= 9 || x * y > 0) //input validation
                    {
                        Valid_Input == true;
                        Game_Area[--x][--y] = 'O';
                        player = 1;
                    }
                }
                clear;
            } while (Valid_Input == true);
        }
            x = 0;
            y = 0;
            Valid_Input = false;
    } while (END_GAME() == 0);
    switch (END_GAME())
    {
    case 1:
    std::cout << "Player 1 won!" << NL;
    break;
    case 2:
    std::cout << "Player 2 won!" << NL;
    break;
    case 4:
        std::cout << "No one won!" << NL;
        break;
    default:
        break;
    }
    system("pause");
    return 0;
}