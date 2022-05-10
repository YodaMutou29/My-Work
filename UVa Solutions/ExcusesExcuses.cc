/* Excuses, Excuses - UVa 409
* @author Jenna McDonnell
*
* This solution takes in all keywords for a case,
* then it takes in each excuse and checks them for
* keywords before bringing in the next excuse. It uses
* isalpha() from the stl library to check if a character
* is alphabetic. A vector stores all excuses that have
* the current highest number of excuses. This vector is
* cleared once a new highest number of excuses has been
* discovered.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

vector<string> findHighestExcuses(string&, const int, const string*, const int);
void searchForKeywords(string&, const int, string&, int&, const string*);
void outputAnswer(const vector<string>, const int);

int main() {
    //keep track of excuse set number
    int excuseSetNumber = 0;
    string line;
    //check for input
    while (getline(cin, line)){
        excuseSetNumber++;
        //take in number of keywords and number of excuses
        stringstream ss(line);
        int numKeywords, numExcuses;
        ss >> numKeywords >> numExcuses;
        //take in keywords and put them in an array
        string keywords[numKeywords];
        for (int i = 0; i < numKeywords; ++i) {
            string keyword;
            cin >> keyword;
            keywords[i] = keyword;
        }
        vector<string> answer = findHighestExcuses(line, numExcuses, keywords, numKeywords);
        outputAnswer(answer, excuseSetNumber);
    }
    return 0;
}

vector<string> findHighestExcuses(string& line, const int numExcuses,
const string* keywords, const int numKeywords) {
        //keep track of highest number of keywords and the excuses with this number (vector)
        int mostExcuses = 0;
        vector<string> highestExcuses;
        getline(cin, line);
        for (int i = 0; i < numExcuses; ++i) {
            string excuse;
            getline(cin, excuse);
            string word;
            int numKeywordsInExcuse = 0;
            //find number of keywords in excuse
            searchForKeywords(excuse, numKeywords, word, numKeywordsInExcuse, keywords);
            if (numKeywordsInExcuse == mostExcuses) {
                highestExcuses.push_back(excuse);
            } else if (numKeywordsInExcuse > mostExcuses) {
                highestExcuses.clear();
                highestExcuses.push_back(excuse);
                mostExcuses = numKeywordsInExcuse;
            } else {
                //do nothing
            }
        }
        return highestExcuses;
}

void searchForKeywords(string& excuse, const int numKeywords, string& word,
int& numKeywordsInExcuse, const string* keywords) {
    int counter = 0;
    for (char ch : excuse) {
        counter++;
        //check if character is alphabetic because all
        //non-alphabetic characters are delimeters
        if (isalpha(ch)) {
            word.push_back(tolower(ch));
            if (counter == excuse.length()) {
                goto checkWord;
            }
        } else {
checkWord:
            //check if word is in keywords
            for (int i = 0; i < numKeywords; ++i) {
                if(word == keywords[i]) {
                    numKeywordsInExcuse++;
                    i = numKeywords;
                }
            }
            word = "";
         }
    }
}

void outputAnswer(const vector<string> answer, const int excuseSetNumber) {
    cout << "Excuse Set #" << excuseSetNumber << endl;
    //output excuse(s) with highest number of keywords
    for (string s : answer) {
        cout << s << endl;
    }
    cout << endl;
}