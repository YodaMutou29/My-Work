/* Dates - UVa 11356
* @author Jenna McDonnell
*
* This solution uses a vector of the months to
* convert months to their respective numbers. It
* then uses Howard Cheng's code to add days to it.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const string months[12] = {"January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};

//changes month to a number value
int parseMonth(string month) {
    int i = 0;
    while (months[i] != month) {
        i++;
    }
    return i + 1;
}

//splits date string into day, month, and year
//returns vector of length 3
vector<string> separateDate(string date) {
    vector<string> separate;
    string temp;
    for (int j = 0; j < date.length(); j++) {
        if (date[j] != '-') {
            temp += date[j];
        } else {
            separate.push_back(temp);
            temp = "";
        }
    }
    separate.push_back(temp);
    temp = "";
    return separate;
}

//taken from Howard's date class
static bool leapYear(int y) {
    return (y % 400 ==0 || (y % 4 == 0 && y % 100 != 0));
}

//taken from Howard's date class
static int daysIn(int m, int y) {
    switch (m) {
    case 4  :
    case 6  :
    case 9  :
    case 11 :
        return 30;
    case 2  :
        if (leapYear(y)) {
    return 29;
        }
        else {
    return 28;
        }
    default :
        return 31;
    }
}

//add days to date and return the new day, month, and year
vector<int> calcNewDate(vector<string> separate, int daysToAdd) {
    int day = stoi(separate[2]);
    int month = parseMonth(separate[1]);
    int year = stoi(separate[0]);
    day += daysToAdd;
    while (day > daysIn(month, year)) {
      day -= daysIn(month, year);
      if (++month > 12) {
        month = 1;
        year++;
      }
    }
    
    while (day < 1) {
      if (--month < 1) {
        month = 12;
        year--;
      }
      day += daysIn(month, year); 
    }
    vector<int> newDate = {day, month, year};
    return newDate;
}

int main() {
    int cases;
    cin >> cases;
    cin.ignore();
    for (int i = 0; i < cases; i++) {
        string date;
        getline(cin, date);

        int daysToAdd;
        cin >> daysToAdd;
        cin.ignore();
        vector<int> newDate = calcNewDate(separateDate(date), daysToAdd);
        cout << "Case " << i + 1 << ": ";
        cout << newDate[2] << "-" << months[newDate[1] - 1] << "-";
        if (newDate[0] < 10) {
            cout << "0" << newDate[0] << endl;
        } else {
            cout << newDate[0] << endl;
        }
    }
    return 0;
}