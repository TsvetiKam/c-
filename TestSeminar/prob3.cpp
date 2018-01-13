#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

int const N = 1000;
// Да се напише програма която чете текст от думи
//(за дума приемаме всяка поредица от малки или главни букви)
// и печата броя на еднобуквените, двубуквените и т.н. думи.
// ПС: Използвайте масив от чарове.

bool isLetter(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
		return true;
	}
	return false;
}

void task() {
	char str[N] = "";
	cin.getline(str, N);

	int wordLengths[50] = { 0 };
	int length = strlen(str);
	int lastNonLetterIndex = 0;

	for (int i = 0; i < length; i++) {
		if (!isLetter(str[i])) {
			wordLengths[i - lastNonLetterIndex]++;
			lastNonLetterIndex = i + 1;
		}
		else if (i == length - 1) {
			wordLengths[i - lastNonLetterIndex + 1]++;
			lastNonLetterIndex = i + 1;
		}
	}

	for (int i = 1; i < 50; i++) {
		if (wordLengths[i] != 0) {
			cout << wordLengths[i] << " : " << i << "-bukveni" << endl;
		}
	}
}

void task2() {
	char str[N] = "";
	cin.getline(str, N);

	int letterCount[26] = { 0 };
	int letterCountC[26] = { 0 };
	int length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		if (isLetter(str[i]) && str[i] > 'Z') {
			letterCount[str[i] - 'a']++;

		}
		else if (isLetter(str[i])) {
			letterCountC[str[i] - 'A']++;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (letterCount[i] != 0) {
			cout << letterCount[i] << " : " << (char)(i + 'a') << endl;
		}
		if (letterCountC[i] != 0) {
			cout << letterCountC[i] << " : " << (char)(i + 'A') << endl;
		}
	}
}

int main() {

	task2();

    return 0;
}

