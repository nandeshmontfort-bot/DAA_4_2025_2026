#include <iostream>
using namespace std;

int main() 
{
    int a, i, j;
    cout << "Enter total number of jobs: ";
    cin >> a;
    int job[a], profit[a], id[a];

    for (i = 0; i < a; i++) 
    {
        id[i] = i + 1;
        cout << "Enter job deadline: ";
        cin >> job[i];
        cout << "Enter job profit: ";
        cin >> profit[i];
    }
    for (i = 0; i < a - 1; i++) 
    {
        for (j = i + 1; j < a; j++) 
        {
            if (profit[i] < profit[j]) 
            {
                swap(profit[i], profit[j]);
                swap(job[i], job[j]);
                swap(id[i], id[j]);
            }
        }
    }

    int maxDeadline = 0;
    for (i = 0; i < a; i++) 
    {
        if (job[i] > maxDeadline)
            maxDeadline = job[i];
    }

    int slot[maxDeadline + 1];
    for (i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;
    for (i = 0; i < a; i++) 
    {
        for (j = job[i]; j > 0; j--) 
        {
            if (slot[j] == -1) 
            {
                slot[j] = id[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    cout << "\nJob sequence: ";
    for (i = 1; i <= maxDeadline; i++) 
    {
        if (slot[i] != -1)
            cout << "J" << slot[i] << " ";
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
    return 0;
}
