#include <stdio.h>

struct process {
    int pid;       
    int btime;      
    int wtime;    
    int ttime;     
} process[10], temp;

int main(void) {
    int i, j, k, n, ttur, twat;
    float awat, atur;
    printf("Enter the no. of process: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Burst time for process P%d: ", (i+1));
        scanf("%d", &process[i].btime);
        process[i].pid += i + 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((process[i].btime > process[j].btime) ||
               (process[i].btime == process[j].btime && process[i].pid > process[i].pid)) {
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
       }
   }

    process[0].wtime = 0;
    for (i = 0; i < n; i++) {
        process[i+1].wtime = process[i].wtime + process[i].btime;
        process[i].ttime = process[i].wtime + process[i].btime;
    }

    ttur = twat = 0;
    for (i = 0; i < n; i++) {
        ttur += process[i].ttime;
        twat += process[i].wtime;
    }

    awat = (float) twat / n;
    atur = (float) ttur / n;

    printf("\n\nSJF Scheduling\n\n");

    for (i = 0; i < 50; i++)
        printf("-");
    printf("\nProcess\t\tB-Time\t\tT-Time\t\tW-Time\n");

    for (i = 0; i < 50; i++)
        printf("-");
    printf("\n");

    for (i = 0; i < n; i++)
        printf("P%d\t\t%4d\t\t%4d\t\t%4d\n",
               process[i].pid,
               process[i].btime,
               process[i].ttime,
               process[i].wtime);
    printf("Average Waiting Time: %5.2fms\n", awat);
    printf("Average Turnaround Time: %5.2fms\n", atur);


    printf("GANTT Chart\n");
    printf("-");
    for (i = 0; i < (process[n-1].ttime + n * 2); i++)
        printf("-");
    printf("\n");
    printf("|");
    for (i = 0; i < n; i++) {
        k = process[i].btime / 2;
        for (j = 0; j < k; j++)
            printf(" ");
        printf("P%d", process[i].pid);
        for (j = k + 1; j < process[i].btime; j++)
            printf(" ");
        printf("|");
    }

    printf("\n-");
    for (i = 0; i < (process[n-1].ttime + 2 * n); i++)
        printf("-");
    printf("\n");

    printf("0");
    for (i = 0; i < n; i++) {
        for (j = 0; j < process[i].btime; j++)
            printf(" ");
        printf("%2d", process[i].ttime);
    }
    printf("\n");
    return 0;
}

