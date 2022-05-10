/* EB Alto Saxophone Player - UVa 10415
* @author Jenna McDonnell
*
* This implementation uses a map of characters 
* and integer arrays to contain the fingers required
* for each note. It uses arrays of length 10 to keep
* track of which buttons are being held down at any
* given time and how many times each finger has been
* pressed.
*/
#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

map<char, list<int>> fingerMap;

void initializeFingerMap() {
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
}

void playNote(char note, int currentlyUsed[10], int totalPresses[10]) {
    int currentlyUsedNew[10] = {0};
    for (int finger : fingerMap[note]) {
        if (currentlyUsed[finger - 1] == 0) {
            currentlyUsedNew[finger - 1] = 1;
            totalPresses[finger - 1]++;
        } else {
            currentlyUsedNew[finger - 1] = 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        currentlyUsed[i] = currentlyUsedNew[i];
    }
}

int main() {
    initializeFingerMap();

    int cases;
    cin >> cases;
    string blank;
    getline(cin, blank);
    //iterate through cases
    for (int i = 0; i < cases; i++) {
        int totalPresses[10] = {0};
        int currentlyUsed[10] = {0};
        string song;
        getline(cin, song);
        if (!song.empty()) {
            for (char note : song) {
                //figure out which fingers we are using and mark them off
                playNote(note, currentlyUsed, totalPresses);
            }
        }
        for (int j = 0; j < 10; j++) {
            cout << totalPresses[j];
            if (j + 1 < 10) {
                cout << " ";
            }
        }
        cout << endl; 
    }
    return 0;
}