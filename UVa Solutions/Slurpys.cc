/* Slurpys - UVa 384
* @author Jenna McDonnell
*
* This program has 3 different boolean functions to check if
* a string is a slump, slimp, or slurpy. For the slurpy function,
* I tried every bisection of the string to see if it could be
* split into a slimp followed by a slump.
*/
#include <iostream>
using namespace std;

// return true if string is a slump
bool slump(string s) {
    // start with D or E
    if (s[0] != 'D' && s[0] != 'E') {
        return false;
    }
    // followed by at least one F
    if (s[1] != 'F') {
        return false;
    }
    for (int i = 2; i < s.length(); i++) {
        if (s[i] != 'F') {
            // ends with G or another slump
            if (s[i] == 'G' && i + 1 == s.length()) {
                return true;
            }
            return slump(s.substr(i, s.length() - i));
        }
    }
    return false;
}

// return true if string is a slimp
bool slimp(string s) {
    if (s[0] != 'A') {
        return false;
    }
    // must end in H if length 2
    if (s.length() == 2) {
        if (s[1] != 'H') {
            return false;
        }
        return true;
    }
    // length greater than 2
    if (s[1] == 'B') {
        if (s[s.length() - 1] == 'C') {
            return slimp(s.substr(2, s.length() - 3));
        }
    }
    // must end in C if length > 2
    if (s[s.length() - 1] == 'C') {
        return slump(s.substr(1, s.length() - 2));
    }
    return false;
}

// return true if string is a slurpy
bool slurpy(string s) {
    // try every bisection of the string
    for (int i = 0; i < s.length(); i++) {
        if (slimp(s.substr(0, i + 1)) && slump(s.substr(i + 1, s.length() - 1))) {
            return true;
        }
    }
    return false;
}

int main () {
    int cases;
    cin >> cases;
    cout << "SLURPYS OUTPUT" << endl;
    for (int i = 0; i < cases; i++) {
        string s;
        cin >> s;
        if (slurpy(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}