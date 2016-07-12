#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int n;

const int UPPER = 0;
const int SEC_ESQ = 1;
const int SEC_DIR = 2;
const int MID = 3;
const int FOUR_ESQ = 4;
const int FOUR_DIR = 5;
const int LAST = 6;

char BLANK = ' ';

bool sections[10][7] = {
	{true, true, true, false, true, true, true},
	{false, false, true, false, false, true, false},
	{true, false, true, true, true, false, true},
	{true, false, true, true, false, true, true},
	{false, true, true, true, false, true, false},
	{true, true, false, true, false, true, true},
	{true, true, false, true, true, true, true},
	{true, false, true, false, false, true, false},
	{true, true, true, true, true, true, true},
	{true, true, true, true, false, true, true}
};

string s;

void printVertical(int partEsq, int partDir) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < s.length(); ++j) {
			int a = s[j] - '0';
			if (sections[a][partEsq])
				cout << "|";
			else 
				cout << BLANK;
			for (int k = 0; k < n; k++)
				cout << BLANK;
			if (sections[a][partDir])
				cout << "|";
			else
				cout << BLANK;
			if (j < s.length() - 1)
				cout << BLANK;
		}
		cout << endl;
	}
}

void printHorizontal(int part) {
	for (int i = 0; i < s.length(); ++i) {
		int a = s[i] - '0';
		cout << BLANK;
		for (int k = 0; k < n; k++)
			if (sections[a][part])
				cout << "-";
			else cout << BLANK;
		if (i < s.length() - 1)
			cout << BLANK;
		cout << BLANK;
	}	
	cout << endl;
}	

int main(void) {
	while (true) {
		cin >> n;

		if (n == 0) return 0;

		cin >> s;
		
		printHorizontal(UPPER);
		printVertical(SEC_ESQ, SEC_DIR);
		printHorizontal(MID);
		printVertical(FOUR_ESQ, FOUR_DIR);
		printHorizontal(LAST);
	
		cout << endl;
	}

	return 0;
}


