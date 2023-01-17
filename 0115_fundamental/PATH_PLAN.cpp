#include <iostream>
#include <vector>
#include <queue>
#include <utility>

bool routeExists(int fromRow, int fromColumn, int toRow, int toColumn,
                 const vector<vector<bool>>& mapMatrix)
{
    // Check if the starting position and the destination are out of bounds
    if (fromRow < 0 || fromRow >= mapMatrix.size() || fromColumn < 0 || fromColumn >= mapMatrix[0].size()
        || toRow < 0 || toRow >= mapMatrix.size() || toColumn < 0 || toColumn >= mapMatrix[0].size())
    {
        return false;
    }

    // Check if the starting position or the destination are blocked
    if (!mapMatrix[fromRow][fromColumn] || !mapMatrix[toRow][toColumn])
    {
        return false;
    }

    // Use breadth-first search to find a path from the starting position to the destination
    queue<pair<int, int>> q;
    q.emplace(fromRow, fromColumn);
    vector<vector<bool>> visited(mapMatrix.size(), vector<bool>(mapMatrix[0].size(), false));
    visited[fromRow][fromColumn] = true;

    int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // left, right, up, down

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();

        if (row == toRow && col == toColumn)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            if (newRow >= 0 && newRow < mapMatrix.size() && newCol >= 0 && newCol < mapMatrix[0].size()
                && mapMatrix[newRow][newCol] && !visited[newRow][newCol])
            {
                visited[newRow][newCol] = true;
                q.emplace(newRow, newCol);
            }
        }
    }

    return false;
}

#ifndef RunTests
int main()
{
    vector<vector<bool>> mapMatrix {
        {true, false, false},
        {true, true, false},
        {false, true, true}
    };

    cout << routeExists(0, 0, 2, 2, mapMatrix) << endl;
}
#endif
