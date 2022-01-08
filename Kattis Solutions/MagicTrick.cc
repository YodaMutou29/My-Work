#include <iostream>
using namespace std;

int main() {
    string word;
    cin >> word;
    char letters[26] = {0};
    for (char ch : word) {
        letters[ch - 'a']++;
        if (letters[ch - 'a'] > 1) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}