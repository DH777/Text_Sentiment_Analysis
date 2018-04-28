/*
  Add "include" and "using namespace" lines here as necessary
*/
#include <bits/stdc++.h>
using namespace std;

class Word {
private:
	string word;
	int count;
	int total;

public:
	Word(string s) {
		word = s;
		count = 0;
		total = 0;
	}

	void increaseTotal(int n) {
		total = total + n;
		count = count + 1;
	}

	double calculateScore() {
		if (count == 0) return 0;
		return (double)total / (double)count;
	}

	string getWord() const {
		return word;
	}

	int getCount() const {
		return count;
	}

	int getTotal() {
		return total;
	}
};


