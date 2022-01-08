#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
    long long int n;
    int power;
    long long int answer = 0;
    cin >> n >> power;
    string divisor = to_string((int)(pow(2, power)));
    for (int j = 0; j <= n; ++j) {
        string number = to_string(j);
        if (number.find(divisor) != std::string::npos) {
            ++answer;
        }
    }
    cout << answer << endl;
    return 0;
}