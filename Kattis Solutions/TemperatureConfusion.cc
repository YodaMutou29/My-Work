#include <iostream>
#include <numeric>
#include <cstring>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}
 
long long int reduceB(long long int a, char b[])
{
    long long int mod = 0;
 
    for (int i = 0; i < strlen(b); i++)
        mod = (mod * 10 + b[i] - '0') % a;
 
    return mod; // return modulo
}

long long int gcdLarge(long long int a, char b[])
{
    long long int num = reduceB(a, b);
    return gcd(a, num);
}

int main() {
    long long int top, bottom;
    char slash;
    cin >> top >> slash >> bottom;
    top = top - (32 * bottom);
    top = 5 * top;
    bottom = 9 * bottom;
    int g = gcd(top, bottom);
    top = top / g;
    bottom = bottom / g;
    cout << top << "/" << bottom << endl;
    return 0;
}