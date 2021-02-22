#include <iostream>
#include <sstream>
#include <Windows.h>
#define clear system("cls");
#define NL '\n'

//             x  y
char Game_Area[3][3];
int player = 1;
int x = 0;
int y = 0;
std::string Xstr;
std::string Ystr;
bool Valid_Input = false;



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
        std::cout << "y" << NL;
        for (int x = 0; x < 3; ++x)
        {
            std::cout << 3-x << " ";
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
        std::cout << "   1  2  3  x" << NL;
        if (END_GAME() == 0)
        {
            do
            {
                if (player == 1)
                {
                    std::cout << "Player 1:" << NL;
                    std::cout << "x y: ";
                    std::cin >> Ystr >> Xstr;
                    std::stringstream(Xstr) >> x;
                    x = 4-x;
                    std::stringstream(Ystr) >> y;
                    if (x == 0 || y == 0)
                    {
                        std::cout << "Invalid input!";
                        Sleep(1500);
                    }
                    else if(x > 3 || y > 3 || x < 1 || y < 1)
                    {
                        std::cout << "Out of playground!";
                        Sleep(1200);
                    }
                    else if(Game_Area[x-1][y-1] != 'N')
                    {
                        std::cout << "This field is already occupied";
                        Sleep(1200);
                    }
                    else
                    {
                        Valid_Input == true;
                        Game_Area[x-1][y-1] = 'X';
                        player = 2;
                    }
                }
                else if (player == 2)
                {
                    std::cout << "Player 2:" << NL;
                    std::cout << "x y: ";
                    std::cin >> Ystr >> Xstr;
                    std::stringstream(Xstr) >> x;
                    x = 4-x;
                    std::stringstream(Ystr) >> y;
                    if (x == 0 || y == 0)
                    {
                        std::cout << NL << "Invalid input!";
                        Sleep(1500);
                    }
                    else if(x > 3 || y > 3 || x < 1 || y < 1)
                    {
                        std::cout << "Out of playground!";
                        Sleep(1200);
                    }
                    else if(Game_Area[x-1][y-1] != 'N')
                    {
                        std::cout << "This field is already occupied";
                        Sleep(1200);
                    }
                    else
                    {
                        Valid_Input == true;
                        Game_Area[x-1][y-1] = 'O';
                        player = 1;
                    }
                }
                x = 0;
                y = 0;
                Xstr = "";
                Ystr = "";
                clear;
            } while (Valid_Input == true);
        }
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