#include <iostream>
using std::cin;
using std::cout;

void ex23()
{
    for (int row = 0; row < 8; row++)
    {
        if (row < 8 / 2)
        {
            for (int c = 0; c < row; c++)
            {
                cout << " ";
            }
            for (int c = 0; c < row + 1; c++)
            {
                cout << "#";
            }
            for (int c = 0; c < 14 - ((row + 1 + row) * 2); c++)
            {
                cout << " ";
            }
            for (int c = 0; c < row + 1; c++)
            {
                cout << "#";
            }
            for (int c = 0; c <= row; c++)
            {
                cout << " ";
            }
        }
        else
        {
            for (int c = 0; c < 7 - row; c++)
            {
                cout << " ";
            }
            for (int c = 0; c < 8 - row; c++)
            {
                cout << "#";
            }
            for (int c = 0; c < (row - (8 - row)) * 2; c++)
            {
                cout << " ";
            }
            for (int c = 0; c < 8 - row; c++)
            {
                cout << "#";
            }
            for (int c = 0; c < 7 - row; c++)
            {
                cout << " ";
            }

        }
        cout << "\n";
    }
}
