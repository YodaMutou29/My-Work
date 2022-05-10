/* Hoax or What - UVa 11136
* @author Jenna McDonnell
*
* This implementation uses a multiset to keep track of
* the bills in the urn at any given time. Multisets
* sort the bills while they are inserted, so to get the
* largest and smallest bill, I just accessed the
* beginning and end elements of the multiset.
*/
#include <iostream>
#include <set>
using namespace std;

//adds to total cost at the end of each day
void countCost(multiset<int>& billPrices, long long int& total) {
    //check to see that there are in fact 2 or more bills in
    //the urn at the end of the day
    if (billPrices.size() >= 2) {
        total += (*(--billPrices.end()) - *billPrices.begin());
    } else if (!billPrices.empty()) {
        total += *billPrices.begin();
    }
    //checks if empty before erasing anything because I no longer
    //trust when a UVa problem says something is guaranteed
    if (!billPrices.empty()) {
        billPrices.erase(billPrices.begin());
        if (!billPrices.empty()) {
            billPrices.erase(--billPrices.end());
        }
    }
}

int main() {
    int numDays;
    cin >> numDays;

    while (numDays > 0) {
        multiset<int> billPrices;
        long long int total = 0;
        for (int i = 0; i < numDays; i++) {
            int numBills;
            cin >> numBills;
            for (int j = 0; j < numBills; j++) {
                int bill;
                cin >> bill;
                billPrices.insert(bill);
            }
            countCost(billPrices, total);
        }
        cout << total << endl;
        cin >> numDays;
    }
    return 0;
}