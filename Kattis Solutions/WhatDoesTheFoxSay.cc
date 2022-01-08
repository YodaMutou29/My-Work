#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    string blank;
    getline(cin, blank);
    for (int i = 0; i < cases; ++i) {
        string answer;
        string recording;
        getline(cin, recording);
        //cout << "recording = " << recording << endl;
        string goes;
        getline(cin, goes);
        while (goes != "what does the fox say?") {
            stringstream s(goes);
            string word;
            s >> word;
            s >> word;
            s >> word;
            //cout << "recording = " << recording << endl;
            stringstream r(recording);
            string word2;
            //r >> word2;
            while (r >> word2) {
                //cout << "word2 = " << word2 << " " << "word = " << word << endl;
                if (word2 != word) {
                    answer.append(word2);
                    answer.append(" ");
                }
            }
            recording = answer;
            //cout << "answer = " << answer << endl;
            //cout << "recording = " << recording << endl;
            answer.clear();
            getline(cin, goes);
        }
        cout << recording << endl;
    }
    return 0;
}