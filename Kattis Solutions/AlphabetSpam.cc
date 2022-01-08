#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string line;
    double whitespace = 0;
    double lower = 0;
    double upper = 0;
    double symbol = 0;
    getline(cin, line);
    for(char ch : line) {
        if (ch == '_') {
            whitespace++;
        } else if (islower(ch)) {
            lower++;
        } else if (isupper(ch)) {
            upper++;
        } else {
            symbol++;
        }
    }
    cout << fixed << setprecision(8) << whitespace / line.length() << endl;
    cout << fixed << setprecision(8) << lower / line.length() << endl;
    cout << fixed << setprecision(8) << upper / line.length() << endl;
    cout << fixed << setprecision(8) << symbol / line.length() << endl;
    return 0;
}