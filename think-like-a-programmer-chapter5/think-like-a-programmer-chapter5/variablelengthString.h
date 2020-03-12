#pragma once

typedef char* arrayString;

class variablelengthString
{
public:
	variablelengthString();
	variablelengthString(arrayString String);
	void setvarString(arrayString varString);
	arrayString getvarString();
	void append(arrayString& s, char c);
	void concatenate(arrayString& s1, arrayString s2);
	char characterAT(arrayString s, int postion);
	void replaceString(arrayString& source, arrayString target, arrayString replaceText);
private:
	int length(arrayString s);
	arrayString _varString;
};

