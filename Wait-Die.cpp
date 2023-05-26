#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int id;
    int timestamp;
    bool isWaiting;
};

bool isYounger(const Process& p1, const Process& p2) {
    return p1.timestamp < p2.timestamp;
}

void allocateResource(Process& process, int resource) {
    cout << "Process " << process.id << " allocated Resource " << resource << endl;
    process.isWaiting = false;
}

void waitForResource(Process& process, int resource) {
    cout << "Process " << process.id << " waiting for Resource " << resource << endl;
    process.isWaiting = true;
}

void waitDieAlgorithm(const vector<Process>& processes, int resource) {
    Process currentProcess = processes[resource];

    for (const Process& p : processes) {
        if (p.id == currentProcess.id) {
            // Skip the current process itself
            continue;
        }

        if (p.isWaiting) {
            if (isYounger(p, currentProcess)) {
                waitForResource(currentProcess, resource);
                return;
            }
        }
    }

    allocateResource(currentProcess, resource);
}

int main() {
    vector<Process> processes = {
        {0, 1, false},
        {1, 2, false},
        {2, 3, false},
        {3, 4, false},
        {4, 5, false}
    };

    // Simulating resource allocation requests
    waitDieAlgorithm(processes, 0);  // Process 0 requests Resource 0
    waitDieAlgorithm(processes, 1);  // Process 1 requests Resource 1
    waitDieAlgorithm(processes, 0);  // Process 2 requests Resource 0

    return 0;
}

