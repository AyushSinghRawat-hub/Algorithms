#include<iostream>
#include<algorithm>

using namespace std;

struct Process {
    int pid;
    int bt;
    int priority;
};

bool comparison(Process a, Process b) {
    return (a.priority > b.priority);
}

void findWaitingTime(Process proc[], int n, int wt[]) {
    wt[0] = 0;
    for(int i=1;i<n;i++) {
        wt[i] = proc[i-1].bt + wt[i-1];
    }
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for(int i=0;i<n;i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findAvgTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
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
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process proc[n];
    for(int i=0;i<n;i++) {
        cout << "Enter burst time for process " << i+1 << ": ";
        cin >> proc[i].bt;
        cout << "Enter priority for process " << i+1 << ": ";
        cin >> proc[i].priority;
        proc[i].pid = i+1;
    }
    sort(proc, proc+n, comparison);
    findAvgTime(proc, n);
    return 0;
}
