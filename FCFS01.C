/* WAPC to Implement FCFS CPU Scheduling ALgorithm.
   Case1: All the Job are Submitted Simulteneously. */
#include<stdio.h>
#include<conio.h>
void main()
  {
    int n;
    int bt[20];
    int wt[20];
    int tat[20];
    float avwt=0;
    float avtat=0;
    int i;
    int j;
    clrscr();
    printf("Enter total number of processes(maximum 20)");
    scanf("%d",&n);
    printf("\nEnter Process Burst Time for Each Process\n");
    for(i=0;i<n;i++)
	  {
	    printf("P[%d]:",i+1);
	    scanf("%d",&bt[i]);
	  }
    wt[0]=0;/* waiting time for the first process is 0*/
    /*calculating waiting time*/
    for(i=1;i<n;i++)
	  {
	    wt[i]=0;
	    for(j=0;j<i;j++)
		  {
		    wt[i]+=bt[j];/*wt[i]=wt[i]+bt[j]*/
		  }
	  }
    printf("\n Process \t Burst Time \t Waiting Time \t Turnaround Time")  ;
    /*calculating turnaround time*/
    for(i=0;i<n;i++)
	  {
	    tat[i]=bt[i]+wt[i];
	    avwt+=wt[i];
	    avtat+=tat[i];
	    printf("\n P[%d] \t\t %d \t \t %d \t \t %d", i+1, bt[i], wt[i], tat[i]);
	  }
    avwt/=n;
    avtat/=n;
    printf("\n\n Average Waiting Time= %f",avwt);
    printf("\n\n Average Turaround Time=%f",avtat);
    getch();
  }
