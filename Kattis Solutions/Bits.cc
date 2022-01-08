#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        string number;
        cin >> number;
        vector<int> numOfOnes;
        for (int j = 1; j <= number.length(); ++j) {
            int count = 0;
            string temp = number.substr(0, j);
            int n = stoi(temp);
            while(n > 0) {
                if (n % 2 != 0) {
                    count++;
                }
                n = n / 2;
            }
            numOfOnes.push_back(count);
        }
        sort(numOfOnes.begin(), numOfOnes.end());
        cout << numOfOnes[numOfOnes.size() - 1] << endl;
    }
    return 0;
}