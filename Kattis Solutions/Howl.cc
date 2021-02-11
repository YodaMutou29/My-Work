# include <iostream>
# include <vector>
using namespace std;

int main(){
  char letter;
  vector<char> letters;
  char next;
  while(next != '\n'){
    cin >> letter;
    letters.push_back(letter);
    next = cin.peek();
  }
  cout << "AWH";
  for(int i = 0; i < letters.size() - 1; i++){
    cout << "O";
  }
  return 0;
}
