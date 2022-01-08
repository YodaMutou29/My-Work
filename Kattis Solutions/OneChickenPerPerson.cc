#include <iostream>
using namespace std;

int main() {
    int people, chicken;
    cin >> people >> chicken;
    if (people > chicken) {
        if (people - chicken == 1) {
            cout << "Dr. Chaz needs 1 more piece of chicken!" << endl;
        } else {
            cout << "Dr. Chaz needs " << people - chicken << " more pieces of chicken!" << endl;
        }
    } else {
        if (chicken - people == 1) {
            cout << "Dr. Chaz will have 1 piece of chicken left over!" << endl;
        } else {
            cout << "Dr. Chaz will have " << chicken - people << " pieces of chicken left over!" << endl;
        }
    }
    return 0;
}