/* Safebreaker - UVa 296
* @author Jenna McDonnell
*
* This implementation uses exhaustive search to try all
* possible answers from 0000 to 9999. It uses a vector of
* vectors to store the user's guesses and feedback and
* checks each of our guesses to see if they are
* consistent with all of these guesses.
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility> //pair
using namespace std;

/*
* Compares two strings and determines the feedback a user
* would get with these strings. String 1 is the user's guess
* and string 2 is our guess for the answer.
*/
void compareGuess(string s1, string s2, vector<int>& answer) {
    //numbers used in user's guess
    bool numUsed1[4] = {0};
    //numbers used in our guess
    bool numUsed2[4] = {0};
    //check correct numbers in correct spot
    for (int i = 0; i < 4; i++) {
        if (s1[i] == s2[i]) {
            answer[0]++;
            numUsed1[i] = 1;
            numUsed2[i] = 1;
        }
    }
    //check correct numbers in wrong spot
    for (int i = 0; i < 4; i++) {
        //check that we are not double counting a number
        //we've already counted
        if (!numUsed1[i]) {
            for (int j = 0; j < 4; j++) {
                //make sure the number we are counting as a
                //match has not been used yet
                if (s1[i] == s2[j] && !numUsed2[j]) {
                    answer[1]++;
                    numUsed1[i] = 1;
                    numUsed2[j] = 1;
                    //break out of this for loop
                    j = 4;
                }
            }
        }
    }
}

/*
* Check if a guess for the answer is consistent with all user guesses
*/
string valid(string s, vector<vector<string>> testSamples) {
    //need to check all user guesses to make sure our guess is consitent
    for (vector<string> v : testSamples) {
        //check how this guess compares to our guess for the answer
        vector<int> feedback = {0, 0};
        compareGuess(v[0], s, feedback);
        //check if this aligns with the feedback given
        if (feedback[0] != stoi(v[1]) || feedback[1] != stoi(v[2])) {
            return "";
        }
    }
    //our guess is consistent with all the user guesses
    return s;
}

/*
* Search through all 10 000 possible answers and test to see if
* they are consistent with all user guesses
*/
string exhastiveSearch(vector<vector<string>> testSamples) {
    //keep track of how many are valid so we know if indeterminate
    int countValid = 0;
    //keep track of which number we are testing
    int currentGuess = 0;
    string answer;
    while(currentGuess < 10000) {
        //convert our guess to a string of exactly length 4
        //making sure there are leading zeroes if necessary
        string s = to_string(currentGuess);
        if (s.length() < 4) {
            string temp;
            for (int j = 0; j < 4 - s.length(); j++) {
                temp += '0';
            }
            temp += s;
            s = temp;
        }
        //check if this guess is valid
        string v = valid(s, testSamples);
        //this means the guess is valid
        if (!v.empty()) {
            countValid++;
            //more than one guess is valid
            if (countValid > 1) {
                return "indeterminate";
            }
            //keep track of the one valid answer so far
            answer = v;
        }
        //move to next guess
        currentGuess++;
    }
    //there is a guess that is valid
    if (countValid > 0) {
        return answer;
    }
    //if we've made it this far, no guesses were valid
    return "impossible";
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int tests;
        cin >> tests;
        //holder for all user guesses
        vector<vector<string>> testSamples;
        for (int j = 0; j < tests; j++) {
            string guess;
            int rightSpot;
            int rightNumber;
            char slash;
            cin >> guess >> rightSpot >> slash >> rightNumber;
            //put information into testSamples
            vector<string> temp;
            temp.push_back(guess);
            temp.push_back(to_string(rightSpot));
            temp.push_back(to_string(rightNumber));
            testSamples.push_back(temp);
        }
        cout << exhastiveSearch(testSamples) << endl;
    }
    return 0;
}