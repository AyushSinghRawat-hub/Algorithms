#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Process {
    string name;
    int arrival_time;
    int burst_time;
    int priority;
};

struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority < p2.priority;
    }
};

int main() {
    // create two priority queues for high and low priority processes
    priority_queue<Process, vector<Process>, ComparePriority> high_priority_queue;
    priority_queue<Process> low_priority_queue;
    
    // create some sample processes
    Process p1 = {"Process 1", 0, 5, 1};
    Process p2 = {"Process 2", 1, 3, 2};
    Process p3 = {"Process 3", 2, 2, 1};
    Process p4 = {"Process 4", 3, 4, 2};
    Process p5 = {"Process 5", 4, 1, 1};
    
    // add processes to their respective priority queues
    high_priority_queue.push(p1);
    high_priority_queue.push(p2);
    high_priority_queue.push(p3);
    low_priority_queue.push(p4);
    low_priority_queue.push(p5);
    
    // simulate execution of processes
    int current_time = 0;
    
    while (!high_priority_queue.empty() || !low_priority_queue.empty()) {
        // execute high priority processes first
        while (!high_priority_queue.empty()) {
            Process p = high_priority_queue.top();
            high_priority_queue.pop();
            cout << "Executing process " << p.name << " at time " << current_time << endl;
            current_time += p.burst_time;
        }
        
        // execute low priority processes next
        while (!low_priority_queue.empty()) {
            Process p = low_priority_queue.front();
            low_priority_queue.pop();
            cout << "Executing process " << p.name << " at time " << current_time << endl;
            current_time += p.burst_time;
        }
    }
    
    return 0;
}

