#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int id;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
    int RT;
    bool isCompleted;
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    
    for(int i =0;i<n;i++)
    {
        processes[i].id = i+1;
        cout<<"Enter Process"<< i+1 << "s AT and BT";
        cin>>processes[i].AT;
        cin>>processes[i].BT;
        processes[i].RT = processes[i].BT;
        processes[i].isCompleted = false;
    }

    int completed = 0;
    int total_TAT = 0;
    int total_WT = 0;
    int curr_time = 0;

    while(completed < n)
    {
        int idx = -1;
        int min_BT = INT_MAX;

        for(int i =0;i<n;i++)
        {
            if(processes[i].AT<=curr_time && processes[i].isCompleted==false)
            {
                if(processes[i].RT < min_BT)
                {
                    min_BT = processes[i].RT;
                    idx = i;
                }
                
                else if(processes[i].RT == min_BT)
                {
                    if(processes[i].AT<processes[idx].AT)
                    {
                        idx = i;
                    }
                }
            }
        }

        if(idx!=-1)
        {
            processes[idx].RT--;
            curr_time++;

            if(processes[idx].RT == 0)
            {
            processes[idx].CT = curr_time;
            processes[idx].TAT = processes[idx].CT - processes[idx].AT;
            processes[idx].WT = processes[idx].TAT - processes[idx].BT;

            total_TAT += processes[idx].TAT;
            total_WT += processes[idx].WT;

            processes[idx].isCompleted = true;
            completed++;
            }
        }

        else
        curr_time++;

    }

    cout << "\n------------------------------------------------------------------------\n";
    cout << " ID | Arrival Time | Burst Time | Completion | Turnaround | Waiting \n";
    cout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) 
    {
             cout << " P" << processes[i].id << " |      " 
             << processes[i].AT << "       |      " 
             << processes[i].BT << "     |     " 
             << processes[i].CT << "      |     " 
             << processes[i].TAT << "      |    " 
             << processes[i].WT << "\n";
    }
    cout << "------------------------------------------------------------------------\n";
    cout << "\nAverage Waiting Time: " << (total_WT / n);
    cout << "\nAverage Turnaround Time: " << (total_TAT / n) << "\n";

    return 0;
}