#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

int main() {
    map<char, list<int>> fingerMap;
    fingerMap['c'] = {2, 3, 4, 7, 8, 9, 10};
    fingerMap['d'] = {2, 3, 4, 7, 8, 9};
    fingerMap['e'] = {2, 3, 4, 7, 8};
    fingerMap['f'] = {2, 3, 4, 7};
    fingerMap['g'] = {2, 3, 4};
    fingerMap['a'] = {2, 3};
    fingerMap['b'] = {2};
    fingerMap['C'] = {3};
    fingerMap['D'] = {1, 2, 3, 4, 7, 8, 9};
    fingerMap['E'] = {1, 2, 3, 4, 7, 8};
    fingerMap['F'] = {1, 2, 3, 4, 7};
    fingerMap['G'] = {1, 2, 3, 4};
    fingerMap['A'] = {1, 2, 3};
    fingerMap['B'] = {1, 2};

    int cases;
    string emptySpace;
    cin >> cases;
    getline(cin, emptySpace);
    for (int i = 0; i < cases; ++i) {
        string song;
        int presses[10] = {0};
        getline(cin, song);
        if (!song.empty()) {
            // count finger presses
            int fingersUsed[10] = {0};
            for (char note : song) {
                int fingersUsedNew[10] = {0};
                for (int finger : fingerMap[note]) {
                    if (fingersUsed[finger - 1] == 0) {
                        fingersUsedNew[finger - 1] = 1;
                        presses[finger - 1]++;
                    } else {
                        fingersUsedNew[finger - 1] = 1;
                    }
                }
                for (int s = 0; s < 10; ++s) {
                    fingersUsed[s] = fingersUsedNew[s];
                }
                
            }
        }
        for (int j = 0; j < 10; ++j) {
            cout << presses[j] << " ";
        }
        cout << endl;
    }

    return 0;
}