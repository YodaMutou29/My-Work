/* Minesweeper - UVa 10189
* @author Jenna McDonnell
*
* This implementation uses DP to update numbers of bombs
* as they are discovered. As the input is being taken in,
* if a bomb is found, all eight spots around it are updated
* (unless that spot already has a bomb). This is done using
* delta arrays to make this easier to iterate through.
*/
#include <iostream>
using namespace std;

void outputAnswer(const int, const int, const int, int[103][103]);

int main() {
    //all eight spots that need to be checked
    const int deltaRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int deltaColumn[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int fieldNum = 0;
    int rows, columns;
    cin >> rows >> columns;
    //iterate through cases
    while (rows != 0 && columns != 0) {
        //most we can have is 100 and I've added 2 to the rows and
        //columns for a buffer to avoid seg faults
        int field[103][103] = {0};
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= columns; ++j) {
                char ch;
                cin >> ch;
                //bomb found
                if (ch == '*') {
                    field[i][j] = -1;
                    //update area around the bomb
                    for (int t = 0; t < 8; ++t) {
                        if (field[i + deltaRow[t]][j + deltaColumn[t]] != -1) {
                            field[i + deltaRow[t]][j + deltaColumn[t]]++;
                        }
                    }
                }
            }
        }
        fieldNum++;
        outputAnswer(fieldNum, rows, columns, field);
        cin >> rows >> columns;
        //only output line if there is another case after
        if (rows != 0 && columns != 0) {
            cout << endl;
        }
    }
    return 0;
}

void outputAnswer(const int fieldNum, const int rows, const int columns, int field[103][103]) {
        cout << "Field #" << fieldNum << ":" << endl;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= columns; ++j) {
                if (field[i][j] >= 0) {
                    cout << field[i][j];
                } else {
                    cout << "*";
                }
            }
            cout << endl;
        }
}