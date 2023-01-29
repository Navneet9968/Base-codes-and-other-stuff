#include<iostream>
using namespace std;


void findWaitingTime(int processes[], int n,
			int bt[], int wt[], int quantum)
{
	// Make a copy of burst times bt[] 
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
	    rem_bt[i] = bt[i];

	int t = 0; 
	
	while (1)
	{
		bool done = true;
		//going through all the processes
		for (int i = 0 ; i < n; i++)
		{
			if (rem_bt[i] > 0)
			{
				done = false; 
				if (rem_bt[i] > quantum)
				{
					t += quantum;
					rem_bt[i] -= quantum;
				}
				else
				{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
                    //process completely executed
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true) //done when no tsk remains
		break;
	}
}

void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
	//turn around time= burstTime +waiting time
		tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[],int quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	//waiting time calculation
	findWaitingTime(processes, n, bt, wt, quantum);
	//turn around time calculation
	findTurnAroundTime(processes, n, bt, wt, tat);
	// Display processes along with all details
	cout << "Process NO\t "<< " \tburst time "<< " waiting time " << " \tturn around \n";

	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t\t\t\t" << bt[i] <<"\t\t\t " << wt[i] <<"\t\t\t \t" << tat[i] <<endl;
	}

	cout << "the average waiting time is  = "<< (float)total_wt / (float)n;
	cout << "\nthe average turn around time is  = "<< (float)total_tat / (float)n;
}

int main()
{
	
	int processes[] = { 1,2,3,4};
	int n = sizeof processes / sizeof processes[0];

	// Burst time
	int burst_time[] = {7,7,7,7};

	// quantum which is the fixed time for any processs to execute
	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}
