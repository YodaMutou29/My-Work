#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <vector>
using namespace std;

void moveBoat();

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int carCapacity, travelTime, linesFollowing;
        cin >> carCapacity >> travelTime >> linesFollowing;
        multiset<int> carsLeft;
        multiset<int> carsRight;
        int currentTime = 0;
        int carsOnFerry = 0;
        string currentSide = "left";
        for (int j = 0; j < linesFollowing; ++j) {
            int arrivalTime;
            string bankSide;
            cin >> arrivalTime >> bankSide;
            if (bankSide == "left") {
                carsLeft.insert(arrivalTime);
            } else {
                carsRight.insert(arrivalTime);
            }
        }
        multiset<int>::iterator it;
        if (currentSide == "left") {
            it = carsLeft.begin();
        } else {
            it = carsRight.begin();
        }
        vector<multiset<int>::iterator> needToErase;
        int iter = 0;
        while (!carsLeft.empty() && !carsRight.empty()) {
            void moveBoat();
        }
        cout << endl;
    }
    return 0;
}

void moveBoat() {
    if (currentSide == "left") {
        it = carsLeft.begin();
    } else {
        it = carsRight.begin();
    }
    while (carsOnFerry < carCapacity && it != carsRight.end() && it != carsLeft.end()) {
        if (*(it) <= currentTime) {
            ++carsOnFerry;
            cout << currentTime + travelTime << endl;
            needToErase.push_back(it);
        }
        ++it;
        ++iter;
        cout << "it: " << iter << endl;
        //cout << "cars on ferry: " << carsOnFerry << endl;
        //cout << "capacity: " << carCapacity << endl;
    }
    for (int s = 0; s < needToErase.size(); ++s) {
        if (currentSide == "left") {
            carsLeft.erase(needToErase[s]);
        } else {
            carsRight.erase(needToErase[s]);
        }
    }
    needToErase.clear();
    if (currentSide == "left") {
        if (carsOnFerry != 0 || *(carsRight.begin()) <= currentTime) {
            currentSide = "right";
            currentTime += travelTime;
            carsOnFerry = 0;
        } else {
            if (*(carsRight.begin()) < *(carsLeft.begin())) {
                currentTime += travelTime;
                currentSide = "right";
                if (*(carsRight.begin()) > currentTime) {
                    currentTime = *(carsRight.begin());
                }
            } else {
                currentTime = *(carsLeft.begin());
            }
        }
    } else {
        if (carsOnFerry != 0 || *(carsLeft.begin()) <= currentTime) {
            currentSide = "left";
            currentTime += travelTime;
            carsOnFerry = 0;
        } else {
            if (*(carsLeft.begin()) < *(carsRight.begin())) {
                currentTime += travelTime;
                currentSide = "left";
                if (*(carsLeft.begin()) > currentTime) {
                    currentTime = *(carsLeft.begin());
                }
            } else {
                currentTime = *(carsRight.begin());
            }  
        }
    }
    //cout << "current side: " << currentSide << endl;
    cout << "currentTime:" << currentTime << endl; 
}