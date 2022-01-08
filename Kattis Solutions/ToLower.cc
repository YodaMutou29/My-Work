#include <iostream>
#include <string>
using namespace std;

int main() {
    int problems, cases;
    int count = 0;
    cin >> problems >> cases;
    for (int i = 0; i < problems; ++i) {
        bool fail = false;
        for (int j = 0; j < cases; ++j) {
            string line;
            cin >> line;
            line.at(0) = (char)tolower(line.at(0));

            for(char ch : line) {
                if (!islower(ch)) {
                    fail = true;
                }
            }
        }
        if (!fail) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}