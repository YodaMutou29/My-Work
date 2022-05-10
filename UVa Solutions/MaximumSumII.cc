/* Maximum Sum (II) - UVa 10656
* @author Jenna McDonnell
*
* Since all numbers are non-negitive, we just remove zeroes to
* get the minimum subsequence with maximum sum.
*/
#include <iostream>
using namespace std;

int main() {
    // keeps track of whether we've output anything or not
    bool output = false;
    int numbers;
    cin >> numbers;
    // numbers == 0 is the end condition of the program
    while (numbers > 0) {
        output = false;
        for (int i = 0; i < numbers; i++) {
            int n;
            cin >> n;
            // don't want to print zeroes
            if (n > 0) {
                // doing this to avoid an extra space at end of line
                if (output) {
                    cout << " ";
                }
                output = true;
                cout << n;
            }
        }
        // print a zero if nothing else has been output
        if (!output) {
            cout << 0;
        }
        cout << endl;
        cin >> numbers;
    }
    return 0;
}