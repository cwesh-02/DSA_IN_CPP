#include <bits/stdc++.h>

using namespace std;

// 1. Update the structure to include Arrival Time and a Completion flag
struct Process {
    int id;
    int AT;
    int BT;
    int CT;
    int WT;
    int RT;
    int TAT;
    bool isCompleted; // To keep track of which jobs are done
};

bool cmp(Process p1, Process p2) {
    return p1.AT < p2.AT;
}

int main()
{
    int n ;
    cout<<"Enter n";

    cin>>n;

    vector<Process> pr(n);

    for(int i = 0; i < n; i++) 
    {
        pr[i].id = i + 1;
        cout << "Input Arrival Time and Burst Time for Process " << pr[i].id << ": ";
        cin >> pr[i].AT >> pr[i].BT;
        
        // At the start, the remaining time is equal to the full burst time
        pr[i].RT = pr[i].BT;
    }

    sort(pr.begin() , pr.end() , cmp);

    int completed = 0;
    int curr_time =0;

    queue<int> rq;
    rq.push(0);
    int tq =2 ;
    int next = 1;
    
    while(!rq.empty())
    {
        int idx = rq.front();
        rq.pop();
        int timespent = 0;

        while(timespent<tq && pr[idx].RT>0)
        {
            pr[idx].RT--;
            curr_time++;
            timespent++;
        }

        while(next < n && pr[next].AT<=curr_time)
        {
            rq.push(next);
            next ++;
        }

        if(pr[idx].RT>0)
        {
            rq.push(idx);
        }

        else{
            pr[idx].CT = curr_time;
        }

        if(rq.empty() && next < n) {
            curr_time = pr[next].AT; // Fast-forward time
            rq.push(next);
            next++;
        }

    }

    return 0;
}