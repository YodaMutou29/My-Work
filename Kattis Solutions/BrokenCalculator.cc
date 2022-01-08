#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    long long int previous = 1;
    for (int i = 0; i < cases; ++i) {
        long long int num1, num2;
        char op;
        cin >> num1 >> op >> num2;
        if (op == '+') {
            previous = ((num1 + num2) - previous);
            cout << previous << endl;
        } else if (op == '-') {
            previous = (previous * (num1 - num2));
            cout << previous << endl;
        } else if (op == '*') {
            previous = (num1 * num2) * (num1 * num2);
            cout << previous << endl;
        } else {
            if (num1 % 2 == 0) {
                previous = num1 / 2;
            } else {
                previous = (num1 + 1) / 2;
            }
            cout << previous << endl;
        }
    }
    return 0;
}