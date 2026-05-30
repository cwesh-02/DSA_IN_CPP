#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int AT;
    int BT;
    int RT;
    int CT;
    int TAT;
    int WT;
};

// Custom sorting to ensure processes enter the queue in order of Arrival Time
bool cmp(Process a, Process b) {
    return a.AT < b.AT;
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) 
    {
        p[i].id = i + 1;
        cout << "Enter AT and BT of P" << i + 1 << " : ";
        cin >> p[i].AT >> p[i].BT;
        p[i].RT = p[i].BT;
    }

    int tq;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    bool executed = false;
    queue<int> q;
    vector<bool> inQueue(n , false);

    int time =0;
    int completed = 0;

    if (p[0].AT > 0) 
    {
        time = p[0].AT;
    }

    q.push(0);
    inQueue[0] = true;

    while(completed<n)
    {
        if(q.empty()) //q empty h to time skip kro
        {
            for (int i = 0; i < n; i++) 
            {
                if (!inQueue[i] && p[i].RT > 0) 
                {
                    time = p[i].AT;
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }
    }

    return 0;
}