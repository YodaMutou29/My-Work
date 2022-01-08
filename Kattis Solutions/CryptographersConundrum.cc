#include <iostream>
#include <string>
using namespace std;

int main() {
    string code;
    cin >> code;
    int position = 1;
    int count = 0;
    for (char ch : code) {
        if (position % 3 == 1) {
            if (ch != 'P') {
                count++;
            }
        } else if (position % 3 == 2) {
            if (ch != 'E') {
                count++;
            }
        } else {
            if (ch != 'R') {
                count++;
            }
        }
        position++;
    }
    cout << count << endl;
    return 0;
}