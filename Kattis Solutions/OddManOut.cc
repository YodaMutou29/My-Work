#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int numberOfGuests;
        cin >> numberOfGuests;
        unordered_set<long long int> unpairedGuestNumbers;
        for (int j = 0; j < numberOfGuests; j++) {
            long long int guestNumber;
            cin >> guestNumber;
            unordered_set<long long int>::iterator it = unpairedGuestNumbers.find(guestNumber);
            if (it != unpairedGuestNumbers.end()) {
                unpairedGuestNumbers.erase(it);
            } else {
                unpairedGuestNumbers.insert(guestNumber);
            }
        }
        cout << "Case #" << i + 1 << ": " << *(unpairedGuestNumbers.begin()) << endl;
    }
    return 0;
}