/* Stratigic Defense Initiative - UVa 497
* @author Jenna McDonnell
*
* This program uses Howard's "Longest Ascending Subsequence" to solve.
* Namely, it uses the strictly ascending subsequence function.
*/
/*
 * Longest Ascending Subsequence
 *
 * Author: Howard Cheng
 * Reference:
 *   Gries, D.  The Science of Programming
 *
 * Given an array of size n, asc_seq returns the length of the longest
 * ascending subsequence, as well as one of the subsequences in S.
 * sasc_seq returns the length of the longest strictly ascending
 * subsequence.  It runs in O(n log n) time.
 *
 * Also included are simplified versions when only the length is needed.
 *
 * Note: If we want to find do the same things with descending
 * subsequences, just reverse the array before calling the routines.
 * 
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

int sasc_seq(vector<int> A, int n, int S[])
{
  vector<int> last(n+1), pos(n+1), pred(n);
  if (n == 0) {
    return 0;
  }

  int len = 1;
  last[1] = A[pos[1] = 0];
  for (int i = 1; i < n; i++) {
    int j = lower_bound(last.begin()+1, last.begin()+len+1, A[i]) -
      last.begin();
    pred[i] = (j-1 > 0) ? pos[j-1] : -1;
    last[j] = A[pos[j] = i];
    len = max(len, j);
  }
  int start = pos[len];
  for (int i = len-1; i >= 0; i--) {
    S[i] = A[start];
    start = pred[start];
  }
  return len;
}

int main() {
    int cases;
    cin >> cases;
    string s;
    // get rid of blank space before input
    getline(cin, s);
    getline(cin, s);
    for (int c = 0; c < cases; c++) {
        vector<int> input;
        // problem did not specify limit so I went with 100000
        // and it worked
        int answerArray[100000] = {0};
        getline(cin, s);
        // blank lines separate cases
        while (s != "") {
            int num = stoi(s);
            input.push_back(num);
            getline(cin, s);
        }
        // strictly ascending subsequence function
        int k = sasc_seq(input, input.size(), answerArray);
        cout << "Max hits: " << k << endl;
        for (int i = 0; i < k; i++) {
            cout << answerArray[i] << endl;
        }
        // don't print an extra line if we are at the end of output
        if (c + 1 != cases) {
            cout << endl;
        }
    }
    return 0;
}
