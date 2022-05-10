/* WiFi - UVa 11516
* @author Jenna McDonnell
*
* This implementation binary searches the
* answer and checks each guess to see if it works.
* It uses a multiset to store the house numbers
* (which sorts them as they are inserted) to make
* it easier to check the number of access points
* needed for a guess.
*/
#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

/*
* Finds the number of access points needed for a given guess
*/
int checkGuess(multiset<int> houseNumbers, double guess) {
    int accessPointsNeeded = 1;
    //Place the first access point the distance of guess to
    //the right of the first house. This reaches the distance
    //of guess to the left and right of where the access point
    //was placed.
    double currentReach = *(houseNumbers.begin()) + (guess * 2);
    //used to find next house not covered by currentReach
    multiset<int>::iterator nextHouse = houseNumbers.begin();
    //not all houses are covered yet
    while (currentReach < *(houseNumbers.rbegin())) {
        accessPointsNeeded++;
        //find next house not in reach
        while (*(nextHouse) <= currentReach) {
            nextHouse++;
        }
        //place the next access point the distance of guess
        //to the right of the next house not covered
        currentReach = (*(nextHouse) + (guess * 2));
    }
    return accessPointsNeeded;
}

/*
* Finds the maximum distance between any house and the nearest
* access point
*/
double maxDistance(int numAccessPoints, multiset<int> houseNumbers) {
    //current guess
    double distance;
    double lo = 0.0;
    //adding 1.0 to play it safe
    double hi = (*(houseNumbers.rbegin()) / 2.0) + 1.0;
    //binary search the answer
    while (hi - lo > 0.01) {
        //find the middle of all possible answers
        distance = (hi + lo) / 2.0;
        if (checkGuess(houseNumbers, distance) <= numAccessPoints) {
            //decrease distance
            hi = distance;
        } else {
            //increase distance
            lo = distance;
        }
    }
    return hi;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int numAccessPoints, numHouses;
        cin >> numAccessPoints >> numHouses;
        //this will automatically sort the houses if
        //they are not in order
        multiset<int> houseNumbers;
        for (int j = 0; j < numHouses; j++) {
            int houseNum;
            cin >> houseNum;
            houseNumbers.insert(houseNum);
        }
        //output max distance between a house and nearest access point
        cout << fixed << setprecision(1) << maxDistance(numAccessPoints, houseNumbers) << endl;
    }
    return 0;
}