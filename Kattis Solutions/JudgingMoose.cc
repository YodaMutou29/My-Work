#include <iostream>
using namespace std;

int main() {
    int left, right;
    cin >> left >> right;
    if (left > right) {
        cout << "Odd " << left * 2 << endl;
    } else if (right > left) {
        cout << "Odd " << right * 2 << endl;
    } else if (left == 0 &&  right == 0) {
        cout << "Not a moose" << endl;
    } else {
        cout << "Even " << left + right << endl;
    }
    return 0;
}