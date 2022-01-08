#include <iostream>
#include <vector>
using namespace std;

vector<int> modifyMerge(vector<int>, int, int);
vector<int> merge(vector<int>, int, int, int, int);

int main() {
    // use merge sort
    int numStudents;
    cin >> numStudents;
    // split into two arrays
    int middle = 1 + ((numStudents - 1) / 2);
    int array1[middle];
    int array2[numStudents - middle];
    long long int moves;
    for (int i = 0; i < numStudents; i++) {
        int studentNumber;
        cin >> studentNumber;
        // place in array1 until full then put in array2
    }

    // call modify merge on first half
    modifyMerge(array1, 0, array1.size() - 1);
    // call modify merge on second half
    modifyMerge(array2, 0, array2.size() - 1);
    // merge the two halves
    merge(currentVector, 0, middle, middle + 1, currentOrder.size() - 1);
    return 0;
}

vector<int> modifyMerge(vector<int> current, int from, int to) {
    if (to - from <= 1) {

    } else {
        int m = 1 + ((from - to - 1) / 2);
        modifyMerge(current, from, m);
        modifyMerge(current, m + 1, to);
        merge(current, from, m, m + 1, to);
    }
}

vector<int> merge(vector<int> current, int from1, int to1, int from2, int to2) {
    
}