#include "Sentence.h"
#include "Word.h"

/*
  Add other "include" and "using namespace" lines here as necessary
*/
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <set>
#include <map>
#include <stdio.h>
#include <ctype.h>

using namespace std;
using namespace boost;

vector<Sentence*>* readFile(char* filename) {
	if (filename == NULL) return NULL;
	vector<Sentence*>* v = new vector<Sentence*>();
  string line;
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      	vector<string> strs;
      	split(strs, line, is_any_of(" "));
      	std::string num = strs[0];
     	if (!(num.compare("-1") == 0 || num.compare("1") == 0 || num.compare("-2") == 0 || num.compare("2") == 0 || num.compare("0") == 0)) continue;
      	std::string text = line.substr(num.length() + 1, line.length() - num.length() - 1);
      	Sentence* s = new Sentence(std::stoi(num), text);
      	v->push_back(s);
    }
    myfile.close();
    return v;
  }
  else return NULL; 

}





// Uncomment this for Part 2
struct wordComparator {
  bool operator() (const Word* lhs, const Word* rhs) const
  {return lhs->getWord() < rhs->getWord();}
};




set<Word*, wordComparator>* allWords(vector<Sentence*>& sentences) {

  // create the set using the wordComparator struct like this:
  set<Word*, wordComparator>* words = new set<Word*, wordComparator>;
  for (int i = 0; i < sentences.size(); i++) {
  	std::string text = sentences[i]->getText();
  	vector<string> ws;
  	split(ws, text, is_any_of(" "));
  	std::string initWord = ws[0];
  	if(initWord.length() == 0 || !isalpha(initWord.at(0))) continue;
  	for (int j = 0; j < ws.size(); j++) {
  		if (ws[j].length() == 0 || !isalpha(ws[j].at(0))) continue;
  		to_lower(ws[j]);
  		Word* newWord = new Word(ws[j]);
  		// cout << ws[j] << "\n";
  		if (words->find(newWord) == words->end()) {
  			words->insert(newWord);
  		}else {
  			Word* cur = *(words->find(newWord));
  			cur->increaseTotal(sentences[i]->getScore());
  		}
  	}
  }
  return words;
}



map<string, double>* calculateScores(set<Word*>& words) {
  
  map<string, double>* mymap = new map<string, double>;
  for (std::set<Word*>::iterator it=words.begin(); it!=words.end(); ++it) {
  	double score = (*it)->calculateScore();
  	string word = (*it)->getWord();
  	mymap->insert (std::pair<string,double>(word,score)); 
  }
  return mymap;
}




double calculateSentenceScore(map<string, double>& scores, string sentence) {

	

}

