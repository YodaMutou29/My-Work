#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

long long int answer = 0;

void recursive(int page, map<int, vector<int>> options) {
    vector<int> n = options[page];
    for (auto p : n) {
        if (p == -1) {
            ++answer;
        } else if (p != -2) {
            recursive(p, options);
        }
    }
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int sections;
        cin >> sections;
        int favorablePages = 0;
        bool haveOptions = false;
        map<int, vector<int>> pageOptions;
        for (int j = 0; j < sections; ++j) {
            int page;
            cin >> page;
            cin.ignore();
            vector<int> options;
            if (isdigit(cin.peek())) {
                int num;
                for (int k = 0; k < 3; ++k) {
                    cin >> num;
                    options.push_back(num);
                    haveOptions = true;
                }
            } else {
                string word;
                cin >> word;
                if (word == "favourably") {
                    options.push_back(-1);
                    ++favorablePages;
                } else {
                    options.push_back(-2);
                }
            }
            pageOptions[page] = options;
        }
        answer = 0;
        if (!haveOptions) {
            answer = favorablePages;
        } else {
            recursive(1, pageOptions);
        }
        cout << answer << endl;
    }
    return 0;
}