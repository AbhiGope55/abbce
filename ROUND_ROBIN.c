// C++ program for implementation of RR scheduling


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    // Make a copy of burst times bt[] to store remaining burst times.
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0; // Current time

    // Keep traversing processes in round robin manner until all of them are not done.
    while (1)
    {
        bool done = true;

        // Traverse all processes one by one repeatedly
        for (int i = 0; i < n; i++)
        {
            // If burst time of a process is greater than 0 then only need to process further
            if (rem_bt[i] > 0)
            {
                done = false; // There is a pending process

                if (rem_bt[i] > quantum)
                {
                    // Increase the value of t i.e. shows how much time a process has been processed
                    t += quantum;

                    // Decrease the burst_time of current process by quantum
                    rem_bt[i] -= quantum;
                }

                // If burst time is smaller than or equal to quantum. Last cycle for this process
                else
                {
                    // Increase the value of t i.e. shows how much time a process has been processed
                    t = t + rem_bt[i];

                    // Waiting time is current time minus time used by this process
                    wt[i] = t - bt[i];

                    // As the process gets fully executed make its remaining burst time = 0
                    rem_bt[i] = 0;
                }
            }
        }

        // If all processes are done
        if (done == true)
            break;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, quantum);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    printf("Processes  Burst time  Waiting time  Turn around time\n");

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\n\n");
    printf("Average waiting time = %f", (float)total_wt / n);
    printf("\nAverage turn around time = %f", (float)total_tat / n);
}

// Driver code
int main()
{
    int n;
    printf("Enter number of Process: ");
    scanf("%d", &n);
    int *processes = (int *)malloc(n * sizeof(int));  // process id's
    int *burst_time = (int *)malloc(n * sizeof(int)); // Burst time of all processes
    int quantum;                                      // Time quantum
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process Id: ");
        scanf("%d", &processes[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &burst_time[i]);
    }
    printf("\nEnter Quantum Time: ");
    scanf("%d", &quantum);
    printf("\n\n");

    findavgTime(processes, n, burst_time, quantum);
    free(processes);
    free(burst_time);
    return 0;
}
