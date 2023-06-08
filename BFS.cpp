#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS traversal
void bfsTraversal(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();

    // Create a visited array to keep track of visited nodes
    vector<bool> visited(numNodes, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the start node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        // Dequeue a node from the queue
        int currentNode = q.front();
        q.pop();

        // Process the current node (print it, for example)
        cout << currentNode << " ";

        // Enqueue all unvisited neighboring nodes
        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int numNodes = 7;

    // Create a graph using adjacency lists
    vector<vector<int>> graph(numNodes);

    // Add edges to the graph
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3, 4};
    graph[2] = {0, 1, 4};
    graph[3] = {1, 4, 5};
    graph[4] = {1, 2, 3, 5};
    graph[5] = {3, 4, 6};
    graph[6] = {5};

    int startNode = 0;  // Choose the start node for BFS traversal

    cout << "BFS Traversal: ";
    bfsTraversal(graph, startNode);

    return 0;
}

