/* The Monocycle - UVa 10047
* @author Jenna McDonnell
*
* This program uses BFS to search all possible nodes
* (nodes have row, column, direction, color, and distance).
* It adds one to the distance for each move or turn and one to the
* color for each move forward.
*/
#include <iostream>
#include <queue>
using namespace std;

class Node {
 public:
    Node(int r, int c, int d, int co, int dis) {
        row = r;
        column = c;
        direction = d;
        color = co;
        distance = dis;
    }
    int row, column;
    // N = 0, E = 1, S = 2, W = 3
    int direction;
    // Green = 0, Black = 1, Red = 2, Blue = 3, White = 4
    int color;
    // time from start
    int distance;
};

void BFS (char chart[26][26], Node startNode, Node& endNode, int length, int width) {
    queue<Node> frontier;
    bool visited[26][26][4][5] = {0};
    // start with start node to explore
    frontier.push(startNode);
    while (!frontier.empty()) {
        Node current = frontier.front();
        frontier.pop();
        if (!visited[current.row][current.column][current.direction][current.color]) {
            // we have made it to the target
            if (current.row == endNode.row && current.column == endNode.column && current.color == endNode.color) {
                // check if this time was shorter than the current lowest time
                if (current.distance < endNode.distance) {
                    endNode.distance = current.distance;
                }
            } else {
                // turn left
                frontier.push(Node(current.row, current.column,
                    (current.direction + 3) % 4, current.color, current.distance + 1));
                // turn right
                frontier.push(Node(current.row, current.column,
                    (current.direction + 1) % 4, current.color, current.distance + 1));
                // move forward
                switch (current.direction) {
                // facing North
                case 0:
                    // make sure we don't go out of bounds
                    if (current.row - 1 >= 0) {
                        // check if there is a barrier
                        if (chart[current.row - 1][current.column] != '#')
                        frontier.push(Node(current.row - 1, current.column,
                            current.direction, (current.color + 1) % 5, current.distance + 1));
                    }
                    break;
                // facing East
                case 1:
                    // make sure we don't go out of bounds
                    if (current.column + 1 < width) {
                        // check if there is a barrier
                        if (chart[current.row][current.column + 1] != '#')
                        frontier.push(Node(current.row, current.column + 1,
                            current.direction, (current.color + 1) % 5, current.distance + 1));
                    }
                    break;
                // facing South
                case 2:
                    // make sure we don't go out of bounds
                    if (current.row + 1 < length) {
                        // check if there is a barrier
                        if (chart[current.row + 1][current.column] != '#')
                        frontier.push(Node(current.row + 1, current.column,
                            current.direction, (current.color + 1) % 5, current.distance + 1));
                    }
                    break;
                // facing West
                case 3:
                    // make sure we don't go out of bounds
                    if (current.column - 1 >= 0) {
                        // check if there is a barrier
                        if (chart[current.row][current.column - 1] != '#')
                        frontier.push(Node(current.row, current.column - 1,
                            current.direction, (current.color + 1) % 5, current.distance + 1));
                    }
                    break;
                }
                visited[current.row][current.column][current.direction][current.color] = true;
            }
        }
    }
}

int main() {
    int caseNumber = 1;
    int length, width;
    cin >> length >> width;
    while (length > 0 && width > 0) {
        char chart[26][26] = {0};
        Node startNode = Node(0, 0, 0, 0, 0);
        Node endNode = Node(0, 0, 0, 0, 1000000);
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                cin >> chart[i][j];
                if (chart[i][j] == 'S') {
                    startNode.row = i;
                    startNode.column = j;
                } else if (chart[i][j] == 'T') {
                    endNode.row = i;
                    endNode.column = j;
                }
            }
        }
        BFS (chart, startNode, endNode, length, width);
        cout << "Case #" << caseNumber << endl;
        if (endNode.distance < 1000000) {
            cout << "minimum time = " << endNode.distance << " sec" << endl;
        } else {
            cout << "destination not reachable" << endl;
        }
        caseNumber++;
        cin >> length >> width;
        // print a blank line in between case outputs
        if (length != 0 && width != 0) {
            cout << endl;
        }
    }
    return 0;
}