/* Black Box - UVa 501
* @author Jenna McDonnell
*
* This implementation uses two priority queues to keep track of
* numbers less than and numbers greater than or equal to the
* kth smallest number. The kth smallest number is stored as its
* own integer. When it is time to output the kth smallest number,
* this algorithm checks to make sure there are k - 1 numbers in
* the left priority queue, ensure it is actually the kth smallest
* number.
*/
#include <iostream>
#include <functional> //greater used for priority queue
#include <vector>
#include <queue> //priority queue
using namespace std;

/*
* Add a number to the current group of numbers in use. Each
* new number becomes part of the left priority queue, part
* of the right priority queue, or the currentIndexValue
* (middle). As numbers are taken from the original group of
* numbers, they are deleted from the vector they were
* stored in.
*/
void addNumber(int& currentIndexVal, priority_queue<int>& left,
    priority_queue<int, vector<int>, greater<int>>& right,
    int index, vector<long long int>& originalOrder) {
    if (originalOrder[0] < currentIndexVal) {
        left.push(originalOrder[0]);
        //make sure currentIndexValue is still the kth smallest
        while (left.size() >= index) {
            right.push(currentIndexVal);
            currentIndexVal = left.top();
            left.pop();
        }
    } else {
        right.push(originalOrder[0]);
    }
    //remove this number from the original vector so it is
    //not inserted again
    originalOrder.erase(originalOrder.begin());
}

/*
* Runs a check to make sure currentIndexVal is the kth smallest number,
* then outputs that number.
*/
void outputNumber(int& currentIndexVal, int index, priority_queue<int>& left,
    priority_queue<int, vector<int>, greater<int>>& right) {
    //make sure there are enough numbers in front of the kth smallest number
    while(left.size() != index - 1) {
        left.push(currentIndexVal);
        currentIndexVal = right.top();
        right.pop();
    }
    cout << currentIndexVal << endl;    
}

/*
* Takes in the query numbers and processes them using priority
* queues.
*/
void processQueries(vector<long long int> originalOrder, int N) {
    int lastNumInVec;

    priority_queue<int> left;
    int currentIndexVal = 0;
    priority_queue<int, vector<int>, greater<int>> right;

    int index = 1;
    for (int j = 0; j < N; j++) {
        int numInVec;
        cin >> numInVec;
        if (j == 0) {
            lastNumInVec = numInVec;
            //first number in is starting point for currentIndexVal
            currentIndexVal = originalOrder[0];
            originalOrder.erase(originalOrder.begin());
            for (int s = 1; s < numInVec; s++) {
                addNumber(currentIndexVal, left, right, index, originalOrder); 
            }
        } else {
            for (int s = 0; s < (numInVec - lastNumInVec); s++) {
                addNumber(currentIndexVal, left, right, index, originalOrder);              
            }
            lastNumInVec = numInVec;
        }
        outputNumber(currentIndexVal, index, left, right);
        //next output function with output the (k + 1)th smallest number
        index++;
    }
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        if (i > 0) {
            cout << endl;
        }
        int M, N;
        cin >> M >> N;
        //numbers can be up to 2 000 000 000 so long long
        vector<long long int> originalOrder;
        for (int j = 0; j < M; j++) {
            long long int num;
            cin >> num;
            originalOrder.push_back(num);
        }
        processQueries(originalOrder, N);
    }
    return 0;
}