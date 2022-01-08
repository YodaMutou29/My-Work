
#include <iostream>
#include <set>
#include <math.h>
using namespace std;
 
// main function
int main()
{
    int cases, numbers;
    long long int sum = 0;
    multiset <int> set1;
    multiset <int> set2;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        set1.clear();
        set2.clear();
        sum = 0;
        cin >> numbers;
        //cout << "Numbers = " << numbers << endl;
        for (int s = 0; s < numbers; s++) {
            int n;
            cin >> n;
            if (set1.empty()) {
                set1.insert(n);
            }else {
                // n <= *(set1.end() - 1) || set1.empty()
                if (n <= *(--set1.end()) || set1.empty()) {
                    set1.insert(n);
                    if (set1.size() - set2.size() >= 2) {
                        set2.insert(*(--set1.end()));
                        set1.erase(--set1.end());       
                    }
                } else {
                    set2.insert(n);
                    if (set2.size() - set1.size() >= 2) {
                        set1.insert(*(set2.begin()));
                        set2.erase(set2.begin());
                    }
                }
            }

            if (set1.size() > set2.size()) {
                sum += *(--set1.end());
            } else if (set2.size() > set1.size()) {
                sum += *(set2.begin());
            } else {
                sum += ((*(--set1.end()) + *(set2.begin())) / 2);
            }
        }
        /*
        multiset<int>::iterator it = set1.begin();
        for (int k = 0; k < set1.size(); k++) {
            cout << *(it) << " ";
            it++;
        }
        cout << endl;
        it = set2.begin();
        for (int k = 0; k < set2.size(); k++) {
            cout << *(it) << " ";
            it++;
        }
        cout << endl;
        */
        cout << sum << endl;
    }
    return 0;
}