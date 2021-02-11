#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int s, t;
  int count = 0;
  bool days[365] = {false};
  for(int i = 0; i < n; i++){
    cin >> s >> t;
    for(int j = s; j <= t; j++){
      if(days[j - 1] == 0){
        days[j - 1] = 1;
        count++;
      }
    }
    //use fill() instead of this loop, it fills a range provided
    //fill(days+s, days+[t])
  }
  cout << count;
  return 0;//quick change
}
