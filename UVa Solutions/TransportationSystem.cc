/* Transportation System - UVa 11228
* @author Jenna McDonnell
*
* This program uses Howard's implementation of Kruskal's
* algorithm, with minor changes to count the states,
* road lengths and railroad lengths as the algorithm runs.
* It does not square root or round until we sum / output the
* answer to avoid rounding errors.
*/
/*
 * Implementation of Kruskal's Minimum Spanning Tree Algorithm
 *
 * Author: Howard Cheng
 *
 * This is a routine to find the minimum spanning tree.  It takes as
 * input:
 *
 *      n: number of vertices
 *      m: number of edges
 *  elist: an array of edges (if (u,v) is in the list, there is no need
 *         for (v,u) to be in, but it wouldn't hurt, as long as the weights
 *         are the same).
 *
 * The following are returned:
 *
 *  index: an array of indices that shows which edges from elist are in
 *         the minimum spanning tree.  It is assumed that its size is at
 *         least n-1.
 *   size: the number of edges selected in "index".  If this is not
 *         n-1, the graph is not connected and we have a "minimum
 *         spanning forest."
 *
 * The weight of the MST is returned as the function return value.
 * 
 * The run time of the algorithm is O(m log m).
 *
 * Note: the elements of elist may be reordered.
 *
 * Modified by Rex Forsyth using C++  Aug 28, 2003
 * This version defines the unionfind and edge as classes and  provides
 * constructors. The edge class overloads the < operator. So the sort does
 * not use a  * cmp function. It uses dynamic arrays.
 */
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <algorithm>
using namespace std;

class Node {
 public:
    Node(int xGiven, int yGiven, int n) {
        x = xGiven;
        y = yGiven;
        nodeNum = n;
    }
    long long int x;
    long long int y;
    // used as an identifier for each node
    int nodeNum;
};

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
      
   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {             // for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

class Edge {
 public:
    Edge(Node i, Node j, int weight = 0) {
	    v1 = i.nodeNum;
	    v2 = j.nodeNum;
	    w = weight;
    }
    bool operator<(const Edge& e) const { return w < e.w; }

    int v1, v2;          /* two endpoints of edge                */
    int w;            /* weight, can be double instead of int */
};


void mst(int n, int m, vector<Edge> elist, int& size, int stateLimit, int c)
{
  UnionFind uf(n);

  sort(elist.begin(), elist.end());

    // start by assuming all cities are in a different state
    int numStates = n;
    double numRoads = 0, numRails = 0;

  size = 0;
  for (int s = 0; s < m && size < n-1; s++) {
    int c1 = uf.find(elist[s].v1);
    int c2 = uf.find(elist[s].v2);
    if (c1 != c2) {
      // <= r is a road
      if (elist[s].w <= stateLimit) {
          numRoads += sqrt(elist[s].w);
          // subtract a state
          numStates--;
      // > r is a railroad
      } else {
          numRails += sqrt(elist[s].w);
      }
      uf.merge(c1, c2);
    }
  }

  // output numStates, numRoads, numRails
  cout << "Case #" << c << ": " << numStates << " " << (int)round(numRoads) << " " << (int)round(numRails) << endl;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int numCities, stateLimit;
        cin >> numCities >> stateLimit;
        // doing this to avoid square rooting distance later
        stateLimit *= stateLimit;
        vector<Node> cities;
        vector<Edge> eList;
        for (int j = 0; j < numCities; j++) {
            int x, y;
            cin >> x >> y;
            Node n = Node(x, y, j);
            // doing this as we go only counts each edge once
            for (Node node : cities) {
                int xDiff = node.x - n.x;
                int yDiff = node.y - n.y;
                // no need to square root because we squared the state limit
                int distanceBetween = (xDiff * xDiff) + (yDiff * yDiff);
                eList.push_back(Edge(node, n, distanceBetween));
            }
            // need to do this after so we don't count distance from itself
            cities.push_back(n);
        }
        int size = 0;
        // use Kruskal's algorithm
        mst(numCities, eList.size(), eList, size, stateLimit, i + 1);
    }
    return 0;
}