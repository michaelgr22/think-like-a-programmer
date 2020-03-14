#include <iostream>
using std::cin;
using std::cout;


int findHighestNumber(int arr[])
{
    int highestnumber = arr[0];
    for (int i = 0; i < 8; i++) {
        if (arr[i] > highestnumber) {
            highestnumber = arr[i];
        }
    }
    return highestnumber;
}

void ex37()
{
    int numbers[8] = { 1, 500, 300, 2, 6, 22, 8, 2 };
    int modes[8];
    for (int i = 0; i < 8; i++) {
        modes[i] = 0;
    }

    for (int i = 0; i < 8; i++) {
        int currentnumber = numbers[i];
        int counter = 0;
        for (int count = 0; count < 8; count++)
        {
            if (numbers[count] == currentnumber)
            {
                counter++;
            }
        }
        modes[i] = counter;
    }

    int highestnumbercount = findHighestNumber(modes);

    int highestnumber = 0;
    for (int i = 0; i < 8; i++) {
        if (modes[i] == highestnumbercount) {
            highestnumber = numbers[i];
        }
    }

    cout << "Highest Number: " << highestnumber;
}