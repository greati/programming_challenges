#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void) {

	int n;
	char lcd[23][8 * 12];

	const int UPPER = 0;
	const int SEC_ESQ = 1;
	const int SEC_DIR = 2;
	const int MID = 3;
	const int FOUR_ESQ = 4;
	const int FOUR_DIR = 5;
	const int LAST = 6;

	bool sections[10][7] = {
		{false, false, true, false, false, true, false},
		{true, false, true, true, true, false, true},
		{true, false, true, true, false, true, true},
		{false, true, true, true, false, true, false},
		{true, true, false, true, false, true, true},
		{true, true, false, true, true, true, true},
		{true, false, true, false, false, true, false},
		{true, true, true, true, true, true, true},
		{true, true, true, true, false, true, true},
		{true, true, true, false, true, true, true}
	};

	while (true) {
	
		cin >> n;

		if (n == 0) return 0;

		string s;
		
		cin >> s;

		int uli = 0; // upper left index

		for (int i = 0; i < s.length(); ++i) {
			int a = s[i] - '0';
		}		
	}

	return 0;
}
