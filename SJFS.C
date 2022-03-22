#include <stdio.h>
// #include<conio.h>
int main()
{
   int nProcess, ProcessingTime[10], SubmissionTime[10], TAT, i, j, t, small, m;
   int Process[10], sdt[10], ResponseTime[10], WaitingTime[10], TurnaroundTime[10];
   //  clrscr();
   /*User has to submit the number of processes to be processed*/
   printf("\n Enter The Number of Processes to be Processed");
   scanf("%d", &nProcess);
   /*User has to submit the processing time of the competing processes*/
   printf("\n Enter the Processing Time of Competing Processes");
   for (i = 0; i < nProcess; i++)
   {
      printf("\nP%d:", i + 1);
      scanf("%d", &ProcessingTime[i]);
   }
   /*User has to submit the sumbssion time of the competing processes*/
   printf("\n Enter the Submission Time of Competing Processes");
   for (i = 0; i < nProcess; i++)
   {
      printf("\nP%d:", i + 1);
      scanf("%d", &SubmissionTime[i]);
   }
   /*The Processing Time and Submission Time of each is Process is tabled below*/
   printf("Process Number\tProcessing Time\t Submission Time");
   for (i = 0; i < nProcess; i++)
   {
      Process[i] = i + 1;
      printf("\n\t P[%d]\t\t%d\t\t%d", i + 1, ProcessingTime[i], SubmissionTime[i]);
   }

   m = SubmissionTime[nProcess - 1]; /*The Submission Time of Last Process is assigned to variable m*/
   /*The Scheduling of Competing Processes is done w.r.t. Asscending Order of Processing Time and Subsequently The Submission Time has also to be rescheduled*/
   for (i = 0; i <= nProcess - 2; i++)
   {
      small = i;
      for (j = i + 1; j <= nProcess - 1; j++)
      {
         if (ProcessingTime[small] > ProcessingTime[j])
            small = j;
      }
      t = ProcessingTime[i];
      ProcessingTime[i] = ProcessingTime[small];
      ProcessingTime[small] = t;
      t = SubmissionTime[i];
      SubmissionTime[i] = SubmissionTime[small];
      SubmissionTime[small] = t;
      t = Process[i];
      Process[i] = Process[small];
      Process[small] = t;
   }

   TAT = m + 1; /*The delay of 1 CPU Time due to SJF Scheduling is taken into consideration*/
   for (i = 0; i < nProcess; i++)
   {
      if (i == 0)
      {
         ResponseTime[i] = TAT;
      }
      else
      {
         ResponseTime[i] = TurnaroundTime[i - 1];
      }
      sdt[i] = m + 1 - SubmissionTime[i];
      WaitingTime[i] = ResponseTime[i] - SubmissionTime[i];
      TurnaroundTime[i] = SubmissionTime[i] + WaitingTime[i] + ProcessingTime[i];
   }

   printf("\n Taking Sorting Time 1 CPU Time");
   printf("\n after sorting....\n");
   printf("ProcessNumber ProcessingTime SubmissionTime sdt ResponseTime WaitingTime TAT");
   for (i = 0; i < nProcess; i++)
   {
      printf("\n\tP[%d] \t %d \t %d \t %d \t %d \t %d \t %d", Process[i], ProcessingTime[i], SubmissionTime[i], sdt[i], ResponseTime[i], WaitingTime[i], TurnaroundTime[i]);
   }
   //  getch();
   return 0;
}
