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
    int nextArrivalIndex = 1;                   // Tracks which process arrives next in the list
    
    queue<int> readyQueue;
    readyQueue.push(0); // Push the index of the first process into the queue

    // 5. Core Round Robin Logic
    while(!readyQueue.empty()) {
        int currentIndex = readyQueue.front();
        readyQueue.pop();
        
        int timeSpent = 0;
        
        // Step A: Execute the process for up to the Time Quantum
        while(timeSpent < timeQuantum && processes[currentIndex].remainingTime > 0) {
            processes[currentIndex].remainingTime--;
            timeSpent++;
            currentTime++;
        }
        
        // Step B: Check if any NEW processes have arrived while the CPU was working
        while(nextArrivalIndex < numberOfProcesses && processes[nextArrivalIndex].arrivalTime <= currentTime) { 
            readyQueue.push(nextArrivalIndex);
            nextArrivalIndex++;
        }
        
        // Step C: If the current process isn't done, it goes to the BACK of the queue
        if(processes[currentIndex].remainingTime > 0) {
            readyQueue.push(currentIndex);
        } 
        // Step D: If it is done, record the time it finished
        else {
            processes[currentIndex].completionTime = currentTime; 
        }
        
        // Step E: Handle an Idle CPU (Queue is empty, but more processes are coming later)
        if(readyQueue.empty() && nextArrivalIndex < numberOfProcesses) {
            currentTime = processes[nextArrivalIndex].arrivalTime; // Fast-forward time
            readyQueue.push(nextArrivalIndex);
            nextArrivalIndex++;
        }
    }

    // 6. Calculate Turnaround Time (TAT), Waiting Time (WT), and Print Results
    float totalTAT = 0, totalWT = 0;
    
    cout << "\n----------------------------------------------------\n";
    cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "----------------------------------------------------\n";
    
    for(int i = 0; i < numberOfProcesses; i++) {
        // Turnaround Time = Completion Time - Arrival Time
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        
        // Waiting Time = Turnaround Time - Burst Time
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        
        // Add to running totals for the average calculation
        totalTAT += processes[i].turnaroundTime;
        totalWT += processes[i].waitingTime;
        
        cout << "P" << processes[i].id << "\t" 
             << processes[i].arrivalTime << "\t" 
             << processes[i].burstTime << "\t" 
             << processes[i].completionTime << "\t" 
             << processes[i].turnaroundTime << "\t" 
             << processes[i].waitingTime << "\n";
    }
    
    cout << "----------------------------------------------------\n";
    cout << "Average Turnaround Time: " << (totalTAT / numberOfProcesses) << "\n";
    cout << "Average Waiting Time:    " << (totalWT / numberOfProcesses) << "\n";

    return 0;
}