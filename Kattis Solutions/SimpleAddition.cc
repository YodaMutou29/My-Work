#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int carry = 0;
    string num1, num2;
    cin >> num1 >> num2;
    vector<int> sum;
    
    int num1Position = num1.size() - 1;
    int num2Position = num2.size() - 1;
    while (num1Position >= 0 && num2Position >= 0) {
        int temp = (int)(num1.at(num1Position) - '0') + (int)(num2.at(num2Position) - '0') + carry;
        if (temp < 10) {
            sum.push_back(temp);
        } else {
            sum.push_back(temp % 10);
            temp -= (temp % 10);
            temp = temp / 10;
            carry = temp;
        }
        --num1Position;
        --num2Position;
    }
    if (num1Position >= 0) {
        while (num1Position >= 0) {
            int temp = (int)(num1.at(num1Position) - '0') + carry;
            if (temp < 10) {
                sum.push_back(temp);
            } else {
                sum.push_back(temp % 10);
                temp -= (temp % 10);
                temp = temp / 10;
                carry = temp;
            }
            --num1Position;
        }
    } else if (num2Position >= 0) {
        while (num2Position >= 0) {
            int temp = (int)(num2.at(num2Position) - '0') + carry;
            if (temp < 10) {
                sum.push_back(temp);
            } else {
                sum.push_back(temp % 10);
                temp -= (temp % 10);
                temp = temp / 10;
                carry = temp;
            }
            --num2Position;
        }
    }
    if (carry != 0) {
        sum.push_back(carry);
    }

    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    return 0;
}