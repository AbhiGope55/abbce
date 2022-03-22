// C++ implementation of Best - Fit algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory to blocks as per Best fit algorithm
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    // Stores block id of the block allocated to a process
    int allocation[n];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks according to its size ad assign to it
    for (int i = 0; i < n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        // If we could find a block for current process
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;

            // Reduce available memory in this block.
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\n");
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

// Driver code
int main()
{
    int n, m;
    printf("Enter number of Process: ");
    scanf("%d", &n);
    printf("\n");
    int *processSize = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter Size of process %d : ", i + 1);
        scanf("%d", &processSize[i]);
    }
    printf("\n\n");
    printf("Enter number of free Blocks: ");
    scanf("%d", &m);
    printf("\n");
    int *blockSize = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        printf("Enter size of block %d : ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    bestFit(blockSize, m, processSize, n);
    free(blockSize);
    free(processSize);

    return 0;
}
