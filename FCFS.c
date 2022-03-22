// C program for implementation of FCFS scheduling with different arrival time
#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[])
{
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    for (int i = 1; i < n; i++) // calculating waiting time
    {

        service_time[i] = service_time[i - 1] + bt[i - 1]; // Add burst time of previous processes

        wt[i] = service_time[i] - at[i]; // Find waiting time for current process = sum - at[i]

        /* If waiting time for a process is in negative
        that means it is already in the ready queue
        before CPU becomes idle so its waiting time is 0*/
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) // Function to calculate turn around time
{

    for (int i = 0; i < n; i++) // Calculating turnaround time by adding bt[i] + wt[i]
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int at[]) // Function to calculate average waiting and turn-around times.
{
    int wt[n], tat[n];

    findWaitingTime(processes, n, bt, wt, at); // Function to find waiting time of all processes

    findTurnAroundTime(processes, n, bt, wt, tat); // Function to find turn around time for all processes

    printf("Processes   Burst Time   Arrival Time   Waiting Time   Turn-Around Time   Completion Time \n"); // Display processes along with all details
    int total_wt = 0, total_tat = 0;
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        printf("    %2d\t\t%2d \t\t %2d \t\t %2d \t\t %2d \t\t %2d \n", i + 1, bt[i], at[i], wt[i], tat[i], compl_time);
    }
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;
    printf("\nAverage waiting time = %2.3f", avg_wt);
    printf("\nAverage turn around time = %2.3f", avg_tat);
}

int main()
{
    // Process id's
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];

    // Burst time of all processes
    int burst_time[] = {5, 9, 6};

    // Arrival time of all processes
    int arrival_time[] = {0, 3, 6};

    findavgTime(processes, n, burst_time, arrival_time);

    return 0;
}
