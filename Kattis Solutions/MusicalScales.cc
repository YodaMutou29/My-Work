#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    // A, A♯, B, C, C♯, D, D♯, E, F, F♯, G, G♯
    // tone, tone, semitone, tone, tone, tone, semitone
    // scales
    /*
    string A[] = {"A", "B", "C", "D", "E", "F#", "G", "A"}; // A#, C#, D#, F, G#
    string Asharp[] = {"A#", "C", "D", "D#", "F", "G", "A#"};
    string B[] = {"B", "C#", "D#", "E", "F#", "G#", "A#", "B"};
    string C[] = {"C", "D", "E", "F", "G", "A", "B", "C"};
    string Csharp[] = {"C#", "D#", "F", "F#", "G#", "A#", "C", "C#"};
    string D[] = {"D", "E", "F#", "G", "A", "B", "C#", "D"};
    string Dsharp[] = {"D#", "F", "G", "G#", "A#", "C", "D", "D#"};
    string E[] = {"E", "F#", "G#", "A", "B", "C#", "D#", "E"};
    string F[] = {"F", "G", "A", "A#", "C", "D", "E", "F"};
    string Fsharp[] = {"F#", "G#", "A#", "B", "C#", "D#", "F", "F#"};
    string G[] = {"G", "A", "B", "C", "D", "E", "F#", "G"};
    string Gsharp[] = {"G#", "A#", "C", "C#", "D#", "F", "G", "G#"};
    */
    //set<string*> scales = {A, Asharp, B, C, Csharp, D, Dsharp, E, F, Fsharp, G, Gsharp};
    set<string> scales = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

    bool possible[12] = {true, true, true, true, true, true, true, true, true, true, true, true}; 
    int numOfNotes;
    cin >> numOfNotes;
    set<string> uniqueNotes;
    for (int i = 0; i < numOfNotes; ++i) {
        string note;
        cin >> note;
        uniqueNotes.insert(note);
    }
    int checkIfTrue = 0;
    for (auto note : uniqueNotes) {
        for (auto scale : scales) {
                if(includes(scale.begin())) {
                    cout << "Scale doesn't have note" << endl;
                    possible[checkIfTrue] = false;
                }
            cout << "next scale" << endl;
            ++checkIfTrue;
        }
    }
    for (int i = 0; i < 12; ++i) {
        if (possible[i]) {
            switch(i) {
            case 0:
                cout << "A";
                break;
            case 1:
                cout << "A#";
                break;
            case 2:
                cout << "B";
                break;
            case 3:
                cout << "C";
                break;
            case 4:
                cout << "C#";
                break;
            case 5:
                cout << "D";
                break;
            case 6:
                cout << "D#";
                break;
            case 7:
                cout << "E";
                break;
            case 8:
                cout << "F";
                break;
            case 9:
                cout << "F#";
                break;
            case 10:
                cout << "G";
                break;
            case 11:
                cout << "G#";
                break;
            }
            cout << " ";
        }
    }
    return 0;
}