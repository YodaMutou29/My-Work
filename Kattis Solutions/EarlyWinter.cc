#include <iostream>
using namespace std;

int main() {
    int years, currentYear;
    cin >> years >> currentYear;
    int answer = 0;
    for (int i = 0; i < years; i++) {
        int y;
        cin >> y;
        if (y > currentYear) {
            ++answer;
        } else {
            cout << "It hadn't snowed this early in " << answer << " years!" << endl;
            return 0;
        }
    }
    cout << "It had never snowed this early!" << endl;
    return 0;
}