#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int numCustomers;
        cin >> numCustomers;
        vector<int> orderTimes;
        for (int j = 0; j < numCustomers; ++j) {
            int numWoodPieces;
            cin >> numWoodPieces;
            int orderTime = 0;
            for (int w = 0; w < numWoodPieces; ++w) {
                int sz;
                cin >> sz;
                orderTime += sz;
            }
            orderTimes.push_back(orderTime);
        }
        long double waitTime = 0;
        long double totalTime = 0;
        sort(orderTimes.begin(), orderTimes.end());
        for (int s = 0; s < orderTimes.size(); ++s) {
            waitTime += orderTimes[s];
            totalTime += waitTime;
        }
        cout << fixed << setprecision(6) << totalTime / numCustomers << endl;
    }
    return 0;
}