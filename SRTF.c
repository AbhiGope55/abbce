// C program to implement Shortest Remaining Time First 
// Shortest Remaining Time First (SRTF) 




// Implementation:

// 1- Traverse until all process gets completely
//    executed.
//    a) Find process with minimum remaining time at
//      every single time lap.
//    b) Reduce its time by 1.
//    c) Check if its remaining time becomes 0 
//    d) Increment the counter of process completion.
//    e) Completion time of current process = 
//      current_time +1;
//    e) Calculate waiting time for each completed 
//      process.
//    wt[i]= Completion time - arrival_time-burst_time
//    f)Increment time lap by one.
// 2- Find turnaround time (waiting_time+burst_time).




#include <stdio.h>  
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>
struct Process { 
	int pid; 			// Process ID 
	int bt; 			// Burst Time 
	int art;			// Arrival Time 
}; 

// Function to find the waiting time for all processes 
void findWaitingTime(struct Process proc[], int n, int wt[]) 
{ 
	int rt[n]; 

	// Copy the burst time into rt[] 
	for (int i = 0; i < n; i++) 
		rt[i] = proc[i].bt; 

	int complete = 0, t = 0, minm = INT_MAX; 
	int shortest = 0, finish_time; 
	bool check = false; 

	// Process until all processes gets completed 
	while (complete != n) { 

		// Find process with minimum remaining time among the 
		// processes that arrives till the current time` 
		for (int j = 0; j < n; j++) { 
			if ((proc[j].art <= t) && 
			(rt[j] < minm) && rt[j] > 0) { 
				minm = rt[j]; 
				shortest = j; 
				check = true; 
			} 
		} 

		if (check == false) { 
			t++; 
			continue; 
		} 

		// Reduce remaining time by one 
		rt[shortest]--; 

		// Update minimum 
		minm = rt[shortest]; 
		if (minm == 0) 
			minm = INT_MAX; 

		// If a process gets completely executed 
		if (rt[shortest] == 0) { 

			// Increment complete 
			complete++; 
			check = false; 

			// Find finish time of current process 
			finish_time = t + 1; 

			// Calculate waiting time 
			wt[shortest] = finish_time - 
						proc[shortest].bt - 
						proc[shortest].art; 

			if (wt[shortest] < 0) 
				wt[shortest] = 0; 
		} 
		// Increment time 
		t++; 
	} 
} 

// Function to calculate turn around time 
void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding bt[i] + wt[i] 
	for (int i = 0; i < n; i++) 
		tat[i] = proc[i].bt + wt[i]; 
} 

// Function to calculate average time 
void findavgTime(struct Process proc[], int n) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	// Function to find waiting time of all processes 
	findWaitingTime(proc, n, wt); 

	// Function to find turn around time for all processes 
	findTurnAroundTime(proc, n, wt, tat); 

	// Display processes along with all details 
	printf("Processes  Arrival time  Burst time    Waiting time  Turn around time\n"); 

	// Calculate total waiting time and total turnaround time 
	for (int i = 0; i < n; i++) { 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		printf(" %2d\t\t%2d\t\t%2d\t\t%2d\t\t%2d\n", proc[i].pid, proc[i].art, proc[i].bt, wt[i], tat[i]);
	} 

	printf("\nAverage waiting time = %f", (float)total_wt /n); 
	printf("\nAverage turn around time = %f ", (float)total_tat / n); 
} 

int main() 
{ 
    int n;
    printf("Enter number of Process: ");
    scanf("%d", &n);

	struct Process* proc=(struct Process*)malloc(n*sizeof(struct Process));  
	for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process Id: ");
        scanf("%d", &proc[i].pid);
        printf("Enter Arrival Time: ");
        scanf("%d", &proc[i].art);
        printf("Enter Burst Time: ");
        scanf("%d", &proc[i].bt);
    }

	findavgTime(proc, n); 
    free(proc);
	return 0; 
} 
