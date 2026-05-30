#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// 1. Update the structure to include Arrival Time and a Completion flag
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    bool isCompleted; // To keep track of which jobs are done
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // 2. Get Input for Arrival and Burst Times
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "\nProcess " << i + 1 << "\n";
        cout << "Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> processes[i].burstTime;
        processes[i].isCompleted = false; // Mark all as incomplete initially
    }

    int currentTime = 0;
    int completedCount = 0;
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    // 3. THE CORE LOGIC: Keep running until all processes are done
    while (completedCount < n) {
        int shortestJobIndex = -1;
        int minBurstTime = INT_MAX;

        // Look at all processes to find the available one with the shortest burst time
        for(int i =0;i<n;i++)
        {
            if(processes[i].arrivalTime<=currentTime && processes[i].isCompleted==false)
            {
                if(processes[i].burstTime<minBurstTime)
                {
                    minBurstTime=processes[i].burstTime;
                    shortestJobIndex = i;
                }

                else if(processes[i].burstTime==minBurstTime)
                {
                    if(processes[i].arrivalTime < processes[shortestJobIndex].arrivalTime)
                    {
                        shortestJobIndex = i;
                    }
                }
            }
        }

        // 4. Execute the chosen process
        if (shortestJobIndex != -1) {
            // Fast-forward time by the burst time of the chosen process
            currentTime += processes[shortestJobIndex].burstTime;
            
            // Calculate metrics for this completed process
            processes[shortestJobIndex].completionTime = currentTime;
            processes[shortestJobIndex].turnaroundTime = processes[shortestJobIndex].completionTime - processes[shortestJobIndex].arrivalTime;
            processes[shortestJobIndex].waitingTime = processes[shortestJobIndex].turnaroundTime - processes[shortestJobIndex].burstTime;
            
            // Add to totals for averages
            totalTurnaroundTime += processes[shortestJobIndex].turnaroundTime;
            totalWaitingTime += processes[shortestJobIndex].waitingTime;
            
            // Mark as done and increment count
            processes[shortestJobIndex].isCompleted = true;
            completedCount++;
        } 
        // 5. What if the CPU is idle?
        else 
        {
            // If no processes have arrived yet, just advance the clock by 1
            currentTime++;
        }
    }

    // 6. Print the Results
    cout << "\n------------------------------------------------------------------------\n";
    cout << " ID | Arrival Time | Burst Time | Completion | Turnaround | Waiting \n";
    cout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) 
    {
             cout << " P" << processes[i].id << " |      " 
             << processes[i].arrivalTime << "       |      " 
             << processes[i].burstTime << "     |     " 
             << processes[i].completionTime << "      |     " 
             << processes[i].turnaroundTime << "      |    " 
             << processes[i].waitingTime << "\n";
    }
    cout << "------------------------------------------------------------------------\n";
    cout << "\nAverage Waiting Time: " << (totalWaitingTime / n);
    cout << "\nAverage Turnaround Time: " << (totalTurnaroundTime / n) << "\n";

    return 0;
}