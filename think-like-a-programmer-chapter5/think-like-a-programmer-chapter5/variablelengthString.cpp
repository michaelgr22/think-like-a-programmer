#include "variablelengthString.h"

//setter
void variablelengthString::setvarString(arrayString varString) {
	 _varString = varString;
}

//getter
arrayString variablelengthString::getvarString() {
	return _varString;
}

//default constructor
variablelengthString::variablelengthString() {
	arrayString s = new char[0];
	s[1] = '0';
	setvarString(s);
}

//constructor
variablelengthString::variablelengthString(arrayString varString) {
	setvarString(varString);
}

int variablelengthString::length(arrayString s) {
	int count = 0;
	while (s[count] != 0) {
		count++;
	}
	return count;
}

void variablelengthString::append(arrayString& s, char c) {
	int oldLength = length(s);
	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i < oldLength; i++) {
		newS[i] = s[i];
	}
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;
	s = newS;
}

char variablelengthString::characterAT(arrayString s, int postion) {
	return s[postion];
}



void variablelengthString::concatenate(arrayString& s1, arrayString s2) {
	int s1_OldLength = length(s1);
	int s2_OldLength = length(s2);

	int s1_NewLength = s1_OldLength + s2_OldLength;

	arrayString newS = new char[s1_NewLength + 1];

	for (int i = 0; i < s1_OldLength; i++) {
		newS[i] = s1[i];
	}
	for (int i = 0; i < s2_OldLength; i++) {
		newS[s1_OldLength + i] = s2[i];
	}
	newS[s1_NewLength] = 0;
	delete[] s1;
	s1 = newS;
}

void variablelengthString::replaceString(arrayString& source, arrayString target, arrayString replaceText) {
	int source_Length = length(source);
	int target_Length = length(target);
	int replaceText_Length = length(replaceText);

	int ReplaceCount = 0;

	//find out how many targets are in source to replace
	for (int source_count = 0; source_count < source_Length; source_count++) {
		if (source[source_count] == target[0]) {
			int count = 0;
			for (int target_count = 0; target_count < target_Length; target_count++) {
				if (target[target_count] == source[source_count + target_count]) {
					count++;
				}
			}
			if (count == target_Length) {
				ReplaceCount++;
			}
		}
	}

	//create new source array with length needed
	int dif_target_replaceText = replaceText_Length - target_Length;
	int source_Length_new = source_Length + ((dif_target_replaceText)*ReplaceCount);
	arrayString source_new = new char[source_Length_new + 1];

	for (int i = 0; i < source_Length; i++) {
		source_new[i] = source[i];
	}
	source_new[source_Length_new] = 0;

	//replace targets with ReplaceText 
	for (int source_count = 0; source_count < source_Length_new; source_count++) {
		if (source_new[source_count] == target[0]) {
			int count = 0;
			for (int target_count = 0; target_count < target_Length; target_count++) {
				if (target[target_count] == source_new[source_count + target_count]) {
					count++;
				}
			}
			if (count == target_Length) {
				//move all element to the right
				for (int i = source_Length_new - 1; i >= source_count + 1; i--)
				{
					source_new[i + dif_target_replaceText] = source_new[i];
				}
				source_new[source_Length_new] = 0;

				//replace target
				for (int i = 0; i < replaceText_Length; i++) {
					source_new[source_count + i] = replaceText[i];
				}
			}
		}
	}

	delete[] source;
	source = source_new;
}

