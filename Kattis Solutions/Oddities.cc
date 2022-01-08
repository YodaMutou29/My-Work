#include <iostream>
using namespace std;

int main() {
    int n, number;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number;
        if (number == 0 || number % 2 == 0) {
            cout << number << " is even" << endl;
        } else {
            cout << number << " is odd" << endl;
        }
    }
    return 0;
}