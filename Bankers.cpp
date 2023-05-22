#include <iostream>
#include <vector>

using namespace std;

// Define the maximum number of resources available
const int MAX_RESOURCES = 5;

// Function to check if a state is safe using Banker's Algorithm
bool isSafeState(const vector<vector<int>>& allocation,
                 const vector<vector<int>>& max,
                 const vector<int>& available)
{
    int numProcesses = allocation.size();
    int numResources = allocation[0].size();

    vector<bool> finished(numProcesses, false);
    vector<int> work = available;
    vector<vector<int>> need(numProcesses, vector<int>(numResources));

    // Calculate the need matrix
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numResources; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int count = 0;
    while (count < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; ++i) {
            if (!finished[i]) {
                bool canExecute = true;
                for (int j = 0; j < numResources; ++j) {
                    if (need[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    finished[i] = true;
                    found = true;
                    ++count;
                    for (int j = 0; j < numResources; ++j) {
                        work[j] += allocation[i][j];
                    }
                }
            }
        }
        if (!found) {
            // No process found that can be executed
            return false;
        }
    }
    // All processes executed successfully
    return true;
}

int main()
{
    vector<vector<int>> allocation = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<vector<int>> max = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    vector<int> available = {3, 3, 2};

    if (isSafeState(allocation, max, available)) {
        cout << "The system is in a safe state." << endl;
    } else {
        cout << "The system is in an unsafe state." << endl;
    }

    return 0;
}

