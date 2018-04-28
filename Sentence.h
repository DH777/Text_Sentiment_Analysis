/*
  Add "include" and "using namespace" lines here as necessary
*/
#include <bits/stdc++.h>
using namespace std;

class Sentence {

  private:
  	int score;
  	string text;

  public:
  	Sentence(int s, string t){
  		score = s;
  		text = t;
  	}

  	int getScore() {
  		return score;
  	}

  	string getText() {
  		return text;
  	}

};
