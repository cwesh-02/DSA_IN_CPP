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
    bool isCompleted;
};

bool cmp(Process a , Process b)
{
    return a.AT<b.AT;
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

        processes[i].isCompleted = false;
    }

    sort(processes.begin(),processes.end(),cmp);

    int completed = 0;
    int curr_time = 0;
    
    int total_TAT =0;
    int total_WT =0;

    for(int i =0;i<n;i++)
    {
        curr_time = max(curr_time , processes[i].AT);
        processes[i].CT=processes[i].AT+processes[i].BT;

        processes[i].TAT=processes[i].CT-processes[i].AT;
        processes[i].WT=processes[i].TAT-processes[i].BT;

        curr_time = processes[i].CT;
        total_TAT += processes[i].TAT;
        total_WT += processes[i].WT;        
    }

    cout << "\nID  AT  BT  CT  TAT  WT\n";

for(int i = 0; i < n; i++)
{
    cout << processes[i].id << "   "
         << processes[i].AT << "   "
         << processes[i].BT << "   "
         << processes[i].CT << "   "
         << processes[i].TAT << "   "
         << processes[i].WT << endl;
}

cout << "\nAverage TAT = " << (float)total_TAT / n;
cout << "\nAverage WT = " << (float)total_WT / n;

    return 0;
}