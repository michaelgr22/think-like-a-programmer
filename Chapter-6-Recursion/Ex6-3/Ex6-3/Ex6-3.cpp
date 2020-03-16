#include <iostream>
using std::cin;
using std::cout;

bool isOneOdd(char* String, int length) {
    if (length == 0) {
        return 0;
    }

    int result = int(isOneOdd(String, length - 1));
    //cout << result << "\n";;
    if (String[length - 1] == '1' && result == 0) {
        return 1;
    }
    else if (String[length - 1] == '0' && result == 1) {
        return 1;
    }
    /*
    else if (String[length - 1] == '1' && result == 1){
        return 0;
    }*/
    else {
        return 0;
    }
}


/*
int isOneOddint(char* String, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (String[i] == '1')
            count++;
    }
    return count;
}

int dispatcher(char* String, int length) {
    if (length == 0) {
        return 0;
    }
    cout << "Length: " << length << "\n";
    int countlast;
    if (String[length-1] == '1') {
        countlast = 1;
    }
    else {
        countlast = 0;
    }
    cout << "Countlast: " << countlast << "\n";
    int counter = dispatcher(String, length - 1);
    return countlast + counter;

}*/

int main()
{
    const int Stringlength = 8;
    char* binaryString = new char[Stringlength];
    binaryString[0] = '1'; binaryString[1] = '0'; binaryString[2] = '0'; binaryString[3] = '1'; binaryString[4] = '0'; binaryString[5] = '1'; binaryString[6] = '1'; binaryString[7] = '0';

    bool result = isOneOdd(binaryString, Stringlength);
    cout << result;

}
