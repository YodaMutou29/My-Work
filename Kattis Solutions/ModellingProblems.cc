#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    string whiteSpace;
    getline(cin, whiteSpace);
    for (int i = 0; i < cases; ++i) {
        string line;
        getline(cin, line);
        while (line.length() > 0) {
            char ch = line.at(0);
            if (ch == '[') {
                string s = line.substr(1, line.find(']') - 1);
                cout << s << endl;
                line.erase(0, s.length() + 2);
                cout << line << endl;
            } else if (ch == '(') {
                string s = line.substr(1, line.find(')') - 1);
                cout << s << endl;
                line.erase(0, s.length() + 2);
                cout << line << endl;
            } else if (ch == '{') {
                string s = line.substr(1, line.find('}') - 1);
                cout << s << endl;
                line.erase(0, s.length() + 2);
                cout << line << endl;
            } else if (ch == '<') {
                string s = line.substr(1, line.find('>') - 1);
                cout << s << endl;
                line.erase(0, s.length() + 2);
                cout << line << endl;               
            }
        }
    }
    return 0;
}