#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int fibonacci(int);
int fibonacci2(int);
int multiply(string, string);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

int main(){
  string line;
  ifstream file;
  int number;

  string answer = "yes";

  while(answer == "yes"){
    file.open("Algorithms.txt");
    if (file.is_open()) {
      while(getline(file, line)){
        cout << line << endl;
      }
    }
    file.close();
    cin >> number;
    switch(number){
      case 1:
        int n;
        cout << "Please enter a number:" << endl;
        cin >> n;
        cout << fibonacci2(n) << endl;
        break;

      case 2:
        string n1, n2;
        cout << "Please enter the first number:" << endl;
        cin >> n1;
        cout << "Please enter the second number:" << endl;
        cin >> n2;
        cout << multiply(n1, n2) << endl;
        break;

      case 3:
        int numbersToSort;
        cout << "How many numbers do you want to sort?" << endl;
        cin >> numbersToSort;
        int numbers[numbersToSort];
        cout << "Please enter the numbers one-by-one, hitting enter after "
        << "each one." << endl;
        for(int i = 0; i < numbersToSort; i++) {
          cin >> numbers[i];
        }
        for(int i = 0; i < numbersToSort; i++) {
          cout << numbers[i] << " ";
        }
        break;
    }
    cout << "Do you want to continue?" << endl;
    cin >> answer;
  }
  file.close();
  return 0;
}

/*
* A basic recursive method to find Fibonacci numbers based on the original
* algorithm given in the definition of Fibonacci numbers by L. Fibonacci as
* written on page 3 of "Algorithms" by S.Dasgupta, C. Papadimitriou, and
* U. Vazirani.
*
* Time complexity: exponential
*/
int fibonacci(int n) {
  if(n == 0){
    return 0;
  }
  if(n == 1){
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
* A faster method of calculating Fibonacci numbers where an array is made
* and filled with the Fibonacci numbers up to a number n. Based on the
* algorithm on page 4 of "Algorithms" by S. Dasgupta, C. Papadimitriou, and
* U. Vazirani.
*
* Time complexity: polynomial
*/
int fibonacci2(int n) {
  if(n == 0){
    return 0;
  }
  int f[n + 1];
  f[0] = 0;
  f[1] = 1;
  for(int i = 2; i <= n; i++){
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

/*
* A divide-and-conquer method for multiplication based on Karatsuba algorithm
* found at https://www.geeksforgeeks.org/karatsuba-algorithm-for-
* fast-multiplication-using-divide-and-conquer-algorithm/
* and the "multiply" algorithm on pg 47 of "Algorithms" by S. Dasgupta, C Papadimitriou,
* and U. Vazirani.
*
* Time complexity: T(n) = 3T(n/2) + O(n)
*/
int multiply(string n1, string n2) {
  int n = n1.length();
  if(n == 1) {
    return stoi(n1) * stoi(n2);
  }
  string xLeft = n1.substr(0, floor(n / 2));
  string xRight = n1.substr(floor(n / 2), n - floor(n / 2));
  string yLeft = n2.substr(0, floor(n / 2));
  string yRight = n2.substr(floor(n / 2), n - floor(n / 2));
  cout << xLeft << " " << xRight << endl;
  cout << yLeft << " " << yRight << endl;
  int p1 = multiply(xLeft, yLeft);
  int p2 = multiply(xRight, yRight);
  int p3 = multiply(to_string(stoi(xLeft) + stoi(xRight)),
    to_string(stoi(yLeft) + stoi(yRight)));
  return p1 * pow(10.0, (double)n) +
    (p3 - p1 - p2) * pow(10.0, (double)n / 2) + p2;
}

void merge(int[], int, int, int) {

}

void mergeSort(int[], int, int) {

}
