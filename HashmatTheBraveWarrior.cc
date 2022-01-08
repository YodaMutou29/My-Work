#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    long long int hashmatSoldiers, opponentSoldiers;
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        ss >> hashmatSoldiers >> opponentSoldiers;
        //need to check which number is bigger for some reason
        if (opponentSoldiers > hashmatSoldiers) {
            cout << opponentSoldiers - hashmatSoldiers << endl;
        } else {
            cout << hashmatSoldiers - opponentSoldiers << endl;
        }
    }
    return 0;
}