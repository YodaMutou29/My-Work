#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double L, K, T1, T2, H;
    cin >> L >> K >> T1 >> T2 >> H;
    cout << fixed << setprecision(6) << H << " ";
    cout << fixed << setprecision(6) << H + (K * T1) + (K * T2) << endl;
    return 0;
}