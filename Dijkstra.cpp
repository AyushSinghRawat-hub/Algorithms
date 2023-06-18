#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // pair of node and distance

// Function to perform Dijkstra's Algorithm
void dijkstra(vector<vector<pii>>& graph, int startNode) {
    int numNodes = graph.size();

    // Create a vector to store the distances from the start node to all other nodes
    vector<int> distances(numNodes, INT_MAX);

    // Create a priority queue to store nodes with the smallest distance
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Set the distance of the start node to 0 and push it to the priority queue
    distances[startNode] = 0;
    pq.push(make_pair(0, startNode));

    while (!pq.empty()) {
        // Extract the node with the smallest distance from the priority queue
        int currentNode = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // Skip if the extracted node has already been processed
        if (currentDistance > distances[currentNode])
            continue;

        // Traverse all neighboring nodes of the current node
        for (auto neighbor : graph[currentNode]) {
            int neighborNode = neighbor.first;
            int neighborDistance = neighbor.second;

            // Update the distance if a shorter path is found
            if (distances[currentNode] + neighborDistance < distances[neighborNode]) {
                distances[neighborNode] = distances[currentNode] + neighborDistance;
                pq.push(make_pair(distances[neighborNode], neighborNode));
            }
        }
    }

    // Print the distances from the start node to all other nodes
    cout << "Shortest distances from node " << startNode << ":" << endl;
    for (int i = 0; i < numNodes; i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }
}

int main() {
    int numNodes = 6;

    // Create a graph using adjacency lists with weights
    vector<vector<pii>> graph(numNodes);

    // Add edges to the graph with their corresponding weights
    graph[0] = {{1, 2}, {2, 5}};
    graph[1] = {{0, 2}, {2, 2}, {3, 1}};
    graph[2] = {{0, 5}, {1, 2}, {3, 2}, {4, 1}};
    graph[3] = {{1, 1}, {2, 2}, {4, 4}, {5, 3}};
    graph[4] = {{2, 1}, {3, 4}, {5, 2}};
    graph[5] = {{3, 3}, {4, 2}};

    int startNode = 0;  // Choose the start node for Dijkstra's Algorithm

    dijkstra(graph, startNode);

    return 0;
}

