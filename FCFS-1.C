#include <stdio.h>
// #include<conio.h>
int main()
{
  int n, pt[20], st[20], wt[20], rt[20], tat[20], i, j, swt, spt;

  // clrscr();

  printf("Enter Total Number of Proccess(<=20)");

  scanf("%d", &n);

  printf("Enter Processing Time for the Process");

  for (i = 0; i < n; i++)
  {
    printf("\nP%d:", i + 1);
    scanf("%d", &pt[i]);
  }

  printf("Enter Submission Time for the Process");

  for (i = 0; i < n; i++)
  {
    printf("\nP%d:", i + 1);
    scanf("%d", &st[i]);
  }

  wt[0] = 0; /*assuming that when the process P1 was submited , the ready queu was empty*/

  for (i = 0; i < n; i++)
  {
    swt = 0;
    for (j = 0; j <= i; j++)
    {
      swt = swt + pt[j];
    }
    wt[i + 1] = swt - st[i + 1];
  }

  rt[0] = 0; /*assuming that when the process P1 was submited , the ready queu was empty*/

  for (i = 0; i <= n; i++)
  {
    spt = 0;
    for (j = 0; j <= i; j++)
    {
      spt = spt + pt[j];
    }
    rt[i + 1] = spt;
  }

  printf("\n Process Process Time Submission Time Waiting Time Response Time Turnaround Time");

  for (i = 0; i < n; i++)
  {
    tat[i] = pt[i] + rt[i];
    printf("\nP[%d]\t%d\t%d\t%d\t%d\t%d", i + 1, pt[i], st[i], wt[i], rt[i], tat[i]);
  }

  // getch();

  return 0;
}
