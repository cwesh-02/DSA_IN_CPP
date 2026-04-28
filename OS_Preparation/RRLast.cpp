#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // Required for std::sort

using namespace std;

// 1. Define the Process structure with clear names
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Custom sorting rule: Sort processes by their Arrival Time
bool compareArrival(Process p1, Process p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

int main() {
    int numberOfProcesses = 5;
    vector<Process> processes(numberOfProcesses);
    
    // 2. Get Inputs
    for(int i = 0; i < numberOfProcesses; i++) {
        processes[i].id = i + 1;
        cout << "Input Arrival Time and Burst Time for Process " << processes[i].id << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        
        // At the start, the remaining time is equal to the full burst time
        processes[i].remainingTime = processes[i].burstTime;
    }
    
    // 3. Sort processes by Arrival Time
    sort(processes.begin(), processes.end(), compareArrival);

    // 4. Setup Round Robin Variables
    int timeQuantum = 2;
    int currentTime = processes[0].arrivalTime; // Start clock at the first arrival
    int nextArrivalIndex = 1;

    queue<int> readyqueue;
    readyqueue.push(0);

    while(!readyqueue.empty())
    {
        int idx = readyqueue.front();
        readyqueue.pop();

        int timespent = 0;
        while(timespent<timeQuantum && processes[idx].remainingTime>0)
        {
            processes[idx].remainingTime--;
            currentTime++;
            timespent++;
        }

        while(nextArrivalIndex < numberOfProcesses && processes[nextArrivalIndex].arrivalTime <= currentTime) { 
            readyqueue.push(nextArrivalIndex);
            nextArrivalIndex++;
        }

    }
    
    return 0;
}