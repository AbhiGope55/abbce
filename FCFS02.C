/* WAPC to Implement FCFS CPU Scheduling ALgorithm.
   Case2: The Jobs are Submitted Seperately.
   SPL Case: The Submission Time of Jobs are Taken into
   Consderation w.r.t. That of Job 1 */
#include<stdio.h>
#include<conio.h>
void main()
  {
    int nProcess;/*Number of Processes in the Ready Queue*/
    int ST[20];/*Submssion Time of Each Process*/
    int BT[20];/*Burst Time of Each Process*/
    int WT[20];/*Waiting Time of Each Process*/
    int RT[20];/*Response Time for Each Process*/
    int TAT[20];/*Turnaround Time for Each Process*/
    float avgWT=0;/*Avergage Waiting Time*/
    float avgTAT=0;/*Average Turnaround Time*/
    int counter;
    int curProcess;
    clrscr();
    printf("Enter Total Number of Processes (Maximum 20)");
    scanf("%d",&nProcess);
    printf("\nEnter Submission Time and Burst Time for Each Process\n");
    for(counter=0;counter<nProcess;counter++)
	  {
	    printf("P[%d]:",counter+1);
	    scanf("%d%d",&ST[counter],&BT[counter]);
	  }
    WT[0]=0;/* waiting time for the first process is assumed as 0*/
    RT[0]=0;/* Response time for the first process is assumed as 0*/
    /*Calculating Waiting Time of Subsequent Processes*/
    for(counter=1;counter<nProcess;counter++)
	  {
	    RT[counter]=RT[counter-1]+BT[counter-1];
	    WT[counter]=RT[counter-1]+BT[counter-1]-ST[counter];

	  }
    printf("\n Process|SubmissionTime|BurstTime|ResponseTime|WaitingTime|TurnaroundTime")  ;
    /*Calculating Turnaround Time*/
    for(counter=0;counter<nProcess;counter++)
	  {
	    TAT[counter]=BT[counter]+WT[counter];
	    avgWT+=WT[counter];
	    avgTAT+=TAT[counter];
	    printf("\n P[%d] \t\t %d \t \t %d \t \t %d\t \t %d\t \t %d", counter+1,ST[counter],BT[counter],RT[counter],WT[counter],TAT[counter]);
	  }
    avgWT/=nProcess;
    avgTAT/=nProcess;
    printf("\n\n Average Waiting Time= %f",avgWT);
    printf("\n\n Average Turaround Time=%f",avgTAT);
    getch();
  }
