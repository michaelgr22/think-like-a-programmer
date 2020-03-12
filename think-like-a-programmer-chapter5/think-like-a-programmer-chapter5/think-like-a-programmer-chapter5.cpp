#include <iostream>
#include "variablelengthString.h"

using std::cin;
using std::cout;

variablelengthString varlengthString;

void appendTester() {
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
	varlengthString.append(a, '!');
	cout << a << "\n";
}

void concatenateTester() {
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
	arrayString b = new char[4];
	b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
	varlengthString.concatenate(a, b);
	cout << a << "\n";
}

void replaceStringTester() {
	arrayString source = new char[9];
	source[0] = 'a'; source[1] = 'b'; source[2] = 'c'; source[3] = 'd'; source[4] = 'a'; source[5] = 'b'; source[6] = 'e'; source[7] = 'e'; source[8] = 0;
	arrayString target = new char[3];
	target[0] = 'a'; target[1] = 'b'; target[2] = 0;
	arrayString replaceText = new char[4];
	replaceText[0] = 'x'; replaceText[1] = 'y'; replaceText[2] = 'z'; replaceText[3] = 0;
	varlengthString.replaceString(source, target, replaceText);
	cout << source << "\n";
}

int main()
{
    std::cout << "Hello World!\n";
	appendTester();
	concatenateTester();
	replaceStringTester();
}
