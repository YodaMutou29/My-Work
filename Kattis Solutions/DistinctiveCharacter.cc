#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
using namespace std;

int main() {
    int existingCharacters, features;
    cin >> existingCharacters >> features;
    cin.ignore();
    int current = 0;
    for (int i = 0; i < existingCharacters; ++i) {
        string line;
        getline(cin, line);
        if (i == 0) {
            current = stoi(line, 0, 2);
            if (existingCharacters == 1) {
                current = ~current;
            }
        } else {
            current = current ^ stoi(line, 0, 2);
        }
    }
    std::bitset<21> x(current);
    string answer = x.to_string();
    answer = answer.substr(answer.length() - features, features);
    cout << answer << endl;
    return 0;
}