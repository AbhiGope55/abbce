/*
   WAPC to Implement SJFS CPU Scheduling Algorithm.
   Case 2: All the Requesting Processes have different Submission Time
   The Submission Time of Subsequent Processes are considered w.r.to that of First Process
*/
#include<stdio.h>
#include<conio.h>
void main()
  {
      /*Number of Process*/

      int nProcess;

      /*Variable TAT is assigned  value 1 more than Submssion Time of Last Process*/

      int TAT;

      /*Used to Count the Number of Iterations of Outer Loop*/

      int counter;

      /*Used to Count then Number of Iteration of Inner Loop*/

      int subCounter;

      /*Temporary Variable used for Swapping*/

      int temp;

      /*Used to keep the index of the process having small(est) Burst Time*/

      int small;

      /*Used to keep the Submission Time of Last Process*/

      int m;

      /* Array to Store Burst Time of Requesting Processes */

      int BurstTime[10];

      /* Array to Store Burst Time of Requesting Processes after Scheduling*/

      int SortedBurstTime[10];

      /* Array to Store Submission Time of Requesting Processes */

      int SubmissionTime[10];

      /* Array to Store Submission Time of Requesting Processes after Scheduling*/

      int SortedSubmissionTime[10];

      /* Array to Store Process Number of Requesting Processes */

      int ProcessNumber[10];

      /* Array to Store Process Number of Requesting Processes after Scheduling*/

      int SortedProcessNumber[10];

      /* Array to Store Delay Time caused due to Scheduling of Requesting Processes */

      int SDT[10];

      /* Array to Store Response Time of Requesting Processes after Scheduling*/

      int ResponseTime[10];

      /* Array to Store Waiting Time of Requesting Processes */

      int WaitingTime[10];

      /* Array to Store Turnaround Time of Requesting Processes */

      int TurnAroundTime[10];

      clrscr();

      /*Reading the Total Number of Processes through Keyboard*/

      printf("Enter the Number of Processes:-");
      scanf("%d",&nProcess);

      /*Reading Submission Time and Burst Time*/

      printf("Enter Submission Time and Burst Time for:-\n");
      for(counter=0;counter<nProcess;counter++)
	 {
	      printf("\nProcessNumber[%d]:-",counter+1);
	      scanf("%d %d",&SubmissionTime[counter],&BurstTime[counter]);
	      /*Copying the value of Burst Time  to Sorted Burst Time */
	      SortedBurstTime[counter]=BurstTime[counter];
	      /*Copying the value of Submission Time  to Sorted Submission Time */
	      SortedSubmissionTime[counter]=SubmissionTime[counter];
	 }

      /*Displaying the List of Submitted Processes along with their Submission Time and Burst Time*/

      printf("||ProcessNumber||SubmissionTime||BurstTime||");
      for(counter=0;counter<nProcess;counter++)
	 {
	      ProcessNumber[counter]=counter+1;
	      printf("\n\tP[%d]\t\t%d\t\t%d",counter+1,SubmissionTime[counter],BurstTime[counter]);
	      SortedProcessNumber[counter]=ProcessNumber[counter];
	 }

      /*Submission Time of Last Process is assigned to m*/

      m=SortedSubmissionTime[nProcess-1];

      /*Scheduling of Processes w.r.to Ascending Order of their Burst Time */

      for(counter=0;counter<=nProcess-2;counter++)
	 {
	      small=counter;
	      for(subCounter=counter+1;subCounter<=nProcess-1;subCounter++)
		 {
			if(SortedBurstTime[small]>SortedBurstTime[subCounter])
			      small=subCounter;
		 }

	      /*Swapping of Burst Time after Scheduling*/

	      temp=SortedBurstTime[counter];
	      SortedBurstTime[counter]=SortedBurstTime[small];
	      SortedBurstTime[small]=temp;

	      /*Swapping of Submission Time after Scheduling*/

	      temp=SortedSubmissionTime[counter];
	      SortedSubmissionTime[counter]=SortedSubmissionTime[small];
	      SortedSubmissionTime[small]=temp;

	      /*Swapping of Process Number after Scheduling*/

	      temp=SortedProcessNumber[counter];
	      SortedProcessNumber[counter]=SortedProcessNumber[small];
	      SortedProcessNumber[small]=temp;
	 }

      /*Variable TAT is assigned  value 1 more than Submssion Time of Last Process*/

      TAT=m+1;

      /*Calculating the Response Time, Waiting Time and Turnaround Time */

      for(counter=0;counter<nProcess;counter++)
	 {
	      if(counter==0)
		 ResponseTime[counter]=TAT;/*Response Time for "Process Number with Smallest Burst Time" */
	      else
		 ResponseTime[counter]=TurnAroundTime[counter-1];

	      /*Computation of Delay Time caused due to Scheduling */
	      SDT[counter]=m+1-SortedSubmissionTime[counter];/*Delay Time caused due to Scheduling for "ith Process" is computed by subtracting the submission time of "ith Process" from Response Time of Process with Smallest Burst Time*/
	      WaitingTime[counter]=ResponseTime[counter]-SortedSubmissionTime[counter];
	      TurnAroundTime[counter]=SortedSubmissionTime[counter]+WaitingTime[counter]+SortedBurstTime[counter];
	 }

      printf("\nTaking sorting time=1 CPUTime");
      printf("\nAfter Sorting...\n");
      printf("||ProcessNumber||BTime||STime||SDT||RTime||WTime||TATime||");
      for(counter=0;counter<nProcess;counter++)
	 {
	      printf("\n\tP[%d]\t%d\t%d\t%d\t%d\t%d\t%d",SortedProcessNumber[counter],SortedBurstTime[counter],SortedSubmissionTime[counter],SDT[counter],ResponseTime[counter],WaitingTime[counter],TurnAroundTime[counter]);
	 }
      getch();
  }