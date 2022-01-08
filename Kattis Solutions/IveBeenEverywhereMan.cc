#include <iostream>
#include <set>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int numCities;
        cin >> numCities;
        set<string> cities;
        for (int j = 0; j < numCities; j++) {
            string city;
            cin >> city;
            cities.insert(city);
        }
        cout << cities.size() << endl;
    }
    return 0;
}