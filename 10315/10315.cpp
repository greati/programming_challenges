#include <iostream>
#include <utility>
#include <algorithm>

#define NCARDS 52
#define NSUITS 4

using namespace std;

string values = "23456789TJQKA";
string suits = "CDHS";

int rank_card(char suit, char value){
	for (int i = 0; i < NSUITS; ++i)
		if (suit == suits[i])
			for (int j = 0; j < (NCARDS/NSUITS); ++j) 
				if (value == values[j])
					return (i*(NCARDS/NSUITS) + j);
}

char suit(int rank) {
	return suits[rank % NSUITS];
}

char value(int rank) {
	return values[rank / NSUITS];
}

int hand[2][5];

pair<int,int> eval(int hand) {
	int po;		// partial ordering
	int rank;	// rank at that ordering
}

int main(void) {

	const int BLACK = 0;
	const int WHITE = 1;

	string card;

	while (true) {
		// read hands
		for (int d = 0; d < 2; ++d) {
			for (int i = 0; i < 5; ++i) {
				if(!(cin >> card)) return 0;
				hand[d][i] = rank_card(card[0], card[1]);
			}
		}
		// classify
		pair<int,int> evals[2];
		evals[BLACK] = eval(BLACK);
		evals[WHITE] = eval(WHITE);
	
		bool blackWins = true;
		bool tie = false;

		if (evals[BLACK].first < evals[WHITE].first)
			blackWins = false;
		else if (evals[BLACK].first == evals[WHITE].first)
			if (evals[BLACK].second < evals[WHITE].second)
				blackWins = false;
			else if (evals[BLACK].second == evals[WHITE].second)
				tie = true;
		cout << (tie ? "Tie." : blackWins ? "Black winds." : "White wins.");
	}
	return 0;
}


