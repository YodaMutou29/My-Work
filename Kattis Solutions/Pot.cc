#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int numbers;
    cin >> numbers;
    double answer = 0;
    for (int i = 0; i < numbers; ++i) {
        int n;
        cin >> n;
        int base = (n - (n % 10)) / 10;
        int exponent = n % 10;
        answer += pow(base, exponent);
    }
    cout << setprecision(10) << answer << endl;
    return 0;
}