/* Vacation - UVa 10192
* @author Jenna McDonnell
*
* This program finds the longest common substring between
* any two strings given in the problem. We have to use getline
* because the problem uses spaces as a character. We also need
* to use dynamic programing to speed up the process for larger
* input.
*/
#include <iostream>
#include <math.h>
#include <string>
#include <map>
using namespace std;

string s, t;

int longestCommonSubstring(int i, int j, int dp[101][101]) {
    // check if we've already calculated this
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    // check if either string is empty
    if (i == 0 || j == 0) {
        dp[i][j] = 0;
        return 0;
    }
    // check if last characters are the same
    if (s[i - 1] == t[j - 1]) {
        dp[i][j] = longestCommonSubstring(i - 1, j - 1, dp) + 1;
        return dp[i][j];
    }
    dp[i][j] = max(
        longestCommonSubstring(i - 1, j, dp),
        longestCommonSubstring(i, j - 1, dp)
    );
    return dp[i][j];
}

int main() {
    int caseNum = 0;
    getline(cin, s);
    while (s[0] != '#') {
        int dp[101][101];
        // init to -1 to show it has not been calculated yet
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j] = -1;
            }
        }
        caseNum++;
        getline(cin, t);
        cout << "Case #" << caseNum << ": you can visit at most "
            << longestCommonSubstring(s.length(), t. length(), dp) << " cities." << endl;
        getline(cin, s);
    }
    return 0;
}