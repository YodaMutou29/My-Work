/* Another n-Queen Problem - UVa 11195
* @author Jenna McDonnell
*
* This implementation uses arrays to mark off the
* occupied rows, columns, and diagonals. It then
* uses a recursive function to check for all legal
* placements of the n Queens.
*/
#include <iostream>
using namespace std;

int answer = 0;

/*
* Recursive call that finds all possible combinations of queens.
*/
void findPossibilities(int row[15], bool col[15], bool dia1[30],
    bool dia2[30], int rowIndex, bool badSpots[15][15], int n) {
    //we have placed n queens
    if (rowIndex == n) {
        answer++;
        return;
    }
    //check each spot we can place a queen in this row
    for (int column = 0; column < n; column++) {
        row[rowIndex] = column;
        if (!badSpots[rowIndex][column]) {
            //calculate which diagonals this tile occupies
            int d1 = rowIndex - column + (n - 1);
            int d2 = rowIndex + column;
            if (!col[column] && !dia1[d1] && !dia2[d2]) {
                //note this column and both diagonals as occupied
                col[column] = 1;
                dia1[d1] = 1;
                dia2[d2] = 1;
                //recurse
                findPossibilities(row, col, dia1, dia2, rowIndex + 1, badSpots, n);
                //undo these occupations so we can test the next possibility
                col[column] = 0;
                dia1[d1] = 0;
                dia2[d2] = 0;               
            }
        }
    }
}

/*
* Basic set up and calling of the recursive function
*/
void numPossibilities(int n, bool badSpots[15][15]) {
    //init rows, columns, diagonals
    int row[15];
    int rowIndex = 0;
    bool col[15] = {0};
    bool dia1[30] = {0};
    bool dia2[30] = {0};

    findPossibilities(row, col, dia1, dia2, rowIndex, badSpots, n);
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    while (n > 0) {
        //keep track of case number for output
        count++;
        bool badSpots[15][15] = {0};
        //process board
        char tile;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //check for bad spots
                cin >> tile;
                if (tile == '*') {
                    badSpots[i][j] = 1;
                }
            }
        }
        //calculates answer which is global
        numPossibilities(n, badSpots);
        //output answer
        cout << "Case " << count << ": " << answer << endl;
        //reset answer for next case
        answer = 0;
        cin >> n;
    }
    return 0;
}