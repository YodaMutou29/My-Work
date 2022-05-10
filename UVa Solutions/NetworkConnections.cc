/* Network Connections - UVa 793
* @author Jenna McDonnell
*
* This implementation uses Howard's code library
* implementation of union-find to connect networks
* of computers and check which computers are
* currently connected.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind


class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n;
	 uf = new UF[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use
      
      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }

      UF* getUF() {
          return uf;
      }
      
   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

/*
* Processes every connection or query line of input using stringstream.
*/
void processLine(UnionFind& u, string line, int& success, int& unsuccess) {
            //do something with the line
            stringstream ss(line);
            char ch;
            int comp1, comp2;
            ss >> ch >> comp1 >> comp2;
            if (ch == 'c') {
                //create connection
                u.merge(comp1 - 1, comp2 - 1);
            } else {
                //query
                if (u.find(comp1 - 1) == u.find(comp2 - 1)) {
                    //connected
                    success++;
                } else {
                    //not connected
                    unsuccess++;
                }
            }
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        //output a blank line between cases
        if (i > 0) {
            cout << endl;
        }
        int numComputers;
        cin >> numComputers;
        UnionFind u(numComputers);
        int success = 0;
        int unsuccess = 0;
        //because we are using getline and did not
        //getline the first input
        cin.ignore();
        string line;
        getline(cin, line);
        //cases are separated by blank line
        while (!line.empty()) {
            processLine(u, line, success, unsuccess);
            getline(cin, line);
        }
        //answer
        cout << success << "," << unsuccess << endl;
    }
    return 0;
}