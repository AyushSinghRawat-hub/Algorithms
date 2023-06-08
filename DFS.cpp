#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS traversal
void dfsTraversal(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();

    // Create a visited array to keep track of visited nodes
    vector<bool> visited(numNodes, false);

    // Create a stack for DFS
    stack<int> s;

    // Mark the start node as visited and push it to the stack
    visited[startNode] = true;
    s.push(startNode);

    while (!s.empty()) {
        // Pop a node from the stack
        int currentNode = s.top();
        s.pop();

        // Process the current node (print it, for example)
        cout << currentNode << " ";

        // Push all unvisited neighboring nodes to the stack
        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
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

    int startNode = 0;  // Choose the start node for DFS traversal

    cout << "DFS Traversal: ";
    dfsTraversal(graph, startNode);

    return 0;
}

