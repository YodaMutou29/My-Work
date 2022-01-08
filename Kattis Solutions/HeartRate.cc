#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int b;
        double p;
        cin >> b >> p;
        double actual = (60 * b) / p;
        double dif = 60 / p;
        cout << fixed << setprecision(4) << actual - dif << " " << actual << " " << actual + dif << endl;
    }
    return 0;
}