#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        //cout << "line: " << line << endl;
        string word;
        stringstream s(line);
        while (s >> word) {
            if (word.at(0) == 'a' || word.at(0) == 'e' || word.at(0) == 'i' || word.at(0) == 'o' || word.at(0) == 'u' || word.at(0) == 'y') {
                cout << word << "yay ";
            } else {
                for (char ch : word) {
                    if (word.at(0) == 'a' || word.at(0) == 'e' || word.at(0) == 'i' || word.at(0) == 'o' || word.at(0) == 'u' || word.at(0) == 'y') {
                        cout << word << "ay ";
                        break;
                    } else {
                        // move letter to end of word
                        word = word.substr(1, word.length() - 1) + word.front();
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}