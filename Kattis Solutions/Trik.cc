#include <iostream>
#include <string>
using namespace std;

int main() {
    string moves;
    getline(cin, moves);
    bool cups[3];
    for (int i = 0; i < 3; i++) {
        cups[i] = false;
    }
    cups[0] = true;
    for (char ch : moves) {
        if (ch == 'A') {
            bool temp = cups[0];
            cups[0] = cups[1];
            cups[1] = temp;
        } else if (ch == 'B') {
            bool temp = cups[1];
            cups[1] = cups[2];
            cups[2] = temp;
        } else {
            bool temp = cups[0];
            cups[0] = cups[2];
            cups[2] = temp;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (cups[i]) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}