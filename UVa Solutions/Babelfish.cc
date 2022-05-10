/* Babelfish - UVa 10282
* @author Jenna McDonnell
*
* This implementation uses a map for the dictionary
* because map's find function is implemented as a
* binary search, making it fast enough to solve this
* problem in time.
*/
#include <iostream>
#include <utility> //pair
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main () {
    map<string, string> dictionary;
    string words;
    getline(cin, words);
    while(!words.empty()) {
        pair<string, string> temp;
        stringstream ss(words);
        ss >> temp.second;
        ss >> temp.first;
        dictionary.insert(temp);
        getline(cin, words);
    }
    string word;
    while (cin >> word) {
        if (dictionary.find(word) != dictionary.end()) {
            cout << dictionary[word] << endl;
        } else {
            cout << "eh" << endl;
        }
    }
    return 0;
}