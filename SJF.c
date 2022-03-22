// C++ program to implement Shortest Job first with Arrival Time
#include <stdio.h>
#define swap(a,b) \
        int t;    \
        t=a;      \
        a=b;      \
        b=t;

int mat[10][6];


void arrangeArrival(int num, int mat[][6])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (mat[j][1] > mat[j + 1][1])
            {
                for (int k = 0; k < 5; k++)
                {
                    swap(mat[j][k], mat[j + 1][k]);
                }
            }
        }
    }
}

void completionTime(int num, int mat[][6])
{
    int temp, val;
    mat[0][3] = mat[0][1] + mat[0][2];      //completion time  
    mat[0][5] = mat[0][3] - mat[0][1];      //turn around time
    mat[0][4] = mat[0][5] - mat[0][2];      //waiting time

    for (int i = 1; i < num; i++)
    {
        temp = mat[i - 1][3];
        int low = mat[i][2];
        for (int j = i; j < num; j++)
        {
            if (temp >= mat[j][1] && low >= mat[j][2])
            {
                low = mat[j][2];
                val = j;
            }
        }
        mat[val][3] = temp + mat[val][2];           //completion time 
        mat[val][5] = mat[val][3] - mat[val][1];    //turn around time
        mat[val][4] = mat[val][5] - mat[val][2];    //waiting time
        for (int k = 0; k < 6; k++)
        {
            swap(mat[val][k], mat[i][k]);
        }
    }
}

int main()
{
    int num, temp;

    printf("Enter number of Process(upto 10): ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("\nEnter Process Id: ");
        scanf("%d", &mat[i][0]);
        printf("Enter Arrival Time: ");
        scanf("%d", &mat[i][1]);
        printf("Enter Burst Time: ");
        scanf("%d", &mat[i][2]);
    }

    printf("\n\nBefore Arrange...\n");
    printf("Process ID\tArrival Time\tBurst Time\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d\t\t%d\t\t%d\n", mat[i][0], mat[i][1], mat[i][2]);
    }

    arrangeArrival(num, mat);
    completionTime(num, mat);
    printf("\n\nFinal Result...\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", mat[i][0], mat[i][1], mat[i][2], mat[i][4], mat[i][5]);
    }
    return 0;
}
