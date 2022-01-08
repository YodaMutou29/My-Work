#include <iostream>
#include <string>
using namespace std;

int main() {
    int cases;
    // number can be from 2 to 50 digits
    string number;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int sum = 0;
        // number of digits that have been added to sum already
        int numDigits = 0;
        cin >> number;
        // digits are removed backwards (right to left)!
        for (int j = number.size() - 1; j >= 0; j--) {
            if (numDigits % 2 == 0) {
                sum += (int)((number.at(j)) - '0');
            } else {
                int temp = 2 * (int)((number.at(j)) - '0');
                if (temp < 10) {
                    sum += temp;
                } else {
                    while (temp > 0) {
                        sum += (temp % 10);
                        temp -= (temp % 10);
                        temp = temp / 10;
                    }
                }
            }
            numDigits++;
        }
        if (sum % 10 == 0) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }
    return 0;
}