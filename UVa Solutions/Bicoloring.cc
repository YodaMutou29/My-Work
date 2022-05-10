/* Bicoloring - UVa 10004
* @author Jenna McDonnell
*
* This program uses DFS to search the connections and
* colors as it goes. A graph is not bicolorable if there
* is a connection to a node that is the same color as the
* current node and the color has already been set (we do not
* change the color once it has been set).
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
 public:
    bool color = 0;
    vector<int> connections;
};

// DFS implementation using a stack
bool checkColoring(Node graph[201]) {
    // nodes to be explored (tracked by node number)
    stack<int> frontier;
    bool visited[201] = {false};
    bool colorSet[201] = {false};
    // visting node 0 first
    visited[0] = true;
    colorSet[0] = true;
    for (int i = 0; i < graph[0].connections.size(); i++) {
        frontier.push(graph[0].connections[i]);
        // all node colors are init to 0 so make node 0's connections opposite
        graph[graph[0].connections[i]].color = 1;
        colorSet[graph[0].connections[i]] = true;
    }
    // while there are still nodes to explore
    while (!frontier.empty()) {
        int current = frontier.top();
        frontier.pop();
        // do nothing if we have already visited the node
        if (!visited[current]) {
            visited[current] = true;
            for (int i = 0; i < graph[current].connections.size(); i++) {
                frontier.push(graph[current].connections[i]);
                // check if connections are consistant
                if (graph[current].color == graph[graph[current].connections[i]].color) {
                    // only change the color if the color hasn't been set yet, otherwise
                    // it is not bicolorable
                    if (colorSet[graph[current].connections[i]]) {
                        return false;
                    } else {
                        graph[graph[current].connections[i]].color = !graph[current].color;
                        colorSet[graph[current].connections[i]] = true;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int numNodes;
    cin >> numNodes;
    while (numNodes != 0) {
        Node graph[201];
        int numEdges;
        cin >> numEdges;
        // take in edges and keep track of connections
        for (int i = 0; i < numEdges; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            graph[node1].connections.push_back(node2);
            graph[node2].connections.push_back(node1);
        }
        if (checkColoring(graph)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
        cin >> numNodes;
    }
    return 0;
}