/* Unidirectional TSP - UVa 116
* @author Jenna McDonnell
*
* This program uses recursion to find the best path
* to take to get the smallest sum. It stores all paths
* taken so the correct path can be output at the end.
* It also stores the lowest sum for each node that has
* been calculated to speed up run time.
*/
#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
using namespace std;

int rowLength = 0;
int columnLength = 0;
// nums taken in from input
int arrayNums[11][101] = {0};
// stores paths taken
int lastPath[11][101] = {0};
// stores the path for the current minimum
int minPathTaken[101] = {0};

int minPath(int row, int column, int lowestSum[11][101]) {
    if (lowestSum[row][column] > 0) {
        return lowestSum[row][column];
    }
    // base case when column is last column
    if (column + 1 >= columnLength) {
        lowestSum[row][column] = arrayNums[row][column];
        return arrayNums[row][column];
    }
    // checking for wrap arounds
    int upRow, downRow;
    if (row - 1 < 0) {
        upRow = rowLength - 1;
    } else {
        upRow = row - 1;
    }
    if (row + 1 >= rowLength) {
        downRow = 0;
    } else {
        downRow = row + 1;
    }
    // using this to check whether up right or down is min
    int up = minPath(upRow, column + 1, lowestSum);
    int right = minPath(row, column + 1, lowestSum);
    int down = minPath(downRow, column + 1, lowestSum);
    // using this to check lowest row numbers for tie breakers
    int arrayMoves[3] = {upRow, row, downRow};
    sort(arrayMoves, arrayMoves + 3);
    // find min number
    int minMove = min(up, min(right, down));
    int index = 0;
    while (true) {
        if (arrayMoves[index] == upRow && up == minMove) {
            //up
            lastPath[row][column + 1] = upRow + 1;
            lowestSum[row][column] = arrayNums[row][column] + up;
            return arrayNums[row][column] + up;
        } else if (arrayMoves[index] == row && right == minMove){
            //right
            lastPath[row][column + 1] = row + 1;
            lowestSum[row][column] = arrayNums[row][column] + right;
            return arrayNums[row][column] + right;
        } else if (arrayMoves[index] == downRow && down == minMove) {
            //down
            lastPath[row][column + 1] = downRow + 1;
            lowestSum[row][column] = arrayNums[row][column] + down;
            return arrayNums[row][column] + down;
        }
        index++;
    }
}

int main() {
    // using getline to check for EOF
    string line;
    getline(cin, line);
    while (line != "") {
        stringstream ss(line);
        ss >> rowLength >> columnLength;
        for (int i = 0; i < rowLength; i++) {
            for (int j = 0; j < columnLength; j++) {
                int num;
                cin >> num;
                arrayNums[i][j] = num;
            }
        }
        // saves lowest sums for each node to save time complexity
        int lowestSum[11][101] = {0};
        int min = 100000;
        for (int i = 0; i < rowLength; i++) {
            int iPath = minPath(i, 0, lowestSum);
            if (iPath < min) {
                min = iPath;
                minPathTaken[0] = i + 1;
                for (int k = 1; k < 101; k++) {
                    minPathTaken[k] = lastPath[minPathTaken[k - 1] - 1][k];
                }
            }
        }
        for (int c = 0; c < columnLength; c++) {
            cout << minPathTaken[c];
            if (c + 1 != columnLength) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
        cout << min << endl;
        // getline twice to get the end of the previous line
        getline(cin, line);
        getline(cin, line);
    }
    return 0;
}