#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int pid;  // id
    int bt;   //  time required
    int priority; // Priority 
};



//this function will find the waiting time for all the process
void findWaitingTime(Process proc[], int n,int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;
 
    // calculating waiting time for each process

    for (int  i = 1; i < n ; i++ )
        wt[i] =  proc[i-1].bt + wt[i-1] ;
}

//this function will find the turn around time
void findTurnAroundTime( Process proc[], int n, int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]  time taken +waiting time


    for (int  i = 0; i < n ; i++)
        tat[i] = proc[i].bt + wt[i];
}

//now finding the average time taken for executing all the processes
int findavgTime(Process proc[],int n){
    int wt[n],tat[n],total_wt=0,total_tat=0;

    findWaitingTime(proc,n,wt);

    findTurnAroundTime(proc,n,wt,tat);
    cout << "\nProcesses  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";

     for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t\t\t"
             << proc[i].bt << "\t\t\t    " << wt[i]
             << "\t\t\t\t  " << tat[i] <<endl;
    }

    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;

}


//comparator function to sort the process
bool comparison(Process a ,Process b){
    return (a.priority<b.priority);

}

void priorityScheduling(Process proc[], int n)
{
    // Sort based on the priority
    sort(proc, proc + n, comparison); 
 
    cout<< "Order for the process execution \n";
    for (int  i = 0 ; i <  n; i++)
        cout << proc[i].pid <<" " ;
 
    findavgTime(proc, n);
}

int main()
{
    Process proc[] = {{1, 4, 2}, {2, 3, 0}, {3, 100, 1},{4, 12, 4},{5, 2, 8},{6, 5, 3},{7, 8, 5},{8, 1, 7},{9, 2, 6}};
    int n = sizeof proc / sizeof proc[0];
    priorityScheduling(proc, n);
    return 0;
}