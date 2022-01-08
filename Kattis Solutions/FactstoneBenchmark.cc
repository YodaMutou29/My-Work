#include <iostream>
#include <cmath>
using namespace std;

/*
* When you don't want to use n! do log2(1) * log2(2) * log2(3) * ...
*/
int main() {
    int year, factstone;
    cin >> year;
    while(year != 0) {
        year = (year - 1960) / 10 + 2;
        // get the number of bits for that year
        double bits = pow(2, year);
        factstone = 1;
        while (bits > 0) {
            bits -= log2(factstone);
            factstone++;

        }          
        cout << factstone - 2 << endl;
        cin >> year;
    }
    return 0;
}