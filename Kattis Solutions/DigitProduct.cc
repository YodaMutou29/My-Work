#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    while (x >= 10) {
        int product = 1;
        while (x > 0) {
            if (x % 10 == 0) {
                x = x / 10;
            } else {
                product = product * (x % 10);
                x -= (x % 10);
                x = x / 10;
            }
        }
        x = product;
    }
    cout << x << endl;
    return 0;
}