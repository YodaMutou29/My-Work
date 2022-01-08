#include <iostream>
#include <queue>
using namespace std;

int tileFlips[] = {416, 464, 200, 308, 186, 89, 38, 23, 11};

int main() {
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; ++c) {
        int grid = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char tile;
                cin >> tile;
                if (tile == '*') {
                    grid = grid | (1 << (3 * i + j));
                }
            }
        }
        int distance[520];
        fill(distance, distance + 520, -1);
        distance[grid] = 0;
        queue<int> q;
        q.push(grid);
        while(!q.empty()) {
            int currentGrid = q.front();
            q.pop();
            for (int i : tileFlips) {
                if (distance[currentGrid ^ i] == -1) {
                    distance[currentGrid ^ i] = distance[currentGrid] + 1;
                    q.push(currentGrid ^ i);
                }
            }
        }
        cout << distance[0] << endl;
    }
    return 0;
}