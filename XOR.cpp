#include <iostream>
#include <vector>
#include <queue>


int getMinimumConnections(const std::vector<std::vector<bool>>& matrix)
{
    // We will use a queue to store the airports that we need to visit in the breadth-first search.
std::queue<int> q;
// We will also use an array to store which airports have been visited.
std::vector<bool> visited(matrix.size(), false);

// We will start at airport 0.
q.push(0);
visited[0] = true;

// We will keep a count of the number of additional connections needed.
int count = 0;

while (!q.empty())
{
    // Get the next airport in the queue.
    int airport = q.front();
    q.pop();

    // Check all the airports that can be reached from this airport.
    for (int i = 0; i < matrix.size(); i++)
    {
        // If there is a connection between these two airports and the destination airport has not been visited yet...
        if (matrix[airport][i] && !visited[i])
        {
            // Mark the destination airport as visited.
            visited[i] = true;
            // Add the destination airport to the queue.
            q.push(i);
        }
    }
}

// If any airports have not been visited, then we need to add connections between the first two unreachable airports.
for (int i = 1; i < visited.size(); i++)
{
    if (!visited[i])
    {
        count++;
        // Add a connection between the first two unreachable airports.
        matrix[0][i] = true;
        matrix[i][0] = true;
        break;
    }
}

return count;

    
}

#ifndef RunTests
int main()
{
    std::vector<std::vector<bool>> matrix {
        {false, true, false, false, true},
        {true, false, false, false, false},
        {false, false, false, true, false},
        {false, false, true, false, false},
        {true, false, false, false, false}
    };
    std::cout << getMinimumConnections(matrix) << std::endl; // should print 1
}
#endif