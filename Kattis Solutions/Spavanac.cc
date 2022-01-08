#include <iostream>
using namespace std;

int main() {
    int hour, minute;
    cin >> hour >> minute;
    int minutes = (hour * 60) + minute;
    minutes -= 45;
    hour = minutes / 60;
    minute = minutes % 60;
    if (minute < 0) {
        minutes = (24 * 60) + minute;
        hour = minutes / 60;
        minute = minutes % 60;
    }
    cout << hour << " " << minute << endl;
    return 0;
}