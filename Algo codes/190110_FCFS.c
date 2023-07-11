#include <stdio.h>
int main()
{
    int pid[15];
    int bt[15];
    int n;
    printf("Number of Processes: ");
    scanf("%d", &n);

    printf("Enter process id of all the Processes: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Process id of Process %d: ", i + 1);
        scanf("%d", &pid[i]);
    }

    printf("Enter burst time of all the Processes: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst time of Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    int i, wt[n];
    wt[0] = 0;

    // for calculating waiting time of each process
    for (i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
    float tot_waiting_time = 0.0;
    float total_turnaround_time = 0.0;
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);

        // calculating and printing turnaround time of each process
        printf("%d\t\t", bt[i] + wt[i]);
        printf("\n");

        // for calculating total waiting time
        tot_waiting_time += wt[i];

        // for calculating total turnaround time
        total_turnaround_time += (wt[i] + bt[i]);
    }
    float avg_turnAround_time, average_waiting_time;

    // for calculating average waiting time
    average_waiting_time = tot_waiting_time / n;

    // for calculating average turnaround time
    avg_turnAround_time = total_turnaround_time / n;
    printf("Avg. waiting time= %.2f\n", average_waiting_time);
    printf("Avg. turnaround time= %.2f\n", avg_turnAround_time);
}
