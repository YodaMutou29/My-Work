#include <iostream>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int noAds, ads, costOfAds;
        cin >> noAds >> ads >> costOfAds;
        if (noAds < ads - costOfAds) {
            cout << "advertise" << endl;
        } else if (noAds > ads - costOfAds) {
            cout << "do not advertise" << endl;
        } else {
            cout << "does not matter" << endl;
        }
    }
    return 0;
}