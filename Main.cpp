#include "Sentence.h"
#include "Word.h"

/*
  Add other "include" and "using namespace" lines here as necessary
*/
#include <iostream>
#include <iomanip>

using namespace std;

/*
 Declarations of functions declared in Analyzer.cpp
 Uncomment these as needed, but do not otherwise change these declarations!
*/
vector<Sentence*>* readFile(char*); // Part 1
set<Word*>* allWords(vector<Sentence*>&); // Part 2
map<string, double>* calculateScores(set<Word*>&); // Part 3
//double calculateSentenceScore(map<string, double>&, string); // Part 4

int main(int argc, char* argv[]) {
	vector<Sentence*>* v = readFile(argv[1]);
	set<Word*>* set = allWords(*v);
	map<string, double>* map = calculateScores(*set);
	
}
