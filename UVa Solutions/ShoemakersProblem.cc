/* Shoemaker's Problem - UVa 10026
* @author Jenna McDonnell
*
* This program uses its own sorting function to compare fines
* of each job (represented as a struct), and simply sorts a
* vector of jobs using this comparison function.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief S = fine, T = time, id = order it was taken in
 */
struct Job {
    int S, T, id;
};

bool compareFine(const Job& j1, const Job& j2) {
    // job 1 should be done before job 2
    if (j2.S * j1.T < j1.S * j2.T) {
        return true;
    // job 2 should be done before job 1
    } else if (j2.S * j1.T > j1.S * j2.T) {
        return false;
    // fines are equal so the job that was listed first in
    // the problem goes first
    } else {
        return j1.id < j2.id;
    }
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        vector<Job> jobs;
        int numJobs;
        cin >> numJobs;
        for (int j = 0; j < numJobs; j++) {
            int time, fine;
            cin >> time >> fine;
            Job job;
            job.T = time;
            job.S = fine;
            job.id = j + 1;
            jobs.push_back(job);
        }
        // sort jobs based on fine
        sort(jobs.begin(), jobs.end(), compareFine);
        // used to keep track of whether we are at the start of a
        // line of output
        bool output = false;
        for (Job j : jobs) {
            // if we have not output any numbers yet, don't put a space
            // at the beginning of a line
            if (output) {
                cout << " ";
            }
            cout << j.id;
            output = true;
        }
        cout << endl;
        // need to output a blank line between each case's answer
        if (i + 1 != cases) {
            cout << endl;
        }
    }
    return 0;
}