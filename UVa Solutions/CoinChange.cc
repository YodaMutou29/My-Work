/* Coin Change - UVa 674
* @author Jenna McDonnell
*
* This program uses recursion to find all possible
* ways of making the change. It stores any already
* found solutions to make solutions for larger numbers
* quicker to find.
*/
#include <iostream>
using namespace std;

// the denominations
int d[5] = {1, 5, 10, 25, 50};
// DP array to store previously done recursions
int stored[100000][6] = {0};

int numOfWays(int sum, int denoms) {
    if (stored[sum][denoms] > 0) {
        return stored[sum][denoms];
    }
    if (denoms == 0) {
        // no coins for sum of zero so one way to do this
        if (sum == 0) {
            stored[sum][denoms] = 1;
            return 1;
        }
        // can't make change with no coins
        stored[sum][denoms] = 0;
        return 0;
    }
    // anything under five cents can only be done with pennies
    if (sum < 5) {
        stored[sum][denoms] = 1;
        return 1;
    }
    // make sure we are not checking a negative sum
    if (sum - d[denoms - 1] >= 0) {
        stored[sum][denoms] = numOfWays(sum - d[denoms - 1], denoms) + numOfWays(sum, denoms - 1);
        return stored[sum][denoms];
    }
    stored[sum][denoms] = numOfWays(sum, denoms - 1);
    return stored[sum][denoms];
}

int main () {
    int num;
    while (cin >> num) {
        cout << numOfWays(num, 5) << endl;
    }
    return 0;
}