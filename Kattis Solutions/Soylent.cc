#include <iostream>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int calories, bottles = 0;
        cin >> calories;
        while (calories > 0) {
            ++bottles;
            calories -= 400;
        }
        cout << bottles << endl;
    }
    return 0;
}