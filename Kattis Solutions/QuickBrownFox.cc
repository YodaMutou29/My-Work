#include <iostream>
#include <string>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    string emptySpace;
    getline(cin, emptySpace);
    for (int i = 0; i < cases; i++) {
        string line;
        getline(cin, line);
        int letter[26] = {0};
        for (char ch : line) {
            if (ch <= 90 && ch >= 65) {
                letter[ch - 'A']++;
            } else if (ch <= 122 && ch >= 97) {
                letter[ch - 'a']++;
            }
        }
        bool missing = false;
        for (int j = 0; j < 26; j++) {
            if (letter[j] < 1) {
                if (!missing) {
                    cout << "missing ";
                    missing = true;
                }
                cout << char('a' + j);
            }
        }
        if (!missing) {
            cout << "pangram" << endl;
        } else {
            cout << endl;
        }
    }
    return 0;
}