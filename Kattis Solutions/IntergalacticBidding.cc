#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class LargeNumber {
  bool negative = false;
 public:
    string number;
    LargeNumber(string n) {
        if (n.at(0) == '-') {
            negative = true;
            n.erase(0, 1);
        }
        number = n;
    }
};

LargeNumber operator-(const LargeNumber &a, const LargeNumber &b);
LargeNumber operator-=(const LargeNumber &a, const LargeNumber &b);
bool operator==(const LargeNumber &a, const LargeNumber &b) {
    return a.number == b.number;
}
bool operator<(const LargeNumber &a, const LargeNumber &b);
bool operator>(const LargeNumber &a, const LargeNumber &b);
bool operator>=(const LargeNumber &a, const LargeNumber &b);
ostream operator<<(istream &input, LargeNumber &a);

int main() {
    int numberOfParticipants;
    string sumString;
    cin >> numberOfParticipants >> sumString;
    LargeNumber sum(sumString);
    vector<string> winners;
    vector<pair<LargeNumber, string>*> data;

    for (int i = 0; i < numberOfParticipants; ++i) {
        string name;
        string bet;
        cin >> name >> bet;
        //data.push_back(pair(convertToArray(bet), name));
    }
    for (int i = data.size() - 1; i >= 0; ++i) {
        if (sum >= data[i]->first) {
            sum -= data[i]->first;
            
        }
    }
    // output
    cout << winners.size() << endl;
    for (int i = 0; i < winners.size(); ++i) {
        cout << winners[i] << endl;
    }
    return 0;
}
