#include <iostream>
#include <string>
using namespace std;

int main() {
    string dividend, divisor;
    cin >> dividend >> divisor;
    int decimalMove = divisor.length() - 1;
    // dividend is less than or equal to divisor we
    // need to add 0s and a . in front
    if (dividend.length() <= decimalMove) {
        int addingZeroes = decimalMove - dividend.length();
        //add decimal and zero in front
        dividend.insert(0, string("0.") + string(addingZeroes, '0'));
    } else {
        dividend.insert(dividend.length() - decimalMove, ".");
    }
    for (int i = dividend.length() - 1; i >= 0; --i) {
        if (dividend.at(i) == '0') {
            dividend.erase(i, 1);
        } else {
            if (dividend.at(i) == '.') {
                dividend.erase(i, 1);
            }
            break;
        }
    }
    cout << dividend << endl;
    return 0;
}