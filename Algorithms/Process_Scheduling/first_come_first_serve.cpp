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
        cout << "\nArrival time of P" << i + 1 << ": ";
        cin >> at[i];
        cout << "Burst time of P" << i + 1 << ": ";
        cin >> bt[i];
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        ct[i] = s + bt[i];
        s = ct[i];
    }
    cout << "  "
         << " TAT\t"
         << "WT" << endl;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        cout << "P" << i + 1 << " " << tat[i] << "\t" << wt[i] << endl;
        total_tat += tat[i];
        total_wt += wt[i];
    }

    cout << "Total TAT: " << total_tat << " Mean TAT: " << float(total_tat) / n << endl;
    cout << "Total WT: " << total_tat << " Mean WT: " << float(total_wt) / n<<endl;

    return 0;
}