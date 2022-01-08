#include <iostream>
#include <string>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int houses;
        cin >> houses;
        string bins;
        cin >> bins;
        int count = 0;
        int total = 0;
        for (char ch : bins) {
            if (ch == '1') {
                bool found = false;
                int j = 1;
                while (!found) {
                    if (houses >= count + j) {
                        if (bins.at(count + j) == '1') {
                            total += (j - count);
                            found = true;
                        }
                    } else if (count - 1 < 0) {
                         if (bins.at(count - j) == '1') {
                            total += (count - j);
                            found = true;
                        }                       
                    }
                    i++;
                }
            }
            count++;
        }
        cout << "Case #" << i << ": " << total << endl;
    }
    return 0;
}