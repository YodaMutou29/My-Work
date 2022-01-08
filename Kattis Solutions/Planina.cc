#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int iteration;
    cin >> iteration;
    cout << setprecision(10) << pow((pow(2, iteration) + 1), 2);
    return 0;
}