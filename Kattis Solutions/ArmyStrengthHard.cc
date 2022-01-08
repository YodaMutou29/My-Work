#include <iostream>
#include <set>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int GodzillaNum, MechaNum;
        cin >> GodzillaNum >> MechaNum;
        multiset<int> GStrength;
        multiset<int> MStrength;
        for (int j = 0; j < GodzillaNum; ++j) {
            int strength;
            cin >> strength;
            GStrength.insert(strength);
        }
        for (int j = 0; j < MechaNum; ++j) {
            int strength;
            cin >> strength;
            MStrength.insert(strength);
        }
        while (!GStrength.empty() && !MStrength.empty()) {
            if (*GStrength.begin() < *MStrength.begin()) {
                GStrength.erase(GStrength.begin());
            } else {
                MStrength.erase(MStrength.begin());
            }
        }
        if (GStrength.empty() && MStrength.empty()) {
            cout << "uncertain" << endl;
        } else if (GStrength.empty()) {
            cout << "MechaGodzilla" << endl;
        } else {
            cout << "Godzilla" << endl;
        }
    }
    return 0;
}