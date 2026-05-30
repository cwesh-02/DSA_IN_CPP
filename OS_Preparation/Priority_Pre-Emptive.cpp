#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int AT;
    int BT;
    int TAT;
    int CT;
    int WT;
    int RT;
    int Priority;
    bool isCompleted;
};

bool cmp(Process a , Process b)
{
    return a.Priority<b.Priority;
}

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
        cout<<"Enter Priority";
        cin>>processes[i].Priority;
        processes[i].isCompleted = false;
        processes[i].RT = processes[i].BT;
    }

    sort(processes.begin(),processes.end(),cmp);

    int completed = 0;
    int curr_time = 0;
    int total_TAT =0;
    int total_WT =0;

    while(completed<n)
    {
        int idx = -1;
        int max_Priority = INT_MAX;

        for(int i =0;i<n;i++)
        {
            if(processes[i].AT<=curr_time && processes[i].isCompleted==false && processes[i].Priority<max_Priority)
            {
                max_Priority = processes[i].Priority;
                idx = i;
            }

            else if(processes[i].Priority==max_Priority && idx!=-1)
            {
                if(processes[i].AT<processes[idx].AT)
                {
                    idx = i;
                }
            }
        
        }

        if(idx!=-1)
        {
        processes[idx].RT--;
        curr_time++;
        
        
if(processes[idx].RT==0)
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
        {
            curr_time++;
        }
        
    }


    cout << "\nID  AT  BT  CT  TAT  WT  Priority\n";

for(int i = 0; i < n; i++)
{
    cout << processes[i].id << "   "
         << processes[i].AT << "   "
         << processes[i].BT << "   "
         << processes[i].CT << "   "
         << processes[i].TAT << "   "
         << processes[i].WT << "   "
         << processes[i].Priority << endl;
}

cout << "\nAverage TAT = " << (float)total_TAT / n;
cout << "\nAverage WT = " << (float)total_WT / n;

    return 0;
}