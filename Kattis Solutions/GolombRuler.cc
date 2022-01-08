#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        set<int> rulerNums;
        stringstream s(line);
        int num;
        while (s >> num) {
            rulerNums.insert(num);
        }
        /*
        set<int>::iterator it = rulerNums.begin();
        for (int i = 0; i < rulerNums.size(); ++i) {
            cout << *(it) << " ";
            ++it;
        }
        */
        //cout << endl;
        int lastNum = *(--rulerNums.end());
        //cout << lastNum << endl;
        
        // subtract one
        int numbers[lastNum];
        for (int i = 0; i < lastNum; ++i) {
            numbers[i] = 0;
        }
        
        set<int>::iterator it1 = rulerNums.begin();
        set<int>::iterator it2 = ++rulerNums.begin();
        while (it1 != --rulerNums.end()) {
            ++numbers[(*it2 - *it1) - 1];
            //cout << *it2 << " - " << *it1 << endl;
            if (it2 == --rulerNums.end()) {
                ++it1;
                it2 = it1;
                if (++it2 == rulerNums.end()) {
                    break;
                }
            } else {
                it2++;
            }
        }
        bool ruler = true;
        bool doubleNum = false;
        set<int> missing;
        for (int i = 0; i < lastNum; ++i) {
            //cout << "numbers " << i + 1 << " = " << numbers[i] << endl;
            if (numbers[i] != 1) {
                ruler = false;
                if (numbers[i] == 0) {
                    missing.insert(i + 1);
                } else {
                    doubleNum = true;
                }
            }
        }
        if (ruler == false) {
            if (doubleNum == true) {
                cout << "not a ruler" << endl;
            } else {
                cout << "missing ";
                set<int>::iterator it3 = missing.begin();
                for (int j = 0; j < missing.size(); ++j) {
                    cout << *it3 << " ";
                    ++it3;
                }
                cout << endl;
            }
        } else {
            cout << "perfect" << endl;
        }

    }
    return 0;
}