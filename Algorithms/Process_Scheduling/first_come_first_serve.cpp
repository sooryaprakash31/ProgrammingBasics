/*
First Come First Serve (FCFS):
    
    - Simplest and easiest process scheduling algorithm
    - The CPU is allotted to the processed in the order they request it
    - Non-preemptive scheduling algorithm

Disadvantages:
    - Average waiting time is high
    - Processes have to wait though their burst time is less (Convoy Effect)
    
    Turn Around Time = Completion Time - Arrival Time
    
    Waiting Time = Turn Around Time - Burst Time

*/

#include <iostream>
using namespace std;

int main()
{

    int n;
    int total_tat = 0, total_wt = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    int at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++)
    {
        //reading arrival time and burst time for all processes
        cout << "\nArrival time of P" << i + 1 << ": ";
        cin >> at[i];
        cout << "Burst time of P" << i + 1 << ": ";
        cin >> bt[i];
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        //Calculating completion time for processes
        ct[i] = s + bt[i];
        s = ct[i];
    }
    cout << "\n   TAT\tWT"<< endl;
    for (int i = 0; i < n; i++)
    {
        //calculating turn around time
        tat[i] = ct[i] - at[i];

        //calculating waiting time
        wt[i] = tat[i] - bt[i];
        cout << "P" << i + 1 << " " << tat[i] << "\t" << wt[i] << endl;
        total_tat += tat[i];
        total_wt += wt[i];
    }

    cout << "Total TAT: " << total_tat << " | Mean TAT: " << float(total_tat) / n << endl;
    cout << "Total WT: " << total_tat << " | Mean WT: " << float(total_wt) / n<<endl;

    return 0;
}