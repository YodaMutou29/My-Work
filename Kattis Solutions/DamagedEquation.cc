#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool computed = false;

    int temp = a * b;
    if (temp == c * d) {
        cout << a << " * " << b << " = " << c << " * " << d << endl;
        computed = true;
    }
    if (temp == c + d) {
        cout << a << " * " << b << " = " << c << " + " << d << endl;
        computed = true;
    }
    if (temp == c - d) {
        cout << a << " * " << b << " = " << c << " - " << d << endl;
        computed = true;
    }
    if (d != 0) {
        if (temp == c / d) {
            cout << a << " * " << b << " = " << c << " / " << d << endl;
            computed = true;
        }
    }

    temp = a + b;
    if (temp == c * d) {
        cout << a << " + " << b << " = " << c << " * " << d << endl;
        computed = true;
    }
    if (temp == c + d) {
        cout << a << " + " << b << " = " << c << " + " << d << endl;
        computed = true;
    }
    if (temp == c - d) {
        cout << a << " + " << b << " = " << c << " - " << d << endl;
        computed = true;
    }
    if (d != 0) {
        if (temp == c / d) {
            cout << a << " + " << b << " = " << c << " / " << d << endl;
            computed = true;
        }
    }
    
    temp = a - b;
    if (temp == c * d) {
        cout << a << " - " << b << " = " << c << " * " << d << endl;
        computed = true;
    }
    if (temp == c + d) {
        cout << a << " - " << b << " = " << c << " + " << d << endl;
        computed = true;
    }
    if (temp == c - d) {
        cout << a << " - " << b << " = " << c << " - " << d << endl;
        computed = true;
    }
    if (d != 0) {
        if (temp == c / d) {
            cout << a << " - " << b << " = " << c << " / " << d << endl;
            computed = true;
        }
    }

    if (b != 0) {
        temp = a / b;
        if (temp == c * d) {
            cout << a << " / " << b << " = " << c << " * " << d << endl;
            computed = true;
        }
        if (temp == c + d) {
            cout << a << " / " << b << " = " << c << " + " << d << endl;
            computed = true;
        }
        if (temp == c - d) {
            cout << a << " / " << b << " = " << c << " - " << d << endl;
            computed = true;
        }
        if (d != 0) {
            if (temp == c / d) {
                cout << a << " / " << b << " = " << c << " / " << d << endl;
                computed = true;
            }
        }
    }
    
    if (!computed) {
        cout << "problems ahead" << endl;
    }
    return 0;
}