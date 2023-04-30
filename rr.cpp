#include<iostream>
#include<queue>

using namespace std;

struct Process {
    int pid;
    int bt;
};

void findWaitingTime(Process proc[], int n, int wt[], int quantum) {
    queue<int> q;
    int remaining_bt[n];
    for(int i=0;i<n;i++) {
        remaining_bt[i] = proc[i].bt;
    }
    int t = 0;
    q.push(0);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(remaining_bt[curr] <= quantum) {
            t += remaining_bt[curr];
            wt[curr] = t - proc[curr].bt;
            remaining_bt[curr] = 0;
        }
        else {
            t += quantum;
            remaining_bt[curr] -= quantum;
        }
        for(int i=0;i<n;i++) {
            if(i != curr && remaining_bt[i] > 0) {
                q.push(i);
            }
        }
        if(remaining_bt[curr] > 0) {
            q.push(curr);
        }
    }
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for(int i=0;i<n;i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findAvgTime(Process proc[], int n, int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt, quantum);
    findTurnAroundTime(proc, n, wt, tat);
    cout << "Processes  Burst Time  Waiting Time  Turn-Around Time\n";
    for(int i=0;i<n;i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "   " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "Average Waiting Time: " << (float)total_wt/(float)n << endl;
    cout << "Average Turn-Around Time: " << (float)total_tat/(float)n << endl;
}

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> quantum;
    Process proc[n];
    for(int i=0;i<n;i++) {
        cout << "Enter burst time for process " << i+1 << ": ";
        cin >> proc[i].bt;
        proc[i].pid = i+1;
    }
    findAvgTime(proc, n, quantum);
    return 0;
}

