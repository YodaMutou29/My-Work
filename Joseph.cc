/* Joseph - UVa 305
* @author Jenna McDonnell
* This approaches uses brute force to check all guesses that would
* land on a bad guy the first time through. It uses modulos to check this.
* It also involves very basic dynamic programming to store the answers so
* each answer is only computed once.
*/
#include <iostream>
#include <vector>
using namespace std;

void checkGuess(int&, int&, int&, const int);

int main () {
    int storedAnswer[14] = {0};
    int input;
    cin >> input;
    while (input != 0) {
        if (storedAnswer[input - 1] != 0) {
            cout << storedAnswer[input - 1] << endl;
            cin >> input;
        }else {
            //skip good guys
            int guess = input + 1;
            //total num of people good or bad
            int numPeople = 2 * input;
            //where we currently are in the circle
            int index = input;
            //there are still bad guys remaining
            while (numPeople > input) {
                checkGuess(index, numPeople, guess, input);
            }
            storedAnswer[input - 1] = guess;
            cout << guess << endl;
            cin >> input;
        }
    }
    return 0;
}

void checkGuess(int& index, int& numPeople, int& guess, const int input) {
    //this means we are on the second half of the circle which consists of bad guys
    if (index % numPeople >= input) {
        //move the index to check the next position
        index += guess;
        //account for anyone remaining in the circle before we return to the start
        index -= numPeople;
        //a bad guy was killed so subtract one person
        numPeople--;
        while (index > numPeople) {
            index = index % numPeople;
        }
    } else {
        //try the next guess
        guess++;
        //reset the total number of people and try again
        numPeople = 2 * input;
        //this guess would immediately kill a good guy 
        if ((guess - 1) % numPeople < input) {
            //skip to the next bad guy
            guess += input;
        }
        //reset index
        index = guess - 1;
        while (index > numPeople) {
            index = index % numPeople;
        }
    }
}